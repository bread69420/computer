#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include "check.h"
using namespace std;

const int MAX = 20;

bool valid_char(char c){ // only accept digits and certain symbols
  if (isdigit(c)){
    return true;
  }
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '='){
    return true;
  }
  return false;
}

bool eval(string s, int len){  // return true when the expression is valid, otherwise return false
  int plus_count, minus_count, times_count, divide_count, equal_count, num1, num2, num3 = 0;
  string n1_s, n2_s, n3_s;
  bool n1_fin, n2_fin = false;
  plus_count = 0;
  minus_count = 0;
  times_count = 0;
  divide_count = 0;
  equal_count = 0;
  for (int i = 0; i < len; i++){
    if (valid_char(s[i])){
      if (isdigit(s[i])){

        if (!n1_fin){
          n1_s = n1_s + s[i];
        }

        if (n1_fin && !n2_fin){
          n2_s = n2_s + s[i];
        }

        if (n1_fin && n2_fin){
          n3_s = n3_s + s[i];
        }
      }

      if(!isdigit(s[i])){
        if (s[i] == '+'){
          plus_count++;
          n1_fin = true;
        }
        if (s[i] == '-'){
          minus_count++;
          n1_fin = true;
        }
        if (s[i] == '*'){
          times_count++;
          n1_fin = true;
        }
        if (s[i] == '/'){
          divide_count++;
          n1_fin = true;
        }
        if (s[i] == '='){
          equal_count++;
          n2_fin = true;
        }

        if (plus_count + minus_count + times_count + divide_count + equal_count >= 3){
          cout << s[i] << plus_count + minus_count + times_count + divide_count + equal_count;
          return false;
        }
      }

    }
    else{
      return false;  // stop running when there is invalid character
    }
  }
  num1 = stoi(n1_s);
  num2 = stoi(n2_s);
  num3 = stoi(n3_s);
  if (plus_count == 1){
    return num1 + num2 == num3;
  }
  if (minus_count == 1){
    return num1 - num2 == num3;
  }
  if (times_count == 1){
    return num1 * num2 == num3;
  }
  if (divide_count == 1){
    return num1 / num2 == num3;
  }
  return false;
}

void accept_guess(string &s, int len){
  cin >> s;
  while (s.length() != len || !eval(s, len)){  // check if input is valid
    cout << "Invalid guess." << endl;
    cin >> s;
  }
}


void obtain_equation(string &str){
  srand(time(NULL)); // set random seed
  ifstream fin;
  fin.open("words.txt");

  string * s = new string [MAX];

  int * i = new int;
  *i = 0;

  while (fin >> s[*i]){  // read equations from file
    (*i)++;
  }

  int equation_num = *i + 1;

  str = s[rand() % equation_num]; // get a random equation from list


  fin.close();
  delete [] s;
  delete i;
}



int main(){
  string equation;
  obtain_equation(equation);
  string guess;
  string attempt_review;
  bool Guess_correct;
  int equation_len, eq_len;
  eq_len = equation.length();
  int * count = new int;
  *count = 0;

  cout << "Welcome to Nerdle! This is a guessing game where you have to guess a random equation of 6 places to win. \n";
  guess_space(attempt_review, eq_len);
  cout << attempt_review << endl;
  while (!Guess_correct){
    accept_guess(guess, eq_len);
    check_guess(guess, equation, attempt_review);
    cout << attempt_review << endl;
    if (attempt_review == "OOOOOO"){
      Guess_correct = true;
    }
    (*count)++;

  }
  cout << "You win!\nYou took " << *count << " times to get the answer." << endl;
  delete count;

  return 0;
}
