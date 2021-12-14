#include<stdlib.h>
#include<ncurses.h>
#include<stdio.h>
#include<string.h>

#define Sun 0
#define Mercury 1
#define Venus 2
#define Earth 3
#define Mars 4
#define Jupiter 5
#define Saturn 6
#define Uranus 7
#define Neptune 8
#define SolarSystem 9

int main (void)
{ 
    int row, col;

    initscr(); //creates standard screen for printing to//
    getmaxyx(stdscr,row,col);
    raw();
    printw("Solar System"); //works same way as printf//
    addch('a'); //types a character// 
    move(20,1); //moves cursor on screen//

    mvprintw(15,2, "Movement"); //moves the word to that coordinate//
    mvaddch(10,3, 'a'); //moves character to that coordinate//

    return 0;
}
