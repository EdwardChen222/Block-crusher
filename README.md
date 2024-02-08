
# Overview

This project is an implementation of a block crushing game in C++ using the ge211 framework. The game features traditional gameplay with graphical representation, allowing players to experience the timeless challenge of arranging falling blocks, or "Bricks", in a way that fills horizontal lines on the board without leaving gaps.

## Features
Graphical Interface: Utilizes the ge211 library to render the game board, tetrominoes, and game stats.
Interactive Gameplay: Players can move, rotate, and drop Bricks to strategically place them on the board.
Score Tracking: The game tracks and displays the player's score based on the number of lines cleared.
Dynamic Difficulty: The game's difficulty increases as the player progresses, with Bricks falling faster over time.
Randomized Bricks: Each new Brick is randomly generated, offering a unique gameplay experience each time.

## How to Play

Movement: Use arrow keys to move the Brick left or right.
Rotation: Press 'R' to rotate the Brick.
Drop: Press 'Space' to drop the Brick quickly to the bottom.
Goal: Complete horizontal lines with no gaps. When such a line is formed, it disappears, and any block above the deleted line will fall.

## Installation
Ensure you have the ge211 library installed.
Clone this repository to your local machine.
Compile the source files using your preferred C++ compiler.
Run the executable to start the game.

## File Structure
main.cxx: Entry point of the game, initializes the Controller.
controller.cxx: Handles user input and game logic.
model.cxx: Manages the game state, including the board, Bricks, and scoring.
view.cxx: Responsible for rendering the game's graphical interface.
board.cxx: Represents the game board and its state.
brick.cxx: Defines the Brick objects and their behaviors.
position_set.cxx: Utility class for managing sets of positions on the board.
