#include "../push_swap.h"

int	ft_isdigit(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str) {
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

int ft_duplicate(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}