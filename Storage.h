#pragma once
#include"Functions.h"
#include"Classes.h"
const int Amount = 255;
int end = 0;

Object* Storage[Amount] = { nullptr };



void Store(Object* ToStore) {
	Storage[end] = ToStore;
	ToStore->PosInStorage = end;
	end += 1;
}

Cube* CreateCube(char Name[99]) {
	Cube* CubePointer = new(Cube);
	Store(CubePointer);
	return CubePointer;
}
Cube* CloneCube(Cube ToClone) {
	Cube* CubePointer = new Cube(ToClone);
	Store(CubePointer);
	return CubePointer;
}
Pyramid* CreatePyramid(char Name[99]) {
	Pyramid* PyramidPointer = new(Pyramid);
	Store(PyramidPointer);
	return PyramidPointer;
}
Pyramid* ClonePyramid(Pyramid ToClone) {
	Pyramid* PyramidPointer = new Pyramid(ToClone);
	Store(PyramidPointer);
	return PyramidPointer;
}

