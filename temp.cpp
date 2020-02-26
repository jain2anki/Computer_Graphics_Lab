#include <GL/glut.h>
GLsizei MOUSEx=0, MOUSEy=0;
GLfloat SIDE=10;
GLfloat BLUE[3] = {0,0,1};

float X_scale = 1, Y_scale =1;

void drawStar()
{
    glColor3fv(BLUE);
    glTranslatef(MOUSEx, MOUSEy, 0.0f);    // Translate
    glScalef(X_scale,Y_scale,0.0f);
   glBegin(GL_TRIANGLES);                  // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex2f(0.1f, -0.6f);
      glVertex2f(0.7f, -0.6f);
      glVertex2f(0.4f, -0.1f);
   glEnd();
   glBegin(GL_TRIANGLES);                  // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex2f(0.1f, -0.3f);
      glVertex2f(0.7f, -0.3f);
      glVertex2f(0.4f, -0.8f);
   glEnd();
}   

void display(void)
{   
    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); 
    drawStar();
    glFlush();
}
void reshape(int w, int h)
{   
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     //gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glOrtho(0.0,1368,768,0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void spindisplay(void)
{       
    glutPostRedisplay();
}

void setX(int x)
{
    MOUSEx=x;
}

void setY(int y)
{
    MOUSEy=y;
}
void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)   
    {
        setX(x);
        setY(y);
        //drawSquare(MOUSEx,HEIGHT-MOUSEy);
        drawStar();
    }
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)   
    {
        exit(1);   // To Exit the Program
    }
}

void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 'S':
         X_scale+=5;
         Y_scale+=5;
         break;
      case 'R':
         X_scale-=5;
         Y_scale-=5;
         break;
   }
}
int main(int argc, char **argv)
{   glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Stars");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutIdleFunc(spindisplay);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}