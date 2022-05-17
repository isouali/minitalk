/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouali <isouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:36:23 by isouali           #+#    #+#             */
/*   Updated: 2022/05/11 22:12:08 by isouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct data
{
	int		i;
	char	s;
	int		client_pid;
}	t_data;

int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	send_byte(char s, int pid);
void	send_message(char *str, int pid);
void	send_mesg(void);
void	handler(int sig, siginfo_t *info, void *ucontext);

#endif
