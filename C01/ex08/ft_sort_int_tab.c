/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:02:08 by landrade          #+#    #+#             */
/*   Updated: 2026/01/29 13:50:31 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	pass;
	int	index;

	pass = 0;
	while (pass < size - 1)
	{
		index = 0;
		while (index < size - 1 - pass)
		{
			if (tab[index] > tab[index + 1])
			{
				ft_swap(&tab[index], &tab[index + 1]);
			}
			index++;
		}
		pass++;
	}
}
/*
#include <stdio.h>

int main(void)
{
    int tab[] = {9, 1, 8, 2, 7, 3};
    int size = 6;
    int i = 0;

    // Chama sua função
    ft_sort_int_tab(tab, size);

    // Imprime resultado
    while (i < size)
    {
        printf("%d", tab[i]);
        if (i < size - 1)
            printf(", ");
        i++;
    }
    printf("\n");
    return (0);
}
*/
