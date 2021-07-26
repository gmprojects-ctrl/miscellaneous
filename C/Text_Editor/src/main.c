#include <stdio.h>
#include<ncurses.h>
int main(){
	initscr();
	cbreak();
	keypad(stdscr,TRUE);
	noecho();
	char c;
	while(true){
		c=getch();
		printw("%c",c);
		if(c == 24){
			break;
		}
	}
	endwin();
	return 0;
}
