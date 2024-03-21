CC=g++
FLAGS=-Wall -Werror -Wextra
TEST_FLAGS=-lgtest
NAME=quadratic_equation

all: check

$(NAME).a: clean
	$(CC) $(FLAGS) -c $(NAME).c
	ar rc $(NAME).a $(NAME).o
	ranlib $(NAME).a
	rm *.o


check: $(NAME).a
	@$(CC) $(FLAGS) $(TEST_FLAGS) tests_to_$(NAME).c $(NAME).a -o unit_tests
	./unit_tests

leaks: check
	leaks --atExit -- ./unit_tests

clean:
	rm -rf unit_tests
	rm -rf $(NAME).a
