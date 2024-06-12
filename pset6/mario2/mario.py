def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                return height
            else:
                print("Altura deve estar entre 1 e 8.")
        except ValueError:
            print("Por favor, insira um número inteiro.")


def print_double_pyramid(height):
    for i in range(1, height + 1):
        spaces = " " * (height - i)
        blocks1 = "#" * i
        blocks2 = "#" * i  # Ambas as pirâmides têm a mesma quantidade de blocos
        print(f"{spaces}{blocks1}  {blocks2}")


def main():
    height = get_height()
    print_double_pyramid(height)


if __name__ == "__main__":
    main()
