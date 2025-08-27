NAME = philo

SRCDIR = src
OBJDIR = OBJ
INCDIR = includes

SRCS = $(SRCDIR)/main.c \
	   $(SRCDIR)/init_program.c \
	   $(SRCDIR)/run_simulation.c \
       $(SRCDIR)/check/check.c \
       $(SRCDIR)/check/check_utils.c \
       $(SRCDIR)/fill/fill_struct.c \
       $(SRCDIR)/fill/fill_struct_utils.c \
       $(SRCDIR)/fill/fill_table.c \
       $(SRCDIR)/fill/fill_table_utils.c \
       $(SRCDIR)/free/free.c \
       $(SRCDIR)/routine/routine.c \
       $(SRCDIR)/routine/routine_time_utils.c \
	   $(SRCDIR)/routine/monitor.c 

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -I$(INCDIR)

GREEN  = \033[0;32m
YELLOW = \033[0;33m
BLUE   = \033[0;34m
RED    = \033[0;31m
RESET  = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)[LINKING]$(RESET) $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)[SUCCESS]$(RESET) $(NAME) is ready!"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)[CC]$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)[CLEAN]$(RESET) removing object files"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)[FCLEAN]$(RESET) removing executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

