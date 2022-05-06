#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include "check.h"
using namespace std;

void guess_space(string &s, int len){  // make initial guess space
  s = "";
  for (int i = 0; i < len; i++){
    s += "_";
  }
}

void check_guess(string guess, string ans, string &review){
  guess_space(review, ans.length());

  std::string guess_copy = guess;  // check if position is correct
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
