glBegin(GL_LINE_STRIP);
      glColor3f(1.0f, 1.0f, 1.0f);     //front
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glVertex3f(0.0f, 1.0f, 1.0f);
      glVertex3f(0.0f, 0.0f,  1.0f);
      glVertex3f( 1.0f, 0.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glEnd();

      glBegin(GL_LINE_STRIP); //right
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glVertex3f(1.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, 0.0f,  0.0f);
      glVertex3f( 1.0f, 0.0f, 1.0f);
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glEnd();

      glBegin(GL_LINE_STRIP); //top
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glVertex3f(1.0f, 1.0f, 0.0f);
      glVertex3f(0.0f, 1.0f,  0.0f);
      glVertex3f( 0.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glEnd();

      glBegin(GL_LINE_STRIP); //left
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 0.0f, 1.0f, 1.0f);
      glVertex3f(0.0f, 0.0f, 1.0f);
      glVertex3f(0.0f, 0.0f,  0.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f( 0.0f, 1.0f, 1.0f);
      glEnd();

            glBegin(GL_LINE_STRIP); //bottom
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f, 0.0f, 1.0f);
      glVertex3f(0.0f, 0.0f, 1.0f);
      glVertex3f(0.0f, 0.0f,  0.0f);
      glVertex3f( 1.0f, 0.0f, 0.0f);
      glVertex3f( 1.0f, 0.0f, 1.0f);
      glEnd();