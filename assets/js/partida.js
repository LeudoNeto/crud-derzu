const csrftokenCookie = document.cookie.split(';').find(cookie => cookie.trim().startsWith('csrftoken='));
const csrftoken = csrftokenCookie ? csrftokenCookie.split('=')[1] : null;

var personagem_1 = document.querySelector('#personagem_1');
var personagem_1_imagem = document.querySelector('#personagem_1_imagem');
var personagem_2 = document.querySelector('#personagem_2');
var personagem_2_imagem = document.querySelector('#personagem_2_imagem');
var nome_personagem_atual = document.querySelector('#nome_personagem_atual');
var p1_escolheu = false;
var p2_escolheu = false;
var skill1 = document.querySelector('#skill_1 h5');
var skill2 = document.querySelector('#skill_2 h5');
var skill3 = document.querySelector('#skill_3 h5');
var skill4 = document.querySelector('#skill_4 h5');
var briga_img = document.querySelector('.briga_img');

function getSkillNameById(id) {
    let skills = ['Investida', 'golpe de escudo', 'golpe pesado', 
                  'golpe poderoso', 'kickbox', 'bola de fogo', 
                  'raio', 'flecha de gelo', 'bala magica', 
                  'raio de vitalidade', 'golpe de vitalidade', 
                  'bolha bomba']
    return skills[id-1];
}

function updateSkills(personagem) {
    nome_personagem_atual.innerHTML = personagem.dataset.nome;
    skill1.textContent = personagem.dataset.skill1Nome;
    skill1.dataset.id = personagem.dataset.skill1Id;
    skill2.textContent = personagem.dataset.skill2Nome;
    skill2.dataset.id = personagem.dataset.skill2Id;
    skill3.textContent = personagem.dataset.skill3Nome;
    skill3.dataset.id = personagem.dataset.skill3Id;
    skill4.textContent = personagem.dataset.skill4Nome;
    skill4.dataset.id = personagem.dataset.skill4Id;
}

function calcularDano(atacante, alvo, skillId) {
    return fetch('/calcular_dano', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'X-CSRFToken': csrftoken
        },
        body: JSON.stringify({
            'id': skillId,
            'hp': atacante.dataset.hp,
            'ee': atacante.dataset.ee,
            'ataque': atacante.dataset.ataque,
            'defesa': atacante.dataset.defesa,
            'sp_ataque': atacante.dataset.sp_ataque,
            'sp_defesa': atacante.dataset.sp_defesa,
            'velocidade': atacante.dataset.velocidade,
            'alvo_defesa': alvo.dataset.defesa,
            'alvo_sp_defesa': alvo.dataset.sp_defesa
        })
    })
    .then(res => res.json())
    .then(res => {
        alvo.dataset.hp = parseInt(alvo.dataset.hp) - res.dano;
        alvo.querySelector('.hp').textContent = alvo.dataset.hp;
        return res.dano;
    });
}

