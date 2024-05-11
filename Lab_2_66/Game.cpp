#include <iostream>
#include <string>
#include "Kit.hpp"
#include "Game.hpp"

namespace mt
{
	Game::Game(int width, int height, const std::string& capture)
	{
		m_width = width;
		m_height = height;
		m_capture = capture;
	}

	bool Game::Setup()
	{
		m_window.create(sf::VideoMode(m_width, m_height), m_capture);

		//Загрузка текстуры фона

		if (!m_textureBackground.loadFromFile("image.jpg"))
		{
			std::cout << "Error while loading image.jpg" << std::endl;
			return false;
		}
		m_spriteBackground.setTexture(m_textureBackground);

		//Создание кота игрока

		if (!m_kit.Setup(100, 100))
			return false;
	}



	void Game::LifeCycle()
	{
		while (m_window.isOpen())
		{
			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window.close();
			}

			//Обработка клавиатуры

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_kit.Move(0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_kit.Move(-0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_kit.Rotate(-0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_kit.Rotate(0.1);
			}

			m_window.clear();
			m_window.draw(m_spriteBackground);
			m_window.draw(m_kit.Get());

			m_window.display();
		}
	}
}