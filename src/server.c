/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:20:01 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 23:32:25 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char		c;
	static int		i;
	static pid_t	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		i = 0;
		c = 0;
	}
	c = c | (signum == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	c <<= 1;
	pid = info->si_pid;
}

void	init_signal_handler(struct sigaction *sa)
{
	sa->sa_sigaction = signal_handler;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	if (sigaction(SIGUSR1, sa, NULL) == -1)
		ft_error("Sigaction failed!\n");
	if (sigaction(SIGUSR2, sa, NULL) == -1)
		ft_error("Sigaction failed!\n");
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	init_signal_handler(&sa);
	while (1)
		pause();
	return (0);
}
