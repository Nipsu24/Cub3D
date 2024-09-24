/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:50:15 by mmeier            #+#    #+#             */
/*   Updated: 2024/09/24 10:54:00 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*Frees related input variables in case map parameters
  are invalid. Quits with 1.*/
int	free_input(data *data)
{
	free_arr(&data->map);
	free_str(&data->file_cnt);
	return (1);
}

/*Frees 2d arrays and sets it to NULL. Caller function
  should pass address of array to this function.*/
void	free_arr(char ***arr)
{
	int	j;

	j = 0;
	if (*arr == NULL)
		return ;
	while ((*arr)[j])
	{
		free((*arr)[j]);
		(*arr)[j] = NULL;
		j++;
	}
	free(*arr);
	*arr = NULL;
}

/*Frees string and sets pointer to NULL. Caller function
  should pass address of str to this function.*/
void	free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
