// ElegantImageLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "Bitmap.h"
//#include "BlackAndWhite.h"
//#include "Speckler.h"
#include "Exploder.h"
#include <iostream>
#include "math.h"
#include <random>
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	explode("C:\\Users\\Sam\\Desktop\\Elegant\\hat_O.bmp",
			"C:\\Users\\Sam\\Desktop\\Elegant\\ID1_004.bmp",
			4);

	//Bitmap I(256, 256);
	//I.read_from("C:\\Users\\Sam\\Desktop\\Elegant\\hat_O.bmp");
	//turn_8(I);
	//I.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\8.bmp");

	return 0;
}