function passivas(personagem_1, personagem_2) {
    return fetch('/passiva', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'X-CSRFToken': csrftoken
        },
        body: JSON.stringify({
            'classe': personagem_1.dataset.classe,
            'hp': personagem_1.dataset.hp,
            'ee': personagem_1.dataset.ee,
            'ataque': personagem_1.dataset.ataque,
            'defesa': personagem_1.dataset.defesa,
            'sp_ataque': personagem_1.dataset.sp_ataque,
            'sp_defesa': personagem_1.dataset.sp_defesa,
            'velocidade': personagem_1.dataset.velocidade,
        })
    })
    .then(res => res.json())
    .then(res => {
        Swal.fire({
            icon: 'info',
            title: personagem_1.dataset.nome + ' usou sua passiva!',
            html: '<div style="display:flex; justify-content: space-between;"><span>' + 'HP: ' + personagem_1.dataset.hp + ' -> ' + res.hp + '</span>' +
                  '<span>' +'EE: ' + personagem_1.dataset.ee + ' -> ' + res.ee + '</span></div>' +
                  '<div style="display:flex; justify-content: space-between;"><span>' + 'Ataque: ' + personagem_1.dataset.ataque + ' -> ' + res.ataque + '</span>' +
                  '<span>' + 'Defesa: ' + personagem_1.dataset.defesa + ' -> ' + res.defesa + '</span></div>' +
                  '<div style="display:flex; justify-content: space-between;"><span>' + 'Ataque Mágico: ' + personagem_1.dataset.sp_ataque + ' -> ' + res.sp_ataque + '</span>' +
                  '<span>' + 'Defesa Mágica: ' + personagem_1.dataset.sp_defesa + ' -> ' + res.sp_defesa + '</span></div>' +
                  '<div style="display:flex; justify-content: center;"><span>' + 'Velocidade: ' + personagem_1.dataset.velocidade + ' -> ' + res.velocidade + '</span></div>',
            showConfirmButton: true,
            confirmButtonText: 'OK',
            confirmButtonColor: '#3fc3ee',
        })
        .then(() => {
            personagem_1.dataset.hp = res.hp;
            personagem_1.querySelector('.hp').textContent = res.hp;
            personagem_1.dataset.ee = res.ee;
            personagem_1.querySelector('.ee').textContent = res.ee;
            personagem_1.dataset.ataque = res.ataque;
            personagem_1.querySelector('.ataque').textContent = res.ataque;
            personagem_1.dataset.defesa = res.defesa;
            personagem_1.querySelector('.defesa').textContent = res.defesa;
            personagem_1.dataset.sp_ataque = res.sp_ataque;
            personagem_1.querySelector('.sp_ataque').textContent = res.sp_ataque;
            personagem_1.dataset.sp_defesa = res.sp_defesa;
            personagem_1.querySelector('.sp_defesa').textContent = res.sp_defesa;
            personagem_1.dataset.velocidade = res.velocidade;
            personagem_1.querySelector('.velocidade').textContent = res.velocidade;
        })
        .then(() => {
            return fetch('/passiva', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'X-CSRFToken': csrftoken
                },
                body: JSON.stringify({
                    'classe': personagem_2.dataset.classe,
                    'hp': personagem_2.dataset.hp,
                    'ee': personagem_2.dataset.ee,
                    'ataque': personagem_2.dataset.ataque,
                    'defesa': personagem_2.dataset.defesa,
                    'sp_ataque': personagem_2.dataset.sp_ataque,
                    'sp_defesa': personagem_2.dataset.sp_defesa,
                    'velocidade': personagem_2.dataset.velocidade,
                })
            })
            .then(res => res.json())
            .then(res => {
                Swal.fire({
                    icon: 'info',
                    title: personagem_2.dataset.nome + ' usou sua passiva!',
                    html: '<div style="display:flex; justify-content: space-between;"><span>' + 'HP: ' + personagem_2.dataset.hp + ' -> ' + res.hp + '</span>' +
                          '<span>' +'EE: ' + personagem_2.dataset.ee + ' -> ' + res.ee + '</span></div>' +
                          '<div style="display:flex; justify-content: space-between;"><span>' + 'Ataque: ' + personagem_2.dataset.ataque + ' -> ' + res.ataque + '</span>' +
                          '<span>' + 'Defesa: ' + personagem_2.dataset.defesa + ' -> ' + res.defesa + '</span></div>' +
                          '<div style="display:flex; justify-content: space-between;"><span>' + 'Ataque Mágico: ' + personagem_2.dataset.sp_ataque + ' -> ' + res.sp_ataque + '</span>' +
                          '<span>' + 'Defesa Mágica: ' + personagem_2.dataset.sp_defesa + ' -> ' + res.sp_defesa + '</span></div>' +
                          '<div style="display:flex; justify-content: center;"><span>' + 'Velocidade: ' + personagem_2.dataset.velocidade + ' -> ' + res.velocidade + '</span></div>',
                    showConfirmButton: true,
                    confirmButtonText: 'OK',
                    confirmButtonColor: '#3fc3ee',
                })
                .then(() => {
                    personagem_2.dataset.hp = res.hp;
                    personagem_2.querySelector('.hp').textContent = res.hp;
                    personagem_2.dataset.ee = res.ee;
                    personagem_2.querySelector('.ee').textContent = res.ee;
                    personagem_2.dataset.ataque = res.ataque;
                    personagem_2.querySelector('.ataque').textContent = res.ataque;
                    personagem_2.dataset.defesa = res.defesa;
                    personagem_2.querySelector('.defesa').textContent = res.defesa;
                    personagem_2.dataset.sp_ataque = res.sp_ataque;
                    personagem_2.querySelector('.sp_ataque').textContent = res.sp_ataque;
                    personagem_2.dataset.sp_defesa = res.sp_defesa;
                    personagem_2.querySelector('.sp_defesa').textContent = res.sp_defesa;
                    personagem_2.dataset.velocidade = res.velocidade;
                    personagem_2.querySelector('.velocidade').textContent = res.velocidade;
                });
            });
        });
    });
}

