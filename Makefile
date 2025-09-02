NAME = miniRT

CC = cc
RM = rm -rf
AR = ar rcs
MKDIR = mkdir -p
MAKE = make -C
GIT = git clone

MAKEFLAGS += --no-print-directory

CFLAGS = -Wall -Werror -Wextra

INC_DIRS = ./ ./incs ./libs/libvec ./libs/libmem ./libs/libft ./libs/minilibx-linux
IFLAGS = $(addprefix -I, $(INC_DIRS))

LFLAGS = -lm

OBJS_DIR = build
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

LIBVEC_DIR = ./libs/libvec
LIBVEC = $(LIBVEC_DIR)/libvec.a

LIBFT_DIR = ./libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBMLX_REPO = https://github.com/42paris/minilibx-linux.git
LIBMLX_DIR = ./libs/minilibx-linux
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a

SRCS_DIR = srcs
SRCS = main.c

VPATH = $(SRCS_DIR) $(addprefix $(SRCS_DIR)/, )

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@ $(IFLAGS)

all: $(LIBVEC) $(LIBMLX) $(LIBFT) dir $(NAME)

$(LIBVEC):
	$(MAKE) $(LIBVEC_DIR)

$(LIBFT):
	$(MAKE) $(LIBFT_DIR)

$(LIBMLX):
	@if [ ! -d $(LIBMLX_DIR) ]; then \
		$(GIT) $(LIBMLX_REPO) $(LIBMLX_DIR); \
	fi; \
	$(MAKE) $(LIBMLX_DIR)

dir:
	@if [ ! -d $(OBJS_DIR) ]; then \
		$(MKDIR) $(OBJS_DIR); \
	fi

$(NAME): $(OBJS) $(LIBMLX) $(LIBFT) $(LIBMEM) $(LIBVEC)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) $(LIBVEC_DIR) clean
	$(MAKE) $(LIBFT_DIR) clean
	$(MAKE) $(LIBMLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(LIBVEC_DIR) fclean
	$(MAKE) $(LIBFT_DIR) fclean

re: fclean all

run:
	./$(NAME)

norm:
	norminette

.PHONY: all clean fclean re dir run
