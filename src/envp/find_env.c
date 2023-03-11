/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:10:06 by gsmereka          #+#    #+#             */
/*   Updated: 2023/03/08 00:14:41 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_env	*find_env(char *key, t_data *data) //usar ft_strncmp é perigoso, troquei pra ft_strcmp //  e acho q tenho uma func q faz isso--na vdd é meio diferente
{
	t_env	*envp;

	envp = data->dict_envp;
	while (envp) // busca a variavel de ambiente
	{
		if (ft_strcmp(envp->key, key) == 0)
			break ;
		envp = envp->next;
	}
	return (envp);
}
