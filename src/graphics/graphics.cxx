#include "graphics.h"
#include "mysqrt.h"

namespace Graphics
{
  double sqrt(double x) { return Detail::mysqrt(x); }
}
