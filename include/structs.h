#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_type				t_type;
typedef struct s_obj			t_obj;
typedef struct s_cam			t_cam;
typedef struct s_light			t_light;
typedef struct s_vec			t_vec;
typedef struct s_cylin			t_cylin;
typedef struct s_ambi			t_ambi;
typedef struct s_meta			t_meta;
typedef struct s_img			t_img;
typedef struct s_mlx			t_mlx;
typedef struct s_bg				t_bg;
typedef struct s_rec			t_rec;
typedef struct s_ray			t_ray;
typedef struct s_discriminant	t_discriminant;
typedef struct s_ctrl			t_ctrl;

enum e_type
{
	SP,
	PL,
	CY,
	A,
	C,
	L
};

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

struct s_ambi
{
	double	ratio;
	t_vec	rgb;
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
	t_vec	color;
	double	ratio;
	t_light	*next;
};

struct s_cylin
{
	double	diameter;
	double	height;
};

struct s_obj
{
	int		num;
	t_type	type;
	t_vec	coor;
	t_vec	vec;
	t_vec	rgb;
	double	ratio;
	t_cylin	cylin;
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

struct s_ctrl
{
	int		md;
	int		category;
	t_light	*light;
	t_obj	*obj;
};

struct s_meta
{
	int		obj_num;
	int		flag;
	t_ctrl	ctrl;
	t_ambi	ambi;
	t_cam	cam;
	t_light	*light;
	t_obj	*objs;
	t_mlx	mlx;
	int		(*hits[3])(t_obj obj, t_ray ray, t_rec *rec);
};

struct s_bg
{
	t_vec	hori;
	t_vec	verti;
	double	theta;
	double	vp_height;
};

struct s_rec
{
	t_vec	p;
	t_vec	normal;
	double	t_max;
	t_obj	obj;
};

struct s_ray
{
	t_vec	coor;
	t_vec	unit_vec;
	t_rec	rec;
};

struct s_discriminant
{
	double	a;
	double	b;
	double	c;
	double	disc;
	double	sqrtd;
};

#endif
