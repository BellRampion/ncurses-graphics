/*** Move an object with Nethack-movement keys ***/
/*===LINUX ONLY===*/
#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main(){
    int i;
    int x = 0; //x coordinates
    int y = 0; //y coordinates
    char ch; //For printing the character


    (void) initscr();      /* initialize the curses library */
    keypad(stdscr, TRUE);  /* enable keyboard mapping */
    (void) nonl();         /* tell curses not to do NL->CR/NL on output */
    (void) cbreak();       /* take input chars one at a time, no wait for \n */
    (void) echo();         /* echo input - in color */

    printf("Press h, j, k, or l to start. Press $ to stop:\n");
    clear();
    
    while (ch != '$'){

        clear(); //Clears the screen
        ch = getchar(); //Get one character of user input

        if(ch == 'l') //If the character inputted was l,
        {
            x++; //Increase x by one 
            mvaddch(y, x, '@'); //first y coordinate, then the x coordinate. Move to the unchanged y and increased x coordinate
            refresh(); //Refresh the screen
        //    sleep(1);
        }
        else if(ch == 'h') //If the character inputted was h,
        {
            x--; //decrease x by one
            mvaddch(y, x, '@'); //first y coordinate, then the x coordinate. Move to the unchanged y and decreased x coordinate
            refresh(); 
        //    sleep(1);
        }
        else if(ch == 'j')
        {
            y++;
            mvaddch(y, x, '@'); //first y coordinate, then the x coordinate
            refresh();
            //sleep(1);
        }
        else if(ch == 'k')
        {
            y--;
            mvaddch(y, x, '@'); //first y coordinate, then the x coordinate
            refresh();
            sleep(0.5);
        }
    }
    mvprintw(30, 10, "Press enter to continue:"); //Print message 3o coordinates down and ten over
    getch(); //Get character; this pauses the program until user input is received. 

    endwin(); //End the ncurses code
}
