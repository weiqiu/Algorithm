#include "stdafx.h"
#include "Huiwen.h"

int Huiwen::Run(const std::string& str)
{
	std::string flipStr = FlipStr(str);
	DynamicProgram(str, flipStr);

	return m_scoreMap[str.size() - 1][str.size() - 1];
}

bool Huiwen::PrintMap()
{
	if (m_scoreMap.size() == 0) {
		return false;
	}

	for (size_t r = 0; r < m_scoreMap.size(); r++) {
		for (size_t c = 0; c < m_scoreMap.size(); c++) {
			std::cout << m_scoreMap[r][c] << " ";
		}
		std::cout << std::endl;
	}

	return true;
}

std::string Huiwen::FlipStr(const std::string& str)
{
	std::string flipStr = str;
	size_t strSize = str.size();
	for (size_t i = 0; i < strSize; i++){
		flipStr[i] = str[strSize - i - 1];
	}
	
	return flipStr;
}

bool Huiwen::DynamicProgram(const std::string& str, const std::string& flipStr)
{
	size_t strSize = str.size();
	if (strSize == 0)
		return false;

	InitDPMap(str, flipStr);
	for (size_t r = 1; r < strSize; ++r) {
		for (size_t c = 1; c < strSize; ++c) {
			if (str[r] == flipStr[c]) {
				m_scoreMap[r][c] = m_scoreMap[r - 1][c - 1] + 1;
			}
			else {
				m_scoreMap[r][c] = Max(m_scoreMap[r - 1][c], m_scoreMap[r][c - 1]);
			}
		}
	}

	Backtracking(str, flipStr);
	return true;
}

bool Huiwen::Backtracking(const std::string& str, const std::string& flipStr)
{
	if (m_scoreMap.size() == 0)
		return false;

	std::string huiwenStr;
	size_t r = m_scoreMap.size() - 1;
	size_t c = m_scoreMap[0].size() - 1;
	for (; r >= 0 && c >= 0; ) {
		if (str[r] == flipStr[c]) {
			huiwenStr += flipStr[c];
			if (r == 0 || c == 0)
				break;
			r--;
			c--;
			continue;
		}

		if (r == 0) {
			c--;
			continue;
		}

		if (c == 0) {
			r--;
			continue;
		}

		if (m_scoreMap[r - 1][c] >= m_scoreMap[r][c - 1]) {
			r--;
		}
		else {
			c--;
		}
	}
	std::cout << huiwenStr;
	m_huiwenSubstr.push_back(huiwenStr);
	return true;
}

bool Huiwen::InitDPMap(const std::string& str, const std::string& flipStr)
{
	m_scoreMap = ScoreMap(str.size(), std::vector<int>(flipStr.size()));

	for (size_t r = 0; r < str.size(); ++r) {
		for (size_t c = 0; c < flipStr.size(); ++c) {
			m_scoreMap[r][c] = 0;
		}
	}

	for (size_t r = 0; r < str.size(); ++r) {
		if (str[r] == flipStr[0]) {
			for(size_t i = r; i < str.size(); i++)
				m_scoreMap[i][0] = 1;
			break;
		}
	}

	for (size_t c = 0; c < flipStr.size(); ++c) {
		if (str[0] == flipStr[c]) {
			for (size_t i = c; i < flipStr.size(); i++)
				m_scoreMap[0][i] = 1;
			break;
		}
	}

	return true;
}

template <typename T>
T Huiwen::Max(const T& item01, const T& item02)
{
	return item01 > item02 ? item01 : item02;
}
