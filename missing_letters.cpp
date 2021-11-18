#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


/*

Problem #2
The sentence "A quick brown fox jumps over the lazy dog" contains every single letter in the
alphabet. Such sentences are called pangrams. You are to write a method getMissingLetters, which
takes a String, sentence, and returns all the letters it is missing (which prevents it from being a
pangram). You should ignore the case of the letters in Sentence, and your return should be all upper
case letters, in alphabetical order.

*/

class Sentence {

private:
	string text;
	std::map<char, int> letter_frequency;
public:

	Sentence(string s)
	{
		text = s;
		// By ignoring the case of the letters I assume that I should convert it to uppercase or lowercase when I've been asked for.
		//std::for_each(text.begin(), text.end(),
		//	[](char& c) { c = ::toupper(c); });
		char c1 = 'a';
		for (char c = 'A' ; c <= 'Z'; c++)
		{
			letter_frequency[c] = 0;
			letter_frequency[c1] = 0;
			c1++;
		}
	}
	~Sentence() {}
	Sentence() = default;
	
	std::set<char> getMissingLetters() 
	{
		std::set<char> missingLetters;

		for (auto c : text)
		{
			letter_frequency[c]++;
		}

		char c1 = 'a';
		for (char c = 'A'; c <= 'Z'; c++)
		{
			if (letter_frequency[c] == 0 && letter_frequency[c1] == 0)
				missingLetters.insert(c);
			c1++;
		}

		return missingLetters;
	}
};

int main()
{
	Sentence sentence(" quick brown fox jumps over the lazy dog");
	
	std::set<char> missingLetters = sentence.getMissingLetters();

	for (auto letter : missingLetters)
	{
		cout << letter << " ";
	}

	cout << endl;

	return 0;

}
