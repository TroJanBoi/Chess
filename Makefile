NAME    = chess
CC      = cc
CFLAGS  = -g
HEADERS = -I./include
OBJDIR  = obj

# Find all C source files in src/
SRCS    = $(wildcard src/*.c)
OBJS    = $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRCS))

# Header files to track dependencies
HEADER_FILES = include/chess.h

# Colors for output
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
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

# Compile .c files to .o in obj/ directory
$(OBJDIR)/%.o: src/%.c $(HEADER_FILES)
	@mkdir -p $(OBJDIR)
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
