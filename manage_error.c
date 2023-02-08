int ft_print_error(int code, char *msg)
{
	if (code == 0)
	{
		printf("%s\n", msg);
		return (1);
	}
}
