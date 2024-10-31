/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:41:17 by mmeier            #+#    #+#             */
/*   Updated: 2024/10/31 13:51:32 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3D.h"

void	draw_wall_slice(t_data *data, float x, float y, float x_tar, float y_tar)
{
	float	dx;
	float	dy;
	int		steps_n;
	float	x_inc;
	float	y_inc;
	int		i;

	i = 0;
	dx = x_tar - x;
	dy = y_tar - y;
	steps_n = fabsf(dx) > fabsf(dy) ? fabsf(dx) : fabsf(dy);
	x_inc = dx / (float)steps_n;
	y_inc = dy / (float)steps_n;
	while (i <= steps_n)
	{
		mlx_put_pixel(data->img->fg, (int)(x), (int)(y), 0xFF0000FF);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void	draw_line_mm(t_data *data, float x, float y, float x_tar, float y_tar)
{
	float	dx;
	float	dy;
	int		steps_n;
	float	x_inc;
	float	y_inc;
	int		i;

	i = 0;
	dx = x_tar - x;
	dy = y_tar - y;
	steps_n = fabsf(dx) > fabsf(dy) ? fabsf(dx) : fabsf(dy);
	x_inc = dx / (float)steps_n;
	y_inc = dy / (float)steps_n;
	while (i <= steps_n)
	{
		mlx_put_pixel(data->img->ray, (int)roundf(x), (int)roundf(y), 0xFF0000FF);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

float	calc_dist(float x, float y, float x_tar, float y_tar)
{
	float	dist;
	
	dist = 0;
	dist = sqrt((x_tar - x) * (x_tar - x) + (y_tar - y) * (y_tar - y));
	return (dist);
	
}

float	calc_ray_len(t_data *data)
{
	if (data->ver_dis > data->hor_dis)
	{
		data->cl_x = data->hor_next_x;
		data->cl_y = data->hor_next_y;
	}
	else
	{
		data->cl_x = data->ver_next_x;
		data->cl_y = data->ver_next_y;
	}
	return(calc_dist(data->x_p, data->y_p, data->cl_x, data->cl_y));
}

void	normalize_angle(float *angle_1, float *angle_2)
{
	if (*angle_1 < 0)
	{
		*angle_1 += 2 * PI;
		*angle_2 += 2 * PI;
	}
	else if (*angle_1 > 2 * PI)
	{
		*angle_1 -= 2 * PI;
		*angle_2 -= 2 * PI;
	}
}