from cs50 import get_float


def main():
    change = -1
    while (change < 0):
        change = get_float("Change owed: ")

    quarters = get_quarters(change)
    change -= quarters * 0.25

    dimes = get_dimes(change)
    change -= dimes * 0.10

    nickels = get_nickels(change)
    change -= nickels * 0.05

    pennies = get_pennies(change)
    change -= pennies * 0.01

    coins = quarters + dimes + nickels + pennies
    print(coins)


def get_quarters(change):
    i = 0
    while (change >= 0.249):
        change -= 0.25
        i += 1
    return (i)


def get_dimes(change):
    i = 0
    while (change >= 0.099):
        change -= 0.10
        i += 1
    return (i)


def get_nickels(change):
    i = 0
    while (change >= 0.049):
        change -= 0.05
        i += 1
    return (i)


def get_pennies(change):
    i = 0
    while (change >= 0.009):
        change -= 0.01
        i += 1
    return (i)


main()