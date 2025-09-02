NAME = libmem.a

CC = cc
RM = rm -rf
AR = ar rcs
MKDIR = mkdir -p

INC_DIRS = ./ ./incs
IFLAGS = $(addprefix -I, $(INC_DIRS))
CFLAGS = -Wall -Werror -Wextra

SRCS_DIR = srcs
SRCS = mem_utils.c mem_alloc.c mem_clear.c
VPATH = $(SRCS_DIR) $(addprefix $(SRCS_DIR)/, )

OBJS_DIR = build
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@ $(IFLAGS)

all: dir $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

dir:
	@if [ ! -d $(OBJS_DIR) ]; then \
		$(MKDIR) $(OBJS_DIR); \
	fi

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re dir
