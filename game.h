//---------directive---------
# define Areagame_X 10
# define Areagame_Y 10

# define compte_X (Areagame_X *2)-1
# define compte_Y (Areagame_Y *2)-1

# define MAX_X Areagame_X *2
# define MAX_Y Areagame_Y *2

//--------prototype--------------
void show_menu (char move);

void initArea  (char gameArea[MAX_X][MAX_Y ],int *pX,int *pY);
void limite    (int x,int y,char gameArea[MAX_X][MAX_Y ]);

void move_up   (int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]);
void move_rigth(int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]);
void move_down (int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]);
void move_left (int *p_X,int *p_Y,char GameArea[MAX_X ][MAX_Y]);

void cleaner   (char gameArea[MAX_X][MAX_Y ]); 
void goto_debut(char gameArea[MAX_X][MAX_Y],int *p_x,int *p_y);


void control(void);