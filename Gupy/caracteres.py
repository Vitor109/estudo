def inverter_string(string):
    # Converte a string para uma lista de caracteres
    caracteres = list(string)

    # Obtém o comprimento da string
    comprimento = len(caracteres)

    # Inverte a lista de caracteres trocando os caracteres de posição
    for i in range(comprimento // 2):
        temp = caracteres[i]
        caracteres[i] = caracteres[comprimento - i - 1]
        caracteres[comprimento - i - 1] = temp

    # Converte a lista de caracteres de volta para uma string
    string_invertida = ''.join(caracteres)

    return string_invertida

# String de exemplo
string = "Exemplo"

# Chama a função para inverter a string
string_invertida = inverter_string(string)

# Exibe a string invertida
print("String invertida:", string_invertida)
