NAME = asm
CC = gcc
FLAGS = -Wall -Wextra -Werror
.PHONY: all clean fclean re

# Sources
SOURCES_DIR = ./src/
SOURCES_LIST = \
	asm.c \
	parser.c \
	parser_utils.c \
	token.c \
	utils.c \
	error.c \
	process_description.c \
	process_body.c \
	process_utils.c \
	process_arg.c \
	label.c \
	write_bytes.c \
	memfree.c \
	debug.c

SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

# Objects
OBJECTS_DIR = ./obj/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

# Headers
HEADERS_DIR = ./includes/
HEADERS_LIST = \
	asm.h \
	error.h \
	utils.h \
	config.h \
	op.h

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))	
INCLUDES = \
	-I$(HEADERS_DIR) \
	-I$(LIB_DIR)libft/ \

# Lib
LIB_DIR = ../lib/
LIB = -lft -L$(LIB_DIR)

# Colors
GREEN = @tput setaf 2; tput bold;
RED = @tput setaf 1; tput bold;
MAGENTA = @tput setaf 5; tput bold;
CYAN = @tput setaf 6; tput bold;
RESET = @tput setaf 7;

all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	@make -C $(LIB_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME) $(LIB)
	$(GREEN)
	@echo "$(NAME) object files were created"
	@echo "$(NAME) was created"
	$(RESET)	

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	$(CYAN)
	@echo "+"
	$(RESET)

clean:
	@cd ../lib && make fclean && cd ../asm
	@rm -rf $(OBJECTS_DIR)
	$(RED)
	@echo "$(NAME) objects were deleted"
	$(RESET)

fclean:	clean
	@rm -f $(NAME)
	$(RED)
	@echo "$(NAME) was deleted"
	$(RESET)
re:
	@$(MAKE) fclean
	@$(MAKE) all