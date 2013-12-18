#include "GEMatrix3.h"
#include "GEMath.h"
using namespace ge;

Vector3 Matrix3 :: getColumn(size_t iCol) const
{
   return Vector3(m[iCol][0], m[iCol][1], m[iCol][2]);
}
void Matrix3 :: setColumn(size_t iCol, const Vector3& vec3)
{
   m[iCol][0] = vec3[0];
   m[iCol][1] = vec3[1];
   m[iCol][2] = vec3[2];
}

Matrix3& Matrix3 :: operator = (const Matrix3& mat3)
{
   for(size_t row = 0; row < 3; row++)
   {
      for(size_t col = 0; col < 3; col++)
      {
         m[row][col] = mat3[row][col];
      }
   }
   return *this;
}

bool Matrix3 :: operator == (const Matrix3& mat3)
{
   for(size_t row = 0; row < 3; row++)
   {
      for(size_t col = 0; col < 3; col++)
      {
         if(m[row][col] != mat3[row][col])
         {
            return false;
         }
      }
   }
   return true;
}

Matrix3 Matrix3 :: operator + ( const Matrix3& mat3)
{
   return Matrix3(m[0][0] + mat3[0][1], m[0][1] + mat3[0][1], m[0][2] + mat3[0][2],
                  m[1][0] + mat3[1][0], m[1][1] + mat3[1][1], m[1][2] + mat3[1][2],
                  m[2][0] + mat3[2][0], m[2][1] + mat3[2][1], m[2][2] + mat3[2][2]);
}

Matrix3 Matrix3 :: operator * (Real scale)
{
   return Matrix3(m[0][0] * scale, m[0][1] * scale, m[0][2] * scale,
                  m[1][0] * scale, m[1][1] * scale, m[1][2] * scale,
                  m[2][0] * scale, m[2][1] * scale, m[2][2] * scale);
}

Vector3 Matrix3 :: operator * (const Vector3& vec3)
{
   return Vector3(m[0][0] * vec3[0] + m[0][1] * vec3[1] + m[0][2] * vec3[2],
                  m[1][0] * vec3[0] + m[1][1] * vec3[1] + m[1][2] * vec3[2],
                  m[2][0] * vec3[0] + m[2][1] * vec3[1] + m[2][2] * vec3[2]);
}

Matrix3 Matrix3 :: operator * (const Matrix3& mat3)
{
   Vector3 col0;
   col0 = mat3.getColumn(0);
   Vector3 col1 = mat3.getColumn(1);
   Vector3 col2 = mat3.getColumn(2);

   Vector3 newCol0 = operator * (col0);
   Vector3 newCol1 = operator * (col1);
   Vector3 newCol2 = operator * (col2);

   Matrix3 newMat;
   newMat.setColumn(0, newCol0);
   newMat.setColumn(1, newCol1);
   newMat.setColumn(2, newCol2);
   return newMat;
}

Real Matrix3 :: determinant()
{
   return m[0][0] * m[1][1] * m[2][2] + m[0][2] * m[1][0] * m[2][1]
      + m[0][1] * m[1][2] * m[2][0] - m[0][2] * m[1][1] * m[2][0]
      - m[0][1] * m[1][0] * m[2][2] - m[0][0] * m[1][2] * m[2][1];
}

Matrix3 Matrix3 :: transpose()
{
   return Matrix3(m[0][0], m[1][0], m[2][0],
                  m[0][1], m[1][1], m[2][1],
                  m[0][2], m[1][2], m[2][2]);
}

Matrix3 Matrix3 :: inverse()
{
   Real det = determinant();
   assert(det != 0.0);
   Real m00 =  (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
   Real m01 = -(m[1][0] * m[1][2] - m[2][0] * m[1][2]) / det;
   Real m02 =  (m[1][0] * m[2][1] - m[2][0] * m[1][1]) / det;

   Real m10 = -(m[0][1] * m[2][2] - m[2][1] * m[0][2]) / det;
   Real m11 =  (m[0][0] * m[2][2] - m[2][0] * m[0][2]) / det;
   Real m12 = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]) / det;

   Real m20 =  (m[0][1] * m[1][2] - m[1][1] * m[0][2]) / det;
   Real m21 = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]) / det;
   Real m22 =  (m[0][0] * m[1][1] - m[1][0] * m[0][1]) / det;
   return Matrix3(m00, m01, m02,
                  m10, m11, m12,
                  m20, m21, m22);
}

