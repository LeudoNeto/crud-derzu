from PIL import Image

for x in range(3):
    for y in range(3):
        for z in range(3):
            # Carregue as imagens das cabeças, corpos e pernas
            cabeca = Image.open(f'assets\partes_personagem\cabeca{x+1}.png')
            corpo = Image.open(f'assets\partes_personagem\corpo{y+1}.png')
            pernas = Image.open(f'assets\partes_personagem\pernas{z+1}.png')

            # Verifique se as imagens têm o mesmo tamanho
            if cabeca.size != corpo.size or cabeca.size != pernas.size:
                raise ValueError("As imagens devem ter o mesmo tamanho.")

            # Crie uma nova imagem para o personagem completo
            largura, altura = cabeca.size
            personagem_completo = Image.new("RGBA", (largura, altura))

            # Sobreponha as imagens da cabeça, corpo e pernas na nova imagem
            personagem_completo.paste(pernas, (0, 4), pernas)
            personagem_completo.paste(corpo, (0, 3), corpo)
            personagem_completo.paste(cabeca, (0, 0), cabeca)
            
            

            # Salve o personagem completo em um arquivo
            personagem_completo = personagem_completo.resize((140, 140), Image.NEAREST)
            personagem_completo.save(f'assets\personagem_completo\{9*x + 3*y + z}.png')

            # Mostrar o personagem completo
            # personagem_completo.show()
