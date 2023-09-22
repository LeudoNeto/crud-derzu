from PIL import Image

for x in range(3):
    cabeca = Image.open(f'assets\partes_personagem\cabeca{x+1}.png')
    cabeca = cabeca.crop((4, 1, 27, 18))
    cabeca = cabeca.resize((46, 34), Image.NEAREST)
    cabeca.save(f'assets\partes_tratadas\cabeca{x+1}.png')

    corpo = Image.open(f'assets\partes_personagem\corpo{x+1}.png')
    corpo = corpo.crop((4, 14, 27, 20))
    corpo = corpo.resize((46, 12), Image.NEAREST)
    corpo.save(f'assets\partes_tratadas\corpo{x+1}.png')

    pernas = Image.open(f'assets\partes_personagem\pernas{x+1}.png')
    pernas = pernas.crop((4, 19, 27, 25))
    pernas = pernas.resize((46, 12), Image.NEAREST)
    pernas.save(f'assets\partes_tratadas\pernas{x+1}.png')