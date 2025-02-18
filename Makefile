NAME    = chess
CC      = cc
CFLAGS  = -g
HEADERS = -I./include
OBJDIR  = obj

# Include chess_piece directory
SRCS    = $(wildcard src/*.c chess_piece/*.c)

OBJS    = $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

HEADER_FILES = include/chess.h

# Colors for output
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
CYAN    = \033[0;36m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME) || (echo "$(RED)Linking failed!$(RESET)" && exit 1)
	@if [ -f $(NAME) ]; then \
		echo "$(GREEN)Executable $(NAME) created!$(RESET)"; \
	else \
		echo "$(RED)Error: $(NAME) was not created!$(RESET)"; \
	fi

# Compile .c files to .o in obj/ directory while maintaining directory structure
$(OBJDIR)/%.o: %.c $(HEADER_FILES)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) || (echo "$(RED)Compilation failed for $(notdir $<)!$(RESET)" && exit 1)

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Removing executable $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
