#pragma once
#include <math.h>
#include<algorithm>

class Vector3
{
public:
    double X;
    double Y;
    double Z;
    double Magnitude;

    void Add(Vector3 NewVector)
    {
        this->X += NewVector.X;
        this->Y += NewVector.Y;
        this->Z += NewVector.Z;
        Update();
    }
    void Subtract(Vector3 NewVector)
    {
        this->X -= NewVector.X;
        this->Y -= NewVector.Y;
        this->Z -= NewVector.Z;
        Update();
    }
    void Mult(double Value) {
        this->X *= Value;
        this->Y *= Value;
        this->Z *= Value;
        Update();
    }
    void Div(double Value) {
        this->X /= Value;
        this->Y /= Value;
        this->Z /= Value;
        Update();
    }
    void Update() {
        this->Magnitude = sqrt(X * X + Y * Y + Z * Z);
    }
    Vector3(double NX, double NY, double NZ)
    {
        this->X = NX;
        this->Y = NY;
        this->Z = NZ;
        Update();
    }
    Vector3()
    {
        this->X = 0;
        this->Y = 0;
        this->Z = 0;
        Update();
    }
};
class CFrame {
public:
    //Postion
    double X, Y, Z;
    //Vector 
    Vector3 Vector;
    //Euler Angles
    double Alpha;
    double Beta;
    double Gamma;
    // Rotation Matrix
    double RotationMatrix[3][3];
    //Deafult Constructor
    CFrame() {
        UpdateAll();
    }
    //Constructor without angles
    CFrame(double NX, double NY, double NZ) {
        this->X = NX;
        this->Y = NY;
        this->Z = NZ;

        UpdateAll();
    }
    //Constructor with Angles
    CFrame(double NX, double NY, double NZ, double Alpha, double Beta, double Gamma) {
        this->X = NX;
        this->Y = NY;
        this->Z = NZ;

        this->Alpha = Alpha;
        this->Beta = Beta;
        this->Gamma = Gamma;
        UpdateAll();
    }
    //Constructor using a vector3
    CFrame(Vector3 Vector) {
        SetPos(Vector);
        UpdateAll();
    }
    //Sets Postion Using a vector
    void SetPos(Vector3 Vector) {
        this->X = Vector.X;
        this->Y = Vector.Y;
        this->Z = Vector.Z;
        UpdatePostition();
    }
    //Adds Vector to CFrame (non directional)
    void AddPos(Vector3 Vector) {
        this->Vector.Add(Vector);
        UpdatePostition();
    }
    //Turns the euler angles stored into a rotation matrix set in the Za Xb Yg formation
    void UpdateMatrix() {
        double ca = cos(Alpha), sa = sin(Alpha);
        double cb = cos(Beta), sb = sin(Beta);
        double cy = cos(Gamma), sy = sin(Gamma);

        double Temp[3][3] = {
            {ca * cy - sa * sb * sy,-cb * sa,ca * sy + cy * sa * sb},
            {cy * sa + ca * sb * sy,ca * cb,sa * sy - ca * cy * sb},
            {-cb * sy,sb,cb * cy}
        };
        std::copy(&Temp[0][0], &Temp[0][0] + 9, &this->RotationMatrix[0][0]);
    }
    //turns matrix into euler angles
    void UpdateEuler() {
        this->Alpha = atan(-RotationMatrix[0][1] / RotationMatrix[1][1]);
        this->Beta = asin(RotationMatrix[2][1]);
        this->Gamma = atan(-RotationMatrix[2][0] / RotationMatrix[2][2]);
    }
    //Updates All Values 
    void UpdateAll() {
        UpdateRotation();
        UpdatePostition();
    }
    //Updates Only Position Related ELements
    void UpdatePostition() {
        this->Vector = Vector3(X, Y, Z);
    }
    //Updates Only Rotation Related ELements
    void UpdateRotation() {
        UpdateMatrix();
        UpdateEuler();
    }
};
class Color3 {
public:
    int RGB[3];

    int Red;
    int Green;
    int Blue;

    Color3() {}
    Color3(int R, int G, int B) {
        this->RGB[0] = R;
        this->RGB[1] = G;
        this->RGB[2] = B;

        this->Red = R;
        this->Green = G;
        this->Blue = B;
    }
};



class Object {
public:
    char Name[100] = "Object"; //Max 99 characters due to the null at the end of a char array
    float Transparency = 0; //Range 1-0
    Color3 Color = Color3(255, 255, 255);
    Vector3 Size = Vector3(5, 5, 5);
    CFrame Position = CFrame(0, 0, 0);
    char Shape[100] = "Cube";

};
