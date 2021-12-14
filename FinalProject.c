#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>

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
  double distSun[2];
};

int momentumCalc(struct Plannet plannet, double *momentum);
int locationCalc(struct Plannet plannet,double *pos, double *momentum);
int motion(double pl1[]);
int absMagCalc(double *x, double *y, double *result);

int main(){
  struct Plannet plannet[PLANNET_NUM];

  plannet[0].name = "sun";

  plannet[0].mass = 1.9891 * pow(10, 7);
  plannet[1].mass = 3.285 * pow(10,0);
  plannet[2].mass = 4.867 * pow(10,1);

  plannet[0].distSun[0] = 0;
  plannet[0].distSun[0] = 0;
  plannet[0].location[0] = 0;
  plannet[0].location[1] = 0;

  plannet[1].location[0] = 69.818 * pow(10,6) /(4.47 * pow(10,9));
  plannet[1].location[1] = 0;
  plannet[1].distSun[0] = 0;
  plannet[1].distSun[1] = 0;

  plannet[2].location[0] = 4.47 * pow(10,9) / (4.47 * pow(10,9));
  plannet[2].location[1] = 0;
  plannet[2].distSun[0] = 0;
  plannet[2].distSun[1] = 0;

  for(int i = 0; i < PLANNET_NUM; i++){
    int row = 0;
    for(int j = 0; j < PLANNET_NUM; j++){
      if(i == j){
        j++;
      }
      forceCalc(plannet[i].mass, plannet[j].mass, plannet[i].location, plannet[j].location, plannet[i].force[row]);
      row++;
    }
  }

  for(int i = 0; i < PLANNET_NUM; i++){
    locationCalc(plannet[i], plannet[i].location, plannet[i].momentum);
  }

 absMagCalc(plannet[0].location, plannet[2].location, plannet[2].distSun);

  motion(plannet[2].distSun);
  endwin(); //deallocates the memory and is basically a killscreen that end the ncurses
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
    force[i] = - (((G_CONSTANT * mA * mB) * mag[i]) / pow(norm, 2));
    //printf("%lf", force[i]);
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

//calculates the magnitude of the two vectors
int absMagCalc(double *x, double *y, double *result){
  for (int i = 0 ; i < 2 ; ++i){
        result[i] = (fabs(y[i] - x[i]));
        printf("%lf\n", result[i]);
  }
  return 0;
}

//calculates the momentum of 2 plannets

/*
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
*/

int locationCalc(struct Plannet plannet,double *pos, double *momentum){
  
  for(int i = 0; i < 2; i++){
    double nF = 0;
    for(int j = 0; j < PLANNET_NUM - 1; j++){
       nF += plannet.force[i][j];
    }
    momentum[i] = momentum[i] + nF * DTIME;
  }

  for(int i = 0; i < 2; i++){
    pos[i] = pos[i] + (plannet.momentum[i] * DTIME / plannet.mass);
  } 

  return 1;
}

int motion(double pl1[]){
  initscr(); //initializes the screen, sets up memory, and clears screen
  double row, col;
  getmaxyx(stdscr,row,col);
  row = row / 2;
  col = col / 2;
  move(row,col);
  printw("Sun");
  refresh();
  sleep(1);
  
  move(row - pl1[1],col - pl1[0]);
  printw("moon");
  refresh();
  sleep(1);
  clear();
  //endwin(); //deallocates the memory and is basically a killscreen that end the ncurses
  return 1;
}
