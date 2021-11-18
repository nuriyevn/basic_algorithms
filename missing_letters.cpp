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

		int text_size = text.size();
		bool already_panagram = false;
		for (int i = 0; i < text_size && !already_panagram; i++)
		{
			char c1 = 'a';

			if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z')
			{
				letter_frequency[text[i]]++;
			}
			
			if (text_size % 1024 == 0) // every 1024 characters we check for panagramity. Assuming that it's regular text.
			{
				int letterPresenceCounter = 0;
				for (char c = 'A'; c <= 'Z'; c++)
				{
					if (letter_frequency[c] + letter_frequency[tolower(c)] > 0) // probably && is better thatn plus.
						letterPresenceCounter++;
				}

				if (letterPresenceCounter == ('Z' - 'A' + 1))
					already_panagram = true;
			}
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

/*
Waltz, nymph, for quick jigs vex Bud. - Dmitri Borgmann
Sphinx of black quartz, judge my vow.
Pack my box with five dozen liquor jugs. - Mark Dunn
Glib jocks quiz nymph to vex dwarf.
Jackdaws love my big sphinx of quartz.
The five boxing wizards jump quickly.
How vexingly quick daft zebras jump!
Quick zephyrs blow, vexing daft Jim.
Two driven jocks help fax my big quiz.
The jay, pig, fox, zebra and my wolves quack!
Sympathizing would fix Quaker objectives.
A wizard's job is to vex chumps quickly in fog.
Watch "Jeopardy!", Alex Trebek's fun TV quiz game.
By Jove, my quick study of lexicography won a prize!
Waxy and quivering, jocks fumble the pizza.
*/
int main()
{
	Sentence sentence("A quick brown fox jumps over the lazy dog");
	
	std::set<char> missingLetters = sentence.getMissingLetters();

	for (auto letter : missingLetters)
	{
		cout << letter;
	}

	cout << endl;

	return 0;

}
