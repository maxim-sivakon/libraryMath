CC= gcc
CLANGFILE = *.c *.h
CFLAGS= -g -Wall -Werror -Wextra -std=c11
# CFLAGS= -g -std=c11
LDFLAGS= -lcheck
UNAME= $(shell uname -s)
ifeq ($(UNAME), Linux)
	LDFLAGS += -lm -lsubunit -lpthread -lrt
	CFLAGS += -lm
endif
MY_LIB_NAME= s21_math.a

source_files= s21_*.c
object_files= s21_*.o

source_files_test= *test.c
object_files_test= *test.o

all: clean $(MY_LIB_NAME) gcov_report clang_check

$(MY_LIB_NAME): to_objects
	ar rcs $(MY_LIB_NAME) $(object_files)
	ranlib $(MY_LIB_NAME)

test: to_objects to_objects_test
	$(CC) $(object_files) $(object_files_test) $(LDFLAGS) -o test
	./test

gcov_report:
	$(CC) $(source_files) $(source_files_test) $(LDFLAGS) --coverage -o test
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
ifeq ($(UNAME), Linux)
	xdg-open report/index.html
else
	open report/index.html
endif
	rm -rf *.o
clang_check:
		cp ../materials/linters/.clang-format .
		clang-format -n --style=Google $(CLANGFILE)
		rm -f .clang-format


clang_format:
		cp ../materials/linters/.clang-format .
		clang-format -i --style=Google $(CLANGFILE)
		rm -f .clang-format


leak_check: test
ifeq ($(UNAME), Linux)
	CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck --trace-children=yes --track-origins=yes ./test
else
	CK_FORK=no leaks -atExit -- ./test
endif

to_objects:
	$(CC) -c $(CFLAGS) $(source_files)
to_objects_test:
	$(CC) -c $(source_files_test)
clean:
	rm -rf *.o *.a *.gcno *.gcda *.info test report
