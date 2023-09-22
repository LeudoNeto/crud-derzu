var status_inputs = document.querySelectorAll('.atribuir_status input, .status_restantes input');
var restantes_number = document.querySelector('#restantes_number');

status_inputs.forEach((input) => {
    input.addEventListener('input', e => {
        let sum = 0;

        // Calcular a soma dos valores dos campos de entrada
        status_inputs.forEach((input) => {
          if (!isNaN(Number(input.value))) {
            sum += Number(input.value);
          }
        });
      
        // Calcular o valor restante
        let remaining = 100 - sum;
      
        if (remaining < 0) {
            input.value = Number(input.value) + remaining;
            remaining = 0;
        }

        // Atualizar o #restantes_number com o valor restante
        restantes_number.textContent = remaining;
    });
});

setas_esquerdas = document.querySelectorAll('.seta_esquerda');

setas_esquerdas.forEach((seta) => {
    seta.addEventListener('click', e => {
        let parte = seta.nextElementSibling;
        let parte_src = parte.src;
        let parte_src_array = parte_src.split('/');
        let parte_number = parte_src_array[parte_src_array.length - 1].split('.')[0].match(/\d+/)[0];
        if (parte_number > 1) {
            parte_number--;
        }
        else {
            parte_number = 3;
        }
        parte.src = parte_src_array.slice(0, -1).join('/') + '/' + parte_src_array[parte_src_array.length - 1].replace(/\d+/, parte_number);
    });
});

setas_direitas = document.querySelectorAll('.seta_direita');

setas_direitas.forEach((seta) => {
    seta.addEventListener('click', e => {
        let parte = seta.previousElementSibling;
        let parte_src = parte.src;
        let parte_src_array = parte_src.split('/');
        let parte_number = parte_src_array[parte_src_array.length - 1].split('.')[0].match(/\d+/)[0];
        if (parte_number < 3) {
            parte_number++;
        }
        else {
            parte_number = 1;
        }
        parte.src = parte_src_array.slice(0, -1).join('/') + '/' + parte_src_array[parte_src_array.length - 1].replace(/\d+/, parte_number);
    });
});