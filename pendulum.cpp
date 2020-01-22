#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define maxWD 640 
#define maxHT 480
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
  for(x=X-r;x<=X+r;x++) {  // bar of pendulum
    glVertex2d(x,Y+3*r);
  }
  for(y=Y+r;y<=Y+3*r;y++) { // 
    glVertex2d(X,y);
  }
  

}

void circle() {
	printf("Enter centre (x,y) and radius of the circle\n");
	scanf("%d%d%d",&X,&Y,&r);

  glClear(GL_COLOR_BUFFER_BIT);
  draw_circle();

	glEnd();
  glFlush();
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