Bitfull Card Game
Bitfull is a terminal-based card game implemented in C++. In this game, you, the player, face off against three CPU opponents in a strategic battle to be the first to empty your hand of cards.

Game Rules:
•	Starting Card: The game begins with the player holding the Heart 7 (H7), which initiates the first move.
•	Board Setup: The board starts with positions for Spade 7, Diamond 7, and Clubs 7.
•	Gameplay: Players take turns playing cards adjacent to existing cards on the board. For instance, to play H8, H7 must already be on the board.
•	Skipping Turns: If a player cannot play a valid card, their turn is skipped, and CPU opponents pass comments to maintain game flow.
•	Winning Condition: The first player to discard all their cards wins the game.
•	Ranking: Players are ranked based on the points of their remaining cards:
o	H1=10, H2=2, H3=3, H4=4, H5=5, H6=6, H7=7, H8=8, H9=9, H10=10, HJ=11, HQ=12, HK=13, AC=14. The player with the highest points ranks last, with positions assigned as King, Queen, Peon, and Toilet Cleaner accordingly.

Features:
•	Interactive Interface: Although text-based, the game offers an engaging interactive experience for the player.
•	CPU Opponents: Three CPU players provide challenging gameplay, with randomized comments to enhance immersion.
•	Ranking System: Adds depth with a ranking system based on remaining card values.

Implementation:
The game is implemented in C++ and runs entirely in the terminal. It utilizes fundamental programming concepts such as object-oriented design, data structures, and algorithmic decision-making to create a dynamic and enjoyable gaming experience.
Future Enhancements:
Future updates could include graphical enhancements for a more visually appealing interface, additional gameplay features, and optimizations for performance and user experience.

How to Play:
To play Bitfull, simply compile and run the provided C++ code. Follow on-screen instructions to navigate the game and enjoy the challenge of outwitting your opponents to claim victory!

