/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>
int findSingleOccurenceNumber(int *a, int n) {
	if (a != 0 && a != NULL&&n>0)
	{
		int i, j, count = 0;
		for (i = 0; i < n; i++)
		{
			for (j = i; j < n; j++)
			{
				if (a[i]>a[j])
				{
					a[i] = a[i] + a[j];
					a[j] = a[i] - a[j];
					a[i] = a[i] - a[j];
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			if (a[i - 1] > 0 && a[i + 1] < n)
			{
				if (a[i] != a[i + 1] && a[i] != a[i - 1])
				{
					return a[i];
					break;
				}
			}
			else if (a[i - 1] < 0)
			{
				if (a[i] != a[i + 1])
				{
					return a[i];
					break;
				}
			}
			else if (a[i + 1] > n)
			{
				if (a[i] != a[i - 1])
				{
					return a[i];
					break;
				}
			}
		}
	}
	return -1;
}