# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "game.h"
//---------zone initialisation-----------
void initArea(char gameArea[MAX_X][MAX_Y ],int *pX,int *pY){
    int x,y;
    
    printf("\n");
    cleaner(gameArea);

    for (x=0; x < MAX_X ;x++){
      for(y=0;y<MAX_Y ;y++){
        
        limite(x, y,gameArea);
          
        gameArea[*pX][*pY]='T';

        if(y==0 && x>0){
          printf("\n%c",gameArea[x][y]);
        }
        else{
           printf("%c",gameArea[x][y]);
        } 
      }
    }
        printf("\n\n");
} 

//--------------------Control system--------------------
void control(void){
  int x=1,y=1;
  char move[10];
  char GameArea[MAX_X][MAX_Y ]={0};

    
  initArea(GameArea, &x,&y);
    
  show_menu(move);
    
  while(strcmp(move,"stop")!=0){
      
    if (strcmp(move,"w")==0)
    {
      move_up(&x,&y,GameArea);
      scanf("%s",move);
    }

    if (strcmp(move,"s")==0)
    {
      move_down(&x,&y,GameArea);
      scanf("%s",move);
    }

    if (strcmp(move,"a")==0)
    {
      move_left(&x,&y,GameArea);
      scanf("%s",move);
    }

    if (strcmp(move,"d")==0)
    {
      move_rigth (&x,&y,GameArea);
      scanf("%s",move);
    }

      if (strcmp(move,"clear")==0)
    {
      goto_debut (GameArea,&x,&y);
      scanf("%s",move);
    }

    if (strcmp(move,"w")!=0 && strcmp(move,"s")!=0 && strcmp(move,"a")!=0)
    {
      if (  strcmp(move,"d")!=0 && strcmp(move,"stop")!=0 && strcmp(move,"clear")!=0)
      {
        printf("*****effectuer des mouvements correct!*****\n");
        show_menu(move);
      }
      
    }
    
  }  
  printf("balade terminer\n");  
}

//------------menu----------------------
void show_menu(char move[]){
  printf("left\nright\nup\ndown\nstop:arreter le jeu\n");
  printf("effectuer un mouvement!\n");
  printf(">");
  scanf("%s",move);
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
    GameArea[*p_X][*p_Y] = 'T';
  }
  initArea(GameArea, p_X, p_Y);

}
//------------------------------------------------------------------
void move_down (int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]){
 if(*p_X==compte_X-1){
    (*p_X)--;
    GameArea[*p_X][*p_Y]='T';
    
  }
   
  else
    GameArea[*p_X][*p_Y]=' ';
    (*p_X)++;
    GameArea[*p_X][*p_Y]='T'; 
    initArea(GameArea,p_X,p_Y);

  
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
    GameArea[*p_X][*p_Y]='T';
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
    GameArea[*p_X][*p_Y]='T';
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

