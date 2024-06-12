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


def print_pyramid(height):
    for i in range(1, height + 1):
        spaces = " " * (height - i)
        blocks = "#" * i
        print(f"{spaces}{blocks}")


def main():
    height = get_height()
    print_pyramid(height)


if __name__ == "__main__":
    main()
