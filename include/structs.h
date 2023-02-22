#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum	e_type		t_type;
typedef struct	s_obj		t_obj;
typedef struct	s_cam		t_cam;
typedef struct	s_light		t_light;
typedef struct	s_vec		t_vec;
typedef struct	s_rgb		t_rgb;
typedef struct	s_cylin		t_cylin;
typedef struct	s_ambi		t_ambi;
typedef	struct	s_meta		t_meta;
typedef	struct	s_img		t_img;
typedef	struct	s_mlx		t_mlx;
typedef	struct	s_bg		t_bg;
typedef struct	s_record	t_record;
typedef struct	s_ray		t_ray;

enum e_type
{
	SP, PL, CY
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

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

struct s_cam
{
	t_vec	coor;
	t_vec	vec;
	int		fov;
};

struct s_light
{
	t_vec	coor;
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
	t_vec	coor;
	t_vec	vec;
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
	int		(*hits[3])(t_obj obj, t_ray ray, t_record *rec);
};


struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		length;
	int		endian;
};

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
};

struct s_bg
{
	t_vec	hori;
	t_vec	verti;
};

struct s_record
{
	t_vec	p;
	t_vec	normal;
	double	t_max;
};

struct s_ray
{
	t_vec		coor;
	t_vec		unit_vec;
	t_record	obj_draw;
};


#endif
