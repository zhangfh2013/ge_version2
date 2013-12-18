#include "GEEuler.h"
using namespace ge;

Euler :: Euler(const Radian& alpha, const Radian& beta, const Radian& gamma, Uint ftype)
{
   switch(ftype)
   {
      case 0:
         x = alpha;
         y = beta;
         z = gamma;
         type  = XYZ;
         break;

      case 1:
         x = alpha;
         y = gamma;
         z = beta;
         type = XZY;
         break;

      case 2:
         y = alpha;
         x = beta;
         z = gamma;
         type = YXZ;
         break;

      case 3:
         y = alpha;
         z = beta;
         x = gamma;
         type = YZX;
         break;

      case 4:
         z = alpha;
         x = alpha;
         y = gamma;
         type = ZXY;
         break;

      case 5:
         z = alpha;
         y = beta;
         x = gamma;
         type = ZYX;
         break;

      default:
         x = alpha;
         y = beta;
         z = gamma;
         type = XYZ;
         break;
   }
}

Euler :: Euler(const Degree& alpha, const Degree& beta, const Degree& gamma)
{
   x = alpha;
   y = beta;
   z = gamma;
}

Euler :: Euler(const Degree& alpha, const Degree& beta, const Degree& gamma, Uint ftype)
{
   switch(ftype)
   {
      case 0:
         x = alpha;
         y = beta;
         z = gamma;
         type  = XYZ;
         break;

      case 1:
         x = alpha;
         y = gamma;
         z = beta;
         type = XZY;
         break;

      case 2:
         y = alpha;
         x = beta;
         z = gamma;
         type = YXZ;
         break;

      case 3:
         y = alpha;
         z = beta;
         x = gamma;
         type = YZX;
         break;

      case 4:
         z = alpha;
         x = alpha;
         y = gamma;
         type = ZXY;
         break;

      case 5:
         z = alpha;
         y = beta;
         x = gamma;
         type = ZYX;
         break;

      default:
         x = alpha;
         y = beta;
         z = gamma;
         type = XYZ;
         break;
   }
}

