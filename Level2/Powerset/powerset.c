#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	calcul(int *nums, int n)
{
	int sum = 0;
	for(int x = 0; x < n; x++)
	{
		sum += nums[x];
	}
	return sum;
}

void	print(int *nums, int n)
{
	for(int x = 0; x < n; x++)
	{
		printf("%d", nums[x]);
		if(x != n -1 )
			printf(" ");
	}
	printf("\n");
}

void	solve(int target, int *nums, int size, int *subset, int index, int level)
{
	if(level == size)
	{
		if(calcul(subset, index) == target)
			print(subset, index);
		return ;
	}
	subset[index] = nums[level];
	solve(target,nums, size, subset, index + 1, level + 1);
	solve(target, nums, size, subset, index, level + 1);
}

int main(int ac, char **av)
{
	int target = atoi(av[1]);
	int size = ac - 2;
	int *nums  = malloc(sizeof(int) * size);
	int *subset  = malloc(sizeof(int) * size);
	for(int x = 0; x < size; x++)
		nums[x] = atoi(av[x + 2]);
	solve(target, nums, size,subset, 0, 0);
	free(nums);
	free(subset);
}
