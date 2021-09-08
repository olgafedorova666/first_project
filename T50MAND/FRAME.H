
struct frame
{
  static const int ws = 200;
  static const int hs = 220;
  unsigned char Image[hs][ws][3];
  static const int x0 = -2, x1 = 2, y0 = -2, y1 = 2; 
  frame(void)
  {
    for(int ys = 0; ys < hs; ys++)
      for(int xs = 0; xs < ws; xs++)
      {

       double a = ((double)xs / ws) * (x1 - x0) + x0;
       double b = ((double)ys / hs) * (y1 - y0) + y0;
       int n = complex(a , b).Iter();
       Image[ys][xs][0] = n;
       Image[ys][xs][1] = n * 2;
       Image[ys][xs][2] = n * 3;

      }
  }
  frame(double SuncTime)
  {
    for(int ys = 0; ys < hs; ys++)
      for(int xs = 0; xs < ws; xs++)
      {

       double a = ((double)xs / ws) * (x1 - x0) + x0;
       double b = ((double)ys / hs) * (y1 - y0) + x0;
       int n = complex(a , b).Iter1(SuncTime);
       Image[ys][xs][0] = n;
       Image[ys][xs][1] = n * 2;
       Image[ys][xs][2] = n * 3;

      }
  }
  void Draw(void)
  {
    glDrawPixels(ws, hs, GL_RGB, GL_UNSIGNED_BYTE, Image);
  }

};
