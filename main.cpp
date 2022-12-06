//
//  main.cpp
//  clock simulation
//
//  Created by Zahra Claura on 15/11/22.
//

#include <iostream>
#include <cstdio>

#define GLUT_DISABLE_ATEXIT_HACK
#define GL_SILENCE_DEPRECATION

#include <OpenGL/gl.h>

#include <OpenGl/glu.h>

#include <GLUT/glut.h>

#include <math.h>//for PI value , sine and cosine function that we used to draw lines


 float angleHour= 0,angleMin  = 0,angleSec  = 0, clockR    = 80.0f,angle1min = M_PI / 30.0f,minStart= 0.9f,minEnd=1.0f,stepStart = 0.8f,stepEnd   = 1.0f;
void init(){
      glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-200,200,-150,150,-150,150);
}
//number method is used to write the numbers found in the clock
void numbers()
{
    glRasterPos2i(58,-2);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'3');
    glRasterPos2i(-1,-60);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'6');
    glRasterPos2i(-62,-2);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'9');
    glRasterPos2i(-3,57);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'1');
    glRasterPos2i(0,57);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'2');
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}
void roomscreen(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glColor3f(1.0f,1.0f,1.0f);
        glRasterPos3f(-85, 125, 0);
        char room[]="THIS IS A BEDROOM IN WHICH THERE IS A CLOCK";
        for  (int i=0;i<strlen(room);i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,room[i]);
        
        glColor3f(1.0f,1.0f,1.0f);
        glRasterPos3f(55, 25, 0);
        char room1[]="Let's Take a Closer Look...";
        for  (int i=0;i<strlen(room1);i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,room1[i]);
        
        glColor3f(1.0f,1.0f,1.0f);
        glRasterPos3f(-13, 45, 0);
        char room2[]="CLOCK";
        for  (int i=0;i<strlen(room2);i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,room2[i]);
        
        //clock
        DrawCircle(0, 50, 40, 50);
        
        // bedside
        glColor3f(0.0f,0.0f, 0.0f);
        glBegin(GL_POLYGON); // Draw A Quad
        glVertex3f(-190, -100, 0); // Top Left
        glVertex3f( -120, -100, 0); // Top Right
        glVertex3f( -120, -150, 0); // Bottom Right
        glVertex3f(-190,-150, 0); // Bottom Left
        glEnd();
        glBegin(GL_POLYGON); // Draw A Quad
        glVertex3f(190, -100, 0); // Top Left
        glVertex3f( 120, -100, 0); // Top Right
        glVertex3f( 120, -150, 0); // Bottom Right
        glVertex3f(190,-150, 0); // Bottom Left
        glEnd();
        
        // headboard
        glColor3f(0.0f,0.05f, 0.0f);
        glBegin(GL_POLYGON); // Draw A Quad
        glVertex3f(-100, -20, 0); // Top Left
        glVertex3f( 100, -20, 0); // Top Right
        glVertex3f( 100, -100, 0); // Bottom Right
        glVertex3f(-100,-100, 0); // Bottom Left
        glEnd();
        
        // mattress
        glColor3f(0.1f,0.1f, 0.1f);
        glBegin(GL_POLYGON); // Draw A Quad
        glVertex3f(-100, -100, 0); // Top Left
        glVertex3f( 100, -100, 0); // Top Right
        glVertex3f( 150, -150, 0); // Bottom Right
        glVertex3f(-150,-150, 0); // Bottom Left
        glEnd();
        
        // pillow
        glColor3f(1.0f,1.0f, 1.0f);
        glBegin(GL_POLYGON); // Draw A Quad
        glVertex3f(-90, -90, 0); // Top Left
        glVertex3f( -10, -90, 0); // Top Right
        glVertex3f( -10, -110, 0); // Bottom Right
        glVertex3f(-100,-110, 0); // Bottom Left
        glEnd();
        glBegin(GL_POLYGON); // Draw A Quad
        glVertex3f(10, -90, 0); // Top Left
        glVertex3f( 90, -90, 0); // Top Right
        glVertex3f( 100, -110, 0); // Bottom Right
        glVertex3f(10,-110, 0); // Bottom Left
        glEnd();
        
        glColor3f(1.0f,1.0f,1.0f);
        glRasterPos3f(-45, -55, 0);
        char room3[]="Press 'x' to Look at the Clock";
        for  (int i=0;i<strlen(room3);i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,room3[i]);
        
        glutSwapBuffers();
        glFlush();
        }

