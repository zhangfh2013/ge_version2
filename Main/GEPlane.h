#ifndef GEPLANE_H_INCLUDED
#define GEPLANE_H_INCLUDED
#include "GEVector3.h"
namespace ge
{
	/*this plane is define as Ax + By + Cz + D = 0
	*/
	class Plane
	{
	public:
		Vector3 normal;
		Real d;

	public:
		/* default constructor */
		Plane()
		{
		}

		/* define a plane from an another plane */
		Plane(const Plane& other):normal(other.normal), d(other.d)
		{

		}

		/* define a plane from a normal vector and a d */
		Plane(const Vector3& fnormal, Real fd):normal(fnormal), d(fd)
		{
		}

		/* define a plane from four Reals */
		Plane(Real fa, Real fb, Real fc, Real fd):normal(fa, fb, fc), d(fd)
		{
		}

		/* define a plane from a normal vector and a point */
		Plane(const Vector3& fnormal, const Vector3& fpoint):normal(fnormal)
		{
			d = -(normal.x * fpoint.x + normal.y * fpoint.y + normal.z * fpoint.z);
		}

		/* define a plane from three points */
		Plane(const Vector3& point0, const Vector3& point1, const Vector3& point2);

		inline Vector3 getNormal(void) const
		{
			return normal;
		}

		inline Real getD() const
		{
			return d;
		}

		/* redefine the plane */
		void redefine(Real fa, Real fb, Real fc, Real fd);
		void redefine(const Vector3& fnormal, const Vector3& fpoint);
		void redefine(const Vector3& point0, const Vector3& point1, const Vector3& point2);

		/* this method is to caculate the distance the plane to
		a point off the plane
		@param point the off point's coordinate
		*/
		Real getDistance(const Vector3& fpoint) const;

		/*  */
		bool operator == (const Plane& other)
		{
			return (d == other.d)&&(normal == other.normal);
		}

		bool operator != (const Plane& other)
		{
			return (d != other.d)||(normal != other.normal);
		}
	};

}
#endif // GEPLANE_H_INCLUDE
