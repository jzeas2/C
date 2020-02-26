#include <stdio.h>
#include <math.h>
//clang ZeasJW5A1.c -o run

struct date
{
   int month;
   int day;
   int year;
   int hour;
   int minutes;
   int seconds;
   double julian_day;
};

void setJulianDay(struct date*);
double getFullJulianDay(const struct date *);
struct date getDateFromJulian (double);
int getIntFromUser(char*);
struct date addDays (double nDays, const struct date *);
struct date addWeeks (double nDays, const struct date *);
struct date addMonths (double nDays, const struct date *);
struct date addYears (double nDays, const struct date *);
struct date addHours (double nDays, const struct date *);
struct date addMinutes (double nDays, const struct date *);
struct date addSeconds (double nDays, const struct date *);
double getYearDiff(const struct date *,const struct date *);
double getMonthDiff(const struct date *,const struct date *);
double getWeekDiff(const struct date *,const struct date *);
double getDayDiff(const struct date *,const struct date *);
double getHourDiff(const struct date *,const struct date *);







int main() {
	//starting variables
	struct date d;
	struct date d2;
	double answer2;
	//1. If you add 1,000,000,000 seconds to 02/02/2017, what will the date be?
	d.day = 2; d.month = 2; d.year = 2017;
	d.hour = 0; d.minutes = 0; d.seconds = 0;
	setJulianDay(&d);
	struct date answer = addSeconds(100000000.0,&d);
	printf("\n\nThe date will be %d/%d/%d %d:%d:%d\n\nThe Julian Day is now %f\n\n\n\n",answer.month,answer.day,answer.year,answer.hour,answer.minutes,answer.seconds,answer.julian_day);


	//2. If you add 14654 days to 03/03/1966, what date will it be?
	d.day = 3; d.month = 3; d.year = 1966;
	d.hour = 0; d.minutes = 0; d.seconds = 0;
	setJulianDay(&d);
	answer = addDays(14654.0,&d);
	printf("The date will be %d/%d/%d %d:%d:%d\n\nThe Julian Day is now %f\n\n\n\n",answer.month,answer.day,answer.year,answer.hour,answer.minutes,answer.seconds,answer.julian_day);


	//3. If you added 68 months to 04/18/1973, what would be the new date?
	d.day = 18; d.month = 4; d.year = 1973;
	d.hour = 0; d.minutes = 0; d.seconds = 0;
	setJulianDay(&d);
	answer = addMonths(68.0,&d);
	printf("The date would be %d/%d/%d %d:%d:%d\n\nThe Julian Day is now %f\n\n\n\n",answer.month,answer.day,answer.year,answer.hour,answer.minutes,answer.seconds,answer.julian_day);


	//4. Suppose that the next supermoon is predicated to be on 11/25/2034 @ 8pm. Approximately how many seconds do we have to wait to see it? (use date of 02/09/2017 @ noon)
	d.day = 25; d.month = 11; d.year = 2034; d.hour = 20; d.minutes = 0; d.seconds = 0;
	d2.day = 9; d2.month = 2; d2.year = 2017; d2.hour = 12; d2.minutes = 0; d2.seconds = 0;
	setJulianDay(&d); 	setJulianDay(&d2);
	answer2 = getHourDiff(&d,&d2);
	answer2*=-3600;//convert to seconds
	printf("We would need to wait %f seconds to see the supermoon.\n\n\n\n",answer2);



	//5. Say it is now 02/09/2017 @ 4:51pm. What will the date and time be 893 minutes from now?
	d.day = 9; d.month = 2; d.year = 2017;
	d.hour = 16; d.minutes = 51; d.seconds = 0;
	setJulianDay(&d);
	answer = addMinutes(893.0,&d);
	printf("The date and time would be %d/%d/%d %d:%d:%d\n\nThe Julian Day is now %f\n\n\n\n",answer.month,answer.day,answer.year,answer.hour,answer.minutes,answer.seconds,answer.julian_day);


	//6. If I had set the dials in my time machine to go back in time exactly 657.76 years from now (now = 02/09/2017 @ 5:13am), to what date and time would the time machine send me?
	d.day = 9; d.month = 2; d.year = 2017;
	d.hour = 5; d.minutes = 13; d.seconds = 0;
	setJulianDay(&d);
	answer = addYears(-657.76,&d);
	printf("The machine would send you to %d/%d/%d %d:%d:%d\n\nThe Julian Day is now %f\n\n\n\n",answer.month,answer.day,answer.year,answer.hour,answer.minutes,answer.seconds,answer.julian_day);


	//7. If you were to subtract 68 months from 04/18/1973, what would the date be?
	d.day = 18; d.month = 4; d.year = 1973;
	d.hour = 0; d.minutes = 0; d.seconds = 0;
	setJulianDay(&d);
	answer = addMonths(-68.0,&d);
	printf("The date would be %d/%d/%d %d:%d:%d\n\nThe Julian Day is now %f\n\n\n\n",answer.month,answer.day,answer.year,answer.hour,answer.minutes,answer.seconds,answer.julian_day);



	//8. If you added 57865 seconds to 08/18/1967 @ 4:15:30am, what would the date and time be?
	d.day = 18; d.month = 8; d.year = 1967;
	d.hour = 4; d.minutes = 15; d.seconds = 30;
	setJulianDay(&d);
	answer = addSeconds(57865.0,&d);
	printf("The date and time would be %d/%d/%d %d:%d:%d\n\nThe Julian Day is now %f\n\n\n\n",answer.month,answer.day,answer.year,answer.hour,answer.minutes,answer.seconds,answer.julian_day);


	//9. How many seconds between dates 02/23/2017 and 06/13/2018?

	d.day = 23; d.month = 2; d.year = 2017; d.hour = 0; d.minutes = 0; d.seconds = 0;
	d2.day = 13; d2.month = 6; d2.year = 2018; d2.hour = 0; d2.minutes = 0; d2.seconds = 0;
	setJulianDay(&d); 	setJulianDay(&d2);
	answer2 = getHourDiff(&d,&d2);
	answer2*=3600;//convert to seconds
	printf("There are %f seconds between 2/23/2017 and 6/13/2018\n\n\n\n",answer2);



	//10. How many days between dates 02/23/2017 and 06/13/2018?

	d.day = 23; d.month = 2; d.year = 2017; d.hour = 0; d.minutes = 0; d.seconds = 0;
	d2.day = 13; d2.month = 6; d2.year = 2018; d2.hour = 0; d2.minutes = 0; d2.seconds = 0;
	setJulianDay(&d); 	setJulianDay(&d2);
	answer2 = getDayDiff(&d,&d2);
	printf("There are %f days between 2/23/2017 and 6/13/2018\n\n\n\n",answer2);

}

