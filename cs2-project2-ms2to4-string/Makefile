###############################################################
# String & Oracle
#
# CS II Kent State University
# Make file for string class and testing oracle
# J. Maletic Fall 2016
#
#

###############################################################
# Variables
CPP     = clang++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11


# Names of your test files - add them in as you build them.
# Names must start with "test_"
MYTESTS = test_default_ctor test_char_ctor test_char_array_ctor test_swap test_assignment test_subscript test_capacity test_length test_addition test_plus_equals test_equal test_less_than test_substr test_findchar test_findstr test_split test_output test_input test_less_than_or_equal test_not_equal test_greater_than_or_equal test_greater_than test_pass
# Names of test oracle files
CTOR = testoracle_ctor_default testoracle_ctor_char testoracle_ctor_charArray
REL  = testoracle_equal testoracle_lessThan
COPY = testoracle_ctor_copy testoracle_assign
OPS  = testoracle_concat

###############################################################
# Compile just the string
# Compile and run all provided test oracles on string
# Compile and run all your tests on string
# Compile and run the project
msg:
@echo 'Targets are:'
@echo '  string'
@echo '  tests'
@echo '  oracle'
@echo '  logview'
@echo '  clean'



###############################################################
# Compile string
#
string.o: string.hpp string.cpp
$(CPP) -c $(OPTIONS) string.cpp -o string.o

string: string.o


###############################################################
# Run all of your tests
#
# You will need to ADD your other below:
# For example: ./test_plus
#
tests: $(MYTESTS)
./test_default_ctor
./test_char_ctor
./test_char_array_ctor
./test_swap
./test_assignment
./test_subscript
./test_capacity
./test_length
./test_addition
./test_plus_equals
./test_equal
./test_less_than
./test_substr
./test_findchar
./test_findstr
./test_split
./test_output
./test_input
./test_less_than_or_equal
./test_not_equal
./test_greater_than_or_equal
./test_greater_than
./test_pass



###############################################################
# Compile all test programs
#
test_%: string.o test_%.o
$(CPP) string.o test_$*.o -o test_$*

test_%.o: string.hpp test_%.cpp
$(CPP) $(OPTIONS) -c test_$*.cpp



###############################################################
# Run test oracle
# Comment out one's you don't want to run.
#
oracle: $(CTOR) $(REL) $(COPY) $(OPS)
./testoracle_ctor_default
./testoracle_ctor_char
./testoracle_ctor_charArray
#./testoracle_ctor_int
#./testoracle_ctor_charArray_int
./testoracle_equal
./testoracle_lessThan
./testoracle_ctor_copy
./testoracle_assign
./testoracle_concat


###############################################################
# Compile all test programs
#
testoracle_%: string.o testoracles/testoracle_%.o
$(CPP) string.o testoracles/testoracle_$*.o -o testoracle_$*




###############################################################
# Compile Project
#

logview.o: logview.cpp logentry.hpp string.hpp
$(CPP) -c $(OPTIONS) logview.cpp -o logview.o

logentry.o: logentry.cpp logentry.hpp string.hpp
$(CPP) -c $(OPTIONS) logentry.cpp -o logentry.o

logview: logview.o string.o logentry.o
$(CPP) $(OPTIONS) logview.o string.o logentry.o -o logview


###############################################################
# clean
# Removes all .o files and all executables
#
clean:
rm -f *.o
rm -f $(CTOR) $(REL) $(COPY) $(OPS)
rm -f $(MYTESTS)
rm -f logview
