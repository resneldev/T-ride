# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "game.h"
# include <conio.h>
# include <time.h>

#define NB_TRAPS 30
static int traps[NB_TRAPS][2];
static int health = 100;
//---------zone initialisation-----------
void initArea(char gameArea[MAX_X][MAX_Y ],int *pX,int *pY){
    int x, y;
    
    // Generate random trap positions
    generateTraps();

    printf("\n");
    cleaner(gameArea);



    for (x = 0; x < MAX_X; x++) {
      for (y = 0; y < MAX_Y; y++) {
        limite(x, y, gameArea);
        gameArea[*pX][*pY] = 'T';
         // Place traps on the game area
        for (int i = 0; i < NB_TRAPS; i++) {
          gameArea[traps[i][0]][traps[i][1]] = 'X';
          

        }       
        if (y == 0 && x > 0) {
            printf("\n%c", gameArea[x][y]);
        } else {
            printf("%c", gameArea[x][y]);
        }
      }
    }
    printf("\n");
    checkTrap(*pX, *pY); // Check if player is on a trap
    printf("\n\n");
} 
// Function to check if the player is on a trap
void checkTrap(int x, int y) {
    for (int i = 0; i < NB_TRAPS; i++) {
        if (x == traps[i][0] && y == traps[i][1]) {
            health -= 20;
            printf("--------------------------------------------------\n");
            printf("--------------------------------------------------\n");
            printf("         Trap! Health: %d\n", health);
            printf("--------------------------------------------------\n");
            printf("--------------------------------------------------\n");
        if (health <= 0) {
            printf("\n");
            printf("**************************************************\n");
            printf("*                                                *\n");
            printf("*                   GAME OVER                    *\n");
            printf("*                                                *\n");
            printf("**************************************************\n");
            printf("\n"); 
            exit(0);
        }
            break;
        }
    }
}
// Function to generate new traps (if needed)
void generateTraps() {
    for (int i = 0; i < NB_TRAPS; i++) {
        traps[i][0] = 1 + rand() % (MAX_X - 2);
        traps[i][1] = 1 + rand() % (MAX_Y - 2);
    }
}
//--------------------Control system--------------------
void control(void){
  int x=1,y=1;
  char move;
  char GameArea[MAX_X][MAX_Y ]={0};

    
  initArea(GameArea, &x,&y);
    
  show_menu(move);
  printf(">");
  while(1){
    
    if (kbhit())
    {
      move=getch();
    
      switch(move){
        case 'w': move_up(&x,&y,GameArea);break;
        case 's': move_down(&x,&y,GameArea);break;
        case 'a': move_left(&x,&y,GameArea);break;
        case 'd': move_rigth(&x,&y,GameArea);break;
        case 'r': goto_debut(GameArea,&x,&y);break;
        case 'm': show_menu(move);break;
        case 'p': exit(0);break;
        default: printf("invalid move\n");break;
      }
      initArea(GameArea, &x,&y); 
    }
    
  } 

   
  printf("ride finish\n");  
}

//------------menu----------------------
void show_menu(char move){
  printf("left\nright\nup\ndown\nstop:stop the game\n");
  printf("make a move!\n");
  printf(">");
 
}

//-------------------------mouvenent----------------------------------
void move_up   (int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]){

  if(*p_X != 1){
    // Already at the top boundary, do nothing or print a message if desired
    GameArea[*p_X][*p_Y] = ' ';
    (*p_X)--;   
    
  }

}
//------------------------------------------------------------------
void move_down (int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]){
  if(*p_X != compte_X - 1){
    // Already at the bottom boundary, do nothing or print a message if desired
    GameArea[*p_X][*p_Y] = ' ';
    (*p_X)++;
   
  }
  
}
//--------------------------------------------------------
void move_left (int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]){
 if(*p_Y != 1){
    GameArea[*p_X][*p_Y]=' ';
    (*p_Y)--;
    
  }
   

}
//---------------------------------------------------------------
void move_rigth(int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]){
  if(*p_Y != (compte_Y-1)){
    GameArea[*p_X][*p_Y]=' ';
    (*p_Y)++;
    
  }

}

//-----------------------bordur-------------------------------
void limite(int x,int y,char gameArea[MAX_X][MAX_Y ]){
  gameArea[x][0]='O';
  gameArea[compte_Y][y]='O';
  gameArea[0][y]='O';
  gameArea[x][compte_X]='O';
}

//--------------------cleaner------------------
void cleaner(char gameArea[MAX_X][MAX_Y ]){
    int x=0,y=0;
    
    for(x=0;x<MAX_X;x++){
        for(y=0;y<MAX_Y;y++){
          gameArea[x][y]= ' ';
        }
    }
  
}

void goto_debut(char gameArea[MAX_X][MAX_Y],int *p_x,int *p_y){
    *p_x=1;
    *p_y=1;
    cleaner(gameArea);
    initArea(gameArea,p_x,p_y);
}

