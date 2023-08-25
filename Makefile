NAME			=	ircserv

INC				=	inc/
BIN				=	src/bin

RESET			=	\033[0m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			=	\033[34m
RED				=	\033[31m

SRCS			=	$(shell find src -type f -name "*.cpp")
INCS			=	$(shell find inc -type f -name "*.hpp")
OBJS			=	$(SRCS:src/%.cpp=src/bin/%.o)
HOBJS			=	$(INCS:inc/%.hpp)

CC				=	c++
RM				=	rm -rf
CPPFLAGS		=	-std=c++98 -Wall -Wextra -Werror

all:			$(NAME)

$(BIN):
	@mkdir $(BIN)

$(NAME):	$(BIN) $(OBJS) $(HOBJS)
			@echo "$(YELLOW)>- Compiling... [$(NAME)] $(RESET)"
			@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)>- Finished! $(RESET)"

clean:
			@echo "$(RED)>- Deleting... [$(NAME)] $(RESET)"
			@$(RM) $(OBJS) $(HOBJS)
			@$(RM) $(BIN)
			@echo "$(BLUE)>- Successfully! $(RESET)"

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

$(BIN)%.o: src/%.cpp
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CPPFLAGS) -c $< -o $@ -I$(INC)


.PHONY:			all clean fclean re bonus

