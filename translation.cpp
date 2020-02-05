#include <stdio.h>
#include <math.h>
#include <GL/glut.h>


float round_value(float v)
{
  return floor(v + 0.5);
}

void translate(int *x, int *y, int Tx, int Ty) {
  *x+=Tx;
  *y+=Ty;
}

void draw_line(int x1, int y1, int x2, int y2) {
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

void draw_circle(int X, int Y, int r)
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

void draw_polygon(int x[], int y[], int n) {
  glBegin(GL_POLYGON);
  for(int i=0;i<n;i++) {
    glVertex2d(x[i], y[i]);
  }
  glEnd();

}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  int ch, x1,y1,x2,y2,Tx,Ty,x,y,r,n;
  printf("Enter your choice\n1. Line\n2. Circle\n3.Polygon\n");
  scanf("%d",&ch);
  if(ch==1) {
    printf("Enter two end points of line (x1,y1) and (x2,y2)\n");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    printf("Enter the translation factor (Tx,Ty)\n");
    scanf("%d%d",&Tx,&Ty);
    draw_line(x1,y1,x2,y2);
    translate(&x1,&y1,Tx,Ty);
    translate(&x2,&y2,Tx,Ty);
    draw_line(x1,y1,x2,y2);        
  }
  if(ch==2) {
    printf("Enter centre (x,y) and radius of the circle\n");
    scanf("%d%d%d",&x,&y,&r);
    printf("Enter the translation factor (Tx,Ty)\n");
    scanf("%d%d",&Tx,&Ty);
    draw_circle(x,y,r);
    translate(&x,&y,Tx,Ty);
    draw_circle(x,y,r);
  }
  if(ch==3) {
    printf("Enter number of coordinates\n");
    scanf("%d",&n);
    int x_c[n], y_c[n];
    printf("Enter the coordinates\n");
    for(int i=0;i<n;i++)
      scanf("%d%d",&x_c[i],&y_c[i]);
    printf("Enter the translation factor (Tx,Ty)\n");
    scanf("%d%d",&Tx,&Ty);
    draw_polygon(x_c, y_c, n);
    for(int i=0;i<n;i++)
      translate(&x_c[i],&y_c[i],Tx,Ty);
    draw_polygon(x_c, y_c, n);
  }


  glEnd();
  glFlush();
}


void Init()
{
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
  glutDisplayFunc(display);
  glutMainLoop();
}