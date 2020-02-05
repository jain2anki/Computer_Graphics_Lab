#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.14159265

void rotate(float *x, float *y, int degree) {
  float t1 = *x, t2  = *y;
  float d = degree;
  float c = cos(d*PI/180);
  float s = sin(d*PI/180);
  *x = t1*c - t2*s;
  *y = t1*s + t2*c;
}

void draw_line(float x1, float y1, float x2, float y2) {
  glBegin(GL_LINES);
  glVertex2d(x1, y1);
  glVertex2d(x2, y2);  
  glEnd();
}

void draw_polygon(float x[], float y[], int n) {
  glBegin(GL_LINE_LOOP);
  for(int i=0;i<n;i++) {
    glVertex2d(x[i], y[i]);
  }
  glEnd();

}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  int ch,degree,r,n;
  float x, y, x1,y1,x2,y2;
  printf("Enter your choice\n1. Line\n2.Polygon\n");
  scanf("%d",&ch);
  if(ch==1) {
    printf("Enter two end points of line (x1,y1) and (x2,y2)\n");
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
    printf("Enter the degree for rotation\n");
    scanf("%d",&degree);
    draw_line(x1,y1,x2,y2);
    rotate(&x1,&y1,degree);
    rotate(&x2,&y2,degree);
    draw_line(x1,y1,x2,y2);        
  }
  if(ch==2) {
    printf("Enter number of coordinates\n");
    scanf("%d",&n);
    float x_c[n], y_c[n];
    printf("Enter the coordinates\n");
    for(int i=0;i<n;i++)
      scanf("%f%f",&x_c[i],&y_c[i]);
    printf("Enter the degree for rotation\n");
    scanf("%d",&degree);
    draw_polygon(x_c, y_c, n);
    for(int i=0;i<n;i++) {
      float t1 = x_c[i], t2 = y_c[i];
      rotate(&t1,&t2,degree);
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