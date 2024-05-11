#include <SFML/Graphics.hpp>
#include <iostream>
#include "Kit.hpp"

namespace mt
{
	Kit::Kit() = default;
	Kit::Kit(float x, float y)
	{
		m_x = x;
		m_y = y;
	}

	bool Kit::Setup(float x, float y)
	{
		m_x = x;
		m_y = y;
		m_alpha = 0;

		if (!m_textureKit.loadFromFile("kot.png"))
		{
			std::cout << "Error while loading kot.png" << std::endl;
			return false;
		}

		m_spriteKit.setTexture(m_textureKit);
		m_spriteKit.setScale(0.2f, 0.2f);
		m_spriteKit.setOrigin(m_textureKit.getSize().x / 2, m_textureKit.getSize().y / 2);
		m_spriteKit.setPosition(m_x, m_y);
		m_spriteKit.setRotation(m_alpha);
	}

	void Kit::Move(float d)
	{
		float alphaRad = acos(-1) * (m_alpha / 180);
		m_x += d * cos(alphaRad);
		m_y += d * sin(alphaRad);
		m_spriteKit.setPosition(m_x, m_y);
	}

	void Kit::Rotate(float d)
	{
		m_alpha += d;
		m_spriteKit.setRotation(m_alpha);
	}

	sf::Sprite Kit::Get()
	{
		return m_spriteKit;
	}
}