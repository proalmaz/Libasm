/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:43:31 by vping             #+#    #+#             */
/*   Updated: 2021/03/26 18:38:46 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	strdup_test(void)
{
	char	*dest1;
	char	*dest2;
	char	*src;

	src = "hello";
	dest1 = ft_strdup(src);
	dest2 = strdup(src);
	if (!strcmp(dest1, dest2))
		printf(GREEN "ft_strdup is [OK]\n" RESET "");
	else
		printf(RED "ft_strdup is [KO]\n" RESET);
}

void	read_test(void)
{
	char	*str1;
	char	*str2;

	str1 = malloc((sizeof(char) * 4));
	str2 = malloc((sizeof(char) * 4));
	if (!str1 || !str2)
	{
		printf("the memory can't be allocate");
		return ;
	}
	ft_read(0, str1, 4);
	read(0, str2, 4);
	printf("s1 = %ss2 = %s\n", str1, str2);
	if (!strcmp(str1, str2))
		printf(GREEN "ft_read is [OK]\n" RESET "");
	else
		printf(RED "ft_read is [KO]\n" RESET);
}

void	write_test(void)
{
	int		res1;
	int		res2;

	ft_write(-1, "123 = ", 6);
	res1 = errno;
	write(-1, "123\n", 4);
	res2 = errno;
	if (res1 == res2)
		printf(GREEN "ft_write  is [OK]\n" RESET "");
	else
		printf(RED "ft_write is  [KO]\n" RESET);
}

void	strlen_test(void)
{
	char	*str;
	size_t	res1;
	size_t	res2;

	str = "123456";
	res1 = ft_strlen(str);
	res2 = strlen(str);
	if (res1 == res2)
		printf(GREEN "ft_strlen is [OK]\n" RESET "");
	else
		printf(RED "ft_strlen is [KO]\n" RESET);
}

void	strcpy_test(void)
{
	char	*dest1;
	char	*dest2;
	char	*src;

	src = "libasm";
	dest1 = malloc(strlen(src));
	dest2 = malloc(strlen(src));
	if (!dest1 || !dest2)
	{
		printf("the memory can't be allocate");
		return ;
	}
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	if (!strcmp(dest1, dest2))
		printf("" GREEN "ft_strcpy is [OK]\n" RESET "");
	else
		printf("" RED "ft_strcpy is [KO]\n" RESET "");
}

void	strcmp_test(void)
{
	char	*s1;
	char	*s2;
	int		res1;
	int		res2;

	s1 = "129";
	s2 = "123";
	res1 = ft_strcmp(s1, s2);
	res2 = strcmp(s1, s2);
	if ((res1 == res2) || (res1 > 0 && res2 > 0) || (res1 < 0 && res2 < 0))
		printf("" GREEN "ft_strcmp is [OK]\n" RESET "");
	else
		printf("" RED "ft_strcmp is [KO]\n" RESET "");
}

int		main(void)
{
	strlen_test();
	strcpy_test();
	strcmp_test();
	write_test();
	read_test();
	strdup_test();
	return (0);
}
