/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilin <emilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:07:53 by abelayad          #+#    #+#             */
/*   Updated: 2024/06/12 12:06:46 by emilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_curr_token_is_binop(t_token *curr_token)
{
	t_token_type	type;

	if (!curr_token)
		return (false);
	type = curr_token->type;
	if (type == T_PIPE)
		return (true);
	return (false);
}

bool	ft_is_redir(t_token_type type)
{
	if (type == T_LESS || type == T_GREAT
		|| type == T_DLESS || type == T_DGREAT)
		return (true);
	return (false);
}

int	ft_prec(t_token_type type)
{
	if (type == T_OR || type == T_AND)
		return (0);
	return (1);
}

int	ft_curr_token_prec(void)
{
	return (ft_prec(g_minishell.curr_token->type));
}
