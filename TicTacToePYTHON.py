class Block():
    def __init__(self):
        self.state = 0

    def mark(self, playernum):
        self.state = playernum
        # 0 for blank 1 for X 2 for 0


table = list()


def print_table():
    print('\n')
    for i in range(0, 9, 3):
        for j in range(i, i+3):
            if table[j].state == 0:
                print(f' {j} ', end=' ')
            elif table[j].state == 1:
                print(" X ", end=' ')
            elif table[j].state == 2:
                print(" O ", end=' ')
            if j not in [2, 5, 8]:
                print('|', end=' ')
        print('\n')


def check_win(last_index, player):
    if horizontal_check(last_index):
        print(f"Congratulations Player {player}!")
        return 1
    elif vertical_check(last_index):
        print(f"Congratulations Player {player}!")
        return 1
    elif diagonal_check(last_index):
        print(f"Congratulations Player {player}!")
        return 1


def horizontal_check(last_index):
    if last_index in [0, 1, 2]:
        last_index = 0
    elif last_index in [3, 4, 5]:
        last_index = 3
    elif last_index in [6, 7, 8]:
        last_index = 6
    for i in range(last_index, last_index + 3):
        if table[i].state != table[last_index].state:
            return 0
    return 1


def vertical_check(last_index):
    if last_index in [0, 3, 6]:
        last_index = 0
    elif last_index in [1, 4, 7]:
        last_index = 1
    elif last_index in [2, 5, 8]:
        last_index = 2
    for i in range(last_index, 9, 3):
        if table[i].state != table[last_index].state:
            return 0
    return 1


def diagonal_check(last_index):
    dlist1 = [0, 4, 8]
    dlist2 = [2, 4, 6]
    if last_index in dlist1:
        for i in dlist1:
            if table[i].state != table[last_index].state:
                return 0
        return 1
    if last_index in dlist2:
        for i in dlist2:
            if table[i].state != table[last_index].state:
                return 0
        return 1


for i in range(0, 9):
    new_block = Block()
    table.append(new_block)
try:
    for i in range(0, 9):
        if i % 2 == 0:
            lastindex = int(input("Player 1 Choose : "))
            table[lastindex].mark(1)
            if check_win(lastindex, 1):
                print_table()
                break
            print_table()
            continue
        lastindex = int(input("Player 2 Choose : "))
        table[lastindex].mark(2)
        if check_win(lastindex, 2):
            print_table()
            break
        print_table()
        continue
except IndexError:
    print("ERROR : Cant Take Index That is Not in Table")
