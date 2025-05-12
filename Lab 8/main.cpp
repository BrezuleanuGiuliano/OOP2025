#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>
#include <vector>

using namespace std;
ifstream fin("input.txt");

string to_lower(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] <= 'Z' && word[i] >= 'A')
		{
			word[i] += 'a' - 'A';
		}
	}
	return word;
}

vector<string> delim_cuv(string &s)
{
	vector<string> cuvinte;
	string word = "";

	for (int i = 0; i < (int)s.length(); i++)
	{
		char ch = s[i];
		if (ch == ' ' || ch == ',' || ch == '?' || ch == '!' || ch == '.')
		{
			if (word != "")
			{	
				cuvinte.push_back(to_lower(word));
				word = "";
			}
			
		}
		else
			word += ch;

	}
	if (word != "")
	{
		cuvinte.push_back(word);
		word = "";
	}

	return cuvinte;


}
class COMPARATOR{

public:
	bool operator()(pair<string, int>& a, pair<string, int>& b)
	{
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
};
int main()
{
	
	
	map<string, int> map1
	{
		{"i", 2},
		{ "bought", 1},
		{ "an", 2},
		{ "apple", 3}, 
		{ "then", 1},
		{ "eat", 1},
		{ "is", 1},
		{ "my", 1 },
		{ "favorite", 1 }
	};
	map<string, int> ::iterator it;
	for (it = map1.begin(); it != map1.end(); ++it) 
	{
		cout << it->first << " : " << it->second << endl;
		
	}
	cout << endl << endl;
	if (!fin)
	{
		cout << "Eroare la accesarea fisierul input.txt" << endl;
		return 1;
	}
	string fraza = "", linie = "";
	while (getline(fin, linie))
	{
		fraza += linie + " ";

	}
	vector<string> cuvinte;
	cuvinte = delim_cuv(fraza);
	
	/*for (int i = 0; i <cuvinte.size(); i++)
	{
		cout << cuvinte[i]<<endl;
	}
	*/
	map<string, int> frecventa;
	for (int i = 0; i < cuvinte.size(); i++)
	{
		frecventa[cuvinte[i]]++;
	}
	/*map<string, int> ::iterator it1;
	for (it1 = frecventa.begin(); it1 != frecventa.end(); it1++)
	{
		cout << it1->first << " : " << it1->second << endl;

	}
	*/
	priority_queue<
		pair<string, int>,
		vector<pair<string, int>>,
		COMPARATOR
	>coada;
	
	map<string, int>::iterator it2;
	for (it2 = frecventa.begin(); it2 != frecventa.end(); ++it2) 
	{
		coada.push(*it2);
	}

	while (!coada.empty()) 
	{
		pair<string, int> top = coada.top();
		cout << top.first << " => " << top.second << endl;
		coada.pop();
	}
	return 0;
}