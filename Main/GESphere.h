#ifndef GESPHERE_H_INCLUDED
#define GESPHERE_H_INCLUDED
namespace ge
{
    class Sphere
    {
    public:
      Real radius;
      Vector3 center;

      Sphere()
      {
      }

      Sphere(const Vector3& fcenter, Real fradius)
      {
        center = fcenter;
        radius = fradius;
      }

      void setRadius(Real fRadius)
      {
        radius = fRadius;
      }

      Real getRadius()
      {
        return radius;
      }

	  Real getRadius() const
      {
        return radius;
      }

      void setCenter(const Vector3& fCenter)
      {
        center = fCenter;
      }

      Vector3 getCenter()
      {
        return center;
      }
      

	  Vector3 getCenter() const
      {
        return center;
      }
    };
}
#endif // GESPHERE_H_INCLUDED
