/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:07:16 by ade-feli          #+#    #+#             */
/*   Updated: 2021/03/27 10:18:03 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char	*charjoin1(char *s, char c, int max)
{
	int		i;
	char	*ret;

	if (!(ret = malloc(max + 2)))
		return (0);
	i = -1;
	while (s[++i])
		ret[i] = s[i];
	ret[i++] = c;
	ret[i] = 0;
	free(s);
	return (ret);
}

int		gnl(char **line)
{
	char	c;
	int		i;
	int		max;

	max = 0;
	if (line == 0)
		return (-1);
	if (!(*line = malloc(1)))
		return (0);
	*line[0] = 0;
	while ((i = read(0, &c, 1)) > 0)
	{
		if (c == '\n')
			break ;
		*line = charjoin1(*line, c, max++);
	}
	if (i == -1)
		return (-1);
	if (i == 0)
		return (0);
	return (1);
}
