/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouali <isouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:15:40 by isouali           #+#    #+#             */
/*   Updated: 2022/05/12 08:10:23 by isouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	check_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == ' ' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			n = n * 10 + s[i] - 48;
			i++;
			j++;
		}
		else
			return (-1);
		if (j > 6)
			return (-1);
	}
	return (n);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long	nbr;
	char	c;

	nbr = nb;
	if (nbr >= 10)
	{
		ft_putnbr (nbr / 10);
		ft_putnbr (nbr % 10);
	}
	else if (nbr < 10)
	{
		c = nbr + 48;
		write (1, &c, 1);
	}
}
