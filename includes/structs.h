#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_type		t_type;
typedef	struct s_meta	t_meta;
typedef struct s_obj	t_obj;
typedef struct s_coor	t_coor;
typedef struct s_rgb	t_rgb;
typedef struct s_cylin	t_cylin;

typedef enum e_type
{
	A, C, L, SP, PL, CY
} t_type;

typedef	struct s_meta
{
	int		obj_num;
	int		flag;
	t_obj	*objs;
} t_meta;

typedef struct s_obj
{
	t_type	type;
	t_coor	coor;
	t_coor	vec;
	t_rgb	rgb;
	int		fov;
	double	ratio;
	t_cylin	cylin;
} t_obj;

typedef struct s_coor
{
	double	x;
	double	y;
	double	z;
} t_coor;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
} t_rgb;

typedef struct s_cylin
{
	double	diameter;
	double	height;
} t_cylin;

#endif