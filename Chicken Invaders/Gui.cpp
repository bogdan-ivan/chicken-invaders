#include "Gui.h"

const float Gui::p2pX(const float perc, sf::VideoMode& vm) noexcept
{
	return std::floor(static_cast<float>(vm.width) * (perc / 100.f));
}

const float Gui::p2pY(const float perc, sf::VideoMode& vm) noexcept
{
	return std::floor(static_cast<float>(vm.height) * (perc / 100.f));
}

const unsigned Gui::charSize(const unsigned modifier, sf::VideoMode& vm) noexcept
{
	return static_cast<unsigned>((vm.width + vm.height) / modifier);
}
