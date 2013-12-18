#ifndef GEMATH_H_INCLUDED
#define GEMATH_H_INCLUDED
#include "GEPrerequires.h"
#include <cmath>
namespace ge
{
  class Ray;
  class Plane;
  class Sphere;
  class AxisAlignedBox;
class Degree;
class Radian
{
private:
    Real mRad;

public:
    inline explicit Radian(Real r = 0.0):mRad(r) {}
    Radian(const Degree&);

    inline Radian& operator = (Real r){mRad  = r; return *this;}
    inline Radian& operator = (const Radian& rad){mRad = rad.mRad; return *this;}
    inline Radian& operator = (const Degree&);

    inline Real getValue(){return mRad;}
    inline Real getValue() const {return mRad;}
    inline void setValue(Real value){mRad = value;}
    inline void setValue(const Radian& rad){mRad = rad.mRad;}
    inline void setValue(const Degree&);



//    inline Radian operator + (const Real& r){return Radian(mRad + r);}
    inline Radian operator + (const Radian& rad){return Radian(mRad + rad.mRad);}
    inline Radian operator + (const Degree&);

    inline Radian& operator += (const Radian rad){mRad += rad.mRad; return *this;}
    Radian& operator += (const Degree&);

    inline Radian operator - (){return Radian(0 - mRad);}
    inline Radian operator - (const Radian rad){return Radian(mRad - rad.mRad);}
    Radian operator - (const Degree& deg);

    inline Radian& operator -= (const Radian& rad){mRad -= rad.mRad; return *this;}
    Radian& operator -= (const Degree& deg);

    inline Radian operator * (const Real r){return Radian(mRad * r);}
	inline Radian operator * (const Real r) const {return Radian(mRad * r);}

    inline Radian& operator *= (const Real r){mRad *= r;return *this;}

    inline Radian operator / (const Real r){assert( r != 0.0);return Radian(mRad / r);}

    inline Radian& operator /= (const Real r){assert(r != 0.0); mRad /= r; return *this;}

    inline bool operator == (const Radian& rad){return (mRad == rad.mRad);}
    inline bool operator != (const Radian& rad){return (mRad != rad.mRad);}
    inline bool operator <  (const Radian& rad){return (mRad <  rad.mRad);}
    inline bool operator <= (const Radian& rad){return (mRad <= rad.mRad);}
    inline bool operator >= (const Radian& rad){return (mRad >= rad.mRad);}
    inline bool operator >  (const Radian& rad){return (mRad >  rad.mRad);}

    inline friend std::ostream& operator << (std::ostream& os, const Radian& rad)
    {
        os << rad.mRad;
        return os;
    }
};

class Degree
{
private:
    Real mDeg;

public:
    inline explicit Degree(Real r = 0.0):mDeg(r){}
    Degree(const Degree& deg):mDeg(deg.mDeg){}
    Degree(const Radian& rad){mDeg = 180.0 * rad.getValue() / PI;}


    inline Real getValue(){return mDeg;}
    inline Real getValue() const {return mDeg;}
    inline void SetValue(const Real deg){mDeg = deg;}
    inline void SetValue(const Degree& deg){mDeg = deg.mDeg;}
    inline void setValue(const Radian& rad){mDeg = 180 * rad.getValue() / PI;}


    inline Degree& operator = (const Degree& deg){mDeg = deg.mDeg; return *this;}
    inline Degree& operator = (const Radian& rad){mDeg = 180 * rad.getValue() / PI; return *this;}

    inline Degree operator + (const Degree& deg){return Degree(mDeg + deg.mDeg);}
    inline Degree operator + (const Radian& rad){return Degree(mDeg + 180 * rad.getValue() / PI);}

    inline Degree& operator += (const Degree& deg){mDeg += deg.mDeg; return *this;}
    inline Degree& operator += (const Radian& rad){mDeg += 180 * rad.getValue() / PI; return *this;}

//    inline Degree operator - (const Real r){return Degree(mDeg - r);}
    inline Degree operator - (const Degree& deg){return Degree(mDeg - deg.mDeg);}
    inline Degree operator - (const Radian& rad){return Degree(mDeg - 180 * rad.getValue() / PI);}

//    inline Degree& operator -= (const Real r){mDeg -= r; return *this;}
    inline Degree& operator -= (const Degree& deg){mDeg -= deg.mDeg; return *this;}
    inline Degree& operator -= (const Radian& rad){mDeg -= 180 * rad.getValue() / PI; return *this;}

    inline Degree operator * (const Real r){return Degree(mDeg * r);}
	inline Degree operator * (const Real r) const {return Degree(mDeg * r);}
//	inline Degree operator * (const Real r, const Degree deg){return Degree(r * deg.mDeg);}
    inline Degree& operator *= (const Real r){mDeg *= r; return *this;}

    inline Degree operator / (const Real r){assert( r != 0.0); return Degree(mDeg / r);}

    inline Degree& operator /= (const Real r){assert(r != 0.0); mDeg /= r; return *this;}

    inline bool operator == (const Degree& deg){return (mDeg == deg.mDeg);}
    inline bool operator != (const Degree& deg){return (mDeg != deg.mDeg);}
    inline bool operator <  (const Degree& deg){return (mDeg <  deg.mDeg);}
    inline bool operator <= (const Degree& deg){return (mDeg <= deg.mDeg);}
    inline bool operator >= (const Degree& deg){return (mDeg >= deg.mDeg);}
    inline bool operator >  (const Degree& deg){return (mDeg >  deg.mDeg);}

    inline friend std::ostream& operator << (std::ostream& os, const Degree & deg)
    {
        os << deg.mDeg;
        return os;
    }
};

class Math
{
    public:
  static inline Real Abs(Real value)
  {
    return value > 0.0 ? value : -value;
  }
  
    static inline Real Sqrt(Real value)
    {
        return sqrt(value);
    }

    static inline Real Square(Real r)
    {
        return r * r;
    }

    static inline Radian ASin(Real r)
    {
        return Radian(asin(r));
    }

    static inline Radian ACos(Real r)
    {
        return Radian(acos(r));
    }

    static inline Radian ATan(Real r)
    {
        return Radian(atan(r));
    }

    static inline Radian ATan2(Real y, Real x)
    {
        return Radian(atan2(y, x));
    }

    static inline Real Sin(const Radian& rad)
    {
        return sin(rad.getValue());
    }

    static inline Real Sin(const Degree& deg)
    {
        return sin(deg.getValue() * PI / 180.0);
    }

    static inline Real Cos(const Radian& rad)
    {
        return cos(rad.getValue());
    }

    static inline Real Cos(const Degree& deg)
    {
        return cos(deg.getValue() * PI / 180.0);
    }

    static inline Real Tan(const Radian& rad)
    {
        return tan(rad.getValue());
    }

    static inline Real Tan(const Degree& deg)
    {
        return tan(deg.getValue() * PI / 180.0);
    }

    static bool intersected(const Ray& ray, const Plane& plane);

    static bool intersected(const Ray& ray, const Sphere& sphere);

    static bool intersected(const Plane& plane, const Sphere& sphere);

    static bool intersected(const Plane& plane, const AxisAlignedBox& box);

    static bool intersected(const Sphere& sphere01, const Sphere& sphere02);

    static bool intersected(const Sphere& sphere, const AxisAlignedBox& box);

    static bool intersected(const AxisAlignedBox& box01, const AxisAlignedBox& box02);

    


};
}


#endif // GEMATH_H_INCLUDED
