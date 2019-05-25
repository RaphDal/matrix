#	CONFIGURATIONS

NAME		=		matrix.a

ROOT		=		.

SRC_DIR		=		$(ROOT)/src

BUILD_DIR	=		$(ROOT)/builds

INCLUDE_DIR	=		$(ROOT)/include

HEADERS		:=		$(shell find $(INCLUDE_DIR)/ -type f -name '*.h')

SRC			:=		$(shell find $(SRC_DIR)/ -type f -name '*.c')

OBJ			=		$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

WARN		=		-W -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable -Wunreachable-code

CFLAGS		=		-D _GNU_SOURCE -I$(INCLUDE_DIR) -I. -g

DEB			=		$(WARN) -D_DEBUG -g3 -O0

PROD		=		-DNDEBUG -fno-builtin

CC			=		gcc

V			=		@

#	COLORS

GREEN		=		\e[1;32m

WHITE		=		\e[0m

BLUE		=		\e[1;34m

ifeq ($(BUILD), debug)
CFLAGS		+=		$(DEB)
else
CFLAGS		+=		$(PROD)
endif

all:	$(NAME)

debug:
	$(V)$(MAKE) --no-print-directory -s $(THIS) all BUILD=debug

$(NAME):	$(OBJ)
	@mkdir -p $(BUILD_DIR)
	ar rc lib$(NAME) $(OBJ)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c	$(HEADERS)
	$(V)mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(V)find $(ROOT) -name \*.o -type f -delete
	$(V)rm -rf $(BUILD_DIR)
	$(V)find $(ROOT) -name \*.gcda -type f -delete
	$(V)find $(ROOT) -name \*.gcno -type f -delete
	$(V)find $(ROOT) -name \*.s -type f -delete
	$(V)rm -rf $(ASM_DIR)

fclean:	clean
	$(V)find $(ROOT) -name \*.a -type f -delete
	$(V)rm -f $(NAME)

re:	fclean	all

.PHONY:	all	fclean	clean	re	debug
