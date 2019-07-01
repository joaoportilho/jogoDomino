#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

//Variaveis globais:

char *pecas_jogo[30] =
    {{"Vazio"},{"[0|0]"}, {"[0|1]"}, {"[0|2]"}, {"[0|3]"},
    {"[0|4]"}, {"[0|5]"}, {"[0|6]"}, {"[1|1]"},
    {"[1|2]"}, {"[1|3]"}, {"[1|4]"}, {"[1|5]"},
    {"[1|6]"}, {"[2|2]"}, {"[2|3]"}, {"[2|4]"},
    {"[2|5]"}, {"[2|6]"}, {"[3|3]"}, {"[3|4]"},
    {"[3|5]"}, {"[3|6]"}, {"[4|4]"}, {"[4|5]"},
    {"[4|6]"}, {"[5|5]"}, {"[5|6]"}, {"[6|6]"}, {"Vazio"}};

char *inverte[30] =
    {{"Vazio"},{"[0|0]"}, {"[1|0]"}, {"[2|0]"}, {"[3|0]"},
    {"[4|0]"}, {"[5|0]"}, {"[6|0]"}, {"[1|1]"},
    {"[2|1]"}, {"[3|1]"}, {"[4|1]"}, {"[5|1]"},
    {"[6|1]"}, {"[2|2]"}, {"[3|2]"}, {"[4|2]"},
    {"[5|2]"}, {"[6|2]"}, {"[3|3]"}, {"[4|3]"},
    {"[5|3]"}, {"[6|3]"}, {"[4|4]"}, {"[5|4]"},
    {"[6|4]"}, {"[5|5]"}, {"[6|5]"}, {"[6|6]"}, {"Vazio"}};

//Funcoes:
void menu(); //Funcao q mostra o menu
void regras(); //Funcao q mostra as regras
void adeus(); //Funcao q mostra mensagem final
bool Existe(int valores[], int tam, int valor); //Funcao auxiliar do GeraAleatorios (nao randomizar a mesma peca)
void GeraAleatorios(int numeros[], int quantNumeros, int Limite); //Funcao para randomizar pecas
void quatro_jogadores(); // Funcao para jogar em 4 jogadores

int main() //Funcao principal
{
    parabains();
    return 0;
}

//__________________________________________________________________________________________________________________________//

void menu(){
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    system("color 06");
    int auxiliar = 1;
    printf("\n********************************************************************************************************");
    printf("\n*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*");
    printf("\n*@@           @@@@@@@@         @@@@@@@ @@@@@@@@@ @@@@@             @@@@   @@@@@@@@@ @@@@@@         @@@@*");
    printf("\n*@@  @@@@@@@@  @@@@@@  @@@@@@@  @@@@@ @ @@@@@@@ @ @@@@@@@@@   @@@@@@@@@ @@ @@@@@@@@ @@@@@  @@@@@@@  @@@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@ @@@@@ @@ @@@@@@@@@   @@@@@@@@@ @@@ @@@@@@@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@@ @@@ @@@ @@@@@@@@@   @@@@@@@@@ @@@@ @@@@@@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@@@   @@@@ @@@@@@@@@   @@@@@@@@@ @@@@@ @@@@@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@@@@ @@@@@ @@@@@@@@@   @@@@@@@@@ @@@@@@ @@@@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@@@@@@@@@@ @@@@@@@@@   @@@@@@@@@ @@@@@@@ @@@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@@  @@@@ @@@@@@@@@@@ @@@@ @@@@@@@@@@@ @@@@@@@@@   @@@@@@@@@ @@@@@@@@ @@ @@@@ @@@@@@@@@@@ @@*");
    printf("\n*@@  @@@@@@@@  @@@@@@  @@@@@@@  @@@@@ @@@@@@@@@@@ @@@@@@@@@   @@@@@@@@@ @@@@@@@@@ @ @@@@@  @@@@@@@  @@@*");
    printf("\n*@@           @@@@@@@@         @@@@@@ @@@@@@@@@@@ @@@@             @@@@ @@@@@@@@@@  @@@@@@         @@@@*");
    printf("\n*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*");
    printf("\n********************************************************************************************************");
    printf("\n*                                                   *                                                  *");
    printf("\n*  Menu:                                            * Desenvolvedores deste Programa:                  *");
    printf("\n*    >Pressione 1 para jogar.                       *  -> João Pedro Portilho                          *");
    printf("\n*    >Pressione 2 para aprender a jogar.            *  -> Lucas A. Cruvinel                            *");
    printf("\n*    >Pressione 3 para fechar o jogo.               *  -> Ramon Soares                                 *");
    printf("\n*                                                   *                                                  *");
    printf("\n********************************************************************************************************");
    int nummenu;

    while(auxiliar){
        nummenu = getch();
        nummenu = nummenu - 48;
        if(nummenu == 1){quatro_jogadores();}
        else if(nummenu == 2){regras();}
        else if(nummenu == 3){adeus();}
        else printf("\n********************************************************************************************************\n*                                 Por favor pressione uma tecla valida!                                *\n********************************************************************************************************");}
 }

