const csrftokenCookie = document.cookie.split(';').find(cookie => cookie.trim().startsWith('csrftoken='));
const csrftoken = csrftokenCookie ? csrftokenCookie.split('=')[1] : null;

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
            parte.dataset.value = parte_number;
        }
        else {
            parte_number = 3;
            parte.dataset.value = parte_number;
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
            parte.dataset.value = parte_number;
        }
        else {
            parte_number = 1;
            parte.dataset.value = parte_number;
        }
        parte.src = parte_src_array.slice(0, -1).join('/') + '/' + parte_src_array[parte_src_array.length - 1].replace(/\d+/, parte_number);
    });
});

let salvar_button = document.querySelector('#salvar_button');

salvar_button.addEventListener('click', e => {
    let data = {
        'nome': document.querySelector('#nome').value,
        'classe': document.querySelector('#classe').value,
        'cabeca': document.querySelector('.cabeca').dataset.value,
        'corpo': document.querySelector('.corpo').dataset.value,
        'pernas': document.querySelector('.pernas').dataset.value,
        'hp': document.querySelector('#hp').value,
        'ee': document.querySelector('#ee').value,
        'ataque': document.querySelector('#ataque').value,
        'defesa': document.querySelector('#defesa').value,
        'sp_ataque': document.querySelector('#sp_ataque').value,
        'sp_defesa': document.querySelector('#sp_defesa').value,
        'velocidade': document.querySelector('#velocidade').value,
        'skill1': document.querySelector('#skill1').value,
        'skill2': document.querySelector('#skill2').value,
        'skill3': document.querySelector('#skill3').value,
        'skill4': document.querySelector('#skill4').value
    }

    fetch('/personagens/', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'X-CSRFToken': csrftoken
        },
        body: JSON.stringify(data)
    })
    .then(res => res.json())
    .then(res => {
        if (res.ok) {
            window.location.reload();
        }
    })
});