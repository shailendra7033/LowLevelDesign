# Tic-Tac-Toe

## Compile and Check Errors

Check for C++ syntax and compilation errors without creating an executable:

```powershell
g++ -fsyntax-only GameBoard.cpp Player.cpp GameMain.cpp 2> errors.log
```

Compile the program:

```powershell
g++ GameBoard.cpp GameMain.cpp -o tic
```

Run the program:

```powershell
.\tic.exe
```

## leetcode ques
  - https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/
  - 


## Prevent Multiple Header Inclusion

Place `#pragma once` at the beginning of each header file:

```cpp
#pragma once
```

## Mistakes and Corrections

### 1. Missing public visibility

Class members are private by default. Getters, setters, the constructor, and methods called outside the class must be public.

Wrong:

```cpp
class GameBoard {
  int getCurrPlayer() { return currPlayer; }
};
```

Correct:

```cpp
class GameBoard {
public:
  int getCurrPlayer() { return currPlayer; }
};
```

### 2. Mixing stack and heap allocation

Wrong:

```cpp
GameBoard gamebrd = new GameBoard();
```

Correct stack allocation:

```cpp
GameBoard gamebrd;
```

Correct heap allocation:

```cpp
GameBoard* gamebrd = new GameBoard();
```

### 3. Adding a return type to a constructor

Constructors do not have a return type.

Wrong:

```cpp
void GameBoard() {
}
```

Correct:

```cpp
GameBoard() {
}
```

### 4. Declaration and definition parameter mismatch

The method declaration and definition must have the same parameters.

Wrong:

```cpp
// GameBoard.h
int calculateWinner();

// GameBoard.cpp
int GameBoard::calculateWinner(int row, int col) {
}
```

Correct:

```cpp
// GameBoard.h
int calculateWinner(int row, int col);

// GameBoard.cpp
int GameBoard::calculateWinner(int row, int col) {
}
```

### 5. Missing the `std` namespace

Wrong:

```cpp
cout << "Welcome";
vector<Player> players;
```

Correct with qualified names:

```cpp
std::cout << "Welcome";
std::vector<Player> players;
```

Alternatively:

```cpp
using namespace std;
```

### 6. Counting empty cells as crosses

The initial value of each board cell is `-1`. An `else` branch treats every value other than `ZERO`, including `-1`, as `CROSS`.

Wrong:

```cpp
if (gameBoard[i][j] == symbol::ZERO) {
  zero_count_dia2++;
} else {
  cross_count_dia2++;
}
```

Correct:

```cpp
if (gameBoard[i][j] == symbol::ZERO) {
  zero_count_dia2++;
} else if (gameBoard[i][j] == symbol::CROSS) {
  cross_count_dia2++;
}
```

## Sample Run

```text
PS C:\Users\shailkumar\Downloads\LowlevelDesign\Tic-Tac-Toe> g++ GameBoard.cpp  GameMain.cpp -o tic 
PS C:\Users\shailkumar\Downloads\LowlevelDesign\Tic-Tac-Toe> .\tic.exe 
Game::Board: PLAYEnter Row no 2
Enter Col no 2
Game::Board: PLAY 
 --- --- 0  
 --- 0  --- 
 --- 1  1  
Game::Board: PLAYEnter Row no 2
Enter Col no 0
Game::Board: ZERO WONWohoo ZERO WON
```