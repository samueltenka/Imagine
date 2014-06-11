#include "stdafx.h"
#include "Exploder.h"
#include <random>





void explode(string source_file, string desti_file, double thoroughness) // e.g. thoroughness = 64
{
	Bitmap I(256, 256);
	I.read_from(source_file);
	Exploded E(&I);
	Annealer A(&E, 1.0);
	int area = I.height*I.width;
	int N = static_cast<int>(area*thoroughness);
	for(int i = 0; i < N; i++)
	{
		if(i % area == 0)
		{
			cout << i/area << endl;
		}
		A.anneal_step();
	}
	I.write_to(desti_file);
}




inline double uni() // TODO: put into central header file
{
	return static_cast<double>(rand())/(RAND_MAX+1); // in [0, 1)
}




Exploded::Exploded(Bitmap* bmp):
	Annealable(),
	my_bitmap(bmp)
{
}




void Exploded::generate_potential_mutation()
{
	old_r = static_cast<int>((my_bitmap->height-2)*uni() + 1);
	old_c = static_cast<int>((my_bitmap->width-2)*uni() + 1);
}


double Exploded::energy_increase()
{
	RGB sum;
	int count = 0;
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			sum += (*my_bitmap)[old_r + i][old_c + j];
			count += 1;
		}
	}
	RGB average = sum / count;

	double var_tot = 0;
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			var_tot += (*my_bitmap)[old_r + i][old_c + j].distance_squared_from(average);
		}
	}
	double variance = var_tot/count;

	//return -0.1; // FOR SNAZZY LICHEN EFFECT
	return (variance - 800)/200; // TODO: CALIBRATE CONSTANTS!
}


void Exploded::keep_mutation()
{
	RGB old = (*my_bitmap)[old_r][old_c];
	old.speckle(1);
	old.bound();
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			(*my_bitmap)[old_r + i][old_c + j] = old;
		}
	}
}


void Exploded::discard_mutation()
{ // nothing happens
}
