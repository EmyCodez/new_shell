/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:51:13 by abelayad          #+#    #+#             */
/*   Updated: 2024/06/12 12:41:52 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clear_envlst(t_env **envlst)
{
	t_env	*current;
	t_env	*temp;

	current = *envlst;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	(*envlst) = NULL;
}

void	ft_clean_ms(t_minishell *myshell)
{
	ft_garbage_collector(NULL, true);
	ft_clear_ast(myshell->ast, &myshell->tokens);
	ft_clear_envlst(&myshell->envlst);
	rl_clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, myshell->original_term);
}
