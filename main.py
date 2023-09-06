import subprocess

# Compila o arquivo C++
subprocess.run(["g++", "vector_example.cpp", "-o", "vector_example"], shell=True)

# # Executa o arquivo compilado e captura a saída
# completed_process = subprocess.run("./vector_example", stdout=subprocess.PIPE, text=True, shell=True)
# output = completed_process.stdout

# # Processa a saída para criar uma lista
# vector_elements = output.strip().split()
# vector_list = [int(element) for element in vector_elements]

# print("Lista equivalente:", vector_list)
