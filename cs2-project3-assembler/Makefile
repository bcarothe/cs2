#============================================================================
# Assembler and Stack
#
# CS II Kent State University
# Make file for string class and testing oracle
# J. Maletic 2016
#
#

###############################################################
# Variables
CPP          = clang++
CPP_FLAGS    = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11
INCLUDE_OPT  =

#This is teh path for your string.cpp and string.hpp
#Alternativly you can have a copy in the local folder and then: STRING_DIR = string/
STRING_DIR = ../assembler/

#===========================================================================
# Your STACK tests here.
STACK_TESTS =  test_default_ctor test_copy_ctor test_assignment test_push test_pop test_equality test_subscript test_swap test_end

#===========================================================================
# Your UTILITIES tests here.
UTILS_TESTS =  test_infix_to_postfix test_postfix_to_assembly test_infix_to_prefix test_prefix_to_assembly test_end


#===========================================================================
msg:
	@echo 'Targets for compiling test programs:'
	@echo '   tests'
	@echo '   testutils'
	@echo '   clean'
	@echo '   postfix'
	@echo '   assembler'
	@echo '   prefix'

#===========================================================================
# Compile string.o from Project 2.

string.o:	${STRING_DIR}string.hpp  ${STRING_DIR}string.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c ${STRING_DIR}string.cpp

#===========================================================================
# No compile for stack is needed - it is a template.



#===========================================================================
# Compile test programs
#
test_%: string.o test_%.o utilities.o
	${CPP} ${CPP_FLAGS} string.o test_$*.o -o test_$* utilities.o

test_%.o: ${STRING_DIR}string.hpp stack.hpp utilities.hpp test_%.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c test_$*.cpp


#===========================================================================
# Run test programs
# INSERT your tests for the stack here.

tests: stack.hpp ${STRING_DIR}string.hpp ${STACK_TESTS}
	./test_default_ctor
	./test_copy_ctor
	./test_assignment
	./test_push
	./test_pop
	./test_equality
	./test_subscript
	./test_swap
	./test_end

#===========================================================================
# Run test programs
# INSERT your tests for the utilities

testutils: utilities.hpp stack.hpp ${STRING_DIR}string.hpp ${UTILS_TESTS}
	./test_infix_to_postfix
	./test_postfix_to_assembly
	./test_infix_to_prefix
	./test_prefix_to_assembly
	./test_end



#===========================================================================
# Compile postfix

utilities.o: utilities.cpp utilities.hpp stack.hpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c utilities.cpp

postfix.o: postfix.cpp ${STRING_DIR}string.hpp stack.hpp utilities.hpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c postfix.cpp


postfix: postfix.o string.o utilities.o
	${CPP} ${CPP_FLAGS} postfix.o string.o utilities.o -o postfix

#===========================================================================
# Compile assembler

assembler.o: assembler.cpp ${STRING_DIR}string.hpp stack.hpp utilities.hpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c assembler.cpp

assembler: assembler.o string.o utilities.o
	${CPP} ${CPP_FLAGS} string.o assembler.o  utilities.o -o assembler

#===========================================================================
# Compile prefix

prefix.o: prefix.cpp ${STRING_DIR}string.hpp stack.hpp utilities.hpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c prefix.cpp

prefix: prefix.o string.o utilities.o
	${CPP} ${CPP_FLAGS} string.o prefix.o  utilities.o -o prefix



#============================================================================
clean:
	rm -f *.o
	rm -f postfix
	rm -f assembler
	rm -f $(STACK_TESTS)
	rm -f $(UTILS_TESTS)
	rm -f prefix
