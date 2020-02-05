#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void reflect_x(int *x, int *y) {
  *y = -*y;
}
void reflect_y(int *x, int *y) {
  *x = -*x;
}

void draw_polygon(int x[], int y[], int n) {
  glBegin(GL_LINE_LOOP);
  for(int i=0;i<n;i++) {
    glVertex2d(x[i], y[i]);
  }
  glEnd();

}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  int ch,n;
    printf("Enter number of coordinates\n");
    scanf("%d",&n);
    int x_c[n], y_c[n], refX_x[n], refX_y[n], refY_x[n], refY_y[n];
    printf("Enter the coordinates\n");
    for(int i=0;i<n;i++) {
      scanf("%d%d",&x_c[i],&y_c[i]);
      refX_x[i] = x_c[i];
      refX_y[i] = y_c[i];
    }
    draw_polygon(x_c, y_c, n);
    for(int i=0;i<n;i++)
      reflect_x(&x_c[i],&y_c[i]);
    glColor3f(1,0,0);
    draw_polygon(x_c, y_c, n);
    for(int i=0;i<n;i++)
      reflect_y(&refX_x[i],&refX_y[i]);
    glColor3f(0,1,0);
    draw_polygon(refX_x, refX_y, n);


  glEnd();
  glFlush();
}


void Init()
{
  // glClearColor(1.0,1.0,1.0,0);
  // glColor3f(0.0,0.0,0.0);
  gluOrtho2D(-640 , 640 , -480 , 480);
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