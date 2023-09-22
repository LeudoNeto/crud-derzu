from django.shortcuts import render

# Create your views here.
def gerenciar(request):
    return render(request, 'gerenciar.html')