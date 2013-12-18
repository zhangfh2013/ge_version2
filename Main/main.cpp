#include <iostream>
#include "GEMath.h"
#include "GEVector2.h"
using namespace std;
using namespace ge;
int main()
{
    Radian rad(30.0);
    cout<<rad / 3<<endl;
 //   cout<<rad / 0<<endl;
    cout<<rad<<endl;
    Vector2 v1(0.0, 1.0);
    Vector2 v2(1.0, 0.0);
    cout<<2.0 * v2<<endl;
    cout<<v1.getRadianBetween(v2)<<endl;
    cout << "Hello world!" << endl;

	system("pause");
    return 0;
}
