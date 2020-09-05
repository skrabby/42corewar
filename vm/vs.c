//
// Created by poligon on 18.05.2020.
//

#include "corewar.h"
#include <sys/stat.h>
#include <fcntl.h>

void    vs_map(t_cursor *cursor)
{
    int i = 0;

    while(i < 100)
    {
        if (i == (int)cursor->pos)
            ft_printf("%d -->", cursor->id);
        if (i % 32 != 0 || i == 0) {
            ft_printf("{red}%d{green}(%d) ", g_vm->arena[i], i);
            i++;
        }
        else{
            ft_printf("{red}%d{green}(%d) ", g_vm->arena[i], i);
            ft_printf("\n");
            i++;
        }
    }
    i = 0;
    while (i < 10) {
        ft_printf("\n");
        i++;
    }
}

