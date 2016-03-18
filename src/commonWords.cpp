/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>

#define SIZE 31

int findLengthString(char *);

char ** commonWords(char *str1, char *str2) {
	int i, j,len1,len2,c1=0,c2=0,k=0,r1=0,r2=0;

	char **common,temp1[10][10],temp2[10][10];

	common = (char **)malloc(sizeof(char) * SIZE);

	if (str1 == '\0' || str2 == '\0') return NULL;
	len1 = findLengthString(str1);
	len2 = findLengthString(str2);
	for (i = 0,j=0; i<len1 && j<len2; i++,j++) //checking if a str1 or str2 contains all spaces
	{
		if (str1[i] == 32) c1++;
		if (str2[j] == 32) c2++;
	}
	if (c1 == len1 || c2 == len2) return NULL;
	c1 = 0; 

	while (i < len1) //storing the words of str1 into a 2d array temp1
	{
		if (str1[i] != 32)
		{
			temp1[r1][c1++] = str1[i++];
		}
		else
		{
			r1++; c1 = 0; i++;
		}
	}
	c2 = 0; i = 0;

	while (i < len2) //storing the words of str2 into a 2d array temp2
	{
		if (str2[i] != 32)
		{
			temp2[r2][c2++] = str2[i++];
		}
		else
		{
			r2++; c2 = 0; i++;
		}
	}
	int p = 0;
	for (i = 0; i < r1; i++) //finding the common words in temp1 and temp2
	{
		for (j = 0; j < r2; j++)
		{
			if (strcmp(temp1[i], temp2[j]) == 0)
			{   
				while (temp2[j][p] != '\0')       //copying the common words to 2d array common
				   common[k][p++] = temp2[j][p++];
				k++;
			}
		}
	}

	return common;
}
int findLengthString(char *str)
{
	int i, count = 0;
	for (i = 0; str[i]; i++)
	{
		count++;
	}
	return count;
}