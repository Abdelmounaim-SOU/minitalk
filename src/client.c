/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:25:30 by asou              #+#    #+#             */
/*   Updated: 2025/03/26 23:34:54 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include "minitalk.h"

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

pid_t	ft_atoi_pid(const char *str)
{
	int	pid;

	pid = 0;
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		if (pid >= PID_MAX)
			return (-1);
		pid = pid * 10 + *str - '0';
		str++;
	}
	return ((pid_t)pid);
}

void	send_char(pid_t pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		ft_printf("pid est : %d\n", pid);
		bit = (c >> i) & 1;
		if (bit)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Error: Signal not sent");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Error: Signal not sent");
		}
		usleep(200);
		i--;
	}
}

void	send_str(pid_t pid, const char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server-pid> <string>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi_pid(argv[1]);
	if (pid == -1 || pid == 0)
	{
		ft_printf("Invalid PID: %s\n", argv[1]);
		return (1);
	}
	if (kill(pid, 0) == -1)
	{
		ft_printf("Server not found: %s\n", argv[1]);
		return (1);
	}
	send_str(pid, argv[2]);
	return (0);
}
