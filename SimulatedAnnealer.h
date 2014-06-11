
class Annealable
{
public:
	Annealable();
	virtual void generate_potential_mutation(){}
	virtual double energy_increase(){return 0.0;}
	virtual void keep_mutation(){}
	virtual void discard_mutation(){}
};

class Annealer
{
private:
	double temperature;
	Annealable* subject;
public:
	Annealer(Annealable* subj, double temp);
	void anneal_step();
	//void adjust_temp();
	//void anneal();
};
