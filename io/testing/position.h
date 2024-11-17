struct ScreenLocation {
  int x = -1;
  int y = -1;
};

struct BoxSizeLocation {
  ScreenLocation topLeft;
  ScreenLocation bottomRight;
};


ScreenLocation centerX(int left, int right, int width);
ScreenLocation centerY(int top, int bottom, int height);
ScreenLocation centerXandY(int width, int height, BoxSizeLocation container);
