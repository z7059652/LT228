// This is the main DLL file.

#include "stdafx.h"

#include "ClassLibrary1.h"

std::vector<int> ClassLibrary1::Class1::string2Vect(std::string s)
{
	std::vector<int> res;
	int pos = -1;
	while ((pos = s.find(",") != -1))
	{
		std::string temp = s.substr(0, pos);
		s = s.substr(pos + 1, s.length() - pos - 1);
		res.push_back(atoi(temp.c_str()));
	}
	res.push_back(atoi(s.c_str()));
	return res;
}
