#include <functional>
#include <random>
#include <iostream>
#include <new>
std::random_device re;
std::mt19937 e2(re());
std::uniform_real_distribution<> dist(-1, 1);

double relu(double i) {
	double tmp_return = 0;
	if(i<=0){
		tmp_return = 0;
	}else{
		tmp_return = i;
	}
	return tmp_return;
}

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
	void printData() const{
		for(int i =0; i< lenW; i++){
			std::cout << W[i] << " ";
		}
	std::cout << std::endl;
	}
	
};

struct Layer {
	Unit* arrayOfUnits;
	int numNeurons;
	int numW;
	double* outputs;
	double* inputs;
	std::function<double(double)> forwardFunc;

	Layer(int lenN, int lenW, std::function<double(double)> func) : numNeurons(lenN), numW(lenW), forwardFunc(func){
		outputs = new double[numNeurons];
		inputs = new double[lenW];
		arrayOfUnits = static_cast<Unit*>(operator new[](numNeurons * sizeof(Unit)));
		for(int i=0;i<numNeurons;i++)
		{
		new (&arrayOfUnits[i]) Unit(lenW);
		for(int x =0; x<lenW; x++){
			arrayOfUnits[i].W[x] = dist(re);
			}
		arrayOfUnits[i].b = dist(re);
		}
	}
	~Layer(){
		for (int i=0; i<numNeurons;i++){
			arrayOfUnits[i].~Unit();
		}
		operator delete[](arrayOfUnits);
		delete[] outputs;
		delete[] inputs;
	}
	void printAll() const{
		for (int i=0; i<numNeurons; i++){
			arrayOfUnits[i].printData();
		}
	}
	void makeInput(double vector[]) const{
		for(int i=0; i<numW; i++){
			inputs[i] = vector[i];
		}
	}
	void forward() const{
		for(int i=0; i<numNeurons;i++){
			double temp_res;
			double final_res;
			for(int j=0; j<numW; j++)
			{
				temp_res += inputs[j]*arrayOfUnits[i].W[j];
			}	
			temp_res += arrayOfUnits[i].b;
			final_res = forwardFunc(temp_res);	
			outputs[i] = final_res;
		}
	}
};
int main()
{

	Layer* layer = new Layer(5,10,relu);
	
	double x[10] = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};
	layer->makeInput(x);
	layer->forward();

	delete layer;
	return 0;
}
