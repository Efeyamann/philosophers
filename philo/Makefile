NAME = philo

SRCDIR = src
OBJDIR = OBJ
INCDIR = includes

SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/check/check.c \
       $(SRCDIR)/check/check_utils.c \
       $(SRCDIR)/fill/fill_struct.c \
       $(SRCDIR)/fill/fill_struct_utils.c \
       $(SRCDIR)/fill/fill_table.c \
       $(SRCDIR)/fill/fill_table_utils.c \
       $(SRCDIR)/free/free.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
