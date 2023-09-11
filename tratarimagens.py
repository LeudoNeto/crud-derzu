from PIL import Image

for x in range(3):
    cabeca = Image.open(f'assets\partes_personagem\cabeca{x+1}.png')
    cabeca = cabeca.crop((4, 1, 27, 17))
    cabeca.save(f'assets\partes_tratadas\cabeca{x+1}.png')
