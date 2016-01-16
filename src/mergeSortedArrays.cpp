/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A != NULL&&B != NULL)
	{
		int count = 0, x = 0, maxcount = 0, iter1 = 0, var2 = 0;
		int i = 0, j = 0, day = 0, month = 0, year = 0, day1 = 0, month1 = 0, year1 = 0;
		struct transaction *result=(struct transaction*)malloc((ALen+BLen)*sizeof(struct transaction)) ;
		while (i < ALen&&j < BLen)
		{
			day = (A[i].date[0] - 48) * 10 + A[i].date[1] - 48;
			month = (A[i].date[3] - 48) * 10 + A[i].date[4] - 48;
			year = (A[i].date[6] - 48) * 1000 + (A[i].date[7] - 48) * 100 + (A[i].date[8] - 48) * 10 + A[i].date[9] - 48;
			day1 = (B[j].date[0] - 48) * 10 + B[j].date[1] - 48;
			month1 = (B[j].date[3] - 48) * 10 + B[j].date[4] - 48;
			year1 = (B[j].date[6] - 48) * 1000 + (B[j].date[7] - 48) * 100 + (B[j].date[8] - 48) * 10 + B[j].date[9] - 48;

			if (year1 < year)
			{
				result[iter1] = B[j];
				iter1++;
				j++;
				x = 1;
			}
			else if (year1 == year&&month1 < month)
			{
				result[iter1] = B[j];
				iter1++;
				j++;
				x = 1;
			}
			else  if (year1 == year&&month1 == month&&day1 < day)
			{
				result[iter1] = B[j];
				iter1++;
				j++;
				x = 1;
			}
			if (x != 1)
			{
				result[iter1] = A[i];
				i++;
				iter1++;
			}
			day1 = 0;
			month1 = 0;
			year1 = 0;
			x = 0;
		}
		while (i < ALen)
		{
			result[iter1] = A[i];
			i++;
			iter1++;
		}
		while (j < BLen)
		{
			result[iter1] = B[j];
			j++;
			iter1++;
		}
		return result;
	}
	else
		return NULL;
}