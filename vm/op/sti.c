#include "corewar.h"

void    op_sti(t_vm *vm, t_cursor *cursor)
{
    int reg1;
    int val2;
    int val3;
    int val;

    cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
    reg1 = get_byte(cursor->pos + cursor->step, vm);
    val = cursor->reg[reg1 - 1];
    cursor->step += REG_LEN;
    val2 = get_arg(vm, cursor, 2, 1);
    val3 = get_arg(vm, cursor, 3, 1);
    int_to_bytecode(vm->arena,
			(cursor->pos + ((val2 + val3) % IDX_MOD)), val, DIR_SIZE);
    if (vm->loger_on == 1){
        ft_printf("P %4d | sti r%d %d %d\n",
                  cursor->id,
                  reg1,
                  val2,
                  val3);
        ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
                  val2,
                  val3,
                  val2 + val3,
                  cursor->pos + ((val2 + val3) % IDX_MOD));
    }
}