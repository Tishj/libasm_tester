# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/21 18:00:17 by tbruinem      #+#    #+#                  #
#    Updated: 2020/06/24 15:14:20 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LSMINCL =	../
LSMLIB	=	../
LSMNAME	=	libasm.a

NAME	=	lasm_test
FLAGS	=	-Wall -Wextra -Werror
INCL	=	-I ./incl -I $(LSMINCL)
ifeq ($(DEBUG),1)
FLAGS	+=	-g -fsanitize=address
endif
TAIL	=	-L $(LSMLIB) $(subst lib,-l,$(basename $(LSMNAME)))
SRC		=	main.c \
			options.c \
			item_cmp.c \
			mandatory.c \
			bonus.c \
			vname.c \
			itoa.c \
			ft_list_print.c \
			tests/test_atoibase.c \
			tests/test_itoabase.c \
			tests/test_lstpushfront.c \
			tests/test_lstremoveif.c \
			tests/test_lstsize.c \
			tests/test_lstsort.c \
			tests/test_read.c \
			tests/test_write.c \
			tests/test_strchr.c \
			tests/test_strdup.c \
			tests/test_strcmp.c \
			tests/test_strcpy.c \
			tests/test_strlen.c

OBJ 	:=	$(addprefix obj/, $(SRC:%.c=%.o))
SRC 	:=	$(addprefix src/, $(SRC))

obj/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(INCL) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INCL) $^ $(TAIL) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
