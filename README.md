# computer

Group members: Pau Huen Kak, Chan Hei

Computer project: Nerdie

Wordle and Nerdle are games that are having an increasing trend these days. Similar to those two, our game to be designed, Nerdie, is an equation version of Hangman that requires player to guess the equation correctly.

#### Rules

The player will be given a sequence with a specific number (the length may vary, unlike in Nerdle) of spaces like this:

`_ _ _ _ _ _ _ _`

There are six rows. Each player would have to enter six equations correspondingly to win.

Each equations consist eight of the following elements: integers 0-9 and symbols "+", "-", "*", "/" and "=". There must be only one "=" in every equation. The elements following "=" has to be a number instead of an expression.

Commutative properties of equations allowed.

After each attempt, the screen will display messages with following rules:
- for characters that are in the same position: `O`
- for characters that exist but in a wrong position: `?`
- for characters that does not exist: `_`

For example, we have this equation that to be guessed:

`5*7+8=43`

The display will be like this:

```
_ _ _ _ _ _ _ _
Please input an equation:
23+45=68
_ ? ? ? ? O _ ?
Please input an equation:
```

Users are allowed to keep guessing until they get the correct answer.

Features and plans:
- random seed with current time
- there could be an easy mode where only '+', '-', '=' and numbers are used
- the program needs to manipulate the program in a correct way e.g order of operation
- use of character arrays to store the equation
