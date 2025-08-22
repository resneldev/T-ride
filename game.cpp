# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "game.h"
#include <conio.h>
#include <time.h>

#define NB_TRAPS 30

//---------zone initialisation-----------
void initArea(char gameArea[MAX_X][MAX_Y ],int *pX,int *pY){
    int x, y;
    int traps[NB_TRAPS][2];

    // Générer les positions aléatoires des pièges
    for (int i = 0; i < NB_TRAPS; i++) {
        traps[i][0] = 1 + rand() % (MAX_X - 2); // x
        traps[i][1] = 1 + rand() % (MAX_Y - 2); // y
    }

    printf("\n");
    cleaner(gameArea);

    for (x = 0; x < MAX_X; x++) {
        for (y = 0; y < MAX_Y; y++) {
            limite(x, y, gameArea);
            gameArea[*pX][*pY] = 'T';
            // Placer les pièges
            for (int i = 0; i < NB_TRAPS; i++) {
                gameArea[traps[i][0]][traps[i][1]] = 'X';
                if(traps[i][0] == *pX && traps[i][1] == *pY) {
                    printf("You hit a trap at (%d, %d)! Game Over.\n", traps[i][0], traps[i][1]);
                    gameArea[traps[i][0]][traps[i][1]] = 'X';
                    exit(0); // End the game if the player falls into a trap
                }
                
            }
            if (y == 0 && x > 0) {
                printf("\n%c", gameArea[x][y]);
            } else {
                printf("%c", gameArea[x][y]);
            }
        }
    }
    printf("\n\n");
} 

//--------------------Control system--------------------
void control(void){
  int x=1,y=1;
  char move;
  char GameArea[MAX_X][MAX_Y ]={0};

    
  initArea(GameArea, &x,&y);
    
  show_menu(move);
    
 
    while (1)
    {
      if (kbhit())  // Check if a key has been pressed
      {
             
        move = getch(); // Read the pressed key without waiting for Enter
        if (move == 'w')
        {
          move_up(&x, &y, GameArea);
          
        }

        else if (move == 's')
        {
          move_down(&x, &y, GameArea);
          
        }

        else if (move == 'a')
        {
          move_left(&x, &y, GameArea);
         
        }

        else if (move == 'd')
        {
          move_rigth (&x, &y, GameArea);
          
        }

        else if (move == 'c')
        {
          goto_debut (GameArea, &x, &y);
          
        }
        else if (move == 'q' || move == 'Q')
        {
          printf("game stoped!\n");
          break;
        }
        else
        {
          printf("*****make correct movements!*****\n");
          show_menu(move);
        }
      }

    }
    
  printf("ride finish\n");  
}

//------------menu----------------------
void show_menu(char move){
  printf("left\nright\nup\ndown\nstop:stop the game\n");
  printf("make a move!\n");
  printf(">");
  scanf("%c",move);
}

//-------------------------mouvenent----------------------------------
void move_up   (int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]){

  if(*p_X == 1){
    // Already at the top boundary, do nothing or print a message if desired
    GameArea[*p_X][*p_Y] = 'T';
  }
  else {
    GameArea[*p_X][*p_Y] = ' ';
    (*p_X)--;
    //GameArea[*p_X][*p_Y] = 'T';
  }
  initArea(GameArea, p_X, p_Y);

}
//------------------------------------------------------------------
void move_down (int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]){
  if(*p_X == compte_X - 1){
    // Already at the bottom boundary, do nothing or print a message if desired
    GameArea[*p_X][*p_Y] = 'T';
  }
  else {
    GameArea[*p_X][*p_Y] = ' ';
    (*p_X)++;
    //GameArea[*p_X][*p_Y] = 'T';
  }
  initArea(GameArea, p_X, p_Y);
}
//--------------------------------------------------------
void move_left (int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]){
 if(*p_Y==1){
    (*p_Y)++;
    GameArea[*p_X][*p_Y]='T';
    
  }
   
  else
    GameArea[*p_X][*p_Y]=' ';
    (*p_Y)--;
    //GameArea[*p_X][*p_Y]='T';
    initArea(GameArea,p_X,p_Y);
}
//---------------------------------------------------------------
void move_rigth(int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]){
  if(*p_Y==(compte_Y-1)){
    (*p_Y)--;
    GameArea[*p_X][*p_Y]='T'; 
  }
   
  else
    GameArea[*p_X][*p_Y]=' ';
    (*p_Y)++;
    //GameArea[*p_X][*p_Y]='T';
    initArea(GameArea,p_X,p_Y);

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

