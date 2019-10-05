

"""
 * @author radhetians
 * E->TE'
 * E'->+TE'|NULL
 * T->FT'
 * T'->*FT'|NULL
 * F->(E)|a
"""


class RecursiveDescent:

    def __init__(self,InputString):
        self.InputString = InputString
        self.lookahead ='$'
        self.length = len(InputString)
        self.len = 0
        self.Match()
        self.E()
        if self.lookahead == '$' :
            print("Accept")
        else:
            print("Error")

    def Match(self):
        self.lookahead = self.InputString[self.len]
        self.len = self.len + 1
    def E(self):
        self.T()
        self.EDS()

    def EDS(self):
        if self.lookahead == '+' :
            self.Match()
            self.T()
            self.EDS()
        else :
            return

    def T(self):
        self.F()
        self.TDS()


    def TDS(self):
        if self.lookahead == '*' :
            self.Match()
            self.F()
            self.TDS()
        else:
            return


    def F(self):
        if self.lookahead == '(' :
            self.Match()
            self.E()
            if self.lookahead == ')' :
                self.Match()

        else:
            self.Match()

def main() :
    while True:
        InuptString = input("Enter the Input String ::==  ")
        RecursiveDescent(InuptString)

if __name__ == '__main__':
    main()










