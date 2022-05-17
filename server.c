/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouali <isouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:11:20 by isouali           #+#    #+#             */
/*   Updated: 2022/05/12 08:20:00 by isouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

t_data	g_t;

void	reset_data(void)
{
	g_t.i = 0;
	g_t.s = 0;
	g_t.clien_pid = 0;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	sig -= SIGUSR1;
	if (g_t.clien_pid != info -> si_pid)
		reset_data();
	g_t.s = g_t.s << 1 | sig;
	g_t.i++;
	if (g_t.i == 8)
	{
		write(1, &g_t.s, 1);
		reset_data();
	}
	g_t.clien_pid = info-> si_pid;
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
