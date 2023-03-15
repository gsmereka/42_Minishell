/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signals_handling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:08:47 by gsmereka          #+#    #+#             */
/*   Updated: 2023/03/14 23:16:21 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern t_data	*g_aux_data;

static void	handle_ctrl_c(int signal);

void	heredoc_signals_handling(t_data *data)
{
	struct sigaction	ctrl_c;
	struct sigaction	ctrl_backsslash;

	g_aux_data = data;
	ft_bzero(&ctrl_c, sizeof(struct sigaction));
	ft_bzero(&ctrl_backsslash, sizeof(struct sigaction));
	ctrl_c.sa_handler = handle_ctrl_c;
	ctrl_backsslash.sa_handler = SIG_IGN;
	sigaction(SIGINT, &ctrl_c, NULL);
	sigaction(SIGQUIT, &ctrl_backsslash, NULL);
}

static void	handle_ctrl_c(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		close_heredoc_pipes(g_aux_data);
		g_aux_data->exec->need_interrupt = 1;
	}
}
