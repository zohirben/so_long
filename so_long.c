#include "so_long.h"

void digit_check(t_data *data, int j, int i)
{
    if (data->map[j][i] != 'P' && data->map[j][i] != 'E' && data->map[j][i] != 'C' && data->map[j][i] != '0' && data->map[j][i] != '1')
    {
        perror("Check input!! nigger\n");
        exit(1);
    }
    else if (data->map[j][i] == 'P')
    {
        data->P_count++;
        data->P_Y = j;
        data->P_X = i;
    }
    else if (data->map[j][i] == 'E')
    {
        data->E_count++;
        data->E_Y = j;
        data->E_X = i;
    }
    else if (data->map[j][i] == 'C')
        data->C_count++;
}

void check_corners(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map[j])
    {

        while (data->map[j][i])
        {
            if (!(data->map[0][i] == '1') || !(data->map[data->lines_len - 1][i] == '1') || !(data->map[j][0] == '1') || !(data->map[j][data->width_len - 1] == '1'))
            {
                perror("Map corners machi homa hadok\n");
                exit(1);
            }
            i++;
        }
        i = 0;
        j++;
    }
}

void map_checker(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        if (data->width_len != (int)ft_strlen(data->map[i]))
        {
            // printf(":%s\n",data->map[i]);
            // printf("*%d =%zu\n",data->width_len,ft_strlen(data->map[i]));
            perror("Map Width mkherbe9\n");
            exit(1);
        }
        i++;
    }
    i = 0;
    j = 0;
    while (data->map[j])
    {
        while (data->map[j][i])
        {
            digit_check(data, j, i);
            i++;
        }
        i = 0;
        j++;
    }
    if (data->C_count == 0 || data->P_count != 1 || data->E_count != 1)
    {
        perror("sir tn3s");
        exit(1);
    }
    check_corners(data);
}

char *ft_strjoinso(char *s1, char *s2)
{
    size_t i;
    size_t j;
    char *str;

    if (!s1 || !s2)
        return (0);
    str = (char *)malloc(ft_strlengnl(s1) + ft_strlengnl(s2) + 1);
    if (!str)
        return (0);
    i = 0;
    j = 0;
    while (s1[i])
        str[j++] = s1[i++];
    i = 0;
    while (s2[i])
        str[j++] = s2[i++];
    str[j] = '\0';
    free(s1);
    return (str);
}

void data_reader(t_data *data, int fd)
{
    char *line;
    char *big_line;

    big_line = ft_calloc(5, 1);
    line = get_next_line(fd);
    if (!line)
    {
        perror("sir tnak\n");
        exit(1);
    }
    data->width_len = ft_strlen(line) - 1;
    while (line)
    {
        big_line = ft_strjoinso(big_line, line);
        free(line);
        data->lines_len++;
        line = get_next_line(fd);
        if (line)
        {
            if ((int)ft_strlen(line) < data->width_len)
            {
                perror("too much new lines!\n");
                exit(1);
            }
        }
    }
    // printf("/%s\n",big_line);
    data->map = ft_split(big_line, '\n');
    free(big_line);
}

void ber_check(char *str, char *format)
{
    int i;
    int len;

    i = ft_strlen(str) -1 ;
    len = ft_strlen(format) - 1;
    while (len > 0)
    {
        if (str[i] == format[len] && str[i - 1] == format[len - 1])
        {
            len--;
            i--;
        }
        else
            break;
    }
    if (len != 0)
    {
        perror("wrong file format!\n");
        exit(1);
    }
}

int main(int ac, char **av)
{
    t_data *data;
    int fd;

    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        exit(0);
    ft_memset(data, 0, sizeof(t_data));
    if (ac < 2)
        exit(0);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        free(data);
        perror("theres no such file!\n");
        exit(1);
    }
    ber_check(av[1], ".ber");
    data_reader(data, fd);
    map_checker(data);
    if (path(data) == 0){
    perror("hhhh0h bslama\n");
    exit (0);
    }
    init(data);
    
    // int i = 0;
    //         // printf("ggg\n");

    // while(data->map[i])
    // {
    //     printf("%s\n",data->map[i]);
    //     i++;
    // }
}
int    path(t_data *data)
{
    int        x;
    int        y;
    int        a;
    int        i;
    char    **visited;

    x = data->P_X;
    y = data->P_Y;
    a = 0;
    i = 0;
    // data->lines_len;
    // data->width_len;
    visited = malloc(data->lines_len * sizeof(char *));
    while (i < data->lines_len)
    {
        visited[i] = malloc(data->width_len * sizeof(char));
        i++;
    }
    a = safe(x, y, data, visited);
    // freeingmachine(visited, NULL, data);
    return (a);
}

int    safe(int x, int y, t_data *data, char **visited)
{
    if ((data->map[y][x] == '0' || data->map[y][x] == 'C'
            || data->map[y][x] == 'P' || data->map[y][x] == 'E')
        && visited[y][x] != 'V')
    {
        visited[y][x] = 'V';
        if (data->map[y][x] == 'E' || data->map[y][x] == 'C')
        {
            data->prize++;
            if (data->prize == data->C_count + 1)
                return (1);
        }
        if (safe(x, y - 1, data, visited) == 1)
            return (1);
        if (safe(x, y + 1, data, visited) == 1)
            return (1);
        if (safe(x - 1, y, data, visited) == 1)
            return (1);
        if (safe(x + 1, y, data, visited) == 1)
            return (1);
    }
    return (0);
}