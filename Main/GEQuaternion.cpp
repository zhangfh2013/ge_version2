#include "GEQuaternion.h"
#include "GEMath.h"
using namespace ge;

Quaternion :: Quaternion(Vector3& vec3, const Radian& rad)
{
   vec3.normalise();
   x = vec3.x;
   y = vec3.y;
   z = vec3.z;
   w = Math :: Cos(rad * 0.5);
}

Quaternion :: Quaternion(Vector3& vec3, const Degree& deg)
{
   vec3.normalise();
   x = vec3.x;
   y = vec3.y;
   z = vec3.z;
   w = Math :: Cos(deg * 0.5);
}


