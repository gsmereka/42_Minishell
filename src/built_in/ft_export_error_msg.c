/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_error_msg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:29:03 by gsmereka          #+#    #+#             */
/*   Updated: 2023/03/04 19:37:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_export_error_msg(int error, char *name, t_data *data)
{
	char		*error_msg;

	if (error == 1)
	{
		error_msg = "bash: export: `1=9': not a valid identifier\n";
		write(2, error_msg, ft_strlen(error_msg));
		data->exit_status = 1;
		return ;
	}
	ft_printf("OK\n");
}
