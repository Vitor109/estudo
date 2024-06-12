import csv
import sys


def main():
    # Verificar se o número correto de argumentos da linha de comando é fornecido
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Abrir o arquivo CSV e ler seu conteúdo na memória
    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        # Obter os STRs do arquivo CSV
        strs = reader.fieldnames[1:]

        # Abrir o arquivo de sequência de DNA e ler seu conteúdo na memória
        with open(sys.argv[2]) as dnafile:
            dna_sequence = dnafile.read()

            # Calcular o número de repetições de cada STR na sequência de DNA
            str_counts = {str: max_repeats(dna_sequence, str) for str in strs}

            # Comparar os resultados com as entradas no arquivo CSV
            match = find_match(reader, str_counts)
            if match:
                print(match)
            else:
                print("No match")


def max_repeats(dna_sequence, str):
    """
    Função para calcular o número máximo de repetições consecutivas de um determinado STR em uma sequência de DNA.
    """
    max_repeats = 0
    length = len(str)
    i = 0
    while i < len(dna_sequence):
        repeat_count = 0
        while dna_sequence[i:i+length] == str:
            repeat_count += 1
            i += length
        max_repeats = max(max_repeats, repeat_count)
        i += 1
    return max_repeats


def find_match(reader, str_counts):
    """
    Função para comparar os resultados com as entradas no arquivo CSV e encontrar uma correspondência.
    """
    for row in reader:
        match = True
        for str, count in str_counts.items():
            if int(row[str]) != count:
                match = False
                break
        if match:
            return row['name']
    return None


if __name__ == "__main__":
    main()
