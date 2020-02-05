#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int X, Y, r;

float round_value(float v)
{
  return floor(v + 0.5);
}

void draw_circle()
{

  glBegin(GL_LINES);
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

  glClear(GL_COLOR_BUFFER_BIT);
  draw_circle();

	glEnd();
  glFlush();
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
  glutMainLoop();
}