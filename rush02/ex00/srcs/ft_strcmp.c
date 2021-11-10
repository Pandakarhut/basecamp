/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:34:01 by mtissari          #+#    #+#             */
/*   Updated: 2021/09/05 18:23:12 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(void *s1, void *s2)
{
	int		i;
	char	*s1char;
	char	*s2char;

	s1char = (char*)s1;
	s2char = (char*)s2;
	i = 0;
	while (*(s1char + i) == *(s2char + i) && *(s1char + i) && *(s2char + i))
		i++;
	return (*(s1char + i) - *(s2char + i));
}
