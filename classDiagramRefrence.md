```mermaid


classDiagram

class Game {
    - Board board
    
    + int currentPlayerIndex
    - GameStatus status
    - start()
    + makeMove(row, col)
    + switchTurn()
    + checkWinner()
    - Player[] players
}

class Board {
    - Cell[][] cells
    - int size
    + placeMove(row, col, symbol)
    + isCellEmpty(row, col)
    + display()
}

class Cell {
    - int row
    - int col
    - Symbol symbol
}

class Player {
    - String name
    - Symbol symbol
    + makeMove()
}

class Move {
    - int row
    - int col
    - Player player
}

class GameStatus {
    <<enumeration>>
    IN_PROGRESS
    DRAW
    WIN
}

class Symbol {
    <<enumeration>>
    X
    O
}

Game --> Board
Game --> Player
Game --> GameStatus
Board *-- Cell
Player --> Symbol
Move --> Player




style Game fill:#90CAF9,stroke:#1565C0,color:#000
style Board fill:#A5D6A7,stroke:#2E7D32,color:#000
style Player fill:#FFCC80,stroke:#EF6C00,color:#000


```


## this is for the class diagrm before ANY following LL
--


## Defining Relationship
```
Where Relation Type can be one of:

Type	Description
<|	Inheritance
\*	Composition
o	Aggregation
>	Association
<	Association
|>	Realization
And Link can be one of:

Type	Description
--	Solid
..	Dashed
```

```mermaid
classDiagram
classA --|> classB : Inheritance
classC --* classD : Composition
classE --o classF : Aggregation
classG --> classH : Association
classI -- classJ : Link(Solid)
classK ..> classL : Dependency
classM ..|> classN : Realization
classO .. classP : Link(Dashed)
```



## Cardinality / Multiplicity on relations
```Multiplicity or cardinality in class diagrams indicates the number of instances of one class that can be linked to an instance of the other class. For example, each company will have one or more employees (not zero), and each employee currently works for zero or one companies.

Multiplicity notations are placed near the end of an association.

The different cardinality options are :

1 Only 1
0..1 Zero or One
1..* One or more
* Many
n n (where n>1)
0..n zero to n (where n>1)
1..n one to n (where n>1)
Cardinality can be easily defined by placing the text option within quotes " before or after a given arrow
```
```mermaid

classDiagram

    Customer "1" --> "*" Ticket
    Student "1" --> "1..*" Course
    Galaxy --> " many " Star : Contains



```
