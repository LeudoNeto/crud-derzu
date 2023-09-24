from django.urls import path
from .views import escolher_personagens

urlpatterns = [
    path('escolher_personagens', escolher_personagens),
    # path('partida/<int:id_1>/<int:id_2>', PersonagensAPIView.as_view()),
]
