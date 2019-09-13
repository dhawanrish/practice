#include<iostream>
#include<utility>
#include<map>
#include<fstream>
#include <string>
using namespace std;

void FindOriginCity(map<string, string>);

int main()
{
	ifstream fin;
	string str, str1, str2;
	fin.open("input.txt"); int i;
	map<string, string> mymap;
	while (getline(fin, str))
	{
		for (i = 0; i < str.length(); ++i)
		{
			if (str[i] == ' ')
				break;
		}
		if (i < str.length())
		{
			str1 = str.substr(0, i);
			str2 = str.substr(i + 1, str.length() - i -1);

		}
		else
		{
			str1 = str;
			getline(fin, str2);
		}
		mymap.insert(pair<string, string>(str1, str2));
	}
	FindOriginCity(mymap);

}

void FindOriginCity(map<string, string> mymap)
{
	map<string, int> mymap2;
	for (auto it = mymap.begin(); it != mymap.end(); ++it)
	{
		if (mymap2.find(it->first) != mymap2.end())
			mymap2[it->first] ++;
		else
			mymap2.insert(pair<string, int>(it->first, 1));

		if (mymap2.find(it->second) != mymap2.end())
			mymap2[it->second] ++;
		else
			mymap2.insert(pair<string, int>(it->second, 1));
	}
	auto it2 = mymap.begin();
	for (auto it = mymap2.begin(); it != mymap2.end(); ++it)
	{
		if ((it->second == 1) && (mymap.find(it->first) != mymap.end()))
		{
			it2 = mymap.find(it->first);
			break;
		}
	}
	cout << it2->first << " ";
	while (mymap.find(it2->second) != mymap.end())
	{
		cout << it2->second << " ";
		it2 = mymap.find(it2->second);
	}
	cout << it2->second;
}
