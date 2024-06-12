def verifica_fibonacci(numero):
    # Inicializa os dois primeiros números da sequência de Fibonacci
    a, b = 0, 1

    # Verifica se o número informado é um dos dois primeiros números
    if numero == a or numero == b:
        return True

    # Calcula a sequência de Fibonacci até atingir ou ultrapassar o número informado
    while b < numero:
        a, b = b, a + b
        if b == numero:
            return True

    return False

# Solicita um número ao usuário
numero_informado = int(input("Digite um número para verificar se pertence à sequência de Fibonacci: "))

# Verifica se o número informado pertence à sequência de Fibonacci e exibe uma mensagem correspondente
if verifica_fibonacci(numero_informado):
    print(f"O número {numero_informado} pertence à sequência de Fibonacci.")
else:
    print(f"O número {numero_informado} não pertence à sequência de Fibonacci.")
