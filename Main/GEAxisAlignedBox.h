#ifndef GEAXISALIGNEDBOX_H_INCLUDED
#define GEAXISALIGNEDBOX_H_INCLUDED
#include "GEVector3.h"
#include "GEVector4.h"
#include "GEMatrix4.h"
namespace ge
{
  class AxisAlignedBox
  {
  public:
    Vector3 minimum;
    Vector3 maximum;

    AxisAlignedBox()
    {
    }

    AxisAlignedBox(const Vector3& fMinimum, const Vector3& fMaximum)
    {
      minimum = fMinimum;
      maximum = fMaximum;
    }

    AxisAlignedBox(Real minX, Real minY, Real minZ,
                   Real maxX, Real maxY, Real maxZ)
    {
      minimum.redefine(minX, minY, minZ);
      maximum.redefine(maxX, maxY, maxZ);
    }

    AxisAlignedBox(const AxisAlignedBox& fbox)
    {
      minimum = fbox.minimum;
      maximum = fbox.maximum;
    }

    AxisAlignedBox& operator = (const AxisAlignedBox& fbox)
      {
        minimum = fbox.minimum;
        maximum = fbox.maximum;
      }

    Vector3 getMinimum()
    {
      return minimum;
    }

    void setMinimum(const Vector3& fmin)
    {
      minimum = fmin;
    }

    void setMinimum(Real fx, Real fy, Real fz)
    {
      minimum.x = fx;
      minimum.y = fy;
      minimum.z = fz;
    }
    

    Vector3 getMaximum()
    {
      return maximum;
    }

    void setMaximum(const Vector3& fmax)
    {
      maximum = fmax;
    }

    void setMaximum(Real fx, Real fy, Real fz)
    {
      maximum.x = fx;
      maximum.y = fy;
      maximum.z = fz;
    }

    void setMinimumX(Real fx)
    {
      minimum.x = fx;
    }

    void setMinimumY(Real fy)
    {
      minimum.y = fy;
    }

    void setMinimumZ(Real fz)
    {
      minimum.z = fz;
    }

    void setMaximumX(Real fx)
    {
      maximum.x = fx;
    }

    void setMaximumY(Real fy)
    {
      maximum.y = fy;
    }

    void setMaximumZ(Real fz)
    {
      maximum.z = fz;
    }

    void transport(const Matrix4& mat4)
    {
      Vector4 min4(minimum);
      Vector4 max4(maximum);

      Vector4 result;
      result.redefine(min4 * mat4);
      minimum.redefine(result[0], result[1], result[2]);
      result.redefine(max4 * mat4);
      maximum.redefine(result[0], result[1], result[2]);
    }
  };
}

#endif//GEAXISALIGNEDBOX_H_INCLUDED
