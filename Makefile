NAME :=			lem_in

SRC_DIR :=		./src/
OBJ_DIR :=		./obj/
INC_DIR :=		./inc/

SRC :=			lem_in.c parse_input.c validate_str.c validate_room.c \
				validate_and_add_link.c add_room.c add_link.c find_room.c \
				find_link.c print_rl.c queue.c get_ants_num.c find_paths.c 

OBJ :=			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC :=			gcc -g
CC_FLAGS :=		-Wall -Wextra -Werror

LIBFT_DIR :=	./libft/
LIBFT_INC :=	./libft/inc/
LIBFT := 		$(LIBFT_DIR)libft.a

all: lib obj_dir $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(CC_FLAGS) $(OBJ) $(LIBFT) -I $(INC_DIR) -I $(LIBFT_INC)
	@echo "Compiling [ $(NAME) ]"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) -I $(INC_DIR) -I $(LIBFT_INC)
	@echo "Linking $(NAME) [ $< ]"

lib:
	@make -C $(LIBFT_DIR)

obj_dir:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJ) $(LIBFT_OBJ)
	@make -C $(LIBFT_DIR) clean
	@echo "Cleaning" [ object files $(NAME) ]

fclean:
	@rm -f $(OBJ) $(LIBFT_OBJ)
	@echo "Cleaning" [ object files $(NAME) ]
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning" [ $(NAME) ]
	@make -C $(LIBFT_DIR) fclean
	@rm -f filler.trace

re: fclean all

.PHONY: all clean fclean re