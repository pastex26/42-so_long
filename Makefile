SRCS_FILE :=	check_collision \
				check_map \
				check_path \
				draw \
				enemy_ai \
				free_memory1 \
				free_memory2 \
				init_coin \
				init_enemy \
				init_game \
				init_map \
				init_player \
				main \
				player_movement \
				sprite_animation \
				utils1 \
				utils2


#LIBFT--------------------------
LIBFT :=		libft/
LIBFT_A :=		$(LIBFT)libft.a

MLX :=			minilibx-linux/
#-------------------------------

#DIR---------------------
OBJ_DIR :=		.objs/
SRC_DIR :=		srcs/
#------------------------

#INCLUDES------------------------------
INC :=			$(SRC_DIR)so_long.h
#--------------------------------------

#FILES .C---------------------------------------------------------------------
SRCS :=			$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRCS_FILE)))
#-----------------------------------------------------------------------------

#FILES .O---------------------------------------------------------------------
OBJS :=			$(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
#-----------------------------------------------------------------------------

#NAMES---------------------
NAME := 		so_long
#--------------------------

CC := 			gcc
CFLAGS :=		-Wall -Wextra -Werror -I $(LIBFT) -I $(MLX)

#style------------
GREEN := \033[0;32m
YELLOW :=\033[0;33m
RED := \033[0;31m
BLUE := \033[0;34m
BOLD := \e[1;48m
NML := \033[0m
YELL_BORDER := \e[1;43m
#-----------------


all: libft mlx intro $(OBJ_DIR) $(NAME)


$(OBJ_DIR):
	@echo "$(BOLD)$(GREEN)Mkdir    $(NML) $(GREEN)$@$(NML)"
	@mkdir -p $(OBJ_DIR)

$(OBJS): $(LIBFT_A) Makefile

$(NAME): $(OBJS)
	@echo "$(BOLD)$(YELLOW)COMPILING...$(NML)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(MLX) -lmlx -lXext -lX11 -lm -o $@
	@echo "$(BOLD)$(YELL_BORDER)CREATED  $@$(NML)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@echo "$(BOLD)$(BLUE)Building:$(NML)$(BLUE) $@ $(BOLD)$(NML) $<"
	@$(CC) $(CFLAGS) -c $< -L$(LIBFT) -lft -L$(MLX) -lmlx -lXext -lX11 -lm -o $@

mlx:
	@make -C $(MLX) | grep -v "^make"
	@echo "$(BOLD)$(GREEN)BUILD MLX$(NML)"

libft:
	@make -C $(LIBFT) | grep -v "^make"

clean:
	@echo "$(BOLD)$(RED)CLEAN $(NAME)$(NML)"
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

fclean: clean
	@echo "$(BOLD)$(RED)FCLEAN $(NAME)$(NML)"
	@make -C $(LIBFT) fclean | grep -v "^make"
	@make -C $(MLX) clean | grep -v "^make"

re: fclean all

intro:
	@echo "\e[1;43m----------So_long----------\e[0m"


.PHONY: all clean fclean libft intro mlx re