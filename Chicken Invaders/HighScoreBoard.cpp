#include "HighScoreBoard.h"
#include <fstream>
#include <iostream>
#include <algorithm>

HighScoreBoard::HighScoreBoard()
	:m_size(10)
{
	loadFromFile("..//Config//Leaderboard.ini");
}

HighScoreBoard::~HighScoreBoard()
{
	saveToFile("..//Config//Leaderboard.ini");
}

void HighScoreBoard::addScore(long score, const std::string& name)
{
	m_map.insert({ score,name });
}

void HighScoreBoard::resetScore()
{
	m_map.clear();
	for (auto nr = 0 ; nr < 10; ++nr)
	{
		m_map.insert({ 0,"Empty" });
	}
}

void HighScoreBoard::printToConsole()
{
	std::cout << " Name \tScore";
	int cnt = 1;
	for (auto& pair: m_runTimeBoard) 
	{
		std::cout << cnt << "." << pair.first << "\t" << pair.second << "\n";
		cnt++;
		if (cnt > m_size)
			break;
	}
}

std::string HighScoreBoard::getString() const noexcept
{
	std::string board;
	int counter = 1;
	for (auto& [score, name] : m_map)
	{
		board += std::to_string(counter);
		board += ". ";
		board += name;
		board += " ";
		board += std::to_string(score);
		board += "\n";
		++counter;
	}
	return board;
}

void HighScoreBoard::saveToFile(const std::string path)
{
	std::ofstream output(path);
	if (!output.good())
		//logger->log(LoggingLevel::ERROR, "Failed to open Window.ini");
		std::cerr << "Failed to open Leaderboards.ini" << std::endl;
	else
	{
		m_persisentBoard = flip_map(m_runTimeBoard);
		for (auto& [name, score] : m_persisentBoard)
		{
			output << name << " " << score << "\n";
		}
	}
	output.close();
}

void HighScoreBoard::loadFromFile(const std::string path)
{
	std::ifstream input(path);
	if (!input.good())
		//logger->log(LoggingLevel::ERROR, "Failed to open Window.ini");
		std::cerr << "Failed to open Leaderboards.ini" << std::endl;
	else
	{
		std::string name;
		std::string score;
		for (int i = 0; i < m_size; ++i)
		{
			input >> name;
			input >> score;
			m_persisentBoard.insert({ name,std::stoi(score) });
			m_map.insert({ std::stoi(score) , name });
		}
	}
	m_runTimeBoard = flip_map(m_persisentBoard);
	input.close();
}

std::multimap<uint64_t, std::string, std::greater<uint64_t>> HighScoreBoard::m_map;