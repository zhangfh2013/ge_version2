#ifndef GERAY_H_INCLUDED
#define GERAY_H_INCLUDED
#include "GEPrerequires.h"
#include "GEVector3.h"
namespace ge
{
	class Ray
	{
	public:
		/* define the ray in the 3D space
		@param orientation define the orientation of the ray emit and it must be  an unit vector
		@param origin define the start point of the ray emit
		@remark the member property orientation must be a unit 3D unit
		*/
		Vector3 orientation, origin;

		Ray()
		{
		}

		Ray(const Vector3& forien, const Vector3& forigin)
		{
			assert(forien.length() == 1);
			orientation = forien;
			origin = forigin;
		}

		inline void setOrien(const Vector3& fOrien)
		{
			assert(fOrien.length() == 1);

			orientation = fOrien;
		}


		inline Vector3 getOrien() const
		{
			return orientation;
		}

		inline void setOrigin(const Vector3& fOrigin)
		{
			origin = fOrigin;
		}

		inline Vector3 getOrigin() const
		{
			return origin;
		}

		inline Vector3 getPoint(Real t) const
		{
			return  Vector3(orientation * t + origin);
		}

	};
}

#endif//GERAY_H_INCLUDED
