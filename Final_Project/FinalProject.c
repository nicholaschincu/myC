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

    start_color();
    init_pair(Sun, COLOR_YELLOW, COLOR_RED);
    init_pair(Mercury, COLOR_WHITE, COLOR_WHITE); //foreground color, background color//
    init_pair(Venus, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(Earth, COLOR_BLUE, COLOR_BLUE);
    init_pair(Mars, COLOR_RED, COLOR_RED);
    init_pair(Jupiter, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(Saturn, COLOR_RED, COLOR_YELLOW);
    init_pair(Uranus, COLOR_GREEN, COLOR_GREEN);
    init_pair(Neptune, COLOR_CYAN, COLOR_CYAN);
    init_pair(SolarSystem, COLOR_BLACK, COLOR_BLACK);
    attron(COLOR_PAIR(1)); //initializes the colors as a pair//
    printw("Solar System"); //works same way as printf//
    attroff(COLOR_PAIR(1));

    getch(); //pauses the program and plots points//
    endwin(); //closes down ncurses library or killscreen//

  return 0;
}

void draw_solarsystem(void)
{
    int y, x;
    //draws the solarsystem//
    //background//

    attron(COLOR_PAIR(SolarSystem));
    attroff(COLOR_PAIR(SolarSystem));

    attron(COLOR_PAIR(Sun));
    attroff(COLOR_PAIR(Sun));

    attron(COLOR_PAIR(Mercury));
    attroff(COLOR_PAIR(Mercury));

    attron(COLOR_PAIR(Venus));
    attroff(COLOR_PAIR(Venus));

    attron(COLOR_PAIR(Earth));
    attroff(COLOR_PAIR(Earth));

    attron(COLOR_PAIR(Mars));
    attroff(COLOR_PAIR(Mars));

    attron(COLOR_PAIR(Jupiter));
    attroff(COLOR_PAIR(Jupiter));

    attron(COLOR_PAIR(Saturn));
    attroff(COLOR_PAIR(Saturn));

    attron(COLOR_PAIR(Uranus));
    attroff(COLOR_PAIR(Uranus));

    attron(COLOR_PAIR(Neptune));
    attroff(COLOR_PAIR(Neptune));

}


________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

#include <math.h>

/*Note:
 *Everything is in SI units
 *m/s, kg, m/s^2, m
*/
#define PLANNET_NUM 3
#define G_CONSTANT 6.62 * pow(10,-11)
#define SUN_M = 1.9891 * pow(10, 30)
#define MERCURY_M 3.285 * pow(10,23)
#define VENUS_M 4.867 * pow(10,24)
#define DTIME 86400 //1 day in seconds 

//function declarations
double norm(double a[3], double b[3]);
double force(double norm, double mA, double mB);
int forceCalc(double mA, double mB, double a[3], double b[3], double *force);
int magCalc(double *x, double *y, double *result);

struct Plannet{
  char *name;
  double mass;
  double location[2];
  double force[PLANNET_NUM - 1][2];
  double momentum[2];
};

int momentumCalc(struct Plannet plannet, double *momentum);
int locationCalc(struct Plannet plannet,double *pos, double *momentum);

int main(){
  struct Plannet plannet[PLANNET_NUM];

  plannet[0].name = "sun";

  plannet[0].mass = 1.9891 * pow(10, 30);
  plannet[1].mass = 3.285 * pow(10,23);
  plannet[2].mass = 4.867 * pow(10,24);

  plannet[0].location[0] = 0;
  plannet[0].location[1] = 0;

  plannet[1].location[0] = 69.818 * pow(10,9);
  plannet[1].location[1] = 0;

  plannet[2].location[0] = 108.11 * pow(10,9);
  plannet[2].location[1] = 0;

  for(int i = 0; i < PLANNET_NUM; i++){
    int col = 0;
    for(int j = 0; j < PLANNET_NUM; j++){
      if(i == j){
        j++;
      }
      forceCalc(plannet[i].mass, plannet[j].mass, plannet[i].location, plannet[j].location, plannet[i].force[col]);
      col++;
    }
  }

  /* Momentum calculation but added to location calc
  for(int i = 0; i < PLANNET_NUM; i++){
    momentumCalc(plannet[i], plannet[i].momentum);
  }
  */

  for(int i = 0; i < PLANNET_NUM; i++){
    locationCalc(plannet[i], plannet[i].location, plannet[i].momentum);
  }
}

//returns the position of plannet as a vector(x,y,z components)



//returns the norm of 2 vectors
double normCalc(double a[2], double b[2]){
  return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
}

//calculates the gravitational force of 2 plannets
int forceCalc(double mA, double mB, double a[2], double b[2], double *force){
  double norm = normCalc(a, b);
  double mag[2];
  magCalc(a, b, mag);

  for(int i = 0; i < 2; i++){
    force[i] = - (G_CONSTANT * mA * mB) * mag[i] / pow(norm, 2);
  }

  return 1;
}

//calculates the magnitude of the two vectors
int magCalc(double *x, double *y, double *result){
  for (int i = 0 ; i < 2 ; ++i){
        result[i] = y[i] - x[i];
  }
  return 0;
}

//calculates the momentum of 2 plannets

int momentumCalc(struct Plannet plannet, double *momentum){
  for(int i = 0; i < 2; i++){
    double nF = 0;
    for(int j = 0; j < PLANNET_NUM - 1; j++){
       nF += plannet.force[i][j];
    }
    momentum[i] = momentum[i] + nF * DTIME;
  }
  return 1;
}

int locationCalc(struct Plannet plannet,double *pos, double *momentum){
  momentumCalc(plannet, momentum);

  for(int i = 0; i < 2; i++){
    pos[i] = pos[i] + plannet.momentum[i] * DTIME / plannet.mass;
  } 

  return 1;
}
