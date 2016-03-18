/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverse(char *, char*);

void str_words_in_rev(char *input, int len){
	int i,c=0;
	char *word = input;
	char *temp = input;
	for (i = 0; i < len;i++)
	{ 
		if (input[i] == 32) c++;
	}
	if (c > 0)
	{
		while (*temp)
		{
			temp++;
			if (*temp == '\0')
			{
				reverse(word, temp - 1);
			}
			else if (*temp == ' ')
			{
				reverse(word, temp - 1);
				word = temp + 1;
			}
		} 
		reverse(input, temp - 1);
	}
}

void reverse(char *begin, char *end)
{
	char temp;
	while (begin < end)
	{
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}