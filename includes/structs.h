#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_type
{
	A, C, L, SP, PL, CY
} t_type;

typedef struct s_element
{
	int		idx;
	t_type	type;
	void	*meta;
} t_element;

typedef struct s_coor
{
	double	x;
	double	y;
	double	z;
	void	*next;
} t_coor;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	void	*next;
} t_rgb;

typedef struct s_double
{
	double	range;
	void	*next;
} t_double;

typedef struct s_cylin
{
	double	diameter;
	double	height;
	void	*next;
} t_cylin;

#endif