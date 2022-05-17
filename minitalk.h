/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouali <isouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:34:51 by isouali           #+#    #+#             */
/*   Updated: 2022/05/12 08:15:30 by isouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct data
{
	int		i;
	char	s;
	int		clien_pid;
}	t_data;
void		ft_putchar_fd(char c, int fd);
static int	check_spaces(char c);
int			ft_atoi(const char *s);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);

#endif
