#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>


#include "Classes.h"
#include "Functions.h"
#include "Debug.h"

int main()
{
    Cube Test;
    Test.Color = Color3(0, 0, 0);
    Test.Size = Vector3(10, 10, 10);
    Test.Position.UpdateMatrix();
    DisplayCube(Test);

    return 0;
}
