# CoolClock

CoolClock is a C++ program that displays the current time in an ASCII art style using pre-created fonts. It runs on Linux systems (specifically tested on Arch Linux) and leverages the `ncurses` library to manage terminal output. Users can toggle between different fonts for the clock by pressing the 'w' key and can exit the program by pressing 'q'.

## Features

- Displays the current time in ASCII art.
- Allows switching between different clock fonts.
- Simple terminal interface using `ncurses`.
- Dynamic adjustment for terminal window size.

## Prerequisites

- **C++ Compiler** (e.g., `g++`)
- **ncurses Library**
  - On Arch Linux, you can install it using:  
    `sudo pacman -S ncurses`
- **Make** (for building the project)

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/CoolClock.git
   cd CoolClock
   ```

2. Build the project using `make`:

   ```bash
   make
   ```

3. Run the program:

   ```bash
   ./CoolClock
   ```

> Please clean up the project directory after use by running `make clean`.

## Usage

Once the program is running, the current time will be displayed in a pre-defined ASCII art font. The available features are:

- **Change Font**: Press `w` or `W` to cycle through different ASCII art fonts.
- **Quit**: Press `q` or `Q` to exit the program.

**Note**: The program requires a terminal window with at least 6 lines and 55 columns.

## Collaboration

We are open to contributions! Feel free to fork the repository, submit issues, and create pull requests.

### How to contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit them (`git commit -am 'Add new feature'`).
4. Push to your branch (`git push origin feature-branch`).
5. Open a pull request with a description of the changes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- `ncurses` library for handling terminal graphics.
- Pre-created ASCII art fonts for time display.

## Author

- [Ornitorink0](https://github.com/Ornitorink0)

> Please note that this project is for educational purposes only and is not intended for commercial use. I do not take responsibility for any legal issues that may arise from its use. I am a beginner, so please be patient and understanding. Your feedback is welcome.
