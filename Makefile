NAME = full

# lib
LIB_DIR	= lib/
LIBFT	= $(LIB_DIR)libft.a
LIB		= -lft -L$(LIB_DIR)

# core_war
COREWAR_DIR	= vm/
COREWAR		= $(COREWAR_DIR)corewar

# asm
ASM_DIR = asm/
ASM 	= $(ASM_DIR)asm


all: $(NAME)

$(NAME):  
	@make -C $(LIB_DIR)
	@make -C $(ASM_DIR)
	@make -C $(COREWAR_DIR)
	@cp $(ASM) ./asm1
	@cp $(ASM) ./Test_core/asm1
	@cp $(COREWAR) ./corewar
	@cp $(COREWAR) ./Test_core/vm

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(ASM_DIR) clean
	@rm -f asm1
	@make -C $(COREWAR_DIR) clean
	@rm -f corewar

fclean: clean
	@make -C $(LIB_DIR) fclean
	@make -C $(ASM_DIR) fclean
	@make -C $(COREWAR_DIR) fclean

re:
	@make fclean
	@make all