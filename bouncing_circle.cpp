#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <unistd.h>

#define maxWD 640 
#define maxHT 480 
int X, Y, r;

// void delay(unsigned int mseconds) 
// { 
//     clock_t goal = mseconds + clock(); 
//     while (goal > clock()) 
//         ; 
// } 

void draw_circle()
{


  glBegin(GL_POINTS);
  int x=0, y=r;
  int p = 3-2*r;
  while(x<y) {
    x++;
    if(p<0)
      p = p + 4*x + 6;
    else {
      p = p + 4*(x-y) + 10;
      y--;
    }
    glVertex2d(x + X, y + Y);
    glVertex2d(y + X, x + Y);
    glVertex2d(x + X, -y + Y);
    glVertex2d(y + X, -x + Y);
    glVertex2d(-x + X, -y + Y);
    glVertex2d(-y + X, -x + Y);
    glVertex2d(-x + X, y + Y);
    glVertex2d(-y + X, x + Y);
  }
  

}

void circle() {
  printf("Enter centre (x,y) and radius of the circle\n");
  scanf("%d%d%d",&X,&Y,&r);
  int x=X, y=Y, flag=1, mode=1;
  while (1) {
  if (flag) {
    X++;
  }
  else {
    X--;
  }
  if(mode)
      Y++;
  else
    Y--;
  if(Y+r==maxHT) {
      mode = 0;
    }
  if(Y==r)
    mode=1;
  if(X+r==maxWD)
    flag=0;
  if(X==r)
    flag=1;
  glClear(GL_COLOR_BUFFER_BIT);
  draw_circle();

  glEnd();
  glFlush();
  usleep(4000);
}
}


void Init()
{
 glClearColor(0, 0, 0, 0.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0.0, maxWD, 0.0, maxHT); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glFlush(); 
}
int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("Bresenham_circle");
  Init();
  glutDisplayFunc(circle);
  glutMainLoop();
}