var personagens = document.querySelectorAll('.personagem');
var p1_selecionado = false;
var selecionado_1 = document.querySelector('#selecionado_1');
var nome_selecionado_1 = document.querySelector('#nome_selecionado_1');
var cabeca_selecionado_1 = selecionado_1.querySelector('.cabeca');
var selecionado_2 = document.querySelector('#selecionado_2');
var nome_selecionado_2 = document.querySelector('#nome_selecionado_2');
var cabeca_selecionado_2 = selecionado_2.querySelector('.cabeca');

personagens.forEach(personagem => {
    personagem.addEventListener('mouseover', e => {
        if (!p1_selecionado) {
            nome_selecionado_1.innerHTML = personagem.querySelector('.personagem_nome').innerHTML;
            cabeca_selecionado_1.src = personagem.querySelector('.cabeca').src;
            document.querySelector('#hp_1').innerHTML = personagem.dataset.hp;
            document.querySelector('#ee_1').innerHTML = personagem.dataset.ee;
            document.querySelector('#ataque_1').innerHTML = personagem.dataset.ataque;
            document.querySelector('#defesa_1').innerHTML = personagem.dataset.defesa;
            document.querySelector('#sp_ataque_1').innerHTML = personagem.dataset.sp_ataque;
            document.querySelector('#sp_defesa_1').innerHTML = personagem.dataset.sp_defesa;
            document.querySelector('#velocidade_1').innerHTML = personagem.dataset.velocidade;
        }
        else {
            nome_selecionado_2.innerHTML = personagem.querySelector('.personagem_nome').innerHTML;
            cabeca_selecionado_2.src = personagem.querySelector('.cabeca').src;
            document.querySelector('#hp_2').innerHTML = personagem.dataset.hp;
            document.querySelector('#ee_2').innerHTML = personagem.dataset.ee;
            document.querySelector('#ataque_2').innerHTML = personagem.dataset.ataque;
            document.querySelector('#defesa_2').innerHTML = personagem.dataset.defesa;
            document.querySelector('#sp_ataque_2').innerHTML = personagem.dataset.sp_ataque;
            document.querySelector('#sp_defesa_2').innerHTML = personagem.dataset.sp_defesa;
            document.querySelector('#velocidade_2').innerHTML = personagem.dataset.velocidade;
        }
    });
});

personagens.forEach(personagem => {
    personagem.addEventListener('click', e => {
        if (!p1_selecionado) {
            selecionado_1.dataset.id = personagem.dataset.id;
            p1_selecionado = true;
        }
        else {
            selecionado_2.dataset.id = personagem.dataset.id;
            Swal.fire({
                title: 'Tem certeza que iniciar uma luta entre ' + nome_selecionado_1.innerHTML + ' e ' + nome_selecionado_2.innerHTML + '?',
                icon: 'info',
                showConfirmButton: true,
                showCancelButton: true,
                confirmButtonText: 'Sim',
                cancelButtonText: 'Não',
                confirmButtonColor: '#28a745',
                cancelButtonColor: '#6c757d'
            })
            .then((result) => {
                if (result.isConfirmed) {
                    window.location.href = 'partida/' + selecionado_1.dataset.id + '/' + selecionado_2.dataset.id;
                }
            });
        }
    });
});