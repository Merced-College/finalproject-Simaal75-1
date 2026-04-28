````markdown
# Casino Nights

## Description

Casino Nights is a terminal-based casino program written in C++. The user starts with a balance of $100 and can choose between two games: Blackjack and High Card. The program uses a menu system, betting, score tracking, and a final scoreboard.

The project uses external card data from `cards.csv`, which stores the full deck of cards. The program loads this file, shuffles the deck, deals cards, and updates the player’s balance based on wins, losses, and ties.

## How to Compile and Run

Make sure all `.cpp`, `.h`, and `cards.csv` files are in the same folder.

Compile:

```bash
g++ -std=c++17 *.cpp -o casino
````

Run:

```bash
./casino
```

## Features

* Main casino menu
* Player name input
* Starting balance of $100
* Betting system
* Blackjack game
* High Card game
* Scoreboard with wins, losses, ties, and rounds played
* Deck loaded from `cards.csv`
* Input checking for menu choices and bets
* Final scoreboard when the program ends

## Data Structures Used

### Data Structure #1: Vector

Where it is used:

* `Deck.h`
* `Deck.cpp`
* `Player.h`
* `Player.cpp`

How it is used:

* In `Deck`, a vector stores all cards in the deck:

```cpp
std::vector<Card> cards;
```

* In `Player`, a vector stores the player’s current hand:

```cpp
std::vector<Card> hand;
```

Why I used it:

* A vector is easy to add to, remove from, and shuffle.
* It works well for storing cards because the size can change during the program.

### Data Structure #2: Map

Where it is used:

* `ScoreManager.h`
* `ScoreManager.cpp`

How it is used:

```cpp
std::map<std::string, int> stats;
```

Why I used it:

* The map stores game stats like wins, losses, ties, Blackjack rounds, and High Card rounds.
* It keeps the scoreboard organized using names as keys.

### Data Structure #3: String

Where it is used:

* `Card.h`
* `Card.cpp`
* `Player.h`
* `Player.cpp`
* `Casino.cpp`

How it is used:

* Strings store the player’s name.
* Strings store card suits and ranks.
* Strings store user input like menu choices and game choices.

Why I used it:

* Strings are needed for text-based input and output.
* They make the program easier to read and interact with.

## Algorithms Used

### Algorithm #1: Shuffle Deck

Where it is used:

* `Deck.cpp`
* Function: `shuffleDeck()`

What it does:

* Randomizes the order of cards in the deck before games are played.

Basic steps:

1. Load cards into the deck.
2. Use `std::shuffle` to randomize the vector.
3. Deal cards from the shuffled deck.

Big-O:

* O(n), because the shuffle works through the deck of cards.

### Algorithm #2: Blackjack Hand Value

Where it is used:

* `BlackjackGame.cpp`
* Function: `getHandValue()`

What it does:

* Calculates the total value of a Blackjack hand.
* Handles aces by counting them as 11 first, then changing them to 1 if the total goes over 21.

Basic steps:

1. Add all card values.
2. Count how many aces are in the hand.
3. If the total is over 21, subtract 10 for each ace until the hand is safe or no aces are left.

Big-O:

* O(n), because it checks each card in the hand.

### Algorithm #3: Bet Validation

Where it is used:

* `BlackjackGame.cpp`
* Function: `getValidBet()`
* `HighCardGame.cpp`
* Function: `getValidBet()`

What it does:

* Makes sure the player enters a valid bet.
* The bet must be a number, greater than 0, and not more than the player’s current balance.

Basic steps:

1. Ask the player for a bet.
2. Check if input is valid.
3. Check if the bet is in range.
4. Repeat until the player enters a valid bet.

Big-O:

* O(1) per check.

### Algorithm #4: Blackjack Winner Logic

Where it is used:

* `BlackjackGame.cpp`
* Inside the `play()` function

What it does:

* Compares the player’s total and dealer’s total to decide the winner.

Basic steps:

1. If dealer busts, player wins.
2. Else if player total is higher, player wins.
3. Else if dealer total is higher, dealer wins.
4. Else it is a tie.
5. Update balance and stats.

Big-O:

* O(1), because it only uses direct comparisons.

### Algorithm #5: High Card Rule Logic

Where it is used:

* `HighCardGame.cpp`
* Inside the `play()` function

What it does:

* Runs the High Card game.
* The player sees their card and chooses to call or fold.
* If the player calls, their card is compared to the dealer’s hidden card.
* If the player folds, they lose half their bet.

Basic steps:

1. Deal one card to the player.
2. Deal one hidden card to the dealer.
3. Ask the player to call or fold.
4. If fold, subtract half the bet.
5. If call, compare card values.
6. Update balance and stats.

Big-O:

* O(1), because it only compares two cards.

### Algorithm #6: Menu Choice Logic

Where it is used:

* `Casino.cpp`
* Function: `getChoice()`

What it does:

* Reads the user’s menu choice and prevents bad input from crashing the program.

Basic steps:

1. Ask the user for a menu choice.
2. Check if input is valid.
3. Clear bad input if needed.
4. Return the selected choice.

Big-O:

* O(1), because it checks one menu input at a time.

## Contributors

Simaal B

This was an individual project.

```
```
