#include "GEMatrix4.h"

using namespace ge;

Matrix4 :: Matrix4()
{
   for(size_t row = 0; row < 4; row++)
   {
      for(size_t col = 0; col < 4; col++)
      {
         if(row == col)
         {
            m[row][col] = 1.0;
         }
         else
         {
            m[row][col] = 0.0;
         }
      }
   }
}

Matrix4 :: Matrix4(const Matrix4& mat4)
{
   for(size_t row = 0; row < 4; row++)
   {
      for(size_t col = 0; col < 4; col++)
      {
         m[row][col] = mat4[row][col];
      }
   }
}

Matrix4 :: Matrix4(const Real mat[4][4])
{
   for(size_t row = 0; row < 4; row++)
   {
      for(size_t col = 0; col < 4; col++)
      {
         m[row][col] = mat[row][col];
      }
   }
}

Matrix4 :: Matrix4(const Matrix3& mat3)
{
   for(size_t row = 0; row < 3; row++)
   {
      for(size_t col = 0; col < 3; col++)
      {
         m[row][col] = mat3[row][col];
      }
   }
   m[0][3] = 0.0;
   m[1][3] = 0.0;
   m[2][3] = 0.0;

   m[3][0] = 0.0;
   m[3][1] = 0.0;
   m[3][2] = 0.0;

   m[3][3] = 1.0;
}

Vector4 Matrix4::getColumn(size_t iCol)
{
   return Vector4(m[0][iCol], m[1][iCol], m[2][iCol], m[3][iCol]);
}

void Matrix4::setColumn(size_t iCol, const Vector4& vec4)
{
   m[0][iCol] = vec4[0];
   m[1][iCol] = vec4[1];
   m[2][iCol] = vec4[2];
   m[3][iCol] = vec4[3];
}

Matrix4& Matrix4 :: operator = (const Matrix4& mat4)
{
   for(size_t row = 0; row < 4; row++)
   {
      for(size_t col = 0; col < 4; col++)
      {
         m[row][col] = mat4[row][col];
      }
   }
   return *this;
}

bool Matrix4 :: operator == (const Matrix4& mat4)
{
   for(size_t row = 0; row < 4; row++)
   {
      for(size_t col = 0; col < 4; col++)
      {
         if(m[row][col] != mat4[row][col])
         {
            return false;
         }
      }
   }
   return true;
}

Matrix4 Matrix4 :: operator + (const Matrix4& mat4)
{
   Real mat[4][4];
   for(size_t row = 0; row < 4; row++)
   {
      for(size_t col = 0; col < 4; col++)
      {
         mat[row][col] = m[row][col] + mat4[row][col];
      }
   }
   return Matrix4(mat);
}

Matrix4 Matrix4 :: operator - (const Matrix4& mat4)
{
   Real mat[4][4];
   for(size_t row = 0; row < 4; row++)
   {
      for(size_t col = 0; col < 4; col++)
      {
         mat[row][col] = m[row][col] - mat4[row][col];
      }
   }
   return Matrix4(mat);
}

Matrix4 Matrix4 :: operator * (Real scale)
{
   Real mat[4][4];
   for(size_t row = 0; row < 4; row++)
   {
      for(size_t col = 0; col < 4; col++)
      {
         mat[row][col] = m[row][col] * scale;
      }
   }
   return Matrix4(mat);
}

Vector4 Matrix4 :: operator * (const Vector4& vec4)
{
   return Vector4(m[0][0] * vec4[0] + m[0][1] * vec4[1] + m[0][2] * vec4[2] + m[0][3] * vec4[3],
                  m[1][0] * vec4[0] + m[1][1] * vec4[1] + m[1][2] * vec4[2] + m[1][3] * vec4[3],
                  m[2][0] * vec4[0] + m[2][1] * vec4[1] + m[2][2] * vec4[2] + m[2][3] * vec4[3],
                  m[3][0] * vec4[0] + m[3][1] * vec4[1] + m[3][2] * vec4[2] + m[3][3] * vec4[3]);
}

//Real Matrix4 :: deteminant()
//{
//}

//Matrix4 Matrix4 :: transpose()
//{
//}
//
//Matrix4 Matrix4 :: inverse()
//{
//
//}

void Matrix4 :: setTransport(const Vector3& vec3)
{
   m[3][0] = vec3[0];
   m[3][1] = vec3[1];
   m[3][2] = vec3[2];
}

Vector3 Matrix4 :: getTransport()
{
   return Vector3(m[3][0], m[3][1], m[3][2]);
}

void Matrix4 :: setScale(const Vector3& vec3)
{
   m[0][0] = vec3[0];
   m[1][1] = vec3[1];
   m[2][2] = vec3[2];
}

Vector3 Matrix4 :: getScale()
{
   return Vector3(m[0][0], m[1][1], m[2][2]);
}

Matrix3 Matrix4 :: extractMatrix3()
{
   return Matrix3(m[0][0], m[0][1], m[0][2],
                  m[1][0], m[1][1], m[1][2],
                  m[2][0], m[2][1], m[2][2]);
}

Quaternion Matrix4 :: extractQuaternion()
{
   Matrix3 mat3 = extractMatrix3();
   Quaternion qtn = mat3.toQuaternion();
   return qtn;
}
