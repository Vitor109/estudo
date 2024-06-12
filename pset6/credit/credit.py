import re
from cs50 import get_string


def main():
    # Solicitar ao usuário um número de cartão de crédito
    while True:
        card_number = get_string("Number: ").replace(" ", "")  # Remover espaços em branco
        if re.match("^[0-9]+$", card_number):
            break

    # Verificar a validade do número do cartão
    card_type = check_card_type(card_number)
    if card_type == "AMEX":
        print("AMEX")
    elif card_type == "MASTERCARD":
        print("MASTERCARD")
    elif card_type == "VISA":
        print("VISA")
    else:
        print("INVALID")


def check_card_type(card_number):
    if re.match("^3[47][0-9]{13}$", card_number):
        return "AMEX"
    elif re.match("^5[1-5][0-9]{14}$", card_number):
        return "MASTERCARD"
    elif re.match("^4[0-9]{12}([0-9]{3})?$", card_number):
        return "VISA"
    else:
        return "INVALID"


if __name__ == "__main__":
    main()
