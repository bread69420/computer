# computer

Group members: Pau Huen Kak, Chan Hei

Computer project: Nerdie

Wordle and Nerdle are games that are having an increasing trend these days. Similar to those two, our game to be designed, Nerdie, is an equation version of Hangman that requires player to guess the equation correctly.

#### Rules

The player will be given 6 entries of spaces to type an equation.

`_ _ _ _ _ _'

The player must guess the correct equation to win.

Each equations consist six of the following elements: integers 0-9 and symbols "+", "-", "*", "/" and "=". There must be only one "=" in every equation. The elements following "=" has to be a number instead of an expression.

Commutative properties of equations allowed.

After each attempt, the screen will display messages with following rules:
- for characters that are in the same position: `O`
- for characters that exist but in a wrong position: `?`
- for characters that does not exist: `_`

For example, we have this equation that to be guessed:

`5+6=11'

The display will be like this:

```
_ _ _ _ _ _ 
Please input an equation:
5+5=10
OO_OO_
Please input an equation:
```
For numbers in RHS with single digits, please type, for example, 09 instead of 9.

Users are allowed to keep guessing until they get the correct answer.

Instructions are also given in the actual game.

Features and plans:
- random seed with current time
- only computational skills are needed
- the program needs to manipulate the program in a correct way e.g order of operation
- the equation would need to match the seed 
