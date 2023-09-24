from django.shortcuts import render

# Create your views here.
def escolher_personagens(request):
    return render(request, 'escolher_personagens.html')