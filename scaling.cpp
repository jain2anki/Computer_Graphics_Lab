#include <stdio.h>
#include <math.h>
#include <GL/glut.h>


float round_value(float v)
{
  return floor(v + 0.5);
}

void scale(int *x, int *y, int Sx, int Sy) {
  *x*=Sx;
  *y*=Sy;
}

void draw_line(float x1, float y1, float x2, float y2) {
  glBegin(GL_LINES);
  glVertex2d(x1, y1);
  glVertex2d(x2, y2);  
  glEnd();
}

void draw_polygon(int x[], int y[], int n) {
  glBegin(GL_LINE_LOOP);
  for(int i=0;i<n;i++) {
    glVertex2d(x[i], y[i]);
  }
  glEnd();

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


void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  int ch, x1,y1,x2,y2,Sx,Sy,x,y,r,n;
  printf("Enter your choice\n1. Line\n2. Circle\n3.Polygon\n");
  scanf("%d",&ch);
  if(ch==1) {
    printf("Enter two end points of line (x1,y1) and (x2,y2)\n");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    printf("Enter the scaling factor (Sx,Sy)\n");
    scanf("%d%d",&Sx,&Sy);
    draw_line(x1,y1,x2,y2);
    scale(&x1,&y1,Sx,Sy);
    scale(&x2,&y2,Sx,Sy);
    draw_line(x1,y1,x2,y2);        
  }
  if(ch==2) {
    printf("Enter centre (x,y) and radius of the circle\n");
    scanf("%d%d%d",&x,&y,&r);
    printf("Enter the scaling factor (Sx,Sy)\n");
    scanf("%d%d",&Sx,&Sy);
    draw_circle(x,y,r);
    scale(&x,&y,Sx,Sy);
    int t1=x+r, t2=y+r;
    scale(&t1,&t2,Sx,Sy);
    r*=Sx;
    draw_circle(x,y,r);
  }
  if(ch==3) {
    printf("Enter number of coordinates\n");
    scanf("%d",&n);
    int x_c[n], y_c[n];
    printf("Enter the coordinates\n");
    for(int i=0;i<n;i++)
      scanf("%d%d",&x_c[i],&y_c[i]);
    printf("Enter the scaling factor (Sx,Sy)\n");
    scanf("%d%d",&Sx,&Sy);
    draw_polygon(x_c, y_c, n);
    for(int i=0;i<n;i++) {
      int t1 = x_c[i], t2 = y_c[i];
      scale(&t1,&t2,Sx,Sy);
      x_c[i] = t1;
      y_c[i] = t2;
    }
    draw_polygon(x_c, y_c, n);
  }


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
  glutDisplayFunc(display);
  glutMainLoop();
}