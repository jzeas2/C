#include <stdio.h>
#include <math.h>

//prototype functions
int getIntFromUser(char* msg);
double getJulianDay (int M, int D, int Y);
void getDateFromJulian (double jd, int *month, int *day, int *year);

int main() {
	//starting variables
	int M; int D; int Y; int Add;
	//get info from user
	Y = getIntFromUser("Enter Year\n");
	M = getIntFromUser("\nEnter Month\n");
	D = getIntFromUser("\nEnter Day\n");
	Add = getIntFromUser("Enter # of days to add to date entered.");
	//convert input to JD
	double JD = getJulianDay(M,D,Y);
	//add days to JD
	JD+=Add;
	//convert JD back to date
	getDateFromJulian(JD ,&M, &D, &Y);
	//print date
	printf("The new date is %d/%d/%d\n",M,D,Y);
	//end
	return 0;
}

int getIntFromUser(char* msg) {
	//print message
	printf("%s",msg);
	//starting variables
	int input;
	char term;
	//get input from user
	if(scanf("%d%c", &input, &term) != 2)
	{
	//if invalid, return -1
	if (term >= 0x41 && term <= 0x7A)
	{
	printf("That's not a valid number!\n");
	return -1;
	} else {
		printf("That's not a valid number!\n");
		return -1;
	}
	}
	//otherwise, return input
	return input;
}

double getJulianDay (int M, int D, int Y) {
//calculate JD
if (M<=2) {
Y--;
M+=12;
}
int A = floor(Y/100);
int B = 2-A+floor(A/4);
double JD = floor((365.25*(Y+4716.0)))+floor((30.6001*(M+1)))+D+B-1524.5;
//return JD
return JD;

}

void getDateFromJulian (double JD, int *month, int *day, int *year) {
//define starting variables
int A,B,C,D,E,alpha;
double Z,F;
//calculations for month, day year
JD = JD +0.5;
F= modf(JD, &Z);
if (Z < 2299161) {
	A = Z;
} else {
	alpha = ((Z - 1867216.25)/36524.25);
	//define variable to allow value to be cast to int
	int num1 = alpha/4;
	A = Z + 1 + alpha - num1;
}
B = A + 1524;
C = (B-122.1)/365.25;
D = 365.25*C;
E = (B-D)/30.6001;
int int2 = 30.6001 * E;
//place value in day's location in calling function
(*day) = B - D - int2 + F;
if (E < 15) {
	//place value in month's location in calling function
	(*month) = E - 1;
} else if (E == 14 | E == 15) {
	(*month) = E - 13;
}
if (*month > 2) {
	//place year in year's location in calling function
	(*year) = C - 4716;
} else {
	(*year) = C - 4715;
}


}
