from PIL import Image

mapa = Image.open(f'assets/img/mapa_partida.png')
mapa = mapa.resize((720, 720), Image.NEAREST)
mapa.save(f'assets/img/mapa_partida.png')