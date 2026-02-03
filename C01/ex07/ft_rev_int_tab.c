/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:02:02 by landrade          #+#    #+#             */
/*   Updated: 2026/01/29 12:02:03 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	*start;
	int	*end;
	int	swap;

	if (!tab || size <= 0)
		return ;


	start = tab;
	end = tab + size - 1;
	while (start < end)
	{
		swap = *start;
		*start = *end;
		*end = swap;
		start++;
		end--;
	}
}
/*
#include <stdio.h>

int main(void)
{
    // --- Teste 1: Tamanho ÍMPAR (5 elementos) ---
    int tab1[] = {1, 2, 3, 4, 5};
    int size1 = 5;
    int i;

    printf("--- Teste 1 (Impar) ---\nOriginal: ");
    for (i = 0; i < size1; i++)
        printf("%d ", tab1[i]);
    printf("\n");

    ft_rev_int_tab(tab1, size1);

    printf("Invertido: ");
    for (i = 0; i < size1; i++)
        printf("%d ", tab1[i]);
    printf("\n\n");

    // --- Teste 2: Tamanho PAR (4 elementos) ---
    int tab2[] = {10, 20, 30, 40};
    int size2 = 4;

    printf("--- Teste 2 (Par) ---\nOriginal: ");
    for (i = 0; i < size2; i++)
        printf("%d ", tab2[i]);
    printf("\n");

    ft_rev_int_tab(tab2, size2);

    printf("Invertido: ");
    for (i = 0; i < size2; i++)
        printf("%d ", tab2[i]);
    printf("\n");

    return (0);
}
*/
