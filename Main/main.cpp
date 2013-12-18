#include <iostream>
#include "GEMath.h"
#include "GEVector2.h"
#include "GEVector3.h"
#include "GEVector4.h"
using namespace std;
using namespace ge;
int main()
{
    Radian rad(30.0);
    cout<<rad / 3<<endl;
 //   cout<<rad / 0<<endl;
    cout<<rad<<endl;

    Vector2 v2(1.0, 2.0);
	cout<<v2<<endl;
	Vector3 v3(1.0, 2.0, 3.0);
	cout<<v3<<endl;
	Vector4 v4(1.0, 2.0, 3.0, 4.0);
	cout<<v4<<endl;
    cout<<2.0 * v2<<endl;
    cout << "Hello world!" << endl;

	system("pause");
    return 0;
}
