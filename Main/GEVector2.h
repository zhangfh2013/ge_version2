#ifndef GEVECTOR2_H_INCLUDED
#define GEVECTOR2_H_INCLUDED
#include "GEPrerequires.h"
#include "GEMath.h"
namespace ge
{
    class Vector2
    {
        public:
        Real x, y;

        public:
        inline Vector2(Real fx = 0.0, Real fy = 0.0):x(fx), y(fy){}
        inline Vector2(const Vector2& vec2):x(vec2.x), y(vec2.y){}
        inline Vector2(const Real a[2]):x(a[0]), y(a[1]){}
        inline Vector2(Real* const a):x(a[0]), y(a[1]){}

        Vector2& operator = (const Vector2& vec2)
        {
            x = vec2.x;
            y = vec2.y;
            return *this;
        }

        Vector2& operator = (const Real a[2])
        {
            x = a[0];
            y = a[1];
            return *this;
        }

        Vector2& operator = (Real* const a)
        {
            x = a[0];
            y = a[1];
            return *this;
        }

        //arithmetic operation
        inline Vector2 operator + (const Vector2& vec2)
        {
            return Vector2(x + vec2.x, y + vec2.y);
        }

        inline Vector2& operator += (const Vector2& vec2)
        {
            x += vec2.x;
            y += vec2.y;
            return *this;
        }

        inline Vector2 operator - ()
        {
            return Vector2(0.0 - x, 0.0 - y);
        }

        inline Vector2 operator - (const Vector2& vec2)
        {
            return Vector2(x - vec2.x, y - vec2.y);
        }

        inline Vector2& operator -= (const Vector2& vec2)
        {
            x -= vec2.x;
            y -= vec2.y;
            return *this;
        }

        inline Vector2 operator * (const Real scale)
        {
            return Vector2(x * scale, y * scale);
        }

        inline friend Vector2 operator * (const Real scale, const Vector2& vec2)
        {
            return Vector2(scale * vec2.x, scale * vec2.y);
        }

        inline Vector2& operator *= (const Real scale)
        {
            x *= scale;
            y *= scale;
            return *this;
        }

        inline Vector2 operator / (const Real scale)
        {
            assert(scale != 0.0);
            return Vector2(x / scale, y / scale);
        }

        inline Vector2& operator /= (const Real scale)
        {
            assert(scale != 0.0);
            x /= scale;
            y /= scale;
            return *this;
        }

        //Logical operation
        inline bool operator == (const Vector2& vec2)
        {
            return (x == vec2.x) && (y == vec2.y);
        }

        inline bool operator != (const Vector2& vec2)
        {
            return (x != vec2.x) || (y != vec2.y);
        }

        inline bool operator >= (const Vector2& vec2)
        {
            return (x >= vec2.x && y >= vec2.y);
        }

        inline bool operator >  (const Vector2& vec2)
        {
            return (x > vec2.x && y >= vec2.y);
        }

        inline bool operator <= (const Vector2& vec2)
        {
            return (x <= vec2.x && y <= vec2.y);
        }

        inline bool operator <  (const Vector2& vec2)
        {
            return (x < vec2.x && y < vec2.y);
        }


        //
        inline Real length() const
        {
            return Math::Sqrt(x * x + y * y);
        }

//        inline Real getNomal()
//        {
//            return length();
//        }


        inline void nomalise()
        {
            Real len = length();

            assert(len != 0.0);
            x /= len;
            y /= len;
        }

        inline Real dotProduct(const Vector2& rhs)
        {
            return x * rhs.x + y * rhs.y;
        }

        inline Real distance(const Vector2& other)
        {
            return (*this - other).length();
        }

        Radian getRadianBetween(const Vector2& other)
        {
            Real numerator = this->dotProduct(other);
            Real denominator = this->length() * other.length();
            if(denominator < 1e-6)
            {
                denominator = 1e-6;
            }
            return Radian(Math::ACos(numerator / denominator));
        }



        inline friend std::ostream& operator<< (std::ostream& os, const Vector2& vec2)
        {
            os<<vec2.x<<" "<<vec2.y;
            return os;
        }
    };
}


#endif // GEVECTOR2_H_INCLUDED
