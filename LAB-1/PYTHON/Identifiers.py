
import re
def identifier(s) :
    regular = re.compile("(int [a-z]*[A-Z]*[0-9]*)|(float [a-z]*[A-Z]*[0-9]*)|(double [a-z]*[A-Z]*[0-9]*)|(char [a-z]*[A-Z]*[0-9]*)")