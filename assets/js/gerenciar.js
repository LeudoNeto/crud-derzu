const csrftokenCookie = document.cookie.split(';').find(cookie => cookie.trim().startsWith('csrftoken='));
const csrftoken = csrftokenCookie ? csrftokenCookie.split('=')[1] : null;

var status_inputs = document.querySelectorAll('.atribuir_status input, .status_restantes input');
var restantes_number = document.querySelector('#restantes_number');
var status_inputs_editar = document.querySelectorAll('.atribuir_status_editar input, .status_restantes_editar input');
var restantes_number_editar = document.querySelector('#restantes_number_editar');
var setas_esquerdas = document.querySelectorAll('.seta_esquerda');
var setas_direitas = document.querySelectorAll('.seta_direita');
var personagens = document.querySelectorAll('.personagem');
var salvar_button = document.querySelector('#salvar_button');
var editar_button = document.querySelector('#editar_button');
var salvar_button_editar = document.querySelector('#salvar_button_editar');
var deletar_button = document.querySelector('#deletar_button');
var target_id;

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

status_inputs_editar.forEach((input) => {
    input.addEventListener('input', e => {
        let sum = 0;

        // Calcular a soma dos valores dos campos de entrada
        status_inputs_editar.forEach((input) => {
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
        restantes_number_editar.textContent = remaining;
    });
});

function getParteNumberBySrc(parte) {
    let parte_src = parte.src;
    let parte_src_array = parte_src.split('/');
    return parte_src_array[parte_src_array.length - 1].split('.')[0].match(/\d+/)[0];
}

function getParteSrcByNumber(parte, parte_number) {
    let parte_src = parte.src;
    let parte_src_array = parte_src.split('/');
    return parte_src_array.slice(0, -1).join('/') + '/' + parte_src_array[parte_src_array.length - 1].replace(/\d+/, parte_number);
}

setas_esquerdas.forEach((seta) => {
    seta.addEventListener('click', e => {
        let parte = seta.nextElementSibling;
        let parte_number = getParteNumberBySrc(parte);

        if (parte_number > 1) {
            parte_number--;
            parte.dataset.value = parte_number;
        }
        else {
            parte_number = 3;
            parte.dataset.value = parte_number;
        }

        parte.src = getParteSrcByNumber(parte, parte_number);
    });
});

setas_direitas.forEach((seta) => {
    seta.addEventListener('click', e => {
        let parte = seta.previousElementSibling;
        let parte_number = getParteNumberBySrc(parte);

        if (parte_number < 3) {
            parte_number++;
            parte.dataset.value = parte_number;
        }
        else {
            parte_number = 1;
            parte.dataset.value = parte_number;
        }

        parte.src = getParteSrcByNumber(parte, parte_number);
    });
});

salvar_button.addEventListener('click', e => {
    let data = {
        'nome': document.querySelector('#nome').value,
        'classe': document.querySelector('#classe').value,
        'cabeca': document.querySelector('#cabeca').dataset.value,
        'corpo': document.querySelector('#corpo').dataset.value,
        'pernas': document.querySelector('#pernas').dataset.value,
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

    Swal.fire({
        title: 'Salvando personagem.',
        text: 'Enviando os dados.',
        icon: 'info',
        showConfirmButton: false
    });

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
        if(res.sucesso) {
            Swal.fire({
                title: 'Personagem criado com sucesso.',
                text: 'Atualizando a lista de personagens.',
                icon: 'success',
                showConfirmButton: false
            });
            window.location.reload();
        } else {
            Swal.fire({
                title: 'Ocorreu um erro na criação do personagem.',
                text: res.erro,
                icon: 'error',
                confirmButtonText: 'Entendi',
                confirmButtonColor: '#f27474'
            });
        }
    })
});

personagens.forEach((personagem) => {
    personagem.addEventListener('click', e => {
        let id = personagem.dataset.id;
        target_id = id;

        Swal.fire({
            title: 'Carregando personagem.',
            text: 'Buscando os dados.',
            icon: 'info',
            showConfirmButton: false
        });

        fetch('/personagens/' + id)
        .then(res => res.json())
        .then(res => {
            if(res.nome) {
                Swal.fire({
                    title: 'Personagem carregado com sucesso.',
                    icon: 'success',
                    showConfirmButton: false
                });
                document.querySelector('#nome_personagem_detalhes').textContent = res.nome;
                document.querySelector('#nome_detalhes').value = res.nome;
                document.querySelector('#classe_detalhes').value = res.classe;
                document.querySelector('#aparencia_detalhes').src = getParteSrcByNumber(document.querySelector('#aparencia_detalhes'), res.aparencia);
                document.querySelector('#aparencia_detalhes').dataset.cabeca = res.cabeca;
                document.querySelector('#aparencia_detalhes').dataset.corpo = res.corpo;
                document.querySelector('#aparencia_detalhes').dataset.pernas = res.pernas;
                document.querySelector('#hp_detalhes').value = res.hp;
                document.querySelector('#ee_detalhes').value = res.ee;
                document.querySelector('#ataque_detalhes').value = res.ataque;
                document.querySelector('#defesa_detalhes').value = res.defesa;
                document.querySelector('#sp_ataque_detalhes').value = res.sp_ataque;
                document.querySelector('#sp_defesa_detalhes').value = res.sp_defesa;
                document.querySelector('#velocidade_detalhes').value = res.velocidade;
                document.querySelector('#skill1_detalhes').value = res.skill1;
                document.querySelector('#skill2_detalhes').value = res.skill2;
                document.querySelector('#skill3_detalhes').value = res.skill3;
                document.querySelector('#skill4_detalhes').value = res.skill4;
                Swal.close();
            } else {
                Swal.fire({
                    title: 'Ocorreu um erro ao carregar o personagem.',
                    text: res.erro,
                    icon: 'error',
                    confirmButtonText: 'Entendi',
                    confirmButtonColor: '#f27474'
                });
            }
        })
    });
});

editar_button.addEventListener('click', e => {
    document.querySelector('#nome_personagem_editar').textContent = document.querySelector('#nome_detalhes').value;
    document.querySelector('#nome_editar').value = document.querySelector('#nome_detalhes').value;
    document.querySelector('#classe_editar').value = document.querySelector('#classe_detalhes').value;
    document.querySelector('#cabeca_editar').src = getParteSrcByNumber(document.querySelector('#cabeca_editar'), document.querySelector('#aparencia_detalhes').dataset.cabeca);
    document.querySelector('#cabeca_editar').dataset.value = document.querySelector('#aparencia_detalhes').dataset.cabeca;
    document.querySelector('#corpo_editar').src = getParteSrcByNumber(document.querySelector('#corpo_editar'), document.querySelector('#aparencia_detalhes').dataset.corpo);
    document.querySelector('#corpo_editar').dataset.value = document.querySelector('#aparencia_detalhes').dataset.corpo;
    document.querySelector('#pernas_editar').src = getParteSrcByNumber(document.querySelector('#pernas_editar'), document.querySelector('#aparencia_detalhes').dataset.pernas);
    document.querySelector('#pernas_editar').dataset.value = document.querySelector('#aparencia_detalhes').dataset.pernas;
    document.querySelector('#hp_editar').value = document.querySelector('#hp_detalhes').value;
    document.querySelector('#ee_editar').value = document.querySelector('#ee_detalhes').value;
    document.querySelector('#ataque_editar').value = document.querySelector('#ataque_detalhes').value;
    document.querySelector('#defesa_editar').value = document.querySelector('#defesa_detalhes').value;
    document.querySelector('#sp_ataque_editar').value = document.querySelector('#sp_ataque_detalhes').value;
    document.querySelector('#sp_defesa_editar').value = document.querySelector('#sp_defesa_detalhes').value;
    document.querySelector('#velocidade_editar').value = document.querySelector('#velocidade_detalhes').value;
    document.querySelector('#skill1_editar').value = document.querySelector('#skill1_detalhes').value;
    document.querySelector('#skill2_editar').value = document.querySelector('#skill2_detalhes').value;
    document.querySelector('#skill3_editar').value = document.querySelector('#skill3_detalhes').value;
    document.querySelector('#skill4_editar').value = document.querySelector('#skill4_detalhes').value;

    let sum = 0;

    // Calcular a soma dos valores dos campos de entrada
    status_inputs_editar.forEach((input) => {
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
    restantes_number_editar.textContent = remaining;
});

salvar_button_editar.addEventListener('click', e => {
    let data = {
        'nome': document.querySelector('#nome_editar').value,
        'classe': document.querySelector('#classe_editar').value,
        'cabeca': document.querySelector('#cabeca_editar').dataset.value,
        'corpo': document.querySelector('#corpo_editar').dataset.value,
        'pernas': document.querySelector('#pernas_editar').dataset.value,
        'hp': document.querySelector('#hp_editar').value,
        'ee': document.querySelector('#ee_editar').value,
        'ataque': document.querySelector('#ataque_editar').value,
        'defesa': document.querySelector('#defesa_editar').value,
        'sp_ataque': document.querySelector('#sp_ataque_editar').value,
        'sp_defesa': document.querySelector('#sp_defesa_editar').value,
        'velocidade': document.querySelector('#velocidade_editar').value,
        'skill1': document.querySelector('#skill1_editar').value,
        'skill2': document.querySelector('#skill2_editar').value,
        'skill3': document.querySelector('#skill3_editar').value,
        'skill4': document.querySelector('#skill4_editar').value
    }

    Swal.fire({
        title: 'Salvando personagem.',
        text: 'Enviando os dados.',
        icon: 'info',
        showConfirmButton: false
    });

    fetch('/personagens/' + target_id, {
        method: 'PUT',
        headers: {
            'Content-Type': 'application/json',
            'X-CSRFToken': csrftoken
        },
        body: JSON.stringify(data)
    })
    .then(res => res.json())
    .then(res => {
        if(res.sucesso) {
            Swal.fire({
                title: 'Personagem editado com sucesso.',
                text: 'Atualizando a lista de personagens.',
                icon: 'success',
                showConfirmButton: false
            });
            window.location.reload();
        } else {
            Swal.fire({
                title: 'Ocorreu um erro na edição do personagem.',
                text: res.erro,
                icon: 'error',
                confirmButtonText: 'Entendi',
                confirmButtonColor: '#f27474'
            });
        }
    })
});

deletar_button.addEventListener('click', e => {
    Swal.fire({
        title: 'Tem certeza que deseja deletar o personagem?.',
        icon: 'info',
        showConfirmButton: true,
        showCancelButton: true,
        confirmButtonText: 'Sim',
        cancelButtonText: 'Não',
        confirmButtonColor: '#f27474',
        cancelButtonColor: '#6c757d'
    })
    .then((result) => {
        if (result.isConfirmed) {
            Swal.fire({
                title: 'Deletando personagem.',
                text: 'Enviando os dados.',
                icon: 'info',
                showConfirmButton: false
            });

            fetch('/personagens/' + target_id, {
                method: 'DELETE',
                headers: {
                    'Content-Type': 'application/json',
                    'X-CSRFToken': csrftoken
                }
            })
            .then(res => res.json())
            .then(res => {
                if(res.sucesso) {
                    Swal.fire({
                        title: 'Personagem deletado com sucesso.',
                        text: 'Atualizando a lista de personagens.',
                        icon: 'success',
                        showConfirmButton: false
                    });
                    window.location.reload();
                } else {
                    Swal.fire({
                        title: 'Ocorreu um erro na deleção do personagem.',
                        text: res.erro,
                        icon: 'error',
                        confirmButtonText: 'Entendi',
                        confirmButtonColor: '#f27474'
                    });
                }
            })
        }
    })
});