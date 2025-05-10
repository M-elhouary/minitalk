/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:01:02 by mel-houa          #+#    #+#             */
/*   Updated: 2025/04/05 23:45:37 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static int	g_nt = 0;

void	handler_f(int t)
{
	(void)t;
	g_nt = 1;
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > 2147483648L))
			return (0);
		str++;
	}
	while (*str == ' ')
		str++;
	if (*str != '\0')
		return (0);
	return ((int)(sign * result));
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(1);
		}
		while (g_nt == 0)
			;
		g_nt = 0;
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	int		i;

	if (argc != 3)
	{
		write(1, "Usage: ./client <pid> <string>\n", 32);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0 || pid == -1)
	{
		write(1, "Error: Invalid PID.\n", 20);
		return (1);
	}
	str = argv[2];
	signal(SIGUSR1, handler_f);
	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		i++;
	}
	return (0);
}
