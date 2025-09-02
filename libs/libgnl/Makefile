NAME = libgnl.a

CC = cc
RM = rm -rf
AR = ar rcs
MKDIR = mkdir -p
MAKE = make -C

MAKEFLAGS += --no-print-directory
CFLAGS = -Wall -Werror -Wextra
INC_DIRS = ./ ./incs ../libmem
IFLAGS = $(addprefix -I, $(INC_DIRS))

LIBMEM_DIR = ../libmem
LIBMEM = $(LIBMEM_DIR)/libmem.a

SRCS_DIR = srcs
SRCS = gnl_funcs.c gnl_utils.c
VPATH = $(SRCS_DIR) $(addprefix $(SRCS_DIR)/, )

OBJS_DIR = build
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@ $(IFLAGS)

all: libs dir $(NAME)

$(NAME): $(OBJS) $(LIBMEM)
	$(AR) $@ $^

dir:
	@if [ ! -d $(OBJS_DIR) ]; then \
		$(MKDIR) $(OBJS_DIR); \
	fi

libs:
	@$(MAKE) $(LIBMEM_DIR)

clean:
	$(RM) $(OBJS_DIR)
	@$(MAKE) $(LIBMEM_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) $(LIBMEM_DIR) fclean

re: fclean all

.PHONY: all clean fclean re dir libs
