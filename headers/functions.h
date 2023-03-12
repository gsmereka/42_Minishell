/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:23:28 by gde-mora          #+#    #+#             */
/*   Updated: 2023/03/12 13:11:42 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "structs.h"

// REPL
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

//built in
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>

// Executor
#include <sys/wait.h>

// REPL
void	init_repl(t_data *data);
void	init_repl_signals_handling(t_data *data);

// envp
void	set_initial_envp(char **envp, t_data *data);
void	dict_add_back(t_env **dict_env, char *key, char *value);
void	dictclear(t_env *envp);
void	att_virtual_envp(t_data *data);
void	att_envp_exitstatus_var(t_data *data);
t_env	*find_env(char *key, t_data *data);

// expander
void	init_expander(t_data *data);

// lexer
void	init_lexer(t_data *data);
void	add_token(t_token **tokens, char *content);
void	token_clear(t_token **tokens);

// parser
void	init_parser(t_data *data);

int		is_reserved(char *word, char *reserved_word);
// executor
void	init_executor(t_data *data);
void	clear_commands(t_data *data);
void	execute_built_in(t_cmd *cmd, t_data *data);
void	get_commands_info(t_data *data);
void	format_cmd(t_token *token, t_cmd *cmd, t_data *data);
void	get_outputs(t_token *token, t_cmd *cmd, t_data *data);
void	get_inputs(t_token *token, t_cmd *cmd, t_data *data);
void	get_env_paths(t_data *data);
void	set_cmds_paths(t_data *data);
int		set_processes(t_data *data);
void	set_files(t_cmd *cmd, t_data *data);
int		redirect_input(int cmd, t_data *data);
int		redirect_output(int cmd, t_data *data);
void	execute(t_cmd *cmd, t_data *data);
void	set_here_doc(t_data *data);
char	*get_next_line_with_free(int fd, int stop);

// built_in
void	ft_cd(char **args, t_data *data);
void	ft_echo(char **args, t_data *data);
void	ft_env(char **args, t_data *data);
void	ft_exit(char **args, t_data *data);
void	ft_export(char **args, t_data *data);
void	ft_pwd(char **args, t_data *data);
void	ft_unset(char **args, t_data *data);
void	ft_cd_error_msg(int error, char *name, t_data *data);
void	ft_export_error_msg(int error, char *name, t_data *data);
int		is_built_in(t_cmd *cmd);

// end_program
void	end_program(t_data *data);
void	exit_error(int error_value, char *msg, t_data *data);
void	free_array_list(void **list);

#endif