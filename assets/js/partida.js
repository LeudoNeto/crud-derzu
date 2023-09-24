var personagem_1 = document.querySelector('#personagem_1');
var personagem_1_imagem = document.querySelector('#personagem_1_imagem');
var personagem_2 = document.querySelector('#personagem_2');
var personagem_2_imagem = document.querySelector('#personagem_2_imagem');
var nome_personagem_atual = document.querySelector('#nome_personagem_atual');
var p1_escolheu = false;
var p1_atacou = false;
var p2_escolheu = false;
var p2_atacou = false;
var skill1 = document.querySelector('#skill_1 h5');
var skill2 = document.querySelector('#skill_2 h5');
var skill3 = document.querySelector('#skill_3 h5');
var skill4 = document.querySelector('#skill_4 h5');

function getSkillNameById(id) {
    let skills = ['Investida', 'golpe de escudo', 'golpe pesado', 
                  'golpe poderoso', 'kickbox', 'bola de fogo', 
                  'raio', 'flecha de gelo', 'bala magica', 
                  'raio de vitalidade', 'golpe de vitalidade', 
                  'bolha bomba']
    return skills[id-1];
}

var skills = document.querySelectorAll('.skill');
skills.forEach(function(skill) {
    skill.addEventListener('click', function() {
        if (p1_escolheu == false) {
            p1_escolheu = skill1.dataset.id;
            nome_personagem_atual.innerHTML = personagem_2.dataset.nome;
            skill1.textContent = personagem_2.dataset.skill1Nome;
            skill1.dataset.id = personagem_2.dataset.skill1Id;
            skill2.textContent = personagem_2.dataset.skill2Nome;
            skill2.dataset.id = personagem_2.dataset.skill2Id;
            skill3.textContent = personagem_2.dataset.skill3Nome;
            skill3.dataset.id = personagem_2.dataset.skill3Id;
            skill4.textContent = personagem_2.dataset.skill4Nome;
            skill4.dataset.id = personagem_2.dataset.skill4Id;
        } else {
            p2_escolheu = skill2.dataset.id;

            fetch('/calcular_dano', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'X-CSRFToken': csrftoken
                },
                body: JSON.stringify({
                    'id': skill.dataset.id,
                })
            })
            .then(res => res.json())
        }
    });
});