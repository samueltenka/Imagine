#include "SimulatedAnnealer.h"
#include "Bitmap.h"


void explode(string source_file, string desti_file, double thoroughness); // e.g. thoroughness = 64


class Exploded: public Annealable
{
private:
	Bitmap* my_bitmap; // TODO: replace with inheritance

	// explode-mutation info:
	int old_r, old_c;		// TODO: combine into struct

public:
	Exploded(Bitmap* bmp);
	void generate_potential_mutation();
	double energy_increase();
	void keep_mutation();
	void discard_mutation();
};
