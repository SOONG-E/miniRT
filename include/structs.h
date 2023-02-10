#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum	e_type			t_type;
typedef struct	s_obj		t_obj;
typedef struct	s_cam		t_cam;
typedef struct	s_light		t_light;
typedef struct	s_coor		t_coor;
typedef struct	s_rgb		t_rgb;
typedef struct	s_cylin		t_cylin;
typedef struct	s_ambi		t_ambi;
typedef	struct	s_meta		t_meta;

enum e_type
{
	A, C, L, SP, PL, CY
};

struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
};

struct s_ambi
{
	double	ratio;
	t_rgb	rgb;
};

struct s_coor
{
	double	x;
	double	y;
	double	z;
};

struct s_cam
{
	t_coor	coor;
	t_coor	vec;
	int		fov;
};

struct s_light
{
	t_coor	coor;
	double	ratio;
};

struct s_cylin
{
	double	diameter;
	double	height;
};

struct s_obj
{
	t_type	type;
	t_coor	coor;
	t_coor	vec;
	t_rgb	rgb;
	double	ratio;
	t_cylin	cylin;
};

struct s_meta
{
	int		obj_num;
	int		flag;
	t_ambi	ambi;
	t_cam	cam;
	t_light	light;
	t_obj	*objs;
};

#endif
