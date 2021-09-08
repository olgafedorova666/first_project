#include <glut.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "COMPLEX.H"



typedef unsigned char byte;
byte Frame[1000][1000][3] = {0};

double SuncTime;
void Idle(void)
{
  static long StartTime = -1;
  long CureTime = clock(); 
  if(StartTime == - 1)
    StartTime = CureTime;
  else
  SuncTime = (double)(CureTime - StartTime) / CLOCKS_PER_SEC;
}

void KeyBoard(byte key, int x, int y)
{
   if (key == 27)
     exit(0);
}

  void Display(void)
{
  glClearColor(0.3, 0.5, 0.7, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glRasterPos2d(-1, 1);
  glPixelZoom(1, -1);
  /*frame MyFrame(SuncTime);
  printf("%f\n", SuncTime);*/

  frame();

  //MyFrame.Draw();
  //glDrawPixels(1000, 1000, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);  
  glFinish();

 /* glClear(GL_COLOR_BUFFER_BIT);
  glRasterPos
  Frame[1][1][1] = 255;
  glFinish();    */
  glutSwapBuffers();
  glutPostRedisplay(); 
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(500, 500);
  glutCreateWindow("9-4");

  glutIdleFunc(Idle);
  glutDisplayFunc(Display);
  glutKeyboardFunc(KeyBoard);
  glutMainLoop();
  return 0;
}