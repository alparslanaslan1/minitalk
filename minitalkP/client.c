/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaslan <alaslan@student.42kocaeli.tr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:17:23 by alaslan           #+#    #+#             */
/*   Updated: 2024/03/25 21:33:23 by alaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str)
		res = res * 10 + (*str++ - 48);
	return (res);
}

void	ft_transfer_center(char c, int pid)
{
	int	bit_index;
	int	error;

	bit_index = 0;
	error = 0;
	while (bit_index < 8)
	{
		if (c << bit_index & 128)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		bit_index++;
		usleep(200);
	}
	if (error == -1)
	{
		ft_putstr("PID Error");
		exit(1);
	}
}

int	main(int arc, char **arv)
{
	int	pid;
	int	i;

	i = 0;
	if (arc == 3)
	{
		pid = ft_atoi(arv[1]);
		if (pid <= 0)
		{
			ft_putstr("Format Error");
			exit (1);
		}
		while (arv[2][i])
			ft_transfer_center(arv[2][i++], pid);
	}
	else
	{
		ft_putstr("Format Error");
		exit (1);
	}
	return (0);
}
