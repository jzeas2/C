#include <stdio.h>
#include <math.h>


//prototype functions
double getJulianDay (int, int, int);
float getDayPart (int, int, int);
int getIntFromUser(char* msg);

int main (void)
{
//starting variables
  int M; int D; int Y; int h; int n; int s;
  //get inputs from user
  Y = getIntFromUser("Enter Year\n");
  M = getIntFromUser("\nEnter Month\n");
  D = getIntFromUser("\nEnter Day\n");
  h = getIntFromUser("\nEnter Hour\n");
  n = getIntFromUser("\nEnter Minute\n");
  s = getIntFromUser("\nEnter Second\n");
  //calculate JD, Day part, and Time part from input
  double JD = getJulianDay(M,D,Y);
  double fullJD = getJulianDay(M,D,Y)+getDayPart(h,n,s);
  float timePart = getDayPart(h,n,s);
  //output JD, Day part and Time part to console
  printf("\nThe Julian Day is:%f\n",fullJD);
  printf("The day part is:%f\n\a",JD);
  printf("The time part is:%f\n",timePart);
  return 0;
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

float getDayPart (int h, int n, int s) {
//convert int to float
float h1 = h * 1.0;
float n1 = n * 1.0;
float s1 = s * 1.0;
//calculate daypart
float dayPart = (((h1 * 60.0) * 60.0)+(n1 * 60.0)+s1)/86400.0;
//return daypart
return dayPart;
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