function mostrarMensagemDano(atacante, alvo, dano) {
    return Swal.fire({
        icon: 'info',
        title: atacante.dataset.nome + ' causou ' + dano + ' de dano a ' + alvo.dataset.nome,
        showConfirmButton: true,
        confirmButtonText: 'OK',
        confirmButtonColor: '#3fc3ee',
    });
}

var skills = document.querySelectorAll('.skill');
skills.forEach(function(skill) {
    skill.addEventListener('click', function() {
        if (p1_escolheu == false) {
            p1_escolheu = skill.querySelector('h5').dataset.id;
            updateSkills(personagem_2);
        } else {
            p2_escolheu = skill.querySelector('h5').dataset.id;

            personagem_1_imagem.classList.add('animacao1');
            personagem_2_imagem.classList.add('animacao2');
            briga_img.classList.add('briga_animacao');
        
            setTimeout(function() {
                personagem_1_imagem.classList.remove('animacao1');
                personagem_2_imagem.classList.remove('animacao2');
                briga_img.classList.remove('briga_animacao');

            let personagem1Velocidade = parseInt(personagem_1.dataset.velocidade);
            let personagem2Velocidade = parseInt(personagem_2.dataset.velocidade);

            let primeiroAtacante = personagem1Velocidade >= personagem2Velocidade ? personagem_1 : personagem_2;
            let segundoAtacante = primeiroAtacante === personagem_1 ? personagem_2 : personagem_1;

            let primeiroAtaque = primeiroAtacante === personagem_1 ? p1_escolheu : p2_escolheu;
            let segundoAtaque = primeiroAtacante === personagem_1 ? p2_escolheu : p1_escolheu;

            calcularDano(primeiroAtacante, segundoAtacante, primeiroAtaque)
            .then(dano => mostrarMensagemDano(primeiroAtacante, segundoAtacante, dano))
            .then(() => calcularDano(segundoAtacante, primeiroAtacante, segundoAtaque))
            .then(dano => mostrarMensagemDano(segundoAtacante, primeiroAtacante, dano))
            .then(() => {
                if (parseInt(personagem_1.dataset.hp) <= 0) {
                    Swal.fire({
                        icon: 'info',
                        title: personagem_2.dataset.nome + ' ganhou a luta!',
                        showConfirmButton: true,
                        confirmButtonText: 'OK',
                        confirmButtonColor: '#3fc3ee',
                    })
                    .then((result) => {
                        if (result.isConfirmed) {
                            window.location.href = '/escolher_personagens';
                        }
                    });
                } else if (parseInt(personagem_2.dataset.hp) <= 0) {
                    Swal.fire({
                        icon: 'info',
                        title: personagem_1.dataset.nome + ' ganhou a luta!',
                        showConfirmButton: true,
                        confirmButtonText: 'OK',
                        confirmButtonColor: '#3fc3ee',
                    })
                    .then((result) => {
                        if (result.isConfirmed) {
                            window.location.href = '/escolher_personagens';
                        }
                    });
                }
                else {
                    updateSkills(personagem_1);
                    passivas(personagem_1, personagem_2);
                    p1_escolheu = false;
                    p2_escolheu = false;
                }
            });
        }, 2000);

        }
    });
});