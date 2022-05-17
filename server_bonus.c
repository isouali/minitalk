/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouali <isouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:34:50 by isouali           #+#    #+#             */
/*   Updated: 2022/05/13 11:06:00 by isouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_t;

void	send_signal(int signum, int pid)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	reset_data(void)
{
	g_t.i = 0;
	g_t.s = 0;
	g_t.client_pid = 0;
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	sig -= SIGUSR1;
	if (g_t.client_pid != info -> si_pid)
		reset_data();
	g_t.s = g_t.s << 1 | sig;
	g_t.i++;
	if (g_t.i == 8)
	{
		if (!g_t.s)
			send_signal(SIGUSR1, info->si_pid);
		else
			write (1, &g_t.s, 1);
		reset_data();
	}
	g_t.client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	reset_data();
	ft_putstr("pid :   ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
