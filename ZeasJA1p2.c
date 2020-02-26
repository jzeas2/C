#include <stdio.h>
#include <math.h>

//prototype functions
void getDateFromJulian (double jd, int *month, int *day, int *year);
double getDoubleFromUser(char* msg) ;

int main()
{
//starting variables
double jd=0;
int month,day,year;
//get JD from user
jd = getDoubleFromUser("Enter a valid Julian Day:");
if (jd!=-999.0) // -999 means “incorrect input”
{
 // Now, convert this jd into calendar date
 getDateFromJulian(jd ,&month, &day, &year);
 //output to console
 printf("Month, day, year is: %d, %d, %d \n",month,day,year);
return 0;
}
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

double getDoubleFromUser(char* msg) {
	//Prints message on screen
	printf("%s",msg);
	//starting variables
	double input;
	char term;
	//gets user input, validates it
	if(scanf("%lf%c", &input, &term) != 2)
	{
	if (term >= 0x41 && term <= 0x7A)
	{
	//if invalid, return -999.0
	printf("That's not a valid number!\n");
	return -999.0;
	} else {
		printf("That's not a valid number!\n");
		return -999.9;
	}

	}
	//otherwise return input
	return input;
}
