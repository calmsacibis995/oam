# oam
Operations, Administration, and Maintenance (OA&amp;M) utilities.

Derived from the [original sources](https://github.com/calmsacibis995/svr4-src/tree/main/cmd/oamintf), but updated to use CMake and run on modern hardware.

## Installation instructions

### Dependencies
You will need:
  * GCC (Clang has not been tested)
  * Curses (devel package or build from source)
  * CMake 3.13.2 or newer.
  * Make

### Building
1. Clone the repository using this command: `git clone https://github.com/calmsacibis995/oam.git`

2. Run `cd oam` to change your current directory to the repository you just cloned.

3. Create a build folder and `cd` into it: `mkdir build;cd build`

4. Run CMake to configure the project for building: `cmake ..`

5. Run `make` and you're done!