//__________________________________________________________________________________________________________________________//

 void regras(){
     system("cls");
     setlocale(LC_ALL, "Portuguese");
     system("color FC");
    printf("\n********************************************************************************************************");
    printf("\n*                                                                                                      *");
    printf("\n*                                              COMO JOGAR:                                             *");
    printf("\n*      ->O jogo começa com uma pessoa colocando uma peça na mesa.                                      *");
    printf("\n*      ->O jogador seguinte deve entao jogar outra peça.                                               *");
    printf("\n*      ->Esta segunda peça deve ter um número que seja igual a um dos numeros da peça anterior.        *");
    printf("\n*      ->E assim o jogo se segue.                                                                      *");
    printf("\n*      ->Caso um jogador não tenha uma peça que possa ser usada.                                       *");
    printf("\n*      ->Ele deve passar sua vez para o proximo jogador.                                               *");
    printf("\n*      ->O primeiro jogador a ficar sem nenhuma peça GANHA                                             *");
    printf("\n*      ->E todos os outros são PERDEDORES                                                              *");
    printf("\n*                                                                                                      *");
    printf("\n********************************************************************************************************");
    printf("\n*                                                                                                      *");
    printf("\n*                                  Pressione 1 para voltar ao menu.                                    *");
    printf("\n*                                  Pressione 2 para fechar o jogo.                                     *");
    printf("\n*                                                                                                      *");
    printf("\n********************************************************************************************************");
    int numreg;
    int auxiliar = 1;
    while(auxiliar){
        numreg = getch();
        numreg = numreg - 48;
        if(numreg == 1){menu();}
        else if(numreg == 2){adeus();}
        else printf("\n********************************************************************************************************\n*                                 Por favor pressione uma tecla valida!                                *\n********************************************************************************************************");
        }
}

//__________________________________________________________________________________________________________________________//

void adeus(){
    system("cls");
    system("color FD");
    printf("\n********************************************************************************************************");
    printf("\n********************************************************************************************************");
    printf("\n**                                                                                                    **");
    printf("\n**         Segundo Lavoisier, na natureza nada se cria, nada se perde, tudo se transforma.            **");
    printf("\n**         E agora mais do que nunca isso se torna verdade.                                           **");
    printf("\n**         Pois a felicidade de poder te servir agora se torna saudade de saber que você vai embora.  **");
    printf("\n**         Obrigado por tudo e volte sempre.                                                          **");
    printf("\n**                                                                                                    **");
    printf("\n********************************************************************************************************");
    printf("\n********************************************************************************************************");
    exit(0);
    }

//__________________________________________________________________________________________________________________________//

bool Existe(int valores[], int tam, int valor){  // Funcao para verificar se o numero aleatorio ja foi incluido //
    for(int i = 0;i < tam; i++){
        if(valores[i]==valor || valor == 0)
            return true;}

    return false;
}

//__________________________________________________________________________________________________________________________//

void GeraAleatorios(int numeros[], int quantNumeros, int Limite){  // Funcao para gerar numeros aleatorios //
    srand(time(NULL));
    int v;
    for(int i = 0; i<quantNumeros;i++){
            v = rand() % Limite;
        while(Existe(numeros,i,v))
            v = rand() % Limite;

        numeros[i] = v;
    }
}

//__________________________________________________________________________________________________________________________//

