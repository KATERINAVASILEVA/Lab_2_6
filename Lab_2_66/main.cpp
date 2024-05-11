#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Kit.hpp"

int main()
{
	mt::Game game(750, 750, "Game");

	if (!game.Setup())
		return -1;

	game.LifeCycle();

	return 0;
};
