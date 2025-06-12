#pragma once
#include"Functions.h"
#include"Classes.h"
const int Amount = 255;
int end = 0;


Object* Storage[Amount] = { nullptr };

Cube* CreateCube(char Name[99]) {
	Cube* CubePointer = new(Cube);
	Storage[end] = CubePointer;
	CubePointer->PosInStorage = end;
	end += 1;
	return CubePointer;
}
Cube* CloneCube(Cube ToClone) {
	Cube* CubePointer = new Cube(ToClone);
	Storage[end] = CubePointer;
	CubePointer->PosInStorage = end;
	end += 1;
	return CubePointer;
}

