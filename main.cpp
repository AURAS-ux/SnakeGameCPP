#include"Game.hpp"
#include"SFML/Graphics.hpp"
int main()
{
	Game* game = new Game();
	/*sf::Time stime;
	stime = sf::seconds(0.1f);*/
	while (game->isRunning())
	{
			game->update();
			//sf::sleep(stime);
	}
	return 0;
}