
def Left_Recursion() :
    p = []
    temp = []
    result = []
    a = []
    b = []
    n = int(input("Enter no. of Grammars that you want :== "))
    print(" <<== Enter the Productions ==>> ")
    for i in range(0, n):
        p.append(input())
    for i in range(0, len(p)):

        t = []
        for j in range(0, len(p[i])):

            if (p[i][j] != "|"):
                t.append(p[i][j])
            else:
                temp.append(t)
                t = []
            if (j == len(p[i]) - 1):
                temp.append(t)

        for x in range(0, len(temp)):
            if (x == 0):
                if (temp[x][0] == temp[x][3]):
                    a.append(temp[x][4:len(temp[x]) + 1])

                else:
                    result.append(p[i])
                    break
            else:
                if (temp[x][0] == temp[0][0]):
                    a.append(temp[x][1:len(temp[x]) + 1])
                else:
                    b.append(temp[x])

        for i in range(0, len(a)):
            s = ""
            for j in range(0, len(a[i])):
                s = s + a[i][j]

            result.append(temp[0][0] + "'" + " -> " + s + temp[0][0] + "'" + " | E")
        for i in range(0, len(b)):
            s = ""
            for j in range(0, len(b[i])):
                s = s + b[i][j]

            result.append(temp[0][0] + " -> " + s + temp[0][0] + "'")
        temp = []
        t = []
        a = []
        b = []
    return result

if __name__ == "__main__" :
    production =Left_Recursion()
    print("\n <<=== Grammar ===>>\n")
    for result in production :
        print(result)


