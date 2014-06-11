#include "stdafx.h"
#include "SimulatedAnnealer.h"
#include <math.h>
#include <random>


Annealable::Annealable()
{
}


Annealer::Annealer(Annealable* subj, double temp):
	subject(subj), temperature(temp)
{
}

// monte carlo:
void Annealer::anneal_step()
{
	subject->generate_potential_mutation();
	double dE = subject->energy_increase();
	if(dE < 0 ||
		rand() < exp(-dE/temperature) * RAND_MAX)
	{
		subject->keep_mutation();
	}
	else
	{
		subject->discard_mutation();
	}
}
