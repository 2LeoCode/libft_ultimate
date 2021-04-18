SHELL =		/bin/sh
.SUFFIXES =	.c .h .o

NAME =		libft.a

SRCD =		src
INCD =		inc
OBJD =		.obj
LIBD =		lib

SRC =		$(addsuffix $(word 1, $(.SUFFIXES)),\
			abs\
			atoi\
			atoi_u\
			atol\
			atol_u\
			atoll\
			atoll_u\
			bzero\
			calloc\
			destroy_array\
			isalnum\
			isalpha\
			isascii\
			isdigit\
			islower\
			isprint\
			isspace\
			isupper\
			itoa\
			itoa_u\
			lltoa\
			lltoa_u\
			ltoa\
			ltoa_u\
			memccpy\
			memchr\
			memcmp\
			memcpy\
			memmove\
			mempcpy\
			memset\
			putchar\
			putchar_fd\
			putendl\
			putendl_fd\
			putllong\
			putllong_fd\
			putlong\
			putlong_fd\
			putnbr\
			putnbr_fd\
			putstr\
			putstr_fd\
			split\
			stpcpy\
			stpncpy\
			strcasecmp\
			strcasestr\
			strcat\
			strcdup\
			strcdup2\
			strchr\
			strcmp\
			strcpy\
			strdup\
			strdup2\
			strjoin\
			strjoin2\
			strlcat\
			strlcpy\
			strlen\
			strmap\
			strmapi\
			strncasecmp\
			strncat\
			strncmp\
			strncpy\
			strndup\
			strndup2\
			strnlen\
			strnstr\
			strrchr\
			strstr\
			strstr2\
			strtrim\
			strtrim2\
			substr\
			substr2\
			tolower\
			toupper)
INC =		$(addsuffix $(word 2, $(.SUFFIXES)),\
			)
OBJ =		$(SRC:$(word 1, $(.SUFFIXES))=$(word 3, $(.SUFFIXES)))
LIB =		

CC =		gcc
CFLAGS =	-Wall\
			-Werror\
			-Wextra\
			-I $(INCD)\
			-o3
LIBCFLAGS =	$(addprefix -L, $(LIBD))\
			$(addprefix -l, $(LIB))

COUNT =		$(shell cat file.count 2>/dev/null)

ifeq ($(COUNT),)
all:
	@echo $(words $(SRC)) > file.count
	@$(MAKE) -n | grep $(CC) | wc -l | tr -d ' ' > tmp.txt
	@rm -f file.count
	@echo $$(($$(cat tmp.txt) - 1)) > file.count
	@rm -f tmp.txt
	@./make/remake.sh
else
all: $(NAME)
endif

$(NAME): $(addprefix $(OBJD)/, $(OBJ)) | $(addprefix $(INCD)/, $(INC))
	@rm -f file.count
	@ar -rcs $@ $^
	@printf "\r\033[2KCompiling [\033[32mOK\033[0m]\n"

$(OBJD):
	@mkdir $@

$(OBJD)/%$(word 3, $(.SUFFIXES)): $(SRCD)/%$(word 1, $(.SUFFIXES)) | $(OBJD)
	@./make/prc.sh 2>/dev/null
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJD)

fclean: clean
	@rm -f $(NAME)

re: fclean all
