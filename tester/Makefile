LIBASM_DIR = ../libasm/
LIBASM = libasm.a

NAME_TESTER = tester
SRCS_TESTER = tester.c
OBJS_TESTER = $(SRCS_TESTER:.c=.o)
DEPS_TESTER = $(SRCS_TESTER:.c=.d)

INCLUDE = -I./
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: makelibasm $(NAME_TESTER)

makelibasm:
	@make --no-print-directory -C $(LIBASM_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@

$(NAME_TESTER): $(OBJS_TESTER) $(LIBASM_DIR)$(LIBASM)
	$(CC) $(CFLAGS) $(OBJS_TESTER) $(LIBASM_DIR)$(LIBASM) -o $@
-include $(DEPS_TESTER)

clean:
	@make clean --no-print-directory -C $(LIBASM_DIR)
	$(RM) $(OBJS_TESTER) $(DEPS_TESTER)
		
fclean:
	@make fclean --no-print-directory -C $(LIBASM_DIR)	
	$(RM) $(OBJS_TESTER) $(DEPS_TESTER)	
	$(RM) $(NAME_TESTER)

re: fclean all

.PHONY: all clean fclean re makelibasm