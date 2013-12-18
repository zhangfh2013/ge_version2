#include "GEPlane.h"
#include "GEMath.h"
using namespace ge;

Plane::Plane(const Vector3& point0, const Vector3& point1,
             const Vector3& point2)
{
  Vector3 dir1 = point1 - point0;
  Vector3 dir2 = point2 - point0;
  Vector3 norm = dir1.crossProduct(dir2);
  normal = norm;
  d = -(normal.x * point0.x + normal.y * point0.y + normal.z * point0.z);
}


void Plane::redefine(Real fa, Real fb, Real fc, Real fd)
{
  normal.redefine(fa, fb, fc);
  d = fd;
}

void Plane::redefine(const Vector3& fnormal, const Vector3& fpoint)
{
  normal.redefine(fnormal);
  d = -(normal.x * fpoint.x + normal.y * fpoint.y + normal.z * fpoint.z);
}

void Plane::redefine(const Vector3& point0, const Vector3& point1,
                     const Vector3& point2)
{
  Vector3 dir1 = point1 - point0;
  Vector3 dir2 = point2 - point0;
  Vector3 norm = dir1.crossProduct(dir2);
  normal.redefine(norm);
  d = -(normal.x * point0.x + normal.y * point0.y + normal.z * point0.z);
}

Real Plane::getDistance(const Vector3& fpoint) const
{
  Real len = normal.length();
  return Math::Abs( normal.dotProduct(fpoint) + d) / len;
}






