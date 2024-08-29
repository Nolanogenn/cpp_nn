#include <random>
#include <iostream>

struct Unit {
	double b;
	double result;
	double* W;
	int lenW;

	Unit(int len) : lenW(len){
		W = new double[lenW];
	}
	~Unit(){
		delete[] W;
	}
	
};

double forward(double x[], const Unit& u)
{
	float temp_res=0;
	int lenW = u.lenW;
	for(int i=0; i<lenW; i++)
	{
		temp_res += x[i]*u.W[i];
	}	
	temp_res += u.b;
	return temp_res;
};

int main()
{
	std::random_device re;
	std::mt19937 e2(re());

	std::uniform_real_distribution<> dist(-1, 1);

	Unit unit1(10);
	double x[10];
	double w[10];
	for(int i =0; i < 10; i++)
	{
		unit1.W[i] = dist(re);
		x[i] = dist(re);
	}
	double first_unit_output = forward(x, unit1);
	std::cout << first_unit_output << "\n";
	return 0;
}
