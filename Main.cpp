#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include "Classes.h"

int main()
{
    Object Test;
    Test.Color = Color3(0, 125, 125);
    Test.Size = Vector3(5, 5, 5);
    Test.Position = CFrame(0, 0, 0);


    printf("\n%f", Test.Size.X);
    printf("\n%s", Test.Shape);
    return 0;
}
