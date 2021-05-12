# Stores the name of the homework. This name can be obtained by
# removing your username from the repository that was created for your
# Github account.
#
# This variable is used in order to instruct make that only those unit
# tests which belong to that homework. That is, all unit tests whose
# filename contain the given string.

ifndef HOMEWORK_NAME
$(error HOMEWORK_NAME is not set)
endif

# Stores the name of the directory which contains the files from a
# single homework.
#
# This variable is used in order to instruct make that consider those
# header files those unit testings that belong to that homework

ifndef HOMEWORK_LOCATION
$(error HOMEWORK_LOCATION is not set)
endif

SRC_TESTS ?= $(shell find . -regextype egrep -type f \( -regex "./tests-$(HOMEWORK_NAME)(-?.+)*\.cpp" -a ! -name 'tests-$.cpp' \))

CXX ?= g++
CXX_FLAGS ?= -I $(HOMEWORK_LOCATION)

CATCH2_BIN ?= ./a.out
CATCH2_FLAGS ?=

tests-main.o: tests-main.cpp
	$(CXX) $(CXX_FLAGS) -c tests-main.cpp -o $(CATCH2_BIN)

clean:
	rm $(CATCH2_BIN)

run: tests-main.o
	$(CXX) $(CXX_FLAGS) tests-main.o $(SRC_TESTS)
	$(CATCH2_BIN) $(CATCH2_FLAGS)

