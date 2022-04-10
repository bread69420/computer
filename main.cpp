#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 20;

void accept_guess(string &s, int len){
  cin >> s;
  while (s.length() != len){
    cout << "Invalid guess." << endl;
    cin >> s;
  }
}

int main(){
  string equation = "3*2=6";
  string guess;
  string attempt_check;
  bool Guess_correct;
  int equation_len, count, eq_len;
  eq_len = equation.length();
  count = 0;
  while (!Guess_correct){
  accept_guess(guess, eq_len);
    if (guess == equation){
      Guess_correct = true;
    }
    count++;

  }
  cout << "You win!\nYou toke " << count << " times to get the answer." << endl;
}