void quatro_jogadores()
{
    // Esquematização e inicialização do sistema de dois jogadores
    struct perfil_jogador
    {
        char nomes[4][50];
        int outroai[4]; // Tive que criar essa variável inútil para resolver um problema.
    };
    struct perfil_jogador jogador;
    system("cls");
    //int score[3] = {0};
    int contador, pontuacao, fim[5] = {0, 0, 0, 0, 0};
    *pecas_jogo = malloc(6*sizeof(char));
    char mesa[50][6] = {0};
      //  printf("%c%c%c%c%c \n", mesa[1][0],mesa[1][1],mesa[1][2],mesa[1][3],mesa[1][4]);
    //printf("%s", mesa+1);
    for(contador = 1; contador < 5; contador++)
    {
        printf("=======================================================");
        printf("\nSeja muito bem-vindo, Jogador %d! Diga-me seu apelido: \n", contador);
        printf("Meu apelido é -> ");
        scanf("%s", jogador.nomes[contador]);
    }
    system("cls");
    int inventario[5][7], aux_inventario[28];
    int cont1, cabo = 0;
    bool turno = false;
    bool fim_de_jogo = true;
    int qtd_turnos = 0;
    int peca_chave, aux_peca, i, j, k=0;
    int peca_mesa = 1;
    int aux_66 = 0;
    bool aux_x = true;
    //int turnos_a_jogar = 7;
    // Sistemas de Turnos e o Desenrolar do jogo em sí
    GeraAleatorios(aux_inventario, 28, 29);
    for (i=0;i<5;i++){
         for (j=0;j<7;j++){
                if(i==0)
                    inventario[i][j] = 29;
                else{
                    inventario[i][j] = aux_inventario[k];
                    k++;}
         }
    }
    while(fim_de_jogo == true)
    {
        for(int cont1 = 1; cont1 < 5; cont1++)
        {
            system("cls");
            printf("                    | Turno do: %s | N Turno: %d \n", jogador.nomes[cont1], qtd_turnos+1);
            printf("\n                    Mesa do jogo:\n");
            printf("________________________________________________________________________________________________________________________\n\n");
            printf("%s", mesa[1]);
            printf("%s", mesa[2]);
            printf("%s", mesa[3]);
            printf("%s", mesa[4]);
            printf("%s", mesa[5]);
            printf("%s", mesa[6]);
            printf("%s", mesa[7]);
            printf("%s", mesa[8]);
            printf("%s", mesa[8]);
            printf("%s", mesa[9]);
            printf("%s", mesa[10]);
            printf("%s", mesa[11]);
            printf("%s", mesa[12]);
            printf("%s", mesa[13]);
            printf("%s", mesa[14]);
            printf("%s", mesa[15]);
            printf("%s", mesa[16]);
            printf("%s", mesa[17]);
            printf("%s", mesa[18]);
            printf("%s", mesa[19]);
            printf("%s", mesa[20]);
            printf("%s", mesa[21]);
            printf("%s", mesa[22]);
            printf("%s", mesa[23]);
            printf("%s", mesa[24]);
            printf("%s", mesa[25]);
            printf("%s", mesa[26]);
            printf("%s", mesa[27]);
            printf("%s", mesa[28]);

           // break;
            printf("\n________________________________________________________________________________________________________________________\n\n");
            printf("                    Meu inventario:\n\n");
            printf("                    {0. %s}, {1. %s}, {2. %s}, {3. %s}, {4. %s}, {5. %s}, {6. %s}", pecas_jogo[inventario[cont1][0]], pecas_jogo[inventario[cont1][1]], pecas_jogo[inventario[cont1][2]], pecas_jogo[inventario[cont1][3]], pecas_jogo[inventario[cont1][4]], pecas_jogo[inventario[cont1][5]], pecas_jogo[inventario[cont1][6]]);
            printf("\n                    OBS: Para pular seu turno, digite 7; ");
            printf("\n                    OBS: Para colocar uma peça invertida, digite 8 e em seguida escolha a peça; ");
            printf("\n                    Qual peca deseja colocar?\n                    > ");

            while(aux_x == true){
                printf("\n                    Se saiu com a peca [6|6], digite 1 e coloque-a, se não digite 0: \n                    > ");
                scanf("%d", &aux_66);
                if(aux_66 == 0){
                    cont1++;
                    system("cls");
                    printf("                    | Turno do: %s | N Turno: %d \n", jogador.nomes[cont1], qtd_turnos+1);
                    printf("\n                    Mesa do jogo:\n");
                    printf("________________________________________________________________________________________________________________________\n\n");
                    printf("%s", mesa[1]);
                    printf("%s", mesa[2]);
                    printf("%s", mesa[3]);
                    printf("%s", mesa[4]);
                    printf("%s", mesa[5]);
                    printf("%s", mesa[6]);
                    printf("%s", mesa[7]);
                    printf("%s", mesa[8]);
                    printf("%s", mesa[8]);
                    printf("%s", mesa[9]);
                    printf("%s", mesa[10]);
                    printf("%s", mesa[11]);
                    printf("%s", mesa[12]);
                    printf("%s", mesa[13]);
                    printf("%s", mesa[14]);
                    printf("%s", mesa[15]);
                    printf("%s", mesa[16]);
                    printf("%s", mesa[17]);
                    printf("%s", mesa[18]);
                    printf("%s", mesa[19]);
                    printf("%s", mesa[20]);
                    printf("%s", mesa[21]);
                    printf("%s", mesa[22]);
                    printf("%s", mesa[23]);
                    printf("%s", mesa[24]);
                    printf("%s", mesa[25]);
                    printf("%s", mesa[26]);
                    printf("%s", mesa[27]);
                    printf("%s", mesa[28]);

                   // break;
                    printf("\n________________________________________________________________________________________________________________________\n\n");
                    printf("                    Meu inventario:\n\n");
                    printf("                    {0. %s}, {1. %s}, {2. %s}, {3. %s}, {4. %s}, {5. %s}, {6. %s}", pecas_jogo[inventario[cont1][0]], pecas_jogo[inventario[cont1][1]], pecas_jogo[inventario[cont1][2]], pecas_jogo[inventario[cont1][3]], pecas_jogo[inventario[cont1][4]], pecas_jogo[inventario[cont1][5]], pecas_jogo[inventario[cont1][6]]);
                    printf("\n                    OBS: Para pular seu turno, digite 7; ");
                    printf("\n                    OBS: Para colocar uma peca invertida, digite 8 e em seguida escolha a peca; ");
                    printf("\n                    Qual peca deseja colocar?\n                    > ");
                }
                else
                    if(aux_66 == 1){
                        aux_x = false;}


            }

            scanf("%d", &peca_chave);
            while(inventario[cont1][peca_chave] == 29 || peca_chave > 8 || peca_chave < 0)
            {
              printf("\n                    Slot inválido! No slot escolhido, nao há peça alguma. Por favor, insira outro número. \n                    > ");
              scanf("%d", &peca_chave);
            }
            if(peca_chave == 7){ cont1++;
                    turno = true;}
            else
                if(peca_chave == 8){
                        printf("\n                    Escolha uma peca para inverter:  ");
                        scanf("%d", &aux_peca);
                        strcpy(mesa[peca_mesa], inverte[inventario[cont1][aux_peca]]);
                        inventario[cont1][aux_peca] = inventario[0][0];
            }
            else
                {
                    //*mesa[peca_mesa] = pecas_jogo[inventario[cont1][peca_chave]];
                    strcpy(mesa[peca_mesa], pecas_jogo[inventario[cont1][peca_chave]]);
                    inventario[cont1][peca_chave] = inventario[0][0];
                    //printf("%s", mesa[peca_mesa]);
                }
            peca_mesa++;

            if (turno == true){
                cont1--;
                turno = false;}

            for(i=0;i<7;i++){
                if(inventario[cont1][i] == 29)
                    cabo++;
            }

            if(cabo == 7){
                fim_de_jogo = false;
                parabains(jogador.nomes[cont1]);}
            else
                cabo = 0;

        }

        qtd_turnos++;
    }
}
//__________________________________________________________________________________________________________________________//

