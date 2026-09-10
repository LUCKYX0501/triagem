#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[50]; 
    int idade;
    int senha;
    float altura;
    char genero;
    int saturacao;
    int frequenciaCardiaca;
    float temperatura;
    int dor;
    int prioridade;
} Paciente;

Paciente fila[100]; 
int totalPacientes = 0;
int proximaSenha = 1;
int totalAtendidos = 0;

void cadastrarPaciente();
void verFila();
void chamarProximo();
void buscarPaciente();
void estatisticas();

int calcularPrioridade(int sat, int fc, float temp, int dor, int idade);

int main(){
    printf("--------- Triagem ---------\n");
    printf("\n Sistema Iniciado \n");
    printf("\n ---------------------------\n");
    int opcao;
    do {
        printf("----------------------------\n Menu principal \n");
        printf("- 1 - Cadastrar paciente \n");
        printf("- 2 - Ver fila \n");
        printf("- 3 - Chamar proximo paciente \n");
        printf("- 4 - Buscar paciente \n");
        printf("- 5 - Estatisticas \n");
        printf("- 0 - Sair \n");
        printf("Escolha uma das opcoes: ");
        scanf("%d", &opcao);
        
        switch (opcao){
            case 1:
                cadastrarPaciente();
                break;
            case 2:
                verFila();
                break;
            case 3:
                chamarProximo();
                break;
            case 4:
                buscarPaciente();
                break;
            case 5:
                estatisticas();
                break;
            case 0:
                printf("Encerrando o sistema... \n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 0);
    return 0;
}

int calcularPrioridade(int sat, int fc, float temp, int dor, int idade) {
    if (sat < 90 || fc > 140 || fc < 40) {
        return 1;
    }
    if ((sat >= 90 && sat <= 94) || (fc >= 120 && fc <= 140) || temp >= 39.5 || dor >= 8) {
        return 2;
    }
    if (temp >= 38.0 || dor >= 5 || idade >= 80) {
        return 3;
    }
    if (dor >= 1 || idade >= 60) {
        return 4;
    }
    return 5;
}


void cadastrarPaciente() {
    if (totalPacientes >= 100) {
        printf("\nFila cheia!\n");
        return;
    }
    printf("\n----- Cadastro do Paciente -----\n");
    Paciente p1;
    p1.senha = proximaSenha++;
    
    printf("Nome: ");
    scanf(" %[^\n]", p1.nome); 
    printf("Idade: ");
    scanf("%d", &p1.idade);
    printf("Altura: ");
    scanf("%f", &p1.altura);
    printf("Genero (M/F): ");
    scanf(" %c", &p1.genero);
    
    printf("\n--- Sinais Vitais ---\n");
    printf("Saturacao (SpO2 %%): ");
    scanf("%d", &p1.saturacao);
    printf("Frequencia Cardiaca (bpm): ");
    scanf("%d", &p1.frequenciaCardiaca);
    printf("Temperatura (C): ");
    scanf("%f", &p1.temperatura);
    printf("Nivel de Dor (0 a 10): ");
    scanf("%d", &p1.dor);
    	
    p1.prioridade = calcularPrioridade(p1.saturacao, p1.frequenciaCardiaca, p1.temperatura, p1.dor, p1.idade);

    int posicao = 0;
    while (posicao < totalPacientes && fila[posicao].prioridade <= p1.prioridade) {
        posicao++;
    }

    int i;
    for (i = totalPacientes; i > posicao; i--) {
       fila[i] = fila[i - 1];
    }

    fila[posicao] = p1;
    totalPacientes++;

    printf("\nPaciente triado com sucesso! Nivel de Urgencia: %d | Senha: %d\n\n", p1.prioridade, p1.senha);
}

void verFila() {
    if (totalPacientes == 0) {
        printf("\nA fila est� vazia no momento.\n\n");
        return;
    }
    printf("\n---------- Pacientes na Fila ----------\n");
    int i;
    for (i = 0; i < totalPacientes; i++){
        printf("Posicao: %d | Senha: %d | Nome: %s | Idade: %d | Altura: %.2fm | Genero: %c | Prioridade: %c\n", 
               i + 1, fila[i].senha, fila[i].nome, fila[i].idade, fila[i].altura, fila[i].genero, fila[i].prioridade);
    }
    
}

void chamarProximo() {
	
    if (totalPacientes == 0) {
        printf("\nNao ha pacientes na fila!\n\n");
        return;
    }

    printf("\nChamando paciente:\n");
    printf("Senha: %d | Nome: %s\n\n",
           fila[0].senha, fila[0].nome);
           
           
	int i;
    for (i = 0; i < totalPacientes - 1; i++) {
        fila[i] = fila[i + 1];
    }

    totalPacientes--;
    totalAtendidos++;
    
}

void buscarPaciente() {
    printf("\n---------- Buscar Pacientes ----------");
    
	int opcaoBusca;
	
	printf("\n--- Buscar Paciente ---\n");
    printf("1 - Buscar por Senha\n");
    printf("2 - Buscar por Nome\n");
    printf("Escolha o metodo: ");
    scanf("%d", &opcaoBusca);
    
    
    
    if(opcaoBusca == 1){
    	int senhaBusca;
		
		printf("Digite a Senha do Paciente: ");
    	scanf("%d", &senhaBusca);
    	senhaBusca = opcaoBusca;
    	
		int i;
		for(i = 0; i < totalPacientes; i++){
			if(fila[i].senha == opcaoBusca)
				printf("Buscando Paciente....\n");
				printf("Paciente encontrado na posicao: %d\n", i + 1);
				printf("Senha: %d| Nome: %s| Idade: %d\n",fila[i].senha, fila[i].nome, fila[i].idade);
				
				return ;
		}
		printf("Paciente com a senha %d nao encontrado.\n", senhaBusca);		
	}
	



	if(opcaoBusca == 2){
    	char nomeBusca[50];
		
		printf("Digite o nome do Paciente: ");
    	scanf("%[~\n]", nomeBusca);
    	
		int i;
		for(i = 0; i < totalPacientes; i++){
			if(fila[i].nome == opcaoBusca){
				printf("Buscando Paciente....\n");
				printf("Paciente encontrado na posicao: %d\n", i + 1);
				printf("Senha: %d| Nome: %s| Idade: %d\n",fila[i].senha, fila[i].nome, fila[i].idade);
				
				return;
			}
		}
		printf("Paciente com a senha %d nao encontrado.\n", nomeBusca);		
	}

	





}

void estatisticas() {
    
	int i;
    int prioridade1 = 0;
    int prioridade2 = 0;
    int prioridade3 = 0;
    int prioridade4 = 0;
    int prioridade5 = 0;
    int somaIdades = 0;

    for (i = 0; i < totalPacientes; i++) {

        somaIdades += fila[i].idade;

        if (fila[i].prioridade == 1) {
            prioridade1++;
        }
        else if (fila[i].prioridade == 2) {
            prioridade2++;
        }
        else if (fila[i].prioridade == 3) {
            prioridade3++;
        }
        else if (fila[i].prioridade == 4) {
            prioridade4++;
        }
        else if (fila[i].prioridade == 5) {
            prioridade5++;
        }
    }



	printf("\n========== ESTATISTICAS ==========\n\n");
    
    printf("Total de Pacientes atendidos: %d\n", totalAtendidos);
    printf("Total de Pacientes na fila: %d\n", totalPacientes);
    
    printf("\n========== Pacientes por prioridade ==========\n\n"); 

    printf("Prioridade 1 (Emergencia): %d\n", prioridade1);
    printf("Prioridade 2 (Muito urgente): %d\n", prioridade2);
    printf("Prioridade 3 (Urgente): %d\n", prioridade3);
    printf("Prioridade 4 (Pouco urgente): %d\n", prioridade4);
    printf("Prioridade 5 (Nao urgente): %d\n", prioridade5);

	if(totalPacientes > 0){
		printf("\nMedia de Idade na fila: %.2f anos\n", 
			(float)somaIdades/totalPacientes);
			
	}


    
}

