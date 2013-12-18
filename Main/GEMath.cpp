#include "GEMath.h"
#include "GERay.h"
#include "GEPlane.h"
#include "GESphere.h"
#include "GEAxisAlignedBox.h"
using namespace ge;

Radian::Radian(const Degree& deg)
{
    mRad = deg.getValue() * 180 / PI;
}


Radian& Radian::operator = (const Degree& deg)
{
    mRad = deg.getValue() * 180 / PI;
    return *this;
}

void Radian::setValue(const Degree& deg)
{
    mRad = deg.getValue() * 180 / PI;
}

Radian Radian::operator + (const Degree& deg)
{
    return Radian(mRad + deg.getValue() * 180 / PI);
}

Radian& Radian::operator += (const Degree& deg)
{
    mRad += deg.getValue() * 180 / PI;
    return *this;
}

Radian Radian::operator - (const Degree& deg)
{
    return Radian(mRad - deg.getValue() * 180 / PI);
}

Radian& Radian::operator -= (const Degree& deg)
{
    mRad -= deg.getValue() * 180 / PI;
    return *this;
}

bool Math::intersected(const Ray& ray, const Plane& plane)
{
   Vector3 rayDir = ray.getOrien();
   Vector3 planeN = plane.getNormal();

   if(rayDir * planeN == 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Math::intersected(const Ray& ray, const Sphere& sphere)
{
   Vector3 t = ray.getOrien();
   Vector3 origin = ray.getOrigin();
   Vector3 center = sphere.getCenter();
   Vector3 s = center - origin;
   Real d = (s.crossProduct(t)).length();

   if(d <= sphere.getRadius())
   {
      return true;
   }
   else
   {
      return false;

   }
}

bool Math::intersected(const Plane& plane, const Sphere& sphere)
{
   Vector3 point = sphere.getCenter();
   Real dis = plane.getDistance(point);

   if(dis < sphere.getRadius())
   {
      return true;
   }
   else
   {
      return false;
   }

}

bool Math::intersected(const Plane& plane, const AxisAlignedBox& box)
{
   return false;
}


bool Math::intersected(const Sphere& sphere01, const Sphere& sphere02)
{
   Vector3 cen01 = sphere01.getCenter();
   Vector3 cen02 = sphere02.getCenter();

   Real d = Sqrt(cen01 * cen02);

   if(d < sphere01.getRadius() + sphere02.getRadius())
   {
      return true;
   }
   else
   {
      return false;
   }

}

bool Math::intersected(const Sphere& sphere, const AxisAlignedBox& box)
{
   return false;
}

bool Math::intersected(const AxisAlignedBox& box01, const AxisAlignedBox& box02)
{
	return false;
}

   
   
