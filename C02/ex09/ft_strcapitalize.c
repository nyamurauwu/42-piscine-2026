/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:44:53 by landrade          #+#    #+#             */
/*   Updated: 2026/02/01 17:44:54 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_type
{
	NONE = 0,
	UPPER = 1,
	LOWER = 2,
	NUMBER = 3
}				t_type;

static t_type	get_type(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (UPPER);
	if (c >= 'a' && c <= 'z')
		return (LOWER);
	if (c >= '0' && c <= '9')
		return (NUMBER);
	return (NONE);
}

char	*ft_strcapitalize(char *str)
{
	char	*ptr;
	int		new_word;
	t_type	type;

	ptr = str;
	new_word = 1;
	while (*ptr != '\0')
	{
		type = get_type(*ptr);
		if (type != NONE)
		{
			if (new_word == 1 && type == LOWER)
				*ptr = *ptr - 32;
			else if (new_word == 0 && type == UPPER)
				*ptr = *ptr + 32;
			new_word = 0;
		}
		else
			new_word = 1;
		ptr++;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "OLA, tudo BEM? 42palavras QUARENTA-e-duas; cinquenta+E+UM";

	printf("antes: %s\n", str);
	printf("depois: %s\n", ft_strcapitalize(str));
}

