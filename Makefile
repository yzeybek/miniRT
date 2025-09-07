NAME = miniRT

TEST_ARG = ./tests/test.rt

CC = cc
RM = rm -rf
AR = ar rcs
MKDIR = mkdir -p
MAKE = make -C
GIT = git clone

MAKEFLAGS += --no-print-directory

CFLAGS = -Wall -Werror -Wextra -g

INC_DIRS = ./ ./incs ./libs/libvec ./libs/libvec/incs ./libs/libmem ./libs/libgnl \
		   ./libs/libft ./libs/libft/incs ./libs/minilibx-linux
IFLAGS = $(addprefix -I, $(INC_DIRS))

LFLAGS = -lm -lX11 -lXext

OBJS_DIR = build
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

LIBVEC_DIR = ./libs/libvec
LIBVEC = $(LIBVEC_DIR)/libvec.a

LIBMEM_DIR = ./libs/libmem
LIBMEM = $(LIBMEM_DIR)/libmem.a

LIBFT_DIR = ./libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBGNL_DIR = ./libs/libgnl
LIBGNL = $(LIBGNL_DIR)/libgnl.a

LIBMLX_REPO = https://github.com/42paris/minilibx-linux.git
LIBMLX_DIR = ./libs/minilibx-linux
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a

SRCS_DIR = srcs
SRCS = main.c error.c view.c parser.c parse_utils.c parse_elem.c parse_objs.c

VPATH = $(SRCS_DIR) $(addprefix $(SRCS_DIR)/, parser parser/parse_funcs)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@ $(IFLAGS)

all: libs dir $(NAME)

$(NAME): $(OBJS) $(LIBMLX) $(LIBGNL) $(LIBFT) $(LIBMEM) $(LIBVEC)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

dir:
	@if [ ! -d $(OBJS_DIR) ]; then \
		$(MKDIR) $(OBJS_DIR); \
	fi

libs:
	@$(MAKE) $(LIBMEM_DIR)
	@$(MAKE) $(LIBGNL_DIR)
	@$(MAKE) $(LIBFT_DIR)
	@$(MAKE) $(LIBVEC_DIR)
	@if [ ! -d $(LIBMLX_DIR) ]; then \
		$(GIT) $(LIBMLX_REPO) $(LIBMLX_DIR); \
	fi; \
	$(MAKE) $(LIBMLX_DIR)

clean:
	$(RM) $(OBJS_DIR)
	@$(MAKE) $(LIBVEC_DIR) clean
	@$(MAKE) $(LIBFT_DIR) clean
	@$(MAKE) $(LIBGNL_DIR) clean
	@$(MAKE) $(LIBMLX_DIR) clean
	@$(MAKE) $(LIBMEM_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) $(LIBVEC_DIR) fclean
	@$(MAKE) $(LIBFT_DIR) fclean
	@$(MAKE) $(LIBGNL_DIR) fclean
	@$(MAKE) $(LIBMEM_DIR) fclean

re: fclean all

run:
	./$(NAME) $(TEST_ARG)

norm:
	norminette

leak:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) $(TEST_ARG)

.PHONY: all clean fclean re dir run libs leak
