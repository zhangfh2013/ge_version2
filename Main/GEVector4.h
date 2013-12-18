#ifndef GEVECTOR4_H_INCLUDED
#define GEVECTOR4_H_INCLUDED
#include "GEPrerequires.h"
#include "GEVector3.h"
#include "GEMath.h"
namespace ge
{
	class Vector4
	{
	public:
		Real x, y, z, w;

		Vector4()
		{
			x = 0.0;
			y = 0.0;
			z = 0.0;
			w = 0.0;
		}

		Vector4(Real fx, Real fy, Real fz, Real fw)
			:x(fx), y(fy), z(fz), w(fw)
		{
		}

		Vector4(const Vector4& vec4):x(vec4.x), y(vec4.y), z(vec4.z), w(vec4.w)
		{
		}

		Vector4(const Real a[4]):x(a[0]), y(a[1]), z(a[2]), w(a[3])
		{
		}

		Vector4(const Vector3& vec3):x(vec3.x), y(vec3.y), z(vec3.z), w(1.0)
		{
		}


		inline Vector4& operator = (const Vector4& vec4)
		{
			x = vec4.x;
			y = vec4.y;
			z = vec4.z;
			w = vec4.w;
			return *this;
		}

		inline Vector4& operator = (const Real a[4])
		{
			x = a[0];
			y = a[1];
			z = a[2];
			w = a[3];
			return *this;
		}

		void redefine(const Vector4& vec4)
		{
			x = vec4[0];
			y = vec4[1];
			z = vec4[2];
			w = vec4[3];
		}

		void redefine(Real fx, Real fy, Real fz, Real fw)
		{
			x = fx;
			y = fy;
			z = fz;
			w = fw;
		}

		inline Vector4 operator + ()
		{
			return *this;
		}

		inline Vector4 operator + (const Vector4& vec4)
		{
			return Vector4(x + vec4.x, y + vec4.y, z + vec4.z, w + vec4.w);
		}

		inline Vector4 operator + (const Real a[4])
		{
			return Vector4(x + a[0], y + a[1], z + a[2], w + a[3]);
		}

		inline Vector4& operator += (const Vector4& vec4)
		{
			x += vec4.x;
			y += vec4.y;
			z += vec4.z;
			w += vec4.w;
			return *this;
		}

		inline Vector4& operator += (const Real a[4])
		{
			x += a[0];
			y += a[1];
			z += a[2];
			w += a[3];
			return *this;
		}

		inline Vector4 operator - ()
		{
			return Vector4(-x, -y, -z, -w);
		}

		inline Vector4 operator - (const Vector4& vec4)
		{
			return Vector4(x - vec4.x, y - vec4.y, z - vec4.z, w -vec4.w);
		}

		inline Vector4 operator - (const Real a[4])
		{
			return Vector4(x - a[0], y - a[1], z - a[2], w - a[3]);
		}

		inline Vector4& operator -= (const Vector4& vec4)
		{
			x -= vec4.x;
			y -= vec4.y;
			z -= vec4.z;
			w -= vec4.w;
			return *this;
		}

		inline Vector4& operator -= (const Real a[4])
		{
			x -= a[0];
			y -= a[1];
			z -= a[2];
			w -= a[3];
			return *this;
		}

		inline Vector4 operator * (const Real scale)
		{
			return Vector4(x * scale, y * scale, z * scale, w * scale);
		}

		inline Real operator * (const Vector4& vec4)
		{
			return x * vec4.x + y * vec4.y + z * vec4.z + w * vec4.w;
		}


		inline Vector4& operator *= (const Real scale)
		{
			x *= scale;
			y *= scale;
			z *= scale;
			w *= scale;
			return *this;
		}

		inline Vector4 operator / (const Real scale)
		{
			assert(scale == 0.0);
			return Vector4(x / scale, y / scale, z / scale, w / scale);
		}

		inline Vector4& operator /= (const Real scale)
		{
			assert(scale == 0.0);
			x /= scale;
			y /= scale;
			z /= scale;
			w /= scale;
			return *this;
		}

		inline bool operator == (const Vector4& vec4)
		{
			return (x == vec4.x)&&(y == vec4.y)&&(z == vec4.z)&&(w == vec4.w);
		}

		inline bool operator != (const Vector4& vec4)
		{
			return (x != vec4.x)||(y != vec4.y)||(z != vec4.z)||(w != vec4.w);
		}

		Real& operator [] (const Uint index)
		{
			assert(index < 4);
			switch(index)
			{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
				return w;
			}
		}

		const Real& operator [] (const Uint index) const
		{
			assert(index < 4);
			switch(index)
			{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
				return w;
			}
		}

		inline Real dotProduct(const Vector4& vec4)
		{
			return x * vec4.x + y * vec4.y + z * vec4.z + w * vec4.w;
		}

		Real length()
		{
			return Math::Sqrt(x * x + y * y + z * z + w * w);
		}

		void normalise()
		{
			Real len = length();
			assert(len >= 0.0);
			x /= len;
			y /= len;
			z /= len;
			w /= len;
		}

		inline friend std::ostream& operator << (std::ostream& os, const Vector4& vec4)
        {
			os<<"(" << vec4.x <<", "<< vec4.y << ", " <<vec4.z<<", "<<vec4.w<<")";
            return os;
        }
	};
}





#endif // GEVECTOR4_H_INCLUDED
