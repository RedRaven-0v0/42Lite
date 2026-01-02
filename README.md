🎓 42Lite – A Roguelike Auto-Battler in C++

42Lite is a small roguelike auto-battler written in C++, telling the story of a student trying to complete the 42 cursus.
It’s a text-based game (in French) that runs entirely in the terminal.

🕹️ How to Play ?

1. Open a terminal and go in the repository directory :
<pre><span style="color:#00FF7F;">user@42lite</span>:<span style="color:#6495ED;">~/current_dir</span>$ cd 42Lite</pre>
2. Build the game (it will reset the exp of the player) :
<pre><span style="color:#00FF7F;">user@42lite</span>:<span style="color:#6495ED;">~/42Lite</span>$ make
Compiling sources... Build successful!</pre>
3. Run the game :
<pre> <span style="color:#00FF7F;">user@42lite</span>:<span style="color:#6495ED;">~/42Lite</span>$ ./game.bin
Welcome to 42Lite! </pre>
4. Enjoy the adventure!

⚔️ Game Features

🧩 Multiple Classes — Each class affects your character’s base stats and the funny lines they say.

😂 Humorous & Exclusive Tone — The game is filled with inside jokes and references shared with my friends.

🗃️ Customizable Content — You can tweak classes, upgrades, and enemies through the .txt files located in the datas/ folder.

Check the commented lines in those files to understand the data format.

🧙 Adding New Classes — To create new classes, update class_unlocks.txt by adding:

The class name, and the required experience to unlock it.
