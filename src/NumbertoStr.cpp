/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string. format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<math.h>

int isInt(float);
int wholeToString(float, char *, int);
int decimalToString(float, char *, int,int);

void number_to_str(float number, char *str, int afterdecimal){
	
	int i = 0;

	// check for negetive float
	if (number<0)
	{

		str[i++] = '-';
		number *= -1;
	}
	int check = isInt(number);
	
	if (check == 1){
	i=wholeToString(number,str,i);
	}
	else
	{
		i=wholeToString(number, str, i);
		i=decimalToString(number, str, afterdecimal, i);
	}
	str[i] = '\0';
}

int wholeToString(float number,char *str,int i)
{
	int a, m, count = 0, b, c,l;
	a = number;	// extracting whole number
	int n = a;
	while (n>0)
	{
		m = n % 10;
		n = n / 10;
		count++;
	}
	for (l = count; l > 0; l--)
	{
		b = pow((float)10, l - 1);
		c = a / b;
		str[i++] = c + 48;
		a %= b;
	}
	return i;
}
int decimalToString(float number,char *str,int afterdecimal,int i)
{
	int a, l, b, k;
	a = number;	// extracting whole number
	number -= a;	// extracting decimal part
	k = afterdecimal;

	str[i++] = '.';

	/* extracting decimal digits till precision */

	for (l = 0; l < afterdecimal; l++)
	{
		number *= 10.0;
		b = number;
		str[i++] = b + 48;
		number -= b;
	}
	return i;
}

int isInt(float val)
{
	int n = (int)val;
	if (n != val) return 0;
	else return 1;
}
