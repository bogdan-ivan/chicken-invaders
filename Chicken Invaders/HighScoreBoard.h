#include <map>
#include <string>
#include <iterator>
#include <algorithm>


template<typename A, typename B>
std::pair<B, A> flip_pair(const std::pair<A, B>& p)
{
	return std::pair<B, A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B, A> flip_map(const std::multimap<A, B>& src)
{
	std::multimap<B, A> dst;
	std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
		flip_pair<A, B>);
	return dst;
}

class HighScoreBoard
{
public:
	HighScoreBoard();
	~HighScoreBoard();
	static void addScore(long score, const std::string& name);
	static void resetScore();
	void printToConsole();
	std::string getString() const noexcept;
private:
	void saveToFile(const std::string path);
	void loadFromFile(const std::string path);
private:
	std::multimap<long, std::string> m_runTimeBoard;
	std::multimap<std::string, long> m_persisentBoard;
	static std::multimap<uint64_t, std::string, std::greater<uint64_t>> m_map;
	int m_size;
};

 