void parabains(char pessoa[]){
    system("cls");
     setlocale(LC_ALL, "Portuguese");
     system("color B1");
    printf("\n********************************************************************************************************");
    printf("\n*                                                                                                      *");
    printf("\n*                                              PARABAINS                                               *");
    printf("\n*                                            VOCÊ GANHOU!!!!                                           *");
    printf("\n*      \"Não acho que quem ganhar ou quem perder, nem quem ganhar nem perder,                           *");
    printf("\n*       vai ganhar ou perder. Vai todo mundo perder.\"                       -Dilma Rousseff            *");
    printf("\n*                                                                                                      *");
    printf("\n*      Dominó pode parecer um jogo de sorte,                                                           *");
    printf("\n*      Mas é um jogo que apenas o mais inteligente ganha,                                              *");
    printf("\n*      E por meio dessa conquista, você se provou;                                                     *");
    printf("\n*      Você É o mais INTELIGENTE e o mais PIK@ CARALH$.                                                *");
    printf("\n*                                                                                                      *");
    printf("\n********************************************************************************************************");
    printf("                                                   Jogador Vencedor: %s", pessoa);
    printf("\n********************************************************************************************************");
    printf("\n*                                                                                                      *");
    printf("\n*                                  Pressione 1 para voltar ao menu.                                    *");
    printf("\n*                                  Pressione 2 para fechar o jogo.                                     *");
    printf("\n*                                                                                                      *");
    printf("\n********************************************************************************************************");
    int numreg;
    int auxiliar = 1;
    while(auxiliar){
        numreg = getch();
        numreg = numreg - 48;
        if(numreg == 1){menu();}
        else if(numreg == 2){adeus();}
        else printf("\n********************************************************************************************************\n*                                 Por favor pressione uma tecla valida!                                *\n********************************************************************************************************");
        }
}
//__________________________________________________________________________________________________________________________//
