#pragma once

#include "SFML/Graphics.hpp"

class Gui
{
public:
	static const float p2pX(const float perc, sf::VideoMode& vm) noexcept;
	static const float p2pY(const float perc, sf::VideoMode& vm) noexcept;
	static const unsigned charSize(const unsigned modifier, sf::VideoMode& vm) noexcept;
};

