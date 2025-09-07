NAME = libft.a

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
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c ft_isnone.c\
	   ft_strlen.c  ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c  ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_memset.c ft_memcpy.c ft_memmove.c ft_memcmp.c ft_memchr.c \
	   ft_toupper.c ft_tolower.c \
	   ft_atoi.c ft_itoa.c \
	   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
VPATH = $(SRCS_DIR) $(addprefix $(SRCS_DIR)/, is int lst mem put str to)

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
