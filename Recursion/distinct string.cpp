#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int distinctStr(char **str, int x, char **output)
{
	if (x == 0)
		return 0;
	int ans = distinctStr(str + 1, x - 1, output);
	if (ans == 0)
	{
		output[0] = str[0];
		return 1;
	}

	for (int i = 0; i < ans; i++)
	{
		if (strcmp(str[0], output[i]) == 0)
		{
			return ans;
		}
	}
	output[ans] = str[0];
	return ans + 1;
}
int main()
{
	char **input, **output;
	printf("Enter the number of string you want to enter : \n");
	int n;
	scanf("%d", &n);
	input = (char **)malloc(n * sizeof(char *));
	output = (char **)malloc(n * sizeof(char *));
	printf("Enter the length of the longest string : \n");
	int l;
	scanf("%d", &l);
	for (int i = 0; i < n; i++)
	{
		input[i] = (char *)malloc(l * sizeof(char));
		output[i] = (char *)malloc(l * sizeof(char));
	}
	for (int i = 0; i < 6; i++)
	{
		scanf("%s", input[i]);
	}
	int x = distinctStr(input, n, output);
	for (int i = 0; i < x; i++)
	{
		printf("%s ", output[i]);
	}
}
