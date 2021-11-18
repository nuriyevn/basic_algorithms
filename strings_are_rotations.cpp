/*

Write a function which checks if one String is a rotation of other string.
If s1 = “helloworld" then the following are some of its rotated versions:
elloworldh
lloworldhe
loworldhel
oworldhell
worldhello


Nsrat Nuriyev 2021 (c) 

*/



#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool areRotations(string s1, string s2)
{
    unsigned int matched_counter = 0;
    unsigned int s1_size = s1.size();
    unsigned int s2_size = s2.size();

    int i = 0; // index iterator over the first string
    int j = 0; // index iterator over the second string
    int k = j; //  when candidate substr appears, using k instead of j, in order not to wipe out j

    if (s1_size != s2_size)
        return false;

    while (matched_counter < s1_size && j < s1_size)
    {
        if (s1[i] == s2[k])
        {
            matched_counter++;
            i++;
            k++;
            if (k >= s1_size)
                k = k % s1_size;
        }
        else
        {
            i = 0;
            matched_counter = 0;
            j++;
            k = j;
        }
    }
    return matched_counter == s1_size;

}

int main()
{
	string s1 = "hellohash"; 
	auto start = s1.begin();
	string s2 = "llohashhe";
	
	cout << areRotations(s1, s2) << endl;
}
