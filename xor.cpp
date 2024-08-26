#include <iostream>

double unit(double n[], double m[], double b)
{
	double result;
	result = 0;
	for(int i=0; i<2; i++)
	{
		result += n[i]*m[i];
	}
	result += b;
	return result;
}

double reLu(double i)
{
	int toReturn;
	if(i <= 0){
		toReturn = 0.0;
	} else {
		toReturn = 1.0;
	}
	return toReturn;
}

int main()
{
	double valueAnd;
	double valueOr;
	double valueXor;


	double n1[2] = { 0.0, 0.0}; //input
	double n2[2] = { 0.0, 1.0}; //input
	double n3[2] = { 1.0, 0.0}; //input
	double n4[2] = { 1.0, 1.0}; //input
				   //
	double m[2] = { 1.0, 1.0}; //first layer (it's the same for both and and or)
	double mXor[2] = { -2.0, 1.0}; //second layer

	double bAnd = -1.0;
	double bOr = 0.0;

	double bXor = 0.0;

	printf("result per (0,0)\n");
 	valueAnd = reLu(unit(n1,m,bAnd));
 	valueOr = reLu(unit(n1,m,bOr));
	double intermediate1[2] = {valueAnd, valueOr}; //for now let's force it
	valueXor = reLu(unit(intermediate1,mXor, bXor));
	printf("and %f\n", valueAnd);
	printf("or %f\n", valueOr);
	printf("xor %f\n", valueXor);
	printf("====");


	printf("result per (0,1)\n");
 	valueAnd = reLu(unit(n2,m,bAnd));
 	valueOr = reLu(unit(n2,m,bOr));
	double intermediate2[2] = {valueAnd, valueOr}; //for now let's force it
	valueXor = reLu(unit(intermediate2,mXor, bXor));
	printf("and %f\n", valueAnd);
	printf("or %f\n", valueOr);
	printf("xor %f\n", valueXor);
	printf("====");

	printf("result per (1,0)\n");
 	valueAnd = reLu(unit(n3,m,bAnd));
 	valueOr = reLu(unit(n3,m,bOr));
	double intermediate3[2] = {valueAnd, valueOr}; //for now let's force it
	valueXor = reLu(unit(intermediate3,mXor, bXor));
	printf("and %f\n", valueAnd);
	printf("or %f\n", valueOr);
	printf("xor %f\n", valueXor);
	printf("====");

	printf("result per (1,1)\n");
 	valueAnd = reLu(unit(n4,m,bAnd));
 	valueOr = reLu(unit(n4,m,bOr));
	double intermediate4[2] = {valueAnd, valueOr}; //for now let's force it
	valueXor = reLu(unit(intermediate4,mXor, bXor));
	printf("and %f\n", valueAnd);
	printf("or %f\n", valueOr);
	printf("xor %f\n", valueXor);
	printf("====");
	return 0;
}

