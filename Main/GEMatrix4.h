#ifndef GEMATRIX4_H_INCLUDED
#define GEMATRIX4_H_INCLUDED
#include "GEQuaternion.h"
#include "GEMatrix3.h"
#include "GEVector4.h"
namespace ge
{
  class Matrix4
  {
  public:
    Real m[4][4];
    /* default constructor function */
    Matrix4();
    Matrix4(const Matrix4& mat4);
    Matrix4(const Real mat[4][4]);
    Matrix4(const Matrix3& mat3);

    inline Real* operator[] (size_t index)
    {
      return (Real*)m[index];
    }

	inline Real* operator[] (size_t index) const
    {
      return (Real*)m[index];
    }

    Vector4 getColumn(size_t iCol);
    void setColumn(size_t iCol, const Vector4& vec4);

    Matrix4& operator = (const Matrix4& mat4);

    bool operator == (const Matrix4& mat4);
    bool operator != (const Matrix4& mat4)
    {
      return !operator == (mat4);
    }

    Matrix4 operator + (const Matrix4& mat4);
    Matrix4 operator - (const Matrix4& mat4);

    Matrix4 operator * (Real scale);
    Vector4 operator * (const Vector4& vec4);
    Matrix4 operator * (const Matrix4& mat4);
//    Vector4 operator * (const Vector4& vec4, const Matrix4& mat4);

    //Real deteminant();
    //Matrix4 transpose();
    //Matrix4 inverse();

    void setTransport(const Vector3& vec3);
    Vector3 getTransport();
    
    void setScale(const Vector3& vec3);
    Vector3 getScale();

    Matrix3 extractMatrix3();
    Quaternion extractQuaternion();
    
  };
  inline Vector4 operator * (const Vector4& vec4, const Matrix4& mat4)
  {
	  return Vector4(vec4[0] * mat4[0][0] + vec4[1] * mat4[1][0] + vec4[2] * mat4[2][0] + vec4[3] * mat4[3][0],
					vec4[0] * mat4[0][1] + vec4[1] * mat4[1][1] + vec4[2] * mat4[2][1] + vec4[3] * mat4[3][1],
					vec4[0] * mat4[0][2] + vec4[1] * mat4[1][2] + vec4[2] * mat4[2][2] + vec4[3] * mat4[3][2],
					vec4[0] * mat4[0][3] + vec4[1] * mat4[1][3] + vec4[2] * mat4[2][3] + vec4[3] * mat4[3][3]);
  }
}


#endif // GEMATRIX4_H_INCLUDED
