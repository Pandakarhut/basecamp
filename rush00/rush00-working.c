#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_first_line(int x)
{
	//Print first character
	ft_putchar('o');

	//Print as many middle characters as needed
	while (x > 2)
	{
		ft_putchar('-');
		x--;
	}

	//Print last character only if there were over 1 column.
	if (x > 1)
		ft_putchar('o');

	//Print newline
	ft_putchar('\n');
}

void ft_print_middle_line(int x)
{
	//Print first character
	ft_putchar('|');

	//Print as many middle characters as needed
	while (x > 2)
	{
		ft_putchar(' ');
		x--;
	}
	//Print last characters only if there were over 1 column.
	if (x > 1)
		ft_putchar('|');

	//Print newline
	ft_putchar('\n');
}

void ft_print_last_line(int x)
{
	//Print first character
	ft_putchar('o');

	//Print as many middle characters as needed
	while (x > 2)
	{
		ft_putchar('-');
		x--;
	}
	//Print last characters only if there were over 1 column.
	if (x > 1)
		ft_putchar('o');

	//Print newline
	ft_putchar('\n');
}

void rush(int x, int y) 
{
	//If x or y are zero or less, dont print anything
	if (x <= 0 || y <= 0)
		return ;
	
	//Start by printing the first line
	ft_print_first_line(x);

	// Print lines-2 middle lines. If y is 3, there is 1 middle line.
	while (y > 2)
	{
		ft_print_middle_line(x);
		y--;
	}
	// Print the last line only if there were a total of over 1 line.
	if (y > 1)
		ft_print_last_line(x);
}

int main()
{
	rush(3,3);
	return (0);
}
