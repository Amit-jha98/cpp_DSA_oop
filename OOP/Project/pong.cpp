#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    const unsigned int windowWidth = 800;
    const unsigned int windowHeight = 600;
    bool twoPlayer = false; // set true for local 2-player

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Simple Pong");
    window.setFramerateLimit(60);

    // Paddles
    float paddleWidth = 10, paddleHeight = 100;
    sf::RectangleShape leftPaddle(sf::Vector2f(paddleWidth, paddleHeight));
    sf::RectangleShape rightPaddle(sf::Vector2f(paddleWidth, paddleHeight));
    leftPaddle.setPosition(50, windowHeight / 2 - paddleHeight / 2);
    rightPaddle.setPosition(windowWidth - 50 - paddleWidth, windowHeight / 2 - paddleHeight / 2);
    leftPaddle.setFillColor(sf::Color::White);
    rightPaddle.setFillColor(sf::Color::White);

    // Ball
    float ballRadius = 8;
    sf::CircleShape ball(ballRadius);
    ball.setPosition(windowWidth / 2 - ballRadius, windowHeight / 2 - ballRadius);
    ball.setFillColor(sf::Color::White);

    // Speeds
    float paddleSpeed = 400.f;
    sf::Vector2f ballVelocity(300.f, 300.f);

    // Main loop
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space)
                    twoPlayer = !twoPlayer;  // toggle mode
            }
        }

        // Player 1 control (left paddle)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && leftPaddle.getPosition().y > 0)
            leftPaddle.move(0, -paddleSpeed * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && leftPaddle.getPosition().y + paddleHeight < windowHeight)
            leftPaddle.move(0, paddleSpeed * dt);

        // Player 2 or AI (right paddle)
        if (twoPlayer) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rightPaddle.getPosition().y > 0)
                rightPaddle.move(0, -paddleSpeed * dt);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rightPaddle.getPosition().y + paddleHeight < windowHeight)
                rightPaddle.move(0, paddleSpeed * dt);
        } else {
            // Simple AI: follow ball
            float paddleCenter = rightPaddle.getPosition().y + paddleHeight / 2;
            if (ball.getPosition().y + ballRadius < paddleCenter && rightPaddle.getPosition().y > 0)
                rightPaddle.move(0, -paddleSpeed * dt * 0.6f);
            if (ball.getPosition().y + ballRadius > paddleCenter && rightPaddle.getPosition().y + paddleHeight < windowHeight)
                rightPaddle.move(0, paddleSpeed * dt * 0.6f);
        }

        // Move ball
        ball.move(ballVelocity * dt);

        // Collision with top/bottom
        if (ball.getPosition().y <= 0 || ball.getPosition().y + 2*ballRadius >= windowHeight)
            ballVelocity.y = -ballVelocity.y;

        // Collision with paddles
        if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()) && ballVelocity.x < 0)
            ballVelocity.x = -ballVelocity.x;
        if (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()) && ballVelocity.x > 0)
            ballVelocity.x = -ballVelocity.x;

        // Reset ball if out of bounds
        if (ball.getPosition().x < 0 || ball.getPosition().x > windowWidth) {
            ball.setPosition(windowWidth / 2 - ballRadius, windowHeight / 2 - ballRadius);
            // invert direction
            ballVelocity.x = -ballVelocity.x;
        }

        // Draw
        window.clear(sf::Color::Black);
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(ball);
        window.display();
    }

    return 0;
}