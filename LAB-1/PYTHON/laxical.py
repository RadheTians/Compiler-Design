
import Keywords
import Operators
import Delimiters
file = open("fibonacci.cpp")
l=1

for line in file :
    print("---------------------LINE-----------------: ",l)
    print()

    print("----------KEYWORDS---------")
    temp = Keywords.keyword(line)
    for t in temp :
        print(t,end="  ")
    print()

    print("----------OPERATORS---------")
    temp = Operators.operator(line)
    for t in temp :
        print(t,end="  ")
    print()

    print("----------DELIMITER---------")
    temp = Delimiters.delimiter(line)
    for t in temp :
        print(t,end="  ")
    print('\n')
    l+=1
