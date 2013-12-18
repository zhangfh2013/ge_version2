#ifndef GEMATRIX3_H_INCLUDED
#define GEMATRIX3_H_INCLUDED
#include "GEPrerequires.h"
#include "GEVector3.h"
#include "GEQuaternion.h"
#include "GEEuler.h"

namespace ge
{
  class Matrix3
  {
  public:
    Real m[3][3];

    inline Matrix3()
    {
      m[0][0] = 1.0;
      m[0][1] = 0.0;
      m[0][2] = 0.0;

      m[1][0] = 0.0;
      m[1][1] = 1.0;
      m[1][2] = 0.0;

      m[2][0] = 0.0;
      m[2][1] = 0.0;
      m[2][2] = 1.0;
    }

    inline explicit Matrix3 (const Real mat[3][3])
    {
      m[0][0] = mat[0][0];
      m[0][1] = mat[0][1];
      m[0][2] = mat[0][2];

      m[1][0] = mat[1][0];
      m[1][1] = mat[1][1];
      m[1][2] = mat[1][2];

      m[2][0] = mat[2][0];
      m[2][1] = mat[2][1];
      m[2][2] = mat[2][2];
    }

    Matrix3(Real f00, Real f01, Real f02,
            Real f10, Real f11, Real f12,
            Real f20, Real f21, Real f22)
    {
      m[0][0] = f00;
      m[0][1] = f01;
      m[0][2] = f02;

      m[1][0] = f10;
      m[1][1] = f11;
      m[1][2] = f12;

      m[2][0] = f20;
      m[2][1] = f21;
      m[2][2] = f22;
    }

    Matrix3(const Vector3& vec0, const Vector3& vec1, const Vector3& vec2)
    {
      m[0][0] = vec0[0];
      m[0][1] = vec0[1];
      m[0][2] = vec0[2];

      m[1][0] = vec1[0];
      m[1][1] = vec1[1];
      m[1][2] = vec1[2];

      m[2][0] = vec2[0];
      m[2][1] = vec2[1];
      m[2][1] = vec2[2];
    }
    

    Matrix3(const Matrix3& mat3)
    {
      m[0][0] = mat3.m[0][0];
      m[0][1] = mat3.m[0][1];
      m[0][2] = mat3.m[0][2];

      m[1][0] = mat3.m[1][0];
      m[1][1] = mat3.m[1][1];
      m[1][2] = mat3.m[1][2];

      m[2][0] = mat3.m[2][0];
      m[2][1] = mat3.m[2][1];
      m[2][2] = mat3.m[2][2];
    }

	inline Real* operator[] (size_t index) const
    {
      return  (Real*)m[index];
    }
    
	Vector3 getColumn(size_t iCol) const;
    void setColumn(size_t iCol, const Vector3& vec3);

    Matrix3& operator = (const Matrix3& mat3);

    bool operator == (const Matrix3& mat3);
    inline bool operator != (const Matrix3& mat3)
    {
      return !operator==(mat3);
    }
    
    Matrix3 operator + (const Matrix3& mat3);
    Matrix3 operator - (const Matrix3& mat3);

    Matrix3 operator * (Real scale);
    Vector3 operator * (const Vector3& vec3);
    Matrix3 operator * (const Matrix3& mat3);
    
    
    Real determinant();
    Matrix3 transpose();
    Matrix3 inverse();
    Matrix3 orthonormalize();

    void fromQuaternion(const Quaternion& qtn);
    void fromEuler(const Euler& eul);
    
    Quaternion toQuaternion();

  private:
    Matrix3 _fromXAxisRotation(const Radian& rad);
    Matrix3 _fromYAxisRotation(const Radian& rad);
    Matrix3 _fromZAxisRotation(const Radian& rad);
    
  };

  inline Vector3 operator * (const Vector3& vec3, const Matrix3& mat3)
  {
	  return Vector3(vec3[0] * mat3[0][0] + vec3[1] * mat3[1][0] + vec3[2] * mat3[2][0],
					vec3[0] * mat3[0][1] + vec3[1] * mat3[1][1] + vec3[2] * mat3[2][1],
					vec3[0] * mat3[0][2] + vec3[1] * mat3[1][2] + vec3[2] * mat3[2][2]);
  }
}



#endif // GEMATRIX3_H_INCLUDED
