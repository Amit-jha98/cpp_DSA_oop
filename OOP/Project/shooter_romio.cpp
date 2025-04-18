#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <random>
#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include <SFML/Audio.hpp> 

// Enum for enemy types
enum class EnemyType {
    FAST,     // Triangle - fast but weak
    TANKY,    // Hexagon - slow but tough
    SHOOTER   // Diamond - shoots back
};

// Enum for power-up types
enum class PowerUpType {
    SHIELD,      // Blue - temporary invulnerability
    RAPID_FIRE,  // Red - increased fire rate
    TRIPLE_SHOT  // Yellow - shoots three bullets at once
};

// Structure for game objects with extended properties
struct GameObject {
    sf::Shape* shape;
    sf::Vector2f velocity;
    bool active;
    int health;
    float timer;      // Multi-purpose timer
    
    // Constructor with default values
    GameObject() : shape(nullptr), velocity(0.f, 0.f), active(true), health(1), timer(0.f) {}
};

// Structure for enemy with type
struct Enemy : GameObject {
    EnemyType type;
    float shootTimer;
    
    Enemy() : GameObject(), type(EnemyType::FAST), shootTimer(0.f) {}
};

// Structure for power-up
struct PowerUp : GameObject {
    PowerUpType type;
    
    PowerUp() : GameObject(), type(PowerUpType::SHIELD) {}
};

// Structure for explosion animation
struct Explosion {
    sf::CircleShape shape;
    float timer;
    float duration;
    float maxRadius;
    
    Explosion(float x, float y, float duration = 0.5f, float maxRadius = 30.f)
        : timer(0.f), duration(duration), maxRadius(maxRadius) {
        shape.setPosition(x, y);
        shape.setRadius(1.f);
        shape.setOrigin(1.f, 1.f);
        shape.setFillColor(sf::Color(255, 200, 50, 200));
        shape.setOutlineColor(sf::Color(255, 120, 0, 200));
        shape.setOutlineThickness(2.f);
    }
    
    bool update(float dt) {
        timer += dt;
        float progress = timer / duration;
        if (progress >= 1.0f) return false;
        
        shape.setRadius(progress * maxRadius);
        shape.setOrigin(progress * maxRadius, progress * maxRadius);
        
        // Fade out
        int alpha = static_cast<int>(255 * (1.0f - progress));
        shape.setFillColor(sf::Color(255, 200, 50, alpha));
        shape.setOutlineColor(sf::Color(255, 120, 0, alpha));
        
        return true;
    }
};

// Structure for star in background
struct Star {
    sf::CircleShape shape;
    float twinkleTimer;
    float twinkleRate;
    
    Star(float x, float y, float radius, sf::Color color) 
        : twinkleTimer(0.f), twinkleRate(static_cast<float>(rand()) / RAND_MAX * 2.f + 0.5f) {
        shape.setPosition(x, y);
        shape.setRadius(radius);
        shape.setFillColor(color);
    }
    
    void update(float dt) {
        twinkleTimer += dt;
        // Make stars twinkle by changing brightness
        float brightness = 0.7f + 0.3f * sin(twinkleTimer * twinkleRate * 3.14f);
        sf::Color color = shape.getFillColor();
        shape.setFillColor(sf::Color(
            static_cast<sf::Uint8>(color.r * brightness),
            static_cast<sf::Uint8>(color.g * brightness),
            static_cast<sf::Uint8>(color.b * brightness),
            color.a
        ));
    }
};

