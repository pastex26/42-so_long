SRCS_FILE :=	$(addprefix ft_, \
		absl \
		abs \
		atoi \
		atol_base \
		atol \
		atoll \
		bzero \
		calloc \
		count_words \
		free_split \
		free \
		gnl \
		isalnum \
		isalpha \
		isascii \
		isdigit \
		islower \
		isprint \
		isspace \
		isupper \
		itoa \
		llitoa \
		lstadd_back \
		lstadd_front \
		lstlast \
		lstnew \
		lstsize \
		lstswap \
		lstdelone \
		lstdup \
		lstfirst \
		lstget_index \
		lstindex \
		lstclear \
		lstiter \
		lstmap \
		memchr \
		memcmp \
		memcpy \
		memmove \
		memset \
		putchar_fd \
		putendl_fd \
		putnbr_base_fd \
		putnbr_fd \
		putstr_fd \
		read_file \
		split \
		strcat \
		strchr \
		strcmp \
		strcpy \
		strcrop \
		strdup \
		striteri \
		strjoin \
		strjoinfree \
		strlcat \
		strlcpy \
		strlen \
		strmapi \
		strncat \
		strncmp \
		strnstr \
		strrchr \
		strrev \
		strtrim \
		substr \
		tolower \
		toupper \
		printf \
		printf_hexa \
		printf_pnt \
		)

SRCS := $(addsufix .c, $(SRCS_FILE))
OBJ_DIR := .objs/
OBJS :=	$(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRCS_FILE)))
INC_FILE := libft.h
CC :=	gcc
CFLAGS :=	-Wall -Wextra -Werror
NAME :=	libft.a

GREEN := \033[0;32m
YELLOW :=\033[0;33m
RED := \033[0;31m
BLUE := \033[0;34m
COLOUR_END := \033[0m


all: intro $(OBJ_DIR) $(NAME)

$(OBJS): Makefile

${NAME}: ${OBJS}
	@echo "${YELLOW}\e[1;49mARCHIVING...\e[0m$(COLOUR_END)"
	@ar -rcs $(NAME) ${OBJS}
	@echo "\e[1;43mCREATED: $(NAME)\e[0m"

$(OBJ_DIR)%.o: %.c $(INC_FILE)
	@echo "$(BLUE)\e[1;48mBuilding:\e[0m $(BLUE)$@  $(COLOUR_END)$<"
	@${CC} ${CFLAGS} -c $< -o $@

$(OBJ_DIR):
	@echo "$(GREEN)\e[1;49mMkdir\e[0m     $(GREEN).objs/$(COLOUR_END)"
	@mkdir -p $(OBJ_DIR)

intro:
	@echo "\e[1;43m-----------LIBFT-----------\e[0m"

clean:
	@echo "$(RED)\e[1;48mCLEAN LIBFT\e[0m$(COLOUR_END)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)\e[1;48mFCLEAN LIBFT\e[0m$(COLOUR_END)"
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re intro
