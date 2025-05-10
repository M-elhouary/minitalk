/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:36:30 by mel-houa          #+#    #+#             */
/*   Updated: 2025/04/06 14:08:36 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putnumber(int n)
{
	char	digit;

	if (n >= 10)
	{
		ft_putnumber(n / 10);
		ft_putnumber(n % 10);
	}
	else
	{
		digit = n + '0';
		write(1, &digit, 1);
	}
}

void	ft_putstring(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	sig_handler(int signum, siginfo_t *info, void *cnt)
{
	static char	c;
	static int	bits;
	static int	client_id;

	(void)cnt;
	if (client_id == 0)
		client_id = info->si_pid;
	if (info->si_pid != client_id)
	{
		c = 0;
		bits = 0;
		client_id = info->si_pid;
	}
	if (signum == SIGUSR2)
		c |= (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
	kill(client_id, SIGUSR1);
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstring("Server PID: ");
	sigemptyset(&sa.sa_mask);
	ft_putnumber(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