double getFullJulianDay(const struct date *d) {
	float h1 = d->hour * 1.0;
	float n1 = d->minutes * 1.0;
	float s1 = d->seconds * 1.0;
	//calculate daypart
	float dayPart = (((h1 * 60.0) * 60.0)+(n1 * 60.0)+s1)/86400.0;
	int month = d->month;
	int year = d->year;
	if (month<=2) {
	year--;
	month+=12;
	}
	int A = floor(year/100);
	int B = 2-A+floor(A/4);
	double JD = floor((365.25*(year+4716.0)))+floor((30.6001*(month+1)))+d->day+B-1524.5;
	JD+=dayPart;
	//return JD
	return JD;
}

//calculates and sets the julian_day member of a date
void setJulianDay(struct date *d) {
	d->julian_day = getFullJulianDay(d);

}

struct date getDateFromJulian (double JD) {
struct date newDate;
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
newDate.day = B - D - int2 + F;
if (E < 14) {
	//place value in month's location in calling function
	newDate.month = E - 1;
} else if (E == 14 | E == 15) {
	newDate.month = E - 13;
}
if (newDate.month > 2) {
	//place year in year's location in calling function
	newDate.year = C - 4716;
} else {
	newDate.year = C - 4715;
}
newDate.julian_day = JD;
// time of day
if (F>0.0)
{
int seconds = F*86400.0;
newDate.hour = (int)(seconds/3600); newDate.minutes = (int)((seconds%3600)/60); newDate.seconds = modf((seconds%3600)/60.0,&Z)*60;
} else {
  newDate.hour = 0;
  newDate.minutes = 0;
  newDate.seconds = 0;
}
return newDate;


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

struct date addDays (double nDays, const struct date *d1) {
	double JD = d1->julian_day;
	JD+=nDays;
	struct date returnValue = getDateFromJulian(JD);
	return returnValue;

}

struct date addWeeks (double nWeeks, const struct date *d1) {
	double JD = d1->julian_day;
	double days = nWeeks * 7;//convert weeks to days
	JD+=days;
	struct date returnValue = getDateFromJulian(JD);//convert new date to JD
	return returnValue;

}

struct date addMonths (double nMonths, const struct date *d1) {
	double JD = d1->julian_day;
	double days = nMonths * 30.44;
	JD+=days;
	struct date returnValue = getDateFromJulian(JD);
	return returnValue;

}

struct date addYears (double nYears, const struct date *d1) {
	double JD = d1->julian_day;
	double days = nYears * 365;
	JD+= days;
	struct date returnValue = getDateFromJulian(JD);
	return returnValue;

}

struct date addHours (double nHours, const struct date *d1) {
	double JD = d1->julian_day;
	double days = nHours /24;
	JD+= days;
	struct date returnValue = getDateFromJulian(JD);
	return returnValue;

}

struct date addMinutes (double nMins, const struct date *d1) {
	double JD = d1->julian_day;
	double days = nMins/1440;
	JD+=days;
	struct date returnValue = getDateFromJulian(JD);
	return returnValue;

}

struct date addSeconds (double nSecs, const struct date *d1) {
	double JD = d1->julian_day;
	double days = nSecs/86400;
	JD+=days;
	struct date returnValue = getDateFromJulian(JD);
	return returnValue;

}




double getYearDiff(const struct date *d1,const struct date *d2) {
	double JD1 = d1->julian_day;
	double JD2 = d2->julian_day;
	double diff = JD2 - JD1;
	double returnValue = diff/365;
	return returnValue;

}

double getMonthDiff(const struct date *d1,const struct date *d2) {
	double JD1 = d1->julian_day;
	double JD2 = d2->julian_day;
	double diff = JD2 - JD1;
	double returnValue = diff/30.44;
	return returnValue;

}

double getWeekDiff(const struct date *d1,const struct date *d2) {
	double JD1 = d1->julian_day;
	double JD2 = d2->julian_day;
	double diff = JD2 - JD1;
	double returnValue = diff/7;
	return returnValue;

}

double getDayDiff(const struct date *d1,const struct date *d2) {
	double JD1 = d1->julian_day;
	double JD2 = d2->julian_day;
	double diff = JD2 - JD1;
	double returnValue = diff;
	return returnValue;
}

double getHourDiff(const struct date *d1,const struct date *d2) {
	double JD1 = d1->julian_day;
	double JD2 = d2->julian_day;
	double diff = JD2 - JD1;
	double returnValue = diff*24;
	return returnValue;
}


