#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

#define PI 3.14159265

class vector
{
private:
    float x = 0;

    float y = 0;

    float z = 0;

    float mod = 0;

    float dot;

public:
    vector();
    vector(float r, float anglex, float anglez);
    vector(float a, float b, float c , int indetity);
    void vectordef(float x, float y, float z);
    void addition(vector v1, vector v2);
    void dotproduct(vector v1, vector v2);
    void magnitude(vector v1, vector v2);
    void anglebetween(vector v1, vector v2);
    void cross(vector v1, vector v2);
    ~vector();
};

vector::vector(float r, float anglez, float anglex)
{
    cout << "Anglex : "<<anglex;
    cout << "Anglez : "<<anglez;

    z = r * cos ((anglez * PI)/ 180.0 );
    if (anglez == 90.0){
        z = 0;
    }
    float proj = r * (sin ((anglez * PI) / 180.0) );
    if (anglez == 0){
        proj = 0;
    }
    x = proj* cos ((anglex * PI )/ 180.0);
    if (anglex == 90.0){
        x = 0;
    }
    y = proj* sin ((anglex * PI )/ 180.0);
    if (anglex == 0){
        y = 0;
    }
    
}
vector::vector(float a, float b, float c , int indetity)
{
    x = a;
    y = b;
    z = c;
    mod = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
}
vector::vector()
{}

void vector::vectordef(float x, float y, float z)
{
    cout << x << " i " << y << " j " << z << " k ";
}
void vector ::magnitude(vector v1, vector v2)
{
    cout << " The magnitude of vector: ";
    vectordef(v1.x, v1.y, v1.z);
    cout << " = " << v1.mod << endl;
    cout << " The magnitude of vector: ";
    vectordef(v2.x, v2.y, v2.z);
    cout << " = " << v2.mod << endl;
}
void vector ::addition(vector v1, vector v2)
{
    int a = v1.x + v2.x;
    int b = v1.y + v2.y;
    int c = v1.z + v2.z;
    cout << "The sum of vectors: " << endl;
    vectordef(v1.x, v1.y, v1.z);
    cout << endl;
    vectordef(v2.x, v2.y, v2.z);
    cout << endl <<" is: "
         << a << " i " << b << " j " << c << " k ";
}
void vector ::dotproduct(vector v1, vector v2)
{
    dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    cout << "The dot product of vectors: " << endl;
    vectordef(v1.x, v1.y, v1.z);
    cout << endl;
    vectordef(v2.x, v2.y, v2.z);
    cout << endl <<" is: "
         << dot;
}

void vector ::anglebetween(vector v1, vector v2)
{
    cout << v1.mod;
    cout << v2.mod;
    cout << (dot / (v1.mod * v2.mod));
    cout << "The angle between the vectors: " << endl;
    vectordef(v1.x, v1.y, v1.z);
    cout << endl;
    vectordef(v2.x, v2.y, v2.z);
    cout << endl <<" in principal domain is: " << (180 / PI) * (acos(dot / (v1.mod * v2.mod)));
}
void vector ::cross(vector v1, vector v2)
{
    int a = (v1.x * v2.y) - (v2.x * v1.y);
    int b = -1 * ((v1.x * v2.z) - (v2.x * v1.z));
    int c = (v1.x * v2.y) - (v2.x * v1.y);

    cout << "The corss product of the vectors: " << endl;
    vectordef(v1.x, v1.y, v1.z);
    cout << endl;
    vectordef(v2.x, v2.y, v2.z);
    cout << endl <<" is: ";

    if (a == 0 && b == 0 && c == 0)
        cout << "A null vector. ";
    else
        cout << a << " i " << b << " j " << c << " k " << endl;
}

vector::~vector()
{
}

int main()
{
    cout << "Welcome to my vector calculator!! " << endl
         << "Please enter 1 to enter your vector values in magnitude and angle form or ";
    cout << endl
         << "else 2 to enter them in unit vector form here: " << flush;
    int n;
    cin >> n;
    float mag1, mag2, angle1, angle2, angle3 , angle4;
    float x1, y1, z1, x2, y2, z2;
    if (n == 1)
    {
        cout << "Please enter the magnitude of vector 1: " << flush;
        cin >> mag1;
        cout<<"Please enter the angle of vector 1 with respect to z-axis: "<<flush;
        cin>>angle1;
        cout<<"Please enter the angle of vector 1's projection with to x-axis: "<<flush;
        cin>>angle2;

        cout << "Please enter the magnitude of vector 2: " << flush;
        cin >> mag2;
        cout<<"Please enter the angle of vector 2 with respect to z-axis: "<<flush;
        cin>>angle3;
        cout<<"Please enter the angle of vector 2's projection with to x-axis: "<<flush;
        cin>>angle4;

        vector v1(mag1, angle1 ,angle2), v2(mag2, angle3 ,angle4), v3;
        v3.addition(v1, v2);
        cout << endl
             << "=============================================" << endl;
        v3.dotproduct(v1, v2);
        cout << endl
             << "=============================================" << endl;
        v3.anglebetween(v1, v2);
        cout << endl
             << "=============================================" << endl;
        v3.cross(v1, v2);
        cout << endl
             << "=============================================" << endl;
    }
    else if (n == 2)
    {
        cout << "Please enter the components of vector 1 in order of x,y and z: " << flush;
        cin >> x1 >> y1 >> z1;
        cout << "Please enter the components of vector 2 in order of x,y and z: " << flush;
        cin >> x2 >> y2 >> z2;
        int ident = 0;
        vector v4(x1, y1, z1 , ident), v5(x2, y2, z2 , ident), v6;
        v6.magnitude(v4, v5);
        cout << endl
             << "=============================================" << endl;
        v6.addition(v4, v5);
        cout << endl
             << "=============================================" << endl;
        v6.dotproduct(v4, v5);
        cout << endl
             << "===============================================" << endl;
        v6.anglebetween(v4, v5);
        cout << endl
             << "=============================================" << endl;
        v6.cross(v4, v5);
        cout << endl
             << "=============================================" << endl;
    }
    else
    {
        cout << "enter correct input!!!";
    }

    return 0;
}