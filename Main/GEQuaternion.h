#ifndef GEQUATERNION_H_INCLUDED
#define GEQUATERNION_H_INCLUDED
#include "GEVector3.h"
namespace ge
{
  class Radian;
  class Degree;
    class Quaternion
    {
    public:
      /* define the quaternion
         */
      Real x, y, z, w;
      /* default constructor */
      Quaternion()
      {
      }
      
      /* constructor by for Reals */
    Quaternion(Real fx, Real fy, Real fz,Real fw)
      :x(fx), y(fy), z(fz), w(1.0)
      {
      }
      
      Quaternion(const Quaternion& qtn)
      {
        x = qtn.x;
        y = qtn.y;
        z = qtn.z;
        w = qtn.w;
      }

      Quaternion(Vector3& vec3, const Radian& rad);
      Quaternion(Vector3& vec3, const Degree& deg);

      Quaternion& operator = (const Quaternion& qtn)
        {
          x = qtn.x;
          y = qtn.y;
          z = qtn.z;
          w = qtn.w;
          return *this;
        }

      Quaternion operator + (const Quaternion& qtn)
      {
        return Quaternion(x + qtn.x, y + qtn.y, z + qtn.z, w + qtn.w);
      }

      Quaternion& operator += (const Quaternion& qtn)
      {
        x += qtn.x;
        y += qtn.y;
        z += qtn.z;
        w += qtn.w;
        return *this;
      }

      Quaternion operator - (const Quaternion& qtn)
      {
        return Quaternion(x - qtn.x, y - qtn.y, z - qtn.z, w - qtn.w);
      }

      Quaternion& operator -= (const Quaternion& qtn)
      {
        x -= qtn.x;
        y -= qtn.y;
        z -= qtn.z;
        w -= qtn.w;
        return *this;
      }

      Quaternion operator * (const Real scale)
      {
        return Quaternion(x * scale, y * scale, z * scale, w * scale);
      }

      Quaternion& operator *= (const Real scale)
      {
        x *= scale;
        y *= scale;
        z *= scale;
        w *= scale;
        return *this;
      }
      

      Quaternion operator * (const Quaternion& qtn)
      {
        return Quaternion(w * qtn.x + x * qtn.w + y * qtn.z - z * qtn.y,
                          w * qtn.y - x * qtn.z + y * qtn.w + z * qtn.x,
                          w * qtn.z + x * qtn.y - y * qtn.x + z * qtn.w,
                          w * qtn.w - x * qtn.x - y * qtn.y - z * qtn.z);
      }

      
      Quaternion conjugation()
      {
        return Quaternion(-x, -y, -z, w);
      }

      inline Real getNorm()
      {
        return x * x + y * y + z * z + w * w;
      }

      Quaternion reverse()
      {
        Quaternion qtn = conjugation();
        Real norm = getNorm();
        assert(norm > 0.0);
        return Quaternion(qtn.x / norm, qtn.y / norm, qtn.z / norm, qtn.w / norm);
      }
    };
    
}
#endif // GEQUATERNION_H_INCLUDED
