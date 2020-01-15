#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double X1, Y1, X2, Y2;

float round_value(float v)
{
  return floor(v + 0.5);
}

void LineDDA(double X1, double Y1, double X2, double Y2)
{

  double dx=(X2-X1);
  double dy=(Y2-Y1);
  double steps;
  float xInc,yInc,x=X1,y=Y1;

  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;


  glBegin(GL_POINTS);
  glVertex2d(x,y);
  int k;
  for(k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;
    glVertex2d(round_value(x), round_value(y));
  }

}

void chessboard() {
	int a,b;
	printf("Enter X*Y for board\n");
	scanf("%d%d",&a,&b);
	X1 = 40;
	X2 = X1 + b*20;
	Y1 = 50;
	Y2 = 50;

  glClear(GL_COLOR_BUFFER_BIT);
  for (int i=0;i<=a;i++) {
  Y1 = Y1 + 20;
  Y2 = Y2 + 20;
  LineDDA(X1,Y1,X2,Y2);
}
  	X1 = 20;
	X2 = 20;
	Y1 = 70;
	Y2 = Y1 + a*20;
  for (int i=0;i<=b;i++) {
  X1 = X1 + 20;
  X2 = X2 + 20;
  LineDDA(X1,Y1,X2,Y2);
}
	glEnd();
  glFlush();
}


void Init()
{
  glClearColor(1.0,1.0,1.0,0);
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}
int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("DDA_Line");
  Init();
  glutDisplayFunc(chessboard);
  glutMainLoop();
}