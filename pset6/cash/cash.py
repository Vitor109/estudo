from cs50 import get_float


def main():
    while True:
        change_owed = get_float("Change owed: ")
        if change_owed >= 0:
            break

    # Convertendo o troco para centavos
    cents = round(change_owed * 100)

    # Contagem das moedas
    coins = 0

    # Moedas disponíveis
    denominations = [25, 10, 5, 1]

    # Calculando o número mínimo de moedas necessárias
    for denomination in denominations:
        coins += cents // denomination
        cents %= denomination

    print(coins)


if __name__ == "__main__":
    main()
