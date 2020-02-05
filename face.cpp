#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <unistd.h>

int X, Y, r;

float round_value(float v)
{
  return floor(v + 0.5);
}

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

void draw_mouth()
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

    // glVertex2d(x + X, y + Y);
    // glVertex2d(y + X, x + Y);
    glVertex2d(x + X, -y + Y);
    glVertex2d(y + X, -x + Y);
    glVertex2d(-x + X, -y + Y);
    glVertex2d(-y + X, -x + Y);
    // glVertex2d(-x + X, y + Y);
    // glVertex2d(-y + X, x + Y);
  }
  

}

void clockwise() {
  printf("hi");
  r=40;
  X=220;
  Y=300;
  float d=0;
  while(1) {
  glClear(GL_COLOR_BUFFER_BIT);
  d+=0.001;
  if(d==360)
    d=0;
  glRotatef(d, 100.0f, 100.0f, 0.0f); // Rotate 180 degree
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

  glEnd();
  glFlush();
    usleep(10000);
}
}

void circle() {

  glClear(GL_COLOR_BUFFER_BIT);
  X=320;
  Y=240;
  r= 180;
  draw_circle();
    X=320;
  Y=200;
  r= 18;
  draw_circle();
    X=220;
  Y=300;
  r= 40;
  draw_circle();
    X=420;
  Y=300;
  r= 40;
  draw_circle();
  X=320;
  Y=200;
  r= 100;
  draw_mouth();

	glEnd();
  glFlush();
}

void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)   
    {
        clockwise();
    }
    // if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)   
    // {
    //     anticlockwise();
    // }
}


void Init()
{
  // glClearColor(1.0,1.0,1.0,0);
  // glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
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
    glutMouseFunc(mouse);
  glutMainLoop();
}