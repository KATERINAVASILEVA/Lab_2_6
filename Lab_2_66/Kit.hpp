#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{
	class Kit
	{
		float m_x, m_y;
		float m_alpha;
		sf::Texture m_textureKit;
		sf::Sprite m_spriteKit;

	public:

		Kit();
		Kit(float x, float y);
		bool Setup(float x, float y);
		void Move(float d);
		void Rotate(float d);
		sf::Sprite Get();
	};
}