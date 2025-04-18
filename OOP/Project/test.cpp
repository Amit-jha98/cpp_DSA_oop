#include <SFML/Audio.hpp> 

sf::Music m;
if (!m.openFromFile("bg.ogg")) std::cerr<<"load failed\n"; 
else m.play();
// then immediately return 0;  // just to see if that single call hangs
return 0;