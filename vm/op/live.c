#include "corewar.h"

void    op_live(t_vm *vm, t_cursor *cursor)
{
    int pl_id;
    t_player *pl;

    cursor->step += OP_CODE_LEN;
    pl_id = get_arg(vm, cursor, 1, 0);
    vm->lives_num++;
    cursor->last_live = vm->cycles;
    pl = NULL;
    if (pl_id <= -1 && pl_id >= -(vm->players_num))
    {
        pl = vm->players[pl_id < 0 ? -(pl_id) : pl_id];
        pl->last_live = vm->cycles;
        pl->current_lives_num++;
        vm->last_alive = pl;
    }
//    loger(cursor);
}
