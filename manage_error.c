int ft_print_error(int code, char *msg)
{
	if (code == 0)
	{
		printf("%s\n", msg);
		return (1);
	}
	if (code == 1)
	{
		printf("%s\n", "system function fail");
		return (1);
	}
}

void *ft_print_error_null(int code, char *msg)
{
	if (code == 0)
	{
		printf("%s\n", msg);
		return (0);
	}
	if (code == 1)
	{
		printf("%s\n", "system function fail");
		return (0);
	}
}