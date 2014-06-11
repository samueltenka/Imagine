#include "RGB.h"
#include "Array2D.h"
#include <iostream>
#include <fstream>
using namespace std;



class Bitmap: public Array2D<RGB>
{
private:
	void initialize_black();

	int row_size();
	int read_header_number(ifstream& myfile, int num_bytes);
	Dimensions read_header(ifstream& myfile);
	void read_body(ifstream& myfile);

	void write_header_number(ofstream& myfile, int value, int num_bytes);
	void write_header(ofstream& myfile);
	void write_body(ofstream& myfile);
public:
	Bitmap(int h, int w);
	// TODO: WRITE Bitmap(string file_name);
	void read_from(string file_name);
	void write_to(string file_name);
	~Bitmap();
};
