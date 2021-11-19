#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
/*
*
Problem #3
A collection of particles is contained in a linearchamber.They all have the same speed, but some are headed toward the rightand others are headedtoward the left.
These particles can pass through each other without disturbing the motion of the particles, so all the particles will leave the chamber relatively quickly.
We will be given the initial conditionsby a String init containing at each position an ‘L' for a leftward moving particle, an 'R’ for a rightwardmoving particle, 
or a'.' for an empty location.init shows all the positions in the chamber.Initially, no location in the chamber contains two particles passing through each other.
We would like an animationof the process.At each unit of time, we want a string showing occupied locations with an 'X' and unoccupied locations with a’.
Implement “animate” function which takes int - speed and std::string(or vector) containing initial condition.
The speed is the number of positions each particle moves in one time unit.
The method will return a std::vector of std::string in whicheach successive element shows the occupied locations at the next time unit.
The ﬁrst element of the return should show the occupied locationsat the initial instant(at time = 0) in the 'X', ’.’ format.
The last element in the return should show the empty chamber at the ﬁrst time that it becomes empty.

Constraints
1. speed will be between 1 and 10 inclusive 2. init will contain between 1 and 50 characters inclusive 3. each character in init will be '.' or 'L' or 'R’
*/
using namespace std;

bool isChamberEmpty(std::vector<string> state)
{
	bool empty = true;
	for (auto c : state)
	{
		if (c[0] != '.')
		{
			empty = false;
			break;
		}
	}

	return empty;
}

std::string convertToBusy(std::vector<string> state)
{
	int size = state.size();
	std::string result(state.size(), '.');
	
	for (int i = 0; i < size; i++)
	{
		if (state[i][0] == 'L' || state[i][0] == 'R') // here we don't care about how many particles reside in a single postion
		{
			result[i] = 'X';
		}
	}

	return result;
}

std::vector<string> animate(int velocity, std::string initial)
{
	std::vector<string> result;
	int size = initial.size();

	std::vector<string> prevState(size, ".");
	for (int i = 0; i < size; i++)
	{
		prevState[i] = initial[i];
	}

	result.push_back(convertToBusy(prevState));

	while (!isChamberEmpty(prevState)) 
	{
		std::vector<string> nextState(size, ".");

		for (int i = 0; i < size; i++)
		{
			int particleCount = prevState[i].size();
			for (auto particle : prevState[i])
			{

				if (particle == '.')
				{
					//nothing to do, skipping, it is an emptiness and that's it
					continue;
				}
				else if (particle == 'L')
				{
					if ((i - velocity) < 0) // out of sight
					{
            //nothing to do
					}
					else
					{
						
						if (nextState[i - velocity][0] == '.')
							nextState[i - velocity] = "L";
						else
							nextState[i - velocity].push_back('L');
							
					}
				}
				else if (particle == 'R')
				{
					if ((i + velocity) >= size) // out of sight
					{
						//nothing to do

					}
					else
					{
						if (nextState[i + velocity][0] == '.')
							nextState[i + velocity] = 'R';
						else
							nextState[i + velocity].push_back('R');
					}
				}
			}
			
		}

		// post-processing
		result.push_back(convertToBusy(nextState));

		prevState = nextState;
	}

	return result;
}

int main()
{
	string initStr;
	string line;
	// The velocity of an object is the rate of change of its position with respect to a frame of reference, and is a function of time. 
	// Velocity is equivalent to a specification of an object's speed and direction of motion
	// So let's call this thing @velocity not @speed
	int velocity = 0; 	
	getline(cin, line);
	stringstream ss(line);
	ss >> initStr;
	ss >> velocity;

	if (initStr.empty())
		return 1;

	initStr.erase(0, 1);
	initStr.erase(initStr.end() - 2, initStr.end());

	std::vector<string> result = animate(velocity, initStr);

	cout << "{ " << endl;
	for (auto str : result)
	{
		cout << str << ',' << endl;
	}
	cout << "}";
}
