#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;



int main(){
  string equation = "3*2=6";
  string guess;
  bool Guess_correct;
  while (!Guess_correct){
    cin >> guess;
    if (guess == equation){
      Guess_correct = true;
    }
  }
  cout << "You win!" << endl;
}
