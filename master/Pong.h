
#define WIDTH  32
#define HEIGHT 32

typedef struct {
int posx,posy;
int vx,vy;
int size;
} actor_t;


enum{
bounce,
puck,
cycle
};
// The application state is stored in the AppState structure defined
// below. A single instance of this structure is initialized in
// glutapp.cpp and is accessible by pointer App. This will allow
// your application data to be visible by all source files including
// this header file and this will be very usefull when your project
// grows and becomes multi-file project.
typedef struct
 { 
	int p1score;
	int p2score;
	actor_t* player1;
	actor_t* player2;
	actor_t* puck;
 } AppState;

void moveActor(AppState* App, actor_t* a,int mode);
void updateScreen(AppState* App);
void printscore(AppState* App);
