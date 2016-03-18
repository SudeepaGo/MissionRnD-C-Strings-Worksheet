/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
int findLengthOfString(char *);
char KthIndexFromEnd(char *str, int K) {
	int len;
	char ch;
	if (str == '\0') return '\0';
	len = findLengthOfString(str);
	if (K < 0 || K >= len) return '\0';
	else
	{
		ch = str[len - K - 1];
		return ch;
	}
}
int findLengthOfString(char *str)
{
	int i, count = 0;
	for (i = 0; str[i]; i++)
	{
		count++;
	}
	return count;
}