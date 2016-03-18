/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
int findLength(char *);
char removeSpaces(char *str) {
	int i,len,count=0;
	if (str == '\0') return '\0';
	else
	{ 
	len = findLength(str);
		for (i = 0; i < len; i++)
		{
			if (str[i] != ' ')
				str[count++] = str[i];
		}
		str[count] = '\0';
		return *str;
	}
}
int findLength(char *str)
{
	int i,count=0;
	for (i = 0; str[i];i++)
	{
		count++;
	}
	return count;
}