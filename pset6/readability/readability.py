from cs50 import get_string


def main():
    # Solicitar ao usuário um texto
    text = get_string("Text: ")

    # Contar o número de letras, palavras e frases no texto
    num_letters = sum(c.isalpha() for c in text)
    num_words = len(text.split())
    num_sentences = text.count('.') + text.count('!') + text.count('?')

    # Calcular o índice Coleman-Liau
    L = (num_letters / num_words) * 100
    S = (num_sentences / num_words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8

    # Arredondar o índice para o inteiro mais próximo
    grade = round(index)

    # Imprimir o resultado
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


if __name__ == "__main__":
    main()
