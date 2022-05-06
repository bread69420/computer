#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> numbers;
vector<int> presence;

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}

int main()
{
    string s[6];
    for (int i = 0; i < 6; ++i)
    {
        cin >> s[i];
        if (isNumber(s[i]))
        {
            numbers.push_back(stoi(s[i]));
        }
    }

    int a = numbers[0];
    int b = numbers[2];
    for (int w=4; )
    int c = numbers[???????????????????]; //need help here

    if (a+b == c){
        presence.push_back(1);
    }
    else if (a-b == c){
        presence.push_back(1);
    }
    else if (a*b == c){
        presence.push_back(1);
    }
    else if (a/b == c){
        presence.push_back(1);
    }

    int count = 0;

    for (int j=0; j<presence.size(); ++j){
        if (presence[j] == 1){
            count += 1;
        }
    }

    if (count == 0){
        cout << "Invalid Equation!" << endl;
    }

    return 0;
}

/*Dear STAs,

We have somehow encountered a coding problem here.

We would like to put all the integers of an equation into a vector for checking if a user has input invalid numbers. 
Say, a user must input numbers. If a user inputs 1+1=2, it is a valid input. Otherwise, inputting something like "hello" or "?!?" is deemed as invalid input.

For example,

a user inputs 8+9=17

I want to put 8, 9, and 17 together in a vector such that the entries of the vector are [8, 9, 17]

Then, we let a = 8, b = 9, and c = 17.

Following this, we let count = 0.

We check for a+b==c, a-b==c, a*b==c and a/b == c.

Here only a+b==c is true, so count += 1 => count = 1.

Now check for count == 0. It is false, so no invalid guess.

Now here is the problem:
We are being troubled by this part:
"I want to put 8, 9, and 17 together in a vector such that the entries of the vector are [8, 9, 17]

Then, we let a = 8, b = 9, and c = 17."

Because c is of two digits, we do not know how to put it into a vector.

We are concerned that we would be putting [8,9,1,7] instead of [8,9,17].

Is it possible to provide help on this? Thanks again.

Best,
Cyrus
*/