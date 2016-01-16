/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr != NULL)
	{
		int count = 0;
		int i = 0, j, day, month, year, day1 = 0, month1 = 0, year1 = 0;
		day = (date[0] - 48) * 10 + date[1] - 48;
		month = (date[3] - 48) * 10 + date[4] - 48;
		year = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (j > 5)
				{
					year1 = year1 * 10 + Arr[i].date[j] - 48;
				}
				else if (j > 2 && j < 5)
				{
					month1 = month1 * 10 + Arr[i].date[j] - 48;
				}
				else if (j < 2)
				{
					day1 = day1 * 10 + Arr[i].date[j] - 48;
				}
			}
			if (year1 > year)
			{
				count += 1;
			}
			else if (year1 == year &&month1 > month)
			{
				count += 1;
			}
			else if (year1 == year && month1 == month && day1 > day)
			{
				count += 1;
			}
			day1 = 0;
			month1 = 0;
			year1 = 0;
		}
		return count;
	}
	else
		return NULL;
}
