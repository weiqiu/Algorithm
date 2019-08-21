std::string RunStr(const std::string& s)
{
	size_t strSize = s.size();
	if (strSize == 1 || strSize == 0)
		return s;

	std::vector<std::vector<bool>> dpMap(strSize, std::vector<bool>(strSize));

	for (size_t r = 0; r<strSize; r++) {
		for (size_t c = 0; c < strSize; c++) {
			dpMap[r][c] = false;
			if( r == c)
				dpMap[r][c] = true;
		}
	}

	for (int r = strSize - 2; r >= 0; r--) {
		if (s[r] == s[r + 1])
			dpMap[r][r + 1] = true;
		for (size_t c = r + 2; c < strSize; c++) {
			if(s[r] == s[c] && dpMap[r + 1][c - 1])
				dpMap[r][c] = true;
		}
	}

	size_t bestRow = 0;
	size_t bestCol = 0;
	size_t best = 0;
	for (size_t r = 0; r < dpMap.size(); r++) {
		for (size_t c = dpMap.size() - 1; c > r; c--) {
			if (dpMap[r][c]) {
				if ((c - r + 1) > best) {
					best = c - r + 1;
					bestRow = r;
					bestCol = c;
				}
				break;
			}
		}
	}

	for (size_t r = 0; r < dpMap.size(); r++) {
		for (size_t c = 0; c < dpMap.size(); c++) {
			std::cout << dpMap[r][c] << " ";
		}
		std::cout << "\n";
	}
    
	std::string result = "";
	for (size_t i = 0; i <= best; i++)
		result += s[i + bestRow];
	return result;
}
