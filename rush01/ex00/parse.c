/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:43:20 by landrade          #+#    #+#             */
/*   Updated: 2026/01/25 20:53:09 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_args(char *str, int clues[4][4])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (count >= 16)
				return (0);
			clues[count / 4][count % 4] = str[i] - '0';
			count++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (count == 16);
}
