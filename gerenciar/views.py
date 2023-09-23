from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status

# Create your views here.
def gerenciar(request):
    return render(request, 'gerenciar.html')

class PersonagensAPIView(APIView):

    def post(self, request):
        print(request.data)
        return Response({'mensagem': 'Criando personagem'})