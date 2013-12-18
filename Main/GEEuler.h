#ifndef GEEULER_H_INCLUDED
#define GEEULER_H_INCLUDED
#include "GEMath.h"
namespace ge
{
  class Euler
  {
    enum EU_Type
    {
      XYZ = 0,
      XZY,
      YXZ,
      YZX,
      ZXY,
      ZYX
    };
    
  public:
    Radian x, y, z;
    EU_Type type;

    Euler()
    {
    }

    inline Euler(const Radian& alpha, const Radian& beta, const Radian& gamma)
      :x(alpha), y(beta), z(gamma), type(XYZ)
    {
    }

    inline Euler(const Radian& alpha, const Radian& beta, const Radian& gamma, Uint ftype);

    inline Euler(const Degree& alpha, const Degree& beta, const Degree& gamma);

    inline Euler(const Degree& alpha, const Degree& beta, const Degree& gamma, Uint ftype);
    
  };
}

#endif//GEEULER_H_INCLUDED
