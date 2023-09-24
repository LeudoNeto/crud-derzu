from django.urls import path
from .views import escolher_personagens, partida

urlpatterns = [
    path('escolher_personagens', escolher_personagens),
    path('partida/<int:id_1>/<int:id_2>', partida),
]
