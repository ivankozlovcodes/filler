# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 15:52:16 by ikozlov           #+#    #+#              #
#    Updated: 2018/03/20 16:51:46 by ikozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ikozlov.filler

# directories
OBJ_DIR = obj/
SRC_DIR = srcs/
INC_DIR = includes/
LIBFT_DIR = libft/
PRINTF_DIR = ft_printf/
GNL_DIR = get_next_line/

# complier
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

# src & obj files
SRC_FILES = main.c player.c reader.c logger.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# libraries
LIBFT = ft
PRINTF = ftprintf

INCLUDES = -I includes/ -I $(LIBFT_DIR)includes/ -I $(PRINTF_DIR)includes -I $(GNL_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(GNL_DIR)
	gcc $(OBJ) $(GNL_DIR)/get_next_line.o -o $(NAME) -L $(LIBFT_DIR) -l $(LIBFT) -L $(PRINTF_DIR) -l $(PRINTF)

$(OBJ): $(SRC)
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) $(INCLUDES) -c $^
	@mv -f *.o $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)
	@echo "[INFO] Object folder removed"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST)
	@echo "[INFO] Executable removed"

re: fclean all

.PHONY: all clean fclean re $(NAME)