NAME = ./vm

all: $(NAME)

# Lib
LIB_DIR = ./lib/
LIB = -lft -L$(LIB_DIR)

CORE_WAR_DIR = ./vm/
ASM_DIR = ./asm/


all: $(NAME)

$(NAME): $(lib) $(corewar) $(asm)


lib:
	@make -C $(LIB_DIR)

corewar:
	@make -C $(CORE_WAR_DIR)

asm:
	@make -C $(ASM_DIR)

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(ASM_DIR) clean
	@make -C $(CORE_WAR_DIR) clean

fclean: clean
	@make -C $(LIB_DIR) fclean
	@make -C $(ASM_DIR) fclean
	@make -C $(CORE_WAR_DIR) fclean

re:
	@make fclean
	@make all