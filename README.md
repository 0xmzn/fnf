# fnf 
CIS 150 project. A flappy-bird clone built with [SFML](https://github.com/SFML/SFML) in C++.

# Features

1- Multiple levels  
2- Saving high score  
3- Pausing the game  
4- Bugless  
5- Suckless

## Installation
### Windows
***Install Linux Mint or smth IDK I use arch btw..***
### Linux

 * Make sure you have git and build essentials installed.  
    
    Debian-based distributions:  
    ```shell
    sudo apt-get install build-essential git
    ```
    Arch-based distributions:   
     ```shell
     sudo pacman -S base-devel git
	 ```

 * Install SFML on your linux machine (it should be available in most repositories).  
   
   Debian-based distributions:
   ```shell
   sudo apt-get install libsfml-dev
   ```
   Arch-based distributions:
   ```shell
   sudo pacman -S sfml
   ```
 * Clone the repo and cd into it:
   ```shell
   git clone https://github.com/mazzensaadd/fnf.git && cd fnf
   ```
 * Compile and run:
   ```shell
   g++ src/main.cpp -o fnf -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./fnf
   ```  
## Team Members
1- [@Omar-Yasser](https://github.com/Omar-Yasser)  
2- [@mazzensaadd](https://github.com/mazzensaadd)  
3- [@mh084449](https://github.com/mh084449)  
4- [@Elkhdiwy](https://github.com/Elkhdiwy)  
5- Abdullah Bahr

## fnf?
fnf not flappy. A totally [original](https://www.gnu.org/gnu/gnu-history.html) idea.
