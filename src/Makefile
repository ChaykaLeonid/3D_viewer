OS = $(shell uname)
CC = gcc
CFLAGS = -lstdc++ -lgtest -std=c++17 -Wall -Werror -Wextra
LINUX = -lsubunit -lrt -lpthread -lm -g

TESTS = unit_tests
BUILDTESTS = Test/unit_tests.cc

all: uninstall clean install

install: clean
ifeq ($(OS), Darwin)
	@mkdir build
	@cd View && qmake6 && make && make clean && rm Makefile && mv 3DViewer_v2-0.app ../build/ && cd ../
else
	@mkdir build
	@cd View && qmake6 && make && make clean && rm Makefile && mv 3DViewer_v2-0 ../build/ && cd ../
endif

uninstall:
	@rm -rf build*

clean:
	@/bin/rm -rf **/*.o *.a build *.gcno *gcda report *.info main *.dSYM *.out gcov_report $(TESTS) View/.qmake.stash View/3DViewer_v2-0.pro.user View/.qtc_clangd build-3DViewer_v2-0-Desktop_x86_darwin_generic_mach_o_64bit-Debug ../Archive_3DViewer_v2-0.tar.gz Archive_3DViewer_v2-0 RESULT_VALGRIND.txt

dvi:
	@open ./dvi.html
	
dist: 
ifeq ($(OS), Darwin)
	@rm -rf Archive_3DViewer_v2-0/
	@mkdir Archive_3DViewer_v2-0/
	@mkdir Archive_3DViewer_v2-0/src
	@mv  ./build/3DViewer_v2-0.app  Archive_3DViewer_v2-0/src/
	@tar cvzf Archive_3DViewer_v2-0.tgz Archive_3DViewer_v2-0/
	@rm -rf Archive_3DViewer_v2-0/
else
	@rm -rf Archive_3DViewer_v2-0/
	@mkdir Archive_3DViewer_v2-0/
	@mkdir Archive_3DViewer_v2-0/src
	@mv  ./build/3DViewer_v2-0 Archive_3DViewer_v2-0/src/
	@tar cvzf Archive_3DViewer_v2-0.tgz Archive_3DViewer_v2-0/
	@rm -rf Archive_3DViewer_v2-0/
endif

tests: build_tests
	@./$(TESTS)

build_tests: $(BUILDTESTS)
ifeq ($(OS), Darwin)
	@$(CC) $< Model/**/*.cc Controller/*.cc $(CFLAGS) -o $(TESTS)
else
	@$(CC) $< Model/**/*.cc Controller/*.cc $(CFLAGS) $(LINUX) -o $(TESTS)
endif

leaks: tests 
ifeq ($(OS), Darwin)
	@CK_FORK=no leaks --atExit -- ./$(TESTS)
else
	@CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./$(TESTS)
endif

style:
	@cp ../materials/linters/.clang-format .
	@clang-format -style=Google -n **/*.cc **/*.h
	@rm -rf .clang-format
