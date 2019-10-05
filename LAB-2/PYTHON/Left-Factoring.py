


def common_prefix(strings):

    if len(strings) == 1:
        return strings[0]

    prefix = strings[0]

    for string in strings[1:]:
        while string[:len(prefix)] != prefix and prefix:
            prefix = prefix[:len(prefix)-1]
        if not prefix:
            break

    return prefix



def Left_Factor():
    production = []
    pro = []
    pros = []
    result = []
    bs = ""
    n = int(input(" Enter the no of Grammar that you want to gave : = "))
    print(" <<== Enter the productions ==>> ")
    for i in range(n):
        production.append(input())
    for i in range(len(production)) :
        if production[i].find("|") :
            pro = production[i].split("->")
            pros = pro[1].split("|")
            com = common_prefix(pros)
            l = len(com)
        result.append(pro[0] + " -> " + com + pro[0] +"'")
        for b in pros :
            bs = bs + b[l:] + "|"

        result.append(pro[0] + "'" + " -> " +bs)

    return result




if __name__ == "__main__" :
    production = Left_Factor()
    for result in production :
        print(result)



