from django.urls import path
from .views import escolher_personagens, partida, calcular_dano, passiva

urlpatterns = [
    path('escolher_personagens', escolher_personagens),
    path('partida/<int:id_1>/<int:id_2>', partida),
    path('calcular_dano', calcular_dano.as_view()),
    path('passiva', passiva.as_view())
]
