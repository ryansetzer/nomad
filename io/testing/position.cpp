#include "display-test.h"
#include <stdexcept>
#include "position.h"

ScreenLocation centerX(int left, int right, int width) {
  ScreenLocation centeredLocation;
  // Checking Valid Positioning
  if (
    left < 0 || right > WIDTH || // Starts / Ends Off Screen
    left >= right ||             // Invalid Positioning
    left + width >= right        // Out of Bounds
  ) {
    throw std::invalid_argument("Invalid Positioning (X and/or Y)");
  }

  int margin = (right - left - width) / 2;
  centeredLocation.x = left + margin;
  return centeredLocation;
}


ScreenLocation centerY(int top, int bottom, int height) {
  ScreenLocation centeredLocation;
  // Checking Valid Positioning
  if (
    top < 0 || bottom > HEIGHT || // Starts / Ends Off Screen
    top >= bottom ||              // Invalid Positioning
    top + height >= bottom        // Out of Bounds
  ) {
    throw std::invalid_argument("Invalid Positioning (X and/or Y)");
  }

  int margin = (bottom - top - height) / 2;
  centeredLocation.y = top + margin;
  return centeredLocation;
}

ScreenLocation centerXandY(int width, int height, BoxSizeLocation container) {
  return ScreenLocation {
    centerX(container.topLeft.x, container.bottomRight.x, width).x,
    centerY(container.topLeft.y, container.bottomRight.y, height).y,
  };
}
