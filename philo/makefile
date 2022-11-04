#****VARIABLES****
NAME = philo
#NAME_BONUS = philo_bonus

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -pthread
RM = rm -rf
#LIBFT = libft.a
HEADER = includes/philo.h
#HEADER_BONUS = includes/pipex_bonus.h
#D_LIBFT = includes/libft/
D_SRC = src/
#D_SRC_BONUS = src_bonus/
D_OBJ = obj/
#D_OBJ_BONUS = obj_bonus/
OBJS = $(patsubst $(D_SRC)%.c,$(D_OBJ)%.o,$(SRCS))
#OBJS_BONUS = $(patsubst $(D_SRC_BONUS)%.c,$(D_OBJ_BONUS)%.o,$(SRCS_BONUS))

OK_STRING = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING = "[WARNING]"
COMP_STRING = "Generating"
CLEAN_STRING = "Cleaning"

NO_OF_FILES := $(words $(wildcard $(D_SRC)*.c))

#****COLORS****
LRED = \033[91m
RED = \033[91m
LGREEN = \033[92m
LYELLOW = \033[93
LMAGENTA = \033[95m
LCYAN = \033[96m
DEF_COLOR = \033[0;39m
NC = \033[0;39m

#*****INTRO*****
define intro
@bash intro.sh
endef

define intro_bonus
@bash intro_bonus.sh
endef

#****MAKEUP RULE****
#****before emoji :
#printf "%-60b%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)" "$(LGREEN)$(OK_STRING)$(DEF_COLOR)\n";
define run_and_test
printf "%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)$(DEF_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $@" "💥$(DEF_COLOR)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $@" "⚠️$(DEF_COLOR)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)" "✅$(DEF_COLOR)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

define cleaning
printf "%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Files$(DEF_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Files" "💥$(DEF_COLOR)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Files" "⚠️$(DEF_COLOR)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Files" "✅$(DEF_COLOR)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

define fcleaning
printf "%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Executable Files$(DEF_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Executable Files" "💥$(DEF_COLOR)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Executable Filess" "⚠️$(DEF_COLOR)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) PROJECT Executable Files" "✅$(DEF_COLOR)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

#****SOURCES****
SRCS = src/philo.c \
		src/philo_libft.c \
		src/philo_utils.c \
		src/philo_simu.c \
		src/philo_init.c \
		src/philo_threads.c \
		src/philo_dead.c \
		src/philo_chopsticks.c

#SRCS_BONUS = src_bonus/...

#$(V).SILENT:

#all:	do_libft $(NAME)
all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)
#	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(D_LIBFT)$(LIBFT)
	@printf "%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)$(DEF_COLOR)\r"
	@echo "$(LGREEN)Software Compilation completed ...$(NO_OF_FILES) files done !$(DEF_COLOR)"

$(OBJS): $(D_OBJ)%.o : $(D_SRC)%.c $(HEADER)
		$(call intro)
		@mkdir -p $(D_OBJ)
		@$(call run_and_test, $(CC) $(CFLAGS) -c $< -o $@)

#do_libft:
#	@$(MAKE) -C $(D_LIBFT)

#$(NAME_BONUS): $(OBJS_BONUS)
#	@$(CC) $(CFLAGS) -o $@ $(OBJS_BONUS)
#	@$(CC) $(CFLAGS) -o $@ $(OBJS_BONUS) $(D_LIBFT)$(LIBFT)
#	@printf "%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)$(DEF_COLOR)\r"
#	@echo "$(LGREEN)Software Compilation completed !$(DEF_COLOR)"

#$(OBJS_BONUS): $(D_OBJ_BONUS)%.o : $(D_SRC_BONUS)%.c $(HEADER_BONUS)
#		$(call intro_bonus)
#		@mkdir -p $(D_OBJ_BONUS)
#		@$(call run_and_test, $(CC) $(CFLAGS) -c $< -o $@)

#bonus: $(NAME_BONUS)
#bonus: do_libft $(NAME_BONUS)

#tests:	

#btests : bonus
	
clean:
	@$(call cleaning, $(RM) $(D_OBJ))
	@$(RM) $(D_OBJ_BONUS)
#	@$(MAKE) --no-print-directory -C $(D_LIBFT) clean

fclean:	clean
	@$(call fcleaning, $(RM) $(NAME))
	@$(RM) $(NAME_BONUS)
#	@$(MAKE) --no-print-directory -C $(D_LIBFT) fclean

re:	fclean all

.PHONY: all clean fclean re