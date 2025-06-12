#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>


#include "Classes.h"
#include "Functions.h"
#include "Debug.h"
#include"Storage.h"

int main()
{   
    Cube Test;
    Test.Color = Color3(0, 0, 0);
    Test.Size = Vector3(10, 10, 10);
    Test.Position.Beta = DegreeToRadian(-90);
    Test.Position.UpdateMatrix();
    CloneCube(Test);
    Cube* NewCube = CloneCube(Test);
    NewCube->Position.AddPos(Vector3(0, 10, 0));
    NewCube->Position.UpdateMatrix();

    DisplayCube(*(Cube*)Storage[0]);
    DisplayCube(*(Cube*)Storage[1]);

    NewCube->DeleteObject(Storage);

    return 0;
}
