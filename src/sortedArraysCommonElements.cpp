/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int hash(char *word1, char *word2)
{
	int i, j, count;
	int hashf[255] = { 0 };
	for (i = 0; word1[i] != '\0'; i++)
	{
		++hashf[word1[i]];
	}
	for (i = 0; word2[i] != '\0'; i++)
	{
		--hashf[word2[i]];
	}
	for (i = 0; i < 255; i++)
	{
		if (hashf[i]>0)
			return 0;
	}
	return 1;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A != NULL&&B != NULL)
	{
		int count = 0, x, maxcount = 0, var, iter1 = 0, iter2 = 0;
		int i = 0, j, day, month, year, day1 = 0, month1 = 0, year1 = 0;
		struct transaction result[10];
		while (i < ALen)
		{
			day = (A[i].date[0] - 48) * 10 + A[i].date[1] - 48;
			month = (A[i].date[3] - 48) * 10 + A[i].date[4] - 48;
			year = (A[i].date[6] - 48) * 1000 + (A[i].date[7] - 48) * 100 + (A[i].date[8] - 48) * 10 + A[i].date[9] - 48;
			for (x = 0; x < BLen; x++)
			{
				if (A[i].amount == B[x].amount&&hash(A[i].description, B[x].description))
				{
					for (j = 0; j < 10; j++)
					{
						if (j > 5)
						{
							year1 = year1 * 10 + B[i].date[j] - 48;
						}
						else if (j > 2 && j < 5)
						{
							month1 = month1 * 10 + B[i].date[j] - 48;
						}
						else if (j < 2)
						{
							day1 = day1 * 10 + B[i].date[j] - 48;
						}
					}
					if (year1 == year && month1 == month && day1 == day)
					{
						result[iter1] = A[i];
						//printf("%d\n", A[i].amount);
						maxcount += 1;
						iter1++;
						iter2 = maxcount - iter2;
					}
				}
				day1 = 0;
				month1 = 0;
				year1 = 0;
			}
			if (maxcount == 0)
				i = i + 1;
			else
				i = i + iter2;
		}
		if (maxcount == 0)
			return NULL;
		else
			return result;
	}
	else
		return NULL;
}