#pragma once

#include <string>
#include <vector>
#include <iostream>

class Huiwen
{
public:
	using ScoreMap = std::vector<std::vector<int>>;
	int Run(const std::string& str);
	
	bool PrintMap();

private:
	std::string FlipStr(const std::string& str);

	bool DynamicProgram(const std::string& str, const std::string& flipStr);

	bool Backtracking(const std::string& str, const std::string& flipStr);

	bool InitDPMap(const std::string& str, const std::string& flipStr);

	template <typename T>
	T Max(const T& item01, const T& item02);

private:
	ScoreMap m_scoreMap;
	std::vector<std::string> m_huiwenSubstr;
};