//display function responsible to design the classic clock interface
void Display(){
    
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0f, 0.0f, 0.0f);
  glLineWidth(2);
  
  glEnable(GL_LINE_SMOOTH);//for drawing  smooth lines
  glBegin(GL_LINES);
    for(int i=0; i<60; i++){
  float c = cos(i*angle1min), s = sin(i*angle1min);
      if(i%5){ // normal minute
        if(i%5 == 1)
              glColor3f(1.0f, 1.0f, 1.0f);
              //The following is to draw white lines around the circle
            glVertex2f( clockR*minStart*c, clockR*minStart*s);
            glVertex2f( clockR*minEnd*c, clockR*minEnd*s);
      }else{
        glColor3f(0.0f, 0.0f, 0.0f);
          //The following is to draw black long lines around the circle
              glVertex2f( clockR*stepStart*c, clockR*stepStart*s);
            glVertex2f( clockR*stepEnd*c, clockR*stepEnd*s);
      }
    }
  glEnd();
  
  
    numbers();
    //the following is for second hand
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
        glTranslatef(-1,3,0);
        glPushMatrix();
        glRotatef(-angleSec,0,0,1);
            glPushMatrix();
             glTranslatef(1,-3,0);
            glBegin(GL_LINES);
                glVertex2i(-1,3);
                glVertex2i(9,-45);
             glEnd();
 
              glBegin(GL_TRIANGLES);
                  glVertex2i(9,-48);
                 glVertex2i(9,-42);
                 glVertex2i(9,-40);
             glEnd();
             glPopMatrix();
        glPopMatrix();
    glPopMatrix();
 //for minute hand
 glLineWidth(8);
 glColor3f(0.3, 0.3, 0.3);
 glPushMatrix();
    glTranslatef(-1,3,0);
    glPushMatrix();
    glRotatef(-angleMin,0,0,1);
    glPushMatrix();
         glTranslatef(1,-3,0);
         glBegin(GL_LINES);
             glVertex2i(-1,3);
             glVertex2i(40,2);
         glEnd();
         glBegin(GL_TRIANGLES);
             glVertex2i(40,-3);
             glVertex2i(40,7);
             glVertex2i(45,2);
         glEnd();
         glPopMatrix();
      glPopMatrix();
  glPopMatrix();
 //for hour hand
 glLineWidth(10);
 glColor3f(0.0f, 0.0f, 0.0f);
 glPushMatrix();
 glTranslatef(-1,3,0);
 glPushMatrix();
    glRotatef(-angleHour,0,0,1);
    glPushMatrix();
         glTranslatef(1,-3,0);
        glBegin(GL_LINES);
             glVertex2i(-1,3);
             glVertex2i(0,35);
         glEnd();
         glBegin(GL_TRIANGLES);
             glVertex2i(-5,35);
             glVertex2i(0,40);
             glVertex2i(5,35);
         glEnd();
         glPopMatrix();
      glPopMatrix();
  glPopMatrix();
    
    
  //circle design
glPushMatrix();
glTranslatef(-140,-160,0);
  float Xpos = 140, Ypos = 160, radius = 90;
  glColor3f(0.0, 0.0, 0.0);
 
  glBegin(GL_LINE_STRIP);
  for (float i = 0; i < 360; i += 0.01)
    glVertex2f(Xpos + sin(i) * radius, Ypos + cos(i) * radius);
  glEnd();
   
  radius=80;
  glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_LINE_STRIP);
      for (float i = 0; i < 360; i += 0.01)
    glVertex2f(Xpos + sin(i) * radius, Ypos + cos(i) * radius);
   glEnd();
  
  glLineWidth(15);
  glPopMatrix();
  glColor3f(0.0, 0.0, 0.0);
  glPointSize(12);
  glBegin(GL_POINTS);
    glVertex2i(-1,2);
  glEnd();
glFlush();
}
//rotate function manages how the hour,minute and second
//hand are simulated
void rotate()
{
    if(angleSec<360)
    {
        angleSec+=0.21;
    }
    else
    {
        angleSec=0;
    }
  if(angleMin<360)
    {
        angleMin+=0.00055;
    }
    else
    {
        angleMin=0;
    }
  if(angleHour<360)
    {
        angleHour+=0.00000154;
    }
    else
    {
        angleHour=0;
    }
    glutPostRedisplay();
}

void keys(unsigned char key, int x, int y)
{
    if(key==  'x')
    {
        glutDisplayFunc(Display);
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,10);
  glutInitWindowSize(1080,780);
  glutCreateWindow("Analog Clock Simulation");
  init();
  glutDisplayFunc(roomscreen);
  glutKeyboardFunc(keys);
  glutIdleFunc(rotate);
  glutMainLoop();
  return 0;
}
