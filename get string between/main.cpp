#include <iostream>
#include <algorithm>
#include <string>

std::string toUpper(const std::string& str)
{
	std::string tmp = str;
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), toupper);
	return tmp;
}

std::string toLowest(const std::string& str)
{
	std::string tmp = str;
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), tolower);
	return tmp;
}

size_t strpos(const std::string& str, const std::string& search, const size_t offset = 0)
{
	return str.find(search, offset);
}

std::string get_string_between(const std::string& str, const std::string& start, const std::string& end)
{
	std::string tmp = ' ' + str;
	size_t ini = strpos(tmp, start);
	if (ini == -1) return "";
	ini += start.length();
	size_t len = strpos(tmp, end, ini) - ini;
	return tmp.substr(ini, len);
}

std::string get_string_between_all(const std::string& str, const std::string& start, const std::string& end)
{
	std::string tmp1 = toLowest(str);
	std::string tmp2 = toLowest(start);
	std::string tmp3 = toLowest(end);
	return get_string_between(tmp1, tmp2, tmp3);
}

int main()
{
	std::string response = "<BODY>hello world</body>";
	std::string result = get_string_between_all(response, "<body>", "</body>");

	std::cout << result << std::endl;

	return std::cin.get();
}