int main() {
    // Window setup
    const unsigned int windowWidth = 800;
    const unsigned int windowHeight = 600;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Space Shooter");
    window.setFramerateLimit(60);

        // Setup background music
        sf::Music backgroundMusic;
        if(!m.openFromFile("bg.ogg")) std::cerr<<"load failed\n"; else {
            backgroundMusic.setLoop(true);  // Make the music loop continuously
            backgroundMusic.setVolume(70);  // Set volume to 50% (adjust as needed)
            backgroundMusic.play();         // Start playing the music
        }

    // Random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> xDist(0, windowWidth);
    std::uniform_real_distribution<float> yDist(0, windowHeight);
    std::uniform_real_distribution<float> speedDist(50.f, 150.f);
    std::uniform_real_distribution<float> sizeDist(1.f, 3.f);
    std::uniform_int_distribution<int> enemyTypeDist(0, 2);
    std::uniform_int_distribution<int> powerUpTypeDist(0, 2);
    std::uniform_int_distribution<int> powerUpChanceDist(0, 100); // For % chance of power-up drop

    // Create starry background
    std::vector<Star> stars;
    for (int i = 0; i < 200; ++i) {
        float radius = sizeDist(gen);
        float brightness = (static_cast<float>(rand()) / RAND_MAX) * 155.f + 100.f;
        sf::Color color;
        int colorType = rand() % 3;
        if (colorType == 0) {
            color = sf::Color(brightness, brightness, brightness); // White
        } else if (colorType == 1) {
            color = sf::Color(brightness, brightness * 0.8f, brightness * 0.5f); // Yellow-ish
        } else {
            color = sf::Color(brightness * 0.8f, brightness * 0.8f, brightness); // Blueish
        }
        stars.emplace_back(xDist(gen), yDist(gen), radius, color);
    }

    // Improved player ship (pointed spaceship shape)
    sf::ConvexShape playerShip;
    playerShip.setPointCount(7);
    playerShip.setPoint(0, sf::Vector2f(0, -20));      // Top point
    playerShip.setPoint(1, sf::Vector2f(-5, -10));     // Left front
    playerShip.setPoint(2, sf::Vector2f(-15, 0));      // Left wing
    playerShip.setPoint(3, sf::Vector2f(-10, 15));     // Left back
    playerShip.setPoint(4, sf::Vector2f(10, 15));      // Right back
    playerShip.setPoint(5, sf::Vector2f(15, 0));       // Right wing
    playerShip.setPoint(6, sf::Vector2f(5, -10));      // Right front
    
    playerShip.setFillColor(sf::Color(0, 230, 230));   // Cyan
    playerShip.setOutlineColor(sf::Color(100, 255, 255));
    playerShip.setOutlineThickness(2.0f);
    playerShip.setPosition(windowWidth / 2, windowHeight - 100);
    playerShip.setOrigin(0, 0);
    float playerSpeed = 300.f;
    int playerHealth = 3;
    bool shieldActive = false;
    float shieldTimer = 0.f;
    float shieldDuration = 5.f;
    
    // Shield visual indicator
    sf::CircleShape shieldShape;
    shieldShape.setRadius(30.f);
    shieldShape.setFillColor(sf::Color(70, 150, 255, 100));
    shieldShape.setOutlineColor(sf::Color(100, 180, 255, 150));
    shieldShape.setOutlineThickness(2.0f);
    shieldShape.setOrigin(30.f, 30.f);

    // Bullets
    std::vector<GameObject> bullets;
    float bulletRadius = 4.f;
    float bulletSpeed = 500.f;
    float basicFireRate = 0.3f; // seconds between shots
    float fireRate = basicFireRate;
    float fireTimer = 0.f;
    bool rapidFireActive = false;
    float rapidFireTimer = 0.f;
    float rapidFireDuration = 8.f;
    bool tripleShootActive = false;
    float tripleShootTimer = 0.f;
    float tripleShootDuration = 10.f;

    // Enemy bullets
    std::vector<GameObject> enemyBullets;
    float enemyBulletRadius = 3.f;
    float enemyBulletSpeed = 250.f;

    // Enemies
    std::vector<Enemy> enemies;
    float basicEnemySpawnRate = 1.5f; // seconds between enemy spawns
    float enemySpawnRate = basicEnemySpawnRate;
    float enemySpawnTimer = 0.f;

    // Power-ups
    std::vector<PowerUp> powerUps;
    float powerUpSpeed = 100.f;
    float powerUpSize = 15.f;

    // Explosions
    std::vector<Explosion> explosions;

    // Game stats
    int score = 0;
    int level = 1;
    bool gameOver = false;

    // Text setup
    sf::Font font;
    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        std::cout << "Warning: Failed to load font, continuing without text" << std::endl;
    }
    
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);
    
    sf::Text levelText;
    levelText.setFont(font);
    levelText.setCharacterSize(20);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(windowWidth - 120, 10);
    
    sf::Text healthText;
    healthText.setFont(font);
    healthText.setCharacterSize(20);
    healthText.setFillColor(sf::Color::White);
    healthText.setPosition(10, 40);
    
    sf::Text powerUpText;
    powerUpText.setFont(font);
    powerUpText.setCharacterSize(16);
    powerUpText.setFillColor(sf::Color::White);
    powerUpText.setPosition(10, 70);
    
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER\nPress R to restart");
    gameOverText.setCharacterSize(40);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(windowWidth / 2 - 150, windowHeight / 2 - 50);

    // Main game loop
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        
        // Timers
        fireTimer += dt;
        enemySpawnTimer += dt;
        
        if (shieldActive) {
            shieldTimer += dt;
            if (shieldTimer >= shieldDuration) {
                shieldActive = false;
                shieldTimer = 0.f;
            }
        }
        
        if (rapidFireActive) {
            rapidFireTimer += dt;
            if (rapidFireTimer >= rapidFireDuration) {
                rapidFireActive = false;
                rapidFireTimer = 0.f;
                fireRate = basicFireRate;
            }
        }
        
        if (tripleShootActive) {
            tripleShootTimer += dt;
            if (tripleShootTimer >= tripleShootDuration) {
                tripleShootActive = false;
                tripleShootTimer = 0.f;
            }
        }

        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && gameOver) {
                // Reset game
                gameOver = false;
                score = 0;
                level = 1;
                playerHealth = 3;
                bullets.clear();
                enemyBullets.clear();
                enemies.clear();
                powerUps.clear();
                explosions.clear();
                playerShip.setPosition(windowWidth / 2, windowHeight - 100);
                enemySpawnRate = basicEnemySpawnRate;
                fireRate = basicFireRate;
                shieldActive = false;
                rapidFireActive = false;
                tripleShootActive = false;
            }
        }

        // Update stars
        for (auto& star : stars) {
            star.update(dt);
        }

        if (!gameOver) {
            // Player movement
            sf::Vector2f movement(0.f, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && playerShip.getPosition().y > 30)
                movement.y = -playerSpeed * dt;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && playerShip.getPosition().y < windowHeight - 30)
                movement.y = playerSpeed * dt;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && playerShip.getPosition().x > 30)
                movement.x = -playerSpeed * dt;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && playerShip.getPosition().x < windowWidth - 30)
                movement.x = playerSpeed * dt;
                
            playerShip.move(movement);
            
            // Update shield position
            if (shieldActive) {
                shieldShape.setPosition(playerShip.getPosition().x, playerShip.getPosition().y);
            }

            // Shooting
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer >= fireRate) {
                fireTimer = 0;
                
                if (tripleShootActive) {
                    // Create three bullets
                    for (int i = -1; i <= 1; ++i) {
                        sf::CircleShape* bulletShape = new sf::CircleShape(bulletRadius);
                        bulletShape->setFillColor(sf::Color::Yellow);
                        bulletShape->setOutlineColor(sf::Color(255, 255, 150));
                        bulletShape->setOutlineThickness(1.0f);
                        bulletShape->setOrigin(bulletRadius, bulletRadius);
                        bulletShape->setPosition(playerShip.getPosition().x + (i * 10), playerShip.getPosition().y - 15);
                        
                        GameObject bullet;
                        bullet.shape = bulletShape;
                        bullet.velocity = sf::Vector2f(i * 50.f, -bulletSpeed); // Slight angle for side bullets
                        bullet.active = true;
                        
                        bullets.push_back(bullet);
                    }
                } else {
                    // Create a single bullet
                    sf::CircleShape* bulletShape = new sf::CircleShape(bulletRadius);
                    bulletShape->setFillColor(sf::Color::Yellow);
                    bulletShape->setOutlineColor(sf::Color(255, 255, 150));
                    bulletShape->setOutlineThickness(1.0f);
                    bulletShape->setOrigin(bulletRadius, bulletRadius);
                    bulletShape->setPosition(playerShip.getPosition().x, playerShip.getPosition().y - 15);
                    
                    GameObject bullet;
                    bullet.shape = bulletShape;
                    bullet.velocity = sf::Vector2f(0, -bulletSpeed);
                    bullet.active = true;
                    
                    bullets.push_back(bullet);
                }
            }

            // Spawn enemies based on level difficulty
            if (enemySpawnTimer >= enemySpawnRate) {
                enemySpawnTimer = 0;
                
                Enemy enemy;
                
                // Determine enemy type
                int typeRoll = enemyTypeDist(gen);
                switch (typeRoll) {
                    case 0: { // Fast triangle enemy
                        sf::ConvexShape* enemyShape = new sf::ConvexShape();
                        enemyShape->setPointCount(3);
                        enemyShape->setPoint(0, sf::Vector2f(0, -15));
                        enemyShape->setPoint(1, sf::Vector2f(-12, 12));
                        enemyShape->setPoint(2, sf::Vector2f(12, 12));
                        enemyShape->setFillColor(sf::Color(255, 100, 100));
                        enemyShape->setOutlineColor(sf::Color(255, 150, 150));
                        enemyShape->setOutlineThickness(1.0f);
                        enemyShape->setOrigin(0, 0);
                        enemyShape->setPosition(xDist(gen), -30);
                        
                        enemy.shape = enemyShape;
                        enemy.velocity = sf::Vector2f(0, speedDist(gen) * 1.5f); // Faster
                        enemy.type = EnemyType::FAST;
                        enemy.health = 1;
                        break;
                    }
                    case 1: { // Tanky hexagon enemy
                        sf::ConvexShape* enemyShape = new sf::ConvexShape();
                        enemyShape->setPointCount(6);
                        float radius = 20.f;
                        for (int i = 0; i < 6; ++i) {
                            float angle = i * 3.14159f * 2.f / 6;
                            enemyShape->setPoint(i, sf::Vector2f(cos(angle) * radius, sin(angle) * radius));
                        }
                        enemyShape->setFillColor(sf::Color(100, 100, 255));
                        enemyShape->setOutlineColor(sf::Color(150, 150, 255));
                        enemyShape->setOutlineThickness(2.0f);
                        enemyShape->setOrigin(radius, radius);
                        enemyShape->setPosition(xDist(gen), -30);
                        
                        enemy.shape = enemyShape;
                        enemy.velocity = sf::Vector2f(0, speedDist(gen) * 0.7f); // Slower
                        enemy.type = EnemyType::TANKY;
                        enemy.health = 3; // More health
                        break;
                    }
                    case 2: { // Shooter diamond enemy
                        sf::ConvexShape* enemyShape = new sf::ConvexShape();
                        enemyShape->setPointCount(4);
                        enemyShape->setPoint(0, sf::Vector2f(0, -15));
                        enemyShape->setPoint(1, sf::Vector2f(-15, 0));
                        enemyShape->setPoint(2, sf::Vector2f(0, 15));
                        enemyShape->setPoint(3, sf::Vector2f(15, 0));
                        enemyShape->setFillColor(sf::Color(255, 160, 0));
                        enemyShape->setOutlineColor(sf::Color(255, 200, 50));
                        enemyShape->setOutlineThickness(1.0f);
                        enemyShape->setOrigin(0, 0);
                        enemyShape->setPosition(xDist(gen), -30);
                        
                        enemy.shape = enemyShape;
                        enemy.velocity = sf::Vector2f(0, speedDist(gen) * 0.9f);
                        enemy.type = EnemyType::SHOOTER;
                        enemy.health = 2;
                        enemy.shootTimer = 0.f;
                        break;
                    }
                }
                
                enemy.active = true;
                enemies.push_back(enemy);
            }

            // Update bullets
            for (auto& bullet : bullets) {
                if (bullet.active) {
                    bullet.shape->move(bullet.velocity * dt);
                    
                    // Remove bullets that go off screen
                    if (bullet.shape->getPosition().y < -10 || 
                        bullet.shape->getPosition().x < -10 || 
                        bullet.shape->getPosition().x > windowWidth + 10) {
                        bullet.active = false;
                    }
                }
            }
            
            // Update enemy bullets
            for (auto& bullet : enemyBullets) {
                if (bullet.active) {
                    bullet.shape->move(bullet.velocity * dt);
                    
                    // Remove bullets that go off screen
                    if (bullet.shape->getPosition().y > windowHeight + 10) {
                        bullet.active = false;
                    }
                    
                    // Check collision with player
                    if (!shieldActive && bullet.shape->getGlobalBounds().intersects(playerShip.getGlobalBounds())) {
                        bullet.active = false;
                        playerHealth--;
                        
                        // Create explosion effect
                        explosions.emplace_back(playerShip.getPosition().x, playerShip.getPosition().y, 0.3f, 15.f);
                        
                        if (playerHealth <= 0) {
                            gameOver = true;
                            // Final big explosion
                            explosions.emplace_back(playerShip.getPosition().x, playerShip.getPosition().y, 1.0f, 50.f);
                        }
                    }
                }
            }

            // Update enemies
            for (auto& enemy : enemies) {
                if (enemy.active) {
                    enemy.shape->move(enemy.velocity * dt);
                    
                    // Shooter enemies fire at player
                    if (enemy.type == EnemyType::SHOOTER) {
                        enemy.shootTimer += dt;
                        if (enemy.shootTimer >= 2.0f) { // Shoot every 2 seconds
                            enemy.shootTimer = 0.f;
                            
                            sf::CircleShape* bulletShape = new sf::CircleShape(enemyBulletRadius);
                            bulletShape->setFillColor(sf::Color(255, 100, 0));
                            bulletShape->setOutlineColor(sf::Color(255, 150, 0));
                            bulletShape->setOutlineThickness(1.0f);
                            bulletShape->setOrigin(enemyBulletRadius, enemyBulletRadius);
                            bulletShape->setPosition(enemy.shape->getPosition().x, enemy.shape->getPosition().y + 20);
                            
                            GameObject bullet;
                            bullet.shape = bulletShape;
                            bullet.velocity = sf::Vector2f(0, enemyBulletSpeed);
                            bullet.active = true;
                            
                            enemyBullets.push_back(bullet);
                        }
                    }
                    
                    // Check collision with player
                    if (!shieldActive && enemy.shape->getGlobalBounds().intersects(playerShip.getGlobalBounds())) {
                        enemy.active = false;
                        playerHealth--;
                        
                        // Create explosion effect
                        explosions.emplace_back(enemy.shape->getPosition().x, enemy.shape->getPosition().y);
                        explosions.emplace_back(playerShip.getPosition().x, playerShip.getPosition().y, 0.3f, 15.f);
                        
                        if (playerHealth <= 0) {
                            gameOver = true;
                            // Final big explosion
                            explosions.emplace_back(playerShip.getPosition().x, playerShip.getPosition().y, 1.0f, 50.f);
                        }
                    }
                    
                    // Remove enemies that go off screen
                    if (enemy.shape->getPosition().y > windowHeight + 30) {
                        enemy.active = false;
                    }
                }
            }
            
            // Update power-ups
            for (auto& powerUp : powerUps) {
                if (powerUp.active) {
                    powerUp.shape->move(powerUp.velocity * dt);
                    
                    // Check collision with player
                    if (powerUp.shape->getGlobalBounds().intersects(playerShip.getGlobalBounds())) {
                        powerUp.active = false;
                        
                        // Apply power-up effect
                        switch (powerUp.type) {
                            case PowerUpType::SHIELD:
                                shieldActive = true;
                                shieldTimer = 0.f;
                                break;
                            case PowerUpType::RAPID_FIRE:
                                rapidFireActive = true;
                                rapidFireTimer = 0.f;
                                fireRate = basicFireRate / 3.0f; // 3x faster firing
                                break;
                            case PowerUpType::TRIPLE_SHOT:
                                tripleShootActive = true;
                                tripleShootTimer = 0.f;
                                break;
                        }
                    }
                    
                    // Remove power-ups that go off screen
                    if (powerUp.shape->getPosition().y > windowHeight + 20) {
                        powerUp.active = false;
                    }
                }
            }

            // Check bullet-enemy collisions
            for (auto& bullet : bullets) {
                if (bullet.active) {
                    for (auto& enemy : enemies) {
                        if (enemy.active && bullet.shape->getGlobalBounds().intersects(enemy.shape->getGlobalBounds())) {
                            bullet.active = false;
                            enemy.health--;
                            
                            if (enemy.health <= 0) {
                                enemy.active = false;
                                
                                // Create explosion
                                sf::Vector2f pos = enemy.shape->getPosition();
                                explosions.emplace_back(pos.x, pos.y);
                                
                                // Increase score based on enemy type
                                switch (enemy.type) {
                                    case EnemyType::FAST:
                                        score += 10;
                                        break;
                                    case EnemyType::TANKY:
                                        score += 30;
                                        break;
                                    case EnemyType::SHOOTER:
                                        score += 20;
                                        break;
                                }
                                
                                
                                if (powerUpChanceDist(gen) < 20) { 
                                    PowerUp powerUp;
                                    sf::ConvexShape* powerUpShape = new sf::ConvexShape();
                                    powerUpShape->setPointCount(4);
                                    powerUpShape->setPoint(0, sf::Vector2f(-powerUpSize, -powerUpSize));
                                    powerUpShape->setPoint(1, sf::Vector2f(powerUpSize, -powerUpSize));
                                    powerUpShape->setPoint(2, sf::Vector2f(powerUpSize, powerUpSize));
                                    powerUpShape->setPoint(3, sf::Vector2f(-powerUpSize, powerUpSize));
                                    powerUpShape->setOrigin(0, 0);
                                    powerUpShape->setPosition(pos);
                                    
                                    powerUp.shape = powerUpShape;
                                    powerUp.velocity = sf::Vector2f(0, powerUpSpeed);
                                    powerUp.active = true;
                                    
                                  
                                    int powerUpTypeRoll = powerUpTypeDist(gen);
                                    switch (powerUpTypeRoll) {
                                        case 0: 
                                            powerUp.type = PowerUpType::SHIELD;
                                            powerUpShape->setFillColor(sf::Color(50, 100, 255, 200));
                                            powerUpShape->setOutlineColor(sf::Color(100, 150, 255));
                                            break;
                                        case 1: 
                                            powerUp.type = PowerUpType::RAPID_FIRE;
                                            powerUpShape->setFillColor(sf::Color(255, 50, 50, 200));
                                            powerUpShape->setOutlineColor(sf::Color(255, 100, 100));
                                            break;
                                        case 2: 
                                            powerUp.type = PowerUpType::TRIPLE_SHOT;
                                            powerUpShape->setFillColor(sf::Color(255, 255, 50, 200));
                                            powerUpShape->setOutlineColor(sf::Color(255, 255, 100));
                                            break;
                                    }
                                    powerUpShape->setOutlineThickness(2.0f);
                                    
                                    powerUps.push_back(powerUp);
                                }
                            }
                            break;
                        }
                    }
                }
            }

           
            for (auto it = explosions.begin(); it != explosions.end();) {
                if (!it->update(dt)) {
                    it = explosions.erase(it);
                } else {
                    ++it;
                }
            }

           
            auto bulletIt = bullets.begin();
            while (bulletIt != bullets.end()) {
                if (!bulletIt->active) {
                    delete bulletIt->shape;
                    bulletIt = bullets.erase(bulletIt);
                } else {
                    ++bulletIt;
                }
            }
            
            auto enemyBulletIt = enemyBullets.begin();
            while (enemyBulletIt != enemyBullets.end()) {
                if (!enemyBulletIt->active) {
                    delete enemyBulletIt->shape;
                    enemyBulletIt = enemyBullets.erase(enemyBulletIt);
                } else {
                    ++enemyBulletIt;
                }
            }

            auto enemyIt = enemies.begin();
            while (enemyIt != enemies.end()) {
                if (!enemyIt->active) {
                    delete enemyIt->shape;
                    enemyIt = enemies.erase(enemyIt);
                } else {
                    ++enemyIt;
                }
            }
            
            auto powerUpIt = powerUps.begin();
            while (powerUpIt != powerUps.end()) {
                if (!powerUpIt->active) {
                    delete powerUpIt->shape;
                    powerUpIt = powerUps.erase(powerUpIt);
                } else {
                    ++powerUpIt;
                }
            }
            
            
            int newLevel = 1 + (score / 100);
            if (newLevel > level) {
                level = newLevel;
                enemySpawnRate = basicEnemySpawnRate * (0.9f - (level - 1) * 0.05f);
                if (enemySpawnRate < 0.3f) enemySpawnRate = 0.3f; 
            }
        }

       
        scoreText.setString("Score: " + std::to_string(score));
        levelText.setString("Level: " + std::to_string(level));
        healthText.setString("Health: " + std::to_string(playerHealth));
        
       
        std::string powerUpStatus;
        if (shieldActive) {
            powerUpStatus += "Shield: " + std::to_string(static_cast<int>(shieldDuration - shieldTimer)) + "s ";
        }
        if (rapidFireActive) {
            powerUpStatus += "Rapid Fire: " + std::to_string(static_cast<int>(rapidFireDuration - rapidFireTimer)) + "s ";
        }
        if (tripleShootActive) {
            powerUpStatus += "Triple Shot: " + std::to_string(static_cast<int>(tripleShootDuration - tripleShootTimer)) + "s";
        }
        powerUpText.setString(powerUpStatus);

       
        window.clear(sf::Color(5, 5, 20)); 
        
        
        for (const auto& star : stars) {
            window.draw(star.shape);
        }
        
        if (!gameOver) {
         
            if (shieldActive) {
                window.draw(shieldShape);
            }
            
            window.draw(playerShip);
            
            for (const auto& bullet : bullets) {
                window.draw(*bullet.shape);
            }
            
            for (const auto& bullet : enemyBullets) {
                window.draw(*bullet.shape);
            }
            
            for (const auto& enemy : enemies) {
                window.draw(*enemy.shape);
            }
            
            for (const auto& powerUp : powerUps) {
                window.draw(*powerUp.shape);
            }
        } else {
            window.draw(gameOverText);
        }
        
    
        for (const auto& explosion : explosions) {
            window.draw(explosion.shape);
        }
        
        
        window.draw(scoreText);
        window.draw(levelText);
        window.draw(healthText);
        window.draw(powerUpText);
        
        window.display();
    }

   
    for (auto& bullet : bullets) {
        delete bullet.shape;
    }
    
    for (auto& bullet : enemyBullets) {
        delete bullet.shape;
    }
    
    for (auto& enemy : enemies) {
        delete enemy.shape;
    }
    
    for (auto& powerUp : powerUps) {
        delete powerUp.shape;
    }

    return 0;
}