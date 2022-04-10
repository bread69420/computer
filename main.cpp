#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 20;

void accept_guess(string &s, int len){
  cin >> s;
  while (s.length() != len){  // check if input is valid
    cout << "Invalid guess." << endl;
    cin >> s;
  }
}

int eval(){
  return 1;
}

void guess_space(string &s, int len){  // make initial guess space
  s = "";
  for (int i = 0; i < len; i++){
    s += "_";
  }
}


void check_guess(string guess, string ans, string &review){
  guess_space(review, ans.length());

  string guess_copy = guess;  // check if position is correct
  for (int i = 0; i < ans.length(); i++){
    if (guess_copy[i] == ans[i]){
      review[i] = 'O';
      guess_copy[i] = 'x';
    }
  }
  
  for (int i = 0; i < ans.length(); i++){  // check if certain character exist
    for (int j = 0; j < ans.length(); j++){
      if (guess_copy[i] == ans[j]){
        review[i] = '?';
        guess_copy[i] = 'x';
      }
    }
  }
}

int main(){
  string equation = "3*2=6";
  string guess;
  string attempt_review;
  bool Guess_correct;
  int equation_len, count, eq_len;
  eq_len = equation.length();
  count = 0;
  guess_space(attempt_review, eq_len);
  cout << attempt_review << endl;
  while (!Guess_correct){
    accept_guess(guess, eq_len);
    check_guess(guess, equation, attempt_review);
    cout << attempt_review << endl;
    if (attempt_review == "OOOOO"){
      Guess_correct = true;
    }
    count++;

  }
  cout << "You win!\nYou toke " << count << " times to get the answer." << endl;
}
