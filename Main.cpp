#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>


#include "Classes.h"
#include "Functions.h"
#include "Debug.h"

int main()
{   
    Object* AllObjects[255] = { nullptr };
   

    Pyramid* Test = new Pyramid();
    Test->Color = Color3(0, 0, 0);
    Test->Size = Vector3(10, 10, 10);
    Test->Position.Beta = DegreeToRadian(-90);
    Test->Position.UpdateMatrix();
    AllObjects[0] = Test;

    
    DisplayPyramid(*(Pyramid*)AllObjects[0]);

    return 0;
}
