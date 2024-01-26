#include <iostream>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::smatch;
using std::regex_search;

int main(void)
{
	string str = "random txt https://www.ex.com/%user rand text";

	// The actual regular expression with / being a delimiter is /https?:\/\/\w+(\.\w+)*(\/[\w@:%_+.~#?&\/=]+)*/
	regex regexp(R"(https?:\/\/\w+(\.\w+)*(\/[\w@:%_+.~#?&\/=]+)*)");

	smatch match;

	regex_search(str, match, regexp);

	cout << "Matched URLs are:" << endl;

	for (auto x : match)
		cout << x << endl;

	return 0;
}