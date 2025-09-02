CC = cc
RM = rm -rf
AR = ar rcs
MKDIR = mkdir -p

IFLAGS = -I. -I ./incs
CFLAGS = -Wall -Werror -Wextra

VPATH = srcs
SRCS = vec_arith.c vec_consts.c vec_norms.c vec_oprs.c vec_prods.c

OBJS_DIR = build
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

NAME = libvec.a

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@ $(IFLAGS)

all: dir $(NAME)

dir:
	@if [ ! -d $(OBJS_DIR) ]; then \
		$(MKDIR) $(OBJS_DIR); \
	fi

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re dir
