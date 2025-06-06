#pragma once
#include <math.h>
#include<algorithm>
#include "Functions.h"


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
        UpdateVector();
    }
    //Adds Vector to CFrame (non directional)
    void AddPos(Vector3 NewVector) {
        this->Vector.Add(NewVector);
        UpdateBaseValues();
    }
    void UpdateBaseValues() {
        this->X = Vector.X;
        this->Y = Vector.Y;
        this->Z = Vector.Z;
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
        UpdateVector();
    }
    //Updates Only Position Related ELements
    void UpdateVector() {
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

    int Red = 255;
    int Green = 255;
    int Blue = 255;

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
        Vector3 RelativeVertices[99]; //store in relation to the object
        CFrame AbsoluteVertices[99]; //store in relation to the object
        Vector3 RelTriangles[99][3];
        CFrame AbsTriangles[99][3];
};

class Cube : public Object {
    public:
        void CreateRelVert(){
            this->RelativeVertices[0] = Vector3(Size.X / 2,Size.Y/2, Size.Z / 2); //+++
            this->RelativeVertices[1] = Vector3(Size.X / 2, Size.Y / 2, -Size.Z / 2);//++-
            this->RelativeVertices[2] = Vector3(Size.X / 2, -Size.Y / 2, Size.Z / 2);//+-+
            this->RelativeVertices[3] = Vector3(Size.X / 2, -Size.Y / 2, -Size.Z / 2);//+--
            this->RelativeVertices[4] = Vector3(-Size.X / 2, Size.Y / 2, Size.Z / 2);//-++
            this->RelativeVertices[5] = Vector3(-Size.X / 2, Size.Y / 2, -Size.Z / 2);//-+-
            this->RelativeVertices[6] = Vector3(-Size.X / 2, -Size.Y / 2, Size.Z / 2);//--+
            this->RelativeVertices[7] = Vector3(-Size.X / 2, -Size.Y / 2, -Size.Z / 2);//---
            
            ApplyRotation();
            CreateAbsVert();
        }
        void ApplyRotation() {
            for (int i = 0; i < 8; i++) {
                double Small[3] = {RelativeVertices[i].X,RelativeVertices[i].Y,RelativeVertices[i].Z};
                MultMatrix(Small, Position.RotationMatrix);
                RelativeVertices[i].X = Small[0];
                RelativeVertices[i].Y = Small[1];
                RelativeVertices[i].Z = Small[2];
            }
        }
        void CreateRelTriangles(){
            RelTriangles[0][0] = RelativeVertices[0];
            RelTriangles[0][1] = RelativeVertices[2];
            RelTriangles[0][2] = RelativeVertices[4];

            RelTriangles[1][0] = RelativeVertices[4];
            RelTriangles[1][1] = RelativeVertices[2];
            RelTriangles[1][2] = RelativeVertices[6];

            RelTriangles[2][0] = RelativeVertices[1];
            RelTriangles[2][1] = RelativeVertices[5];
            RelTriangles[2][2] = RelativeVertices[3];

            RelTriangles[3][0] = RelativeVertices[3];
            RelTriangles[3][1] = RelativeVertices[5];
            RelTriangles[3][2] = RelativeVertices[7];

            RelTriangles[4][0] = RelativeVertices[0];
            RelTriangles[4][1] = RelativeVertices[4];
            RelTriangles[4][2] = RelativeVertices[1];

            RelTriangles[5][0] = RelativeVertices[1];
            RelTriangles[5][1] = RelativeVertices[4];
            RelTriangles[5][2] = RelativeVertices[5];

            RelTriangles[6][0] = RelativeVertices[2];
            RelTriangles[6][1] = RelativeVertices[3];
            RelTriangles[6][2] = RelativeVertices[6];

            RelTriangles[7][0] = RelativeVertices[6];
            RelTriangles[7][1] = RelativeVertices[3];
            RelTriangles[7][2] = RelativeVertices[7];

            RelTriangles[8][0] = RelativeVertices[0];
            RelTriangles[8][1] = RelativeVertices[1];
            RelTriangles[8][2] = RelativeVertices[2];

            RelTriangles[9][0] = RelativeVertices[2];
            RelTriangles[9][1] = RelativeVertices[1];
            RelTriangles[9][2] = RelativeVertices[3];

            RelTriangles[10][0] = RelativeVertices[4];
            RelTriangles[10][1] = RelativeVertices[6];
            RelTriangles[10][2] = RelativeVertices[5];

            RelTriangles[11][0] = RelativeVertices[5];
            RelTriangles[11][1] = RelativeVertices[6];
            RelTriangles[11][2] = RelativeVertices[7];


        }
        void CreateAbsTriangles() {
            AbsTriangles[0][0] = AbsoluteVertices[0];
            AbsTriangles[0][1] = AbsoluteVertices[2];
            AbsTriangles[0][2] = AbsoluteVertices[4];

            AbsTriangles[1][0] = AbsoluteVertices[4];
            AbsTriangles[1][1] = AbsoluteVertices[2];
            AbsTriangles[1][2] = AbsoluteVertices[6];

            AbsTriangles[2][0] = AbsoluteVertices[1];
            AbsTriangles[2][1] = AbsoluteVertices[5];
            AbsTriangles[2][2] = AbsoluteVertices[3];

            AbsTriangles[3][0] = AbsoluteVertices[3];
            AbsTriangles[3][1] = AbsoluteVertices[5];
            AbsTriangles[3][2] = AbsoluteVertices[7];

            AbsTriangles[4][0] = AbsoluteVertices[0];
            AbsTriangles[4][1] = AbsoluteVertices[4];
            AbsTriangles[4][2] = AbsoluteVertices[1];

            AbsTriangles[5][0] = AbsoluteVertices[1];
            AbsTriangles[5][1] = AbsoluteVertices[4];
            AbsTriangles[5][2] = AbsoluteVertices[5];

            AbsTriangles[6][0] = AbsoluteVertices[2];
            AbsTriangles[6][1] = AbsoluteVertices[3];
            AbsTriangles[6][2] = AbsoluteVertices[6];

            AbsTriangles[7][0] = AbsoluteVertices[6];
            AbsTriangles[7][1] = AbsoluteVertices[3];
            AbsTriangles[7][2] = AbsoluteVertices[7];

            AbsTriangles[8][0] = AbsoluteVertices[0];
            AbsTriangles[8][1] = AbsoluteVertices[1];
            AbsTriangles[8][2] = AbsoluteVertices[2];

            AbsTriangles[9][0] = AbsoluteVertices[2];
            AbsTriangles[9][1] = AbsoluteVertices[1];
            AbsTriangles[9][2] = AbsoluteVertices[3];

            AbsTriangles[10][0] = AbsoluteVertices[4];
            AbsTriangles[10][1] = AbsoluteVertices[6];
            AbsTriangles[10][2] = AbsoluteVertices[5];

            AbsTriangles[11][0] = AbsoluteVertices[5];
            AbsTriangles[11][1] = AbsoluteVertices[6];
            AbsTriangles[11][2] = AbsoluteVertices[7];


        }
        void CreateAbsVert() {
            for (int i = 0; i < 8; i++){
                CFrame NewFrame(Position);
                NewFrame.AddPos(RelativeVertices[i]);
                this->AbsoluteVertices[i] = NewFrame;
            };
        }
        
};

