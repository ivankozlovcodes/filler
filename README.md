# filler
### [42 school Silicon Valley][42]

## TOC

* [What is it about?](#what-is-it-about)
* [Usage](#usage)
* [Examples](#examples)
* [Author](#author)
* [License](#license)

## What is it about?

##### Creator: 42 staff. [Task description][pdf]

Filler is a game, where two players / algorithm are fighting on a map.

A virtual machine organizes the game :

calls the players alternatively
give each a random piece

On each turn, the current player have to put his piece on the map, and try to bother the enemy. To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin).

The game appears on the standard input.

The aim of the game is to put more pieces on the map than the enemy.

The purpose is to make the smallest possible "square" (which can contain holes) with a given list of tetriminos(tetris pieces), but the disposition must be as such that it returns the first possible solution when placing them recursively from the top left.

## Usage
Download and compile repo:
```sh
    git clone https://github.com/IvanKozlov95/filler
    cd filler
    make
```
Player `ikozlov.filler` will be created.

## Examples
In order to see what does player do we need to make him fight! From cloned directory:
```sh
    cd resources
    ./filler_vm -f maps/map01 -p1 ../ikozlov.filler -p2 players/abanlin.filler
    * see the result in terminal output *
```
There are several maps available in `resources/maps` folder. Also several bots for testing in `/resources/players`.\
You can make my bot fight against other peoples bots. Try [this one][marcs filler].

### Visualizer
On big maps it's difficult to see what is really happening. That's why I've also create a visualizer using python's *tkinter* library.\
In order to see it working simply pipe the virtual machine output to visualizer.
```sh
    ./filler_vm -f maps/map01 -p1 ../ikozlov.filler -p2 players/abanlin.filler | python3 ../visualizer/visualizer.py
```
<img src="resources/usage.gif"></img>

## Author
This project was developed by Ivan Kozlov [@ivankozlov95][me].

## License
This project is licensed under the [GNU General Public License 3][license].

[42]: http://42.us.org "42 USA"
[pdf]: https://github.com/IvanKozlov95/fillit/blob/master/resources/filler.en.pdf "pdf"
[license]: https://github.com/IvanKozlov95/fillit/blob/master/LICENSE "license"
[me]: https://github.com/IvanKozlov95 "ivankozlov95"
[marcs filler]: https://github.com/mgia/fillerBot "Marc's bot"
[gif]: https://github.com/IvanKozlov95/fillit/blob/master/resources/usage.gif "gif"
