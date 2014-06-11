class RGB
{
	friend class Bitmap;

private:
	int R, G, B;	// 0 to 256
					// or would double from 0.0 to 1.0 be easier, mathematically?
	friend void turn_8(Bitmap &bitmap);

public:
	RGB();
	RGB(int r, int g, int b);
	void set(int value);

	int distance_squared_from(RGB other);
	double distance_from(RGB other);

	void bound();
	int value();
	void speckle(int scale);

	RGB & operator=(const RGB& other);
	RGB & operator+=(const RGB& other);
	RGB & operator-=(const RGB& other);
	RGB & operator*=(int scale);
	RGB & operator*=(double scale);
	RGB & operator/=(int scale);
	RGB & operator/=(double scale);

	const RGB operator+(const RGB& other);
	const RGB operator-(const RGB& other);
	const RGB operator*(int scale);
	const RGB operator*(double scale);
	const RGB operator/(int scale);
	const RGB operator/(double scale);
};