Matrix3 Matrix3 :: orthonormalize()
{
   Vector3 vec0 = getColumn(0);
   Vector3 vec1 = getColumn(1);
   Vector3 vec2 = getColumn(2);
   vec0.normalise();
   vec1.normalise();
   vec2.normalise();
   Vector3 vec3 = vec1 - vec1 * (vec0 * vec1) / (vec0 * vec0);
   Vector3 vec4 = vec2 - vec1 * (vec0 * vec2) / (vec0 * vec0) - vec2 * (vec3 * vec2) / (vec2 * vec2);
   return Matrix3(vec0, vec3, vec4);
}

void Matrix3 :: fromQuaternion(const Quaternion& qtn)
{
   Real m00 = qtn.w * qtn.w + qtn.x * qtn.x - qtn.y * qtn.y - qtn.z * qtn.z;
   Real m01 = 2 * (qtn.x * qtn.y - qtn.w * qtn.z);
   Real m02 = 2 * (qtn.w * qtn.y + qtn.x * qtn.z);

   Real m10 = 2 * (qtn.x * qtn.y + qtn.w * qtn.z);
   Real m11 = qtn.w * qtn.w - qtn.x * qtn.x + qtn.y * qtn.y - qtn.z * qtn.z;
   Real m12 = 2 * (qtn.y * qtn.z - qtn.w * qtn.x);

   Real m20 = 2 * (qtn.x * qtn.z - qtn.w * qtn.y);
   Real m21 = 2 * (qtn.w * qtn.x + qtn.y * qtn.z);
   Real m22 = qtn.w * qtn.w - qtn.x * qtn.x - qtn.y * qtn.y + qtn.z * qtn.z;

   Matrix3 result(m00, m01, m02,
                  m10, m11, m12,
                  m20, m21, m22);

   operator = (result);
}

Quaternion Matrix3 :: toQuaternion()
{
   Real qw = Math :: Sqrt(1 + m[0][0] + m[1][1] + m[2][2]);
   Real qx = 0.25 * (m[2][1] - m[1][2]) / qw;
   Real qy = 0.25 * (m[0][2] - m[2][0]) / qw;
   Real qz = 0.25 * (m[1][0] - m[0][1]) / qw;
   return Quaternion(qx, qy, qz, qw);
}

Matrix3 Matrix3 :: _fromXAxisRotation(const Radian& rad)
{
   Real rs = Math::Sin(rad);
   Real rc = Math::Cos(rad);
   return Matrix3(1.0, 0.0, 0.0,
                  0.0,  rc, -rs,
                  0.0,  rs,  rc);
}

Matrix3 Matrix3 :: _fromYAxisRotation(const Radian& rad)
{
   Real rs = Math::Sin(rad);
   Real rc = Math::Cos(rad);
   return Matrix3( rc, 0.0,  rs,
                  0.0, 1.0, 0.0,
                   -rs, 0.0,  rc);
}

Matrix3 Matrix3 :: _fromZAxisRotation(const Radian& rad)
{
   Real rs = Math::Sin(rad);
   Real rc = Math::Cos(rad);
   return Matrix3( rc, -rs, 0.0,
                   rs,  rc, 0.0,
                   0.0, 0.0, 1.0);
}

void Matrix3 :: fromEuler(const Euler& eul)
{
   Matrix3 matx, maty, matz, result;
   matx = _fromXAxisRotation(eul.x);
   maty = _fromYAxisRotation(eul.y);
   matz = _fromZAxisRotation(eul.z);
   switch((Uint)eul.type)
   {
      case 0:
         result = matx * maty * matz;
         break;
      case 1:
         result = matx * matz * maty;
         break;
      case 2:
         result = maty * matx * matz;
         break;
      case 3:
         result = maty * matz * matx;
         break;
      case 4:
         result = matz * matx * maty;
         break;
      case 5:
         result = matz * maty * matx;
         break;
      default:
         result = matx * maty * matz;
         break;
   }
   operator = (result);
}

