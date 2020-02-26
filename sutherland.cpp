#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int Xmin ,Ymin, Xmax, Ymax, x1, y1, x2, y2;


void Bresenham(int x1, int y1, int x2, int y2) {
	int dx = x2-x1;
	int dy = y2-y1;

	int p = 2*dy-dx;
	
	int X=x1, Y=y1;
	int i;
	glBegin(GL_POINTS);
	for(;X<=x2;X++) {
		glVertex2d(X,Y);
		if(p>=0) {
			Y++;
			p=p+2*dy-2*dx;
		}
		else {
			p=p+2*dy;
		}
	}
}

int computeCode(int x, int y) {
	int code = 0;
	if(x<Xmin)
		code = code | 1;
	else if(x>Xmax)
		code = code | 2;
	if(y<Ymin)
		code = code | 4;
	else if(y>Ymax)
		code = code | 8;
	return code;
}

void chessboard() {
	
	printf("Enter Xmin, Ymin, Xmax, Ymax\n");
	scanf("%d%d%d%d", &Xmin, &Ymin, &Xmax, &Ymax);
	printf("Enter line coordinates (x1,y1), (x2,y2)");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	Bresenham(x1, y1, x2, y2);
	Bresenham(Xmin, Ymin, Xmax, Ymin);
	Bresenham(Xmin, Ymin, Xmin, Ymax);
	Bresenham(Xmax, Ymin, Xmax, Ymax);
	Bresenham(Xmax, Ymax, Xmin, Ymax);
	int code1 = computeCode(x1,y1);
	int code2 = computeCode(x2,y2);
	bool accept=false;
	while(1) {
		if(code1==0 && code2==0)
			break;
		if(code1&code2)
		{
			accept=false;
			break;
		}


	}
	// if (accept) 
 //    { 
 //        printf("Line accepted from %d,%d to %d,%d", x1,y1,x2,y2);
 //    } 
 //    else
 //       	printf("Line rejected"); 
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