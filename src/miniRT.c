#include "miniRT.h"

int main(int ac, char **av)
{
	t_meta	meta;
	
	if (ac != 2)
		ft_exit("miniRT need only one argument");
	parse_line(av[1], &meta);
	ray_tracing(&meta);

	return (0);
}


/*

0. mlx창 띄우기
	mlx 구조체 {
		mlx
		window
		img

	}
1. 카메라 시점에서 보이는 코너 점을 구함
2. 배경을 먼저 그림
3. 오브젝트를 그림
4. 바닥/ 빛/ 그림자 그림

*/