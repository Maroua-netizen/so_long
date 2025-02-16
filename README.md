# so_long

This project is a very small 2D game compatible with Macos.

## Gameplay

The player’s goal is to collect every flower present on the map, then enter the house choosing the shortest possible route.

## Video Demo

Watch a demo of the game:

<iframe width="560" height="315" src="https://github.com/user-attachments/assets/e1f84493-bcaf-48e9-a380-e02174497793" frameborder="0" allowfullscreen></iframe>

## Dependencies

In order to be able to play this game, you need to first install Minilibx on your computer. Below is a git repository where you can find it:
https://github.com/42Paris/minilibx-linux

## Installation

To install and run the game, follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/Maroua-netizen/so_long.git
   ```
2. Navigate to the project directory:
   ```sh
   cd so_long
   ```
3. Compile the game:
   ```sh
   make
   ```

## Usage

To start the game, execute the following command with the appropriate map file:
```sh
./so_long [map_file]
```

## Example Map File

You can find an example map file here: [map.ber](map.ber). Use it to test the game.

## Controls

- Arrow keys or WASD keys: Move the player
- Escape: Exit the game

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Credits

- [Cup Nooble](https://cupnooble.itch.io/) - Provided the textures used in this game.
