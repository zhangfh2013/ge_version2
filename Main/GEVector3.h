#ifndef GEVECTOR3_H_INCLUDED
#define GEVECTOR3_H_INCLUDED
#include "GEPrerequires.h"
#include "GEVector2.h"
namespace ge
{
    class Vector3
    {
        public:
        Real x, y, z;

        public:
			Vector3()
			{
				x = 0.0;
				y = 0.0;
				z = 0.0;
			}
        inline explicit Vector3(const Real fx, const Real fy, const Real fz):x(fx), y(fy), z(fz)
        {
        }
        inline explicit Vector3(const Vector2& vec2):x(vec2.x), y(vec2.y), z(0.0){}
//        inline explicit Vector3(const Vector3& vec3):x(vec3.x), y(vec3.y), z(vec3.z){}
        inline explicit Vector3(const Real a[3]):x(a[0]), y(a[1]), z(a[2]){}

        void redefine(const Vector3& vec3)
        {
          x = vec3.x;
          y = vec3.y;
          z = vec3.z;
        }

        void redefine(Real fx, Real fy, Real fz)
        {
          x = fx;
          y = fy;
          z = fz;
        }
        
        inline Vector3& operator = (const Real a[3])
        {
            x = a[0];
            y = a[1];
            z = a[2];
            return *this;
        }

        inline Vector3& operator = (const Vector3& vec3)
        {
            x = vec3.x;
            y = vec3.y;
            z = vec3.z;
            return *this;
        }

        inline Vector3 operator + ()
        {
            return Vector3(x, y, z);
        }

        inline Vector3 operator + (const Real a[3])
        {
            return Vector3(x + a[0], y + a[1], z + a[2]);
        }

        inline Vector3 operator + (const Vector3& vec3)
        {
            return Vector3(x + vec3.x, y + vec3.y, z + vec3.z);
        }

        inline Vector3& operator += (const Real a[3])
        {
            x += a[0];
            y += a[1];
            z += a[2];
            return *this;
        }

        inline Vector3& operator += (const Vector3& vec3)
        {
            x += vec3.x;
            y += vec3.y;
            z += vec3.z;
            return *this;
        }

        inline Vector3 operator - ()
        {
            return Vector3(0.0 - x, 0.0 - y, 0.0 - z);
        }

        inline Vector3 operator - (const Real a[3])
        {
            return Vector3(x - a[0], y - a[1], z - a[2]);
        }

		inline Vector3 operator - (const Real a[3]) const
        {
            return Vector3(x - a[0], y - a[1], z - a[2]);
        }

        inline Vector3 operator - (const Vector3& vec3)
        {
            return Vector3(x - vec3.x, y - vec3.y, z - vec3.z);
        }

		inline Vector3 operator - (const Vector3& vec3) const
        {
            return Vector3(x - vec3.x, y - vec3.y, z - vec3.z);
        }

        inline Vector3& operator -= (const Real a[3])
        {
            x -= a[0];
            y -= a[1];
            z -= a[2];
            return *this;
        }

        inline Vector3& operator -= (const Vector3& vec3)
        {
            x -= vec3.x;
            y -= vec3.y;
            z -= vec3.z;
            return *this;
        }

        inline Vector3 operator * (const Real scale)
        {
            return Vector3(x * scale, y * scale, z * scale);
        }

        inline Real operator * (const Vector3& vec3)
        {
          return x * vec3.x + y * vec3.y + z * vec3.z;
        }
        
        inline Vector3& operator *= (const Real real)
        {
            x *= real;
            y *= real;
            z *= real;
            return *this;
        }

        inline Vector3 operator / (const Real scale)
        {
            assert(scale != 0.0);
            return Vector3(x / scale, y / scale, z / scale);
        }

        inline Vector3& operator /= (const Real scale)
        {
            assert(scale != 0.0);
            x /= scale;
            y /= scale;
            z /= scale;
            return *this;
        }
        inline bool operator == (const Real a[3])
        {
            return (x == a[0]) && (y == a[1]) && (z == a[2]);
        }

        inline bool operator == (const Vector3& vec3)
        {
            return (x == vec3.x) && (y == vec3.y) && (z == vec3.z);
        }

        inline bool operator != (const Real a[3])
        {
            return (x != a[0]) || (y != a[1]) || (z != a[2]);
        }

        inline bool operator != (const Vector3& vec3)
        {
            return (x != vec3.x) || (y != vec3.y) || (z != vec3.z);
        }

        inline Real length()
        {
            return Math::Sqrt(x * x + y * y + z * z);
        }

		inline Real length() const
        {
            return Math::Sqrt(x * x + y * y + z * z);
        }

		void normalise()
		{
			Real len = length();
            assert(len != 0.0);
			x /= len;
			y /= len;
			z /= len;
		}
        
        inline Real dotProduct(const Vector3& other)
        {
            return x * other.x + y * other.y + z * other.z;
        }

		inline Real dotProduct(const Vector3& other) const
        {
            return x * other.x + y * other.y + z * other.z;
        }

        inline Vector3 crossProduct(const Vector3& other)
        {
          return Vector3(y * other.z - z * other.y,
                         z * other.x - x * other.z,
                         x * other.y - y * other.x);
        }

        Real operator [] (const Uint index)
        {
            assert(index < 3);
            switch(index)
            {
                case 0:
                return x;
                case 1:
                return y;
                case 2:
                return z;
            }
        }

        const Real operator [] (const int index) const
        {
            assert(index < 3);
            switch(index)
            {
                case 0:
                return x;
                case 1:
                return y;
                case 2:
                return z;
            }
        }

        inline friend std::ostream& operator << (std::ostream& os, const Vector3& vec3)
        {
            os << vec3.x <<" "<< vec3.y << " " <<vec3.z;
            return os;
        }
    };
}
#endif // GEVECTOR3_H_INCLUDED
