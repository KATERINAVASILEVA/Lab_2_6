#pragma once
#include "Kit.hpp"

namespace mt
{
	const float pi = acos(-1);

	class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;
		sf::RenderWindow m_window;
		sf::Texture m_textureBackground;
		sf::Sprite m_spriteBackground;
		Kit m_kit;

	public:
		Game(int width, int height, const std::string& capture);
		bool Setup();
		void LifeCycle();
	};
}