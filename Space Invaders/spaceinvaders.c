#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX_C 105
#define TAM_MAX_L 45
#define QTD_TOTAL_ENEMY 80

typedef struct
{

    int ID;
    int fileira;
    int linha;
    int iteracao;

} tRanking;

typedef struct
{

    int movimentos;
    int tirosEfetivos;
    int tirosErrados;
    int numDescidas;

} tEstatistica;

typedef struct
{

    int pos_x;
    int pos_y;
    int posX_tiro;
    int posY_tiro;

} tJogador;

typedef struct
{

    int pos_x;
    int pos_y;
    int ID;
    int fileira;
    int flagEliminado; // 0 para eliminado e 1 para vivo

} tInimigo;

typedef struct
{

    char matriz[TAM_MAX_L][TAM_MAX_C];
    int c;
    int l;
    int coluna_com_borda; // matriz do mapa com colunas contando as bordas;
    int linha_com_borda;  // matriz do mapa com linhas contando as bordas;
    int qtddeinimigos;

} tMapa;

typedef struct
{

    tInimigo enemy[QTD_TOTAL_ENEMY];
    tMapa map;
    tJogador player;
    tEstatistica estatistica;
    tRanking ranking[QTD_TOTAL_ENEMY];
    int heatMatriz[TAM_MAX_L][TAM_MAX_C];
    int rankingIndice; // guarda o indice dos tRanking
    char desenhoEnemy[3][3][4];
    int flagAnimacao;    // determina qual tipo de animacao(0, 1 ou 2);
    int flagDesenho;     // desenho inimigo casos bonus
    int flagMoveInimigo; // 0 para mover ele para direita 1 para esquerda
    int existeTiroAtivo; // 1 para existe 0 para nao existe
    int pontos;
    int inimigosMortos;
    int iteracoes;

} tJogo;

// abre os arquivos para comecar o jogo
tJogo AbrindoArq_Inimigo_e_Mapatxt(char diretorio[]);

tJogo LeArq_Inimigotxt(tJogo jogo, FILE *inimigoFile);

tJogo LeArq_Mapatxt(tJogo jogo, FILE *mapaFile);

tJogo CriaArq_Inicializacaotxt(tJogo jogo, char diretorio[]);

// abrindo arquivo de entrada
FILE *AbrindoArq_Entradatxt(char diretorio[]);

// recebe o arq entradatxt
char Inicia_Jogada(FILE *entradaF);

// le as jogadas do entrada.txt
char Le_Jogada(FILE *fEntrada);

// preenche a struct do jogo com 0;
tJogo InicializaStruct_Jogo(tJogo jogo);

void Imprime_Mapa(tJogo jogo, int iteracoes);

int PerdeuJogo(tJogo jogo);

int GanhouJogo(tJogo jogo);

tJogo Preenche_Borda(tJogo jogo);

tJogo Preenche_Primeiro_Tiro(tJogo jogo);

tJogo Move_Tiro(tJogo jogo);

tJogo MoveJogador_Esquerda(tJogo jogo, char diretorio[]);

tJogo MoveJogador_Direita(tJogo jogo, char diretorio[]);

tJogo Preenche_Jogador(tJogo jogo);

tJogo Move_Inimigo(tJogo jogo, int verificador, char diretorio[]);

tJogo Move_Inimigo_Baixo(tJogo jogo, int QTD);

tJogo Move_Inimigo_Direita(tJogo jogo, int QTD);

tJogo Move_Inimigo_Esquerda(tJogo jogo, int QTD);

tJogo Preenche_Inimigos(tJogo jogo);

int Verifica_Tiro_Acertou_Inimigo(tJogo jogo, char diretorio[]);

int Verifica_Tiro_Acertou_Borda(tJogo jogo);

// verifica se algum inimigo atingiu a borda esquerda
int Verifica_Inimigo_Borda_Esquerda(int QTD, tJogo jogo, char diretorio[]);

// verifica se algum inimigo atingiu a borda direita
int Verifica_Inimigo_Borda_Direita(int QTD, tJogo jogo, char diretorio[]);

// atualiza o tJogo com os inimigos mortos
tJogo Elimina_Inimigos(tJogo jogo);

int Calcula_Pontos(tJogo jogo, int linha);

tJogo Desenha_tMapa(tJogo jogo, char carJogada, int iteracao, char diretorio[]);

tJogo Atualiza_Flag_Animacao(tJogo jogo);

tJogo Inicializa_Matriz_HeatMap(tJogo jogo, int l, int c);

tJogo Atualiza_Matriz_HeatMap(tJogo jogo, int l, int c);

void Cria_Arq_HeatMaptxt(int matriz[TAM_MAX_L][TAM_MAX_C], char diretorio[], int l, int c);

void Cria_Arq_Estatisticatxt(tEstatistica status, char diretorio[]);

void Inicializa_Arq_Resumotxt(char diretorio[], tJogo jogo);

// preenche o arquivo com as infos da colisao dos inimigos
void Preenche_Inimigos_Colisao_Resumotxt(tInimigo inimigo, char diretorio[], int lateral, int iteracao);

// preenche o arquivo com as infos do tiro
void Preenche_Tiro_Resumotxt(tInimigo inimigo, int coluna, int linha, char diretorio[], int iteracao);

// preenche o arquivo com as infos da colisao do jogador na direita
void Preenche_Jogador_Colisao_Borda_Direita_Resumotxt(char diretorio[], int iteracao);

// preenche o arquivo com as infos da colisao do jogador na esquerda
void Preenche_Jogador_Colisao_Borda_Esquerda_Resumotxt(char diretorio[], int iteracao);

tJogo Atualiza_tRanking(tJogo jogo, int indice, int fileira, int linha, int iteracao);

// organiza como eh pedido no pdf o rankingtxt
tJogo Ordena_tRanking(tJogo jogo);

int Acha_Menor_AeB(tRanking vet[], int i, int TAM);

void Troca_Vetores_tRanking(tRanking vet[], int idexMenor, int i);

void CriaArq_Rankingtxt(char diretorio[], tJogo jogo);


int main(int argc, char *argv[])
{
    tJogo jogo;
    char jogada;

    if (argc <= 1)
    {
        printf("ERRO:informe o diretorio com os arquivos\n");
        return 1;
    }

    jogo = AbrindoArq_Inimigo_e_Mapatxt(argv[1]);
    jogo = CriaArq_Inicializacaotxt(jogo, argv[1]);

    jogo = InicializaStruct_Jogo(jogo);

    Inicializa_Arq_Resumotxt(argv[1], jogo);

    jogo = Atualiza_Matriz_HeatMap(jogo, jogo.map.l, jogo.map.c);

    FILE *entradaFile;

    entradaFile = AbrindoArq_Entradatxt(argv[1]);

    printf("Pontos: %d ", jogo.pontos);
    Imprime_Mapa(jogo, jogo.iteracoes);

    while (1)
    {

        if (GanhouJogo(jogo))
        {
            printf("Parabéns, você ganhou!");
            break;
        }

        if (PerdeuJogo(jogo))
        {
            printf("Você perdeu, tente novamente!");
            break;
        }

        jogada = Inicia_Jogada(entradaFile);
        jogo = Atualiza_Flag_Animacao(jogo);
        jogo.iteracoes++;
        jogo = Desenha_tMapa(jogo, jogada, jogo.iteracoes, argv[1]);
        jogo = Atualiza_Matriz_HeatMap(jogo, jogo.map.l, jogo.map.c);
        printf("Pontos: %d ", jogo.pontos);
        Imprime_Mapa(jogo, jogo.iteracoes);
    }

    CriaArq_Rankingtxt(argv[1], jogo);
    Cria_Arq_Estatisticatxt(jogo.estatistica, argv[1]);
    Cria_Arq_HeatMaptxt(jogo.heatMatriz, argv[1], jogo.map.l, jogo.map.c);

    return 0;
}

tJogo AbrindoArq_Inimigo_e_Mapatxt(char diretorio[])
{
    tJogo jogo;

    FILE *mapaFile;
    char arquivo_mapa[1000];

    sprintf(arquivo_mapa, "%s/mapa.txt", diretorio);

    // abrindo arq mapa
    mapaFile = fopen(arquivo_mapa, "r");

    if (!mapaFile)
    {
        printf("Error opening file %s\n", arquivo_mapa);
        exit(0);
    }

    jogo = LeArq_Mapatxt(jogo, mapaFile);

    fclose(mapaFile);

    FILE *inimigoFile;
    char arquivo_inimigo[1000];

    sprintf(arquivo_inimigo, "%s/inimigo.txt", diretorio);

    // abrindo arq inimigo
    inimigoFile = fopen(arquivo_inimigo, "r");

    if (!inimigoFile)
    {
        printf("Error opening file %s\n", arquivo_inimigo);
        exit(0);
    }

    jogo = LeArq_Inimigotxt(jogo, inimigoFile);

    fclose(inimigoFile);

    return jogo;
}

tJogo LeArq_Inimigotxt(tJogo jogo, FILE *inimigoFile)
{

    int FlagInimigo;

    fscanf(inimigoFile, "%d", &FlagInimigo);
    fscanf(inimigoFile, "%*c");

    jogo.flagDesenho = FlagInimigo;

    int b, a;

    for (a = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
            fscanf(inimigoFile, "%[^\n]", jogo.desenhoEnemy[a][b]);
            fscanf(inimigoFile, "%*c");
        }
    }

    return jogo;
}

tJogo LeArq_Mapatxt(tJogo jogo, FILE *mapaFile)
{
    int mapa_c, mapa_l;
    int jogador_x, jogador_y;
    int i = 0;

    fscanf(mapaFile, "%d %d", &mapa_c, &mapa_l);
    fscanf(mapaFile, "%*[^(]");
    fscanf(mapaFile, "%*c");
    fscanf(mapaFile, "%d %d", &jogador_x, &jogador_y);
    fscanf(mapaFile, "%*[^\n]");
    fscanf(mapaFile, "%*c");

    tJogador jogador;
    jogador.pos_x = jogador_x;
    jogador.pos_y = jogador_y;

    jogo.player = jogador;

    tMapa mapa;
    mapa.coluna_com_borda = mapa_c + 2;
    mapa.linha_com_borda = mapa_l + 2;
    mapa.c = mapa_c;
    mapa.l = mapa_l;

    int fileira = 1;

    char car;

    int b = 1;

    tInimigo inimigo;

    while (!feof(mapaFile))
    {

        fscanf(mapaFile, "%c", &car);

        if (car == '\n')
        {
            fileira++;
            b = 1;
        }
        else if (car == '(')
        {
            fscanf(mapaFile, "%d %d", &inimigo.pos_x, &inimigo.pos_y);
            inimigo.fileira = fileira;
            inimigo.ID = b;
            inimigo.flagEliminado = 1;
            jogo.enemy[i] = inimigo;
            i++;
            b++;
        }
    }

    fscanf(mapaFile, "%*[^\n]");
    fscanf(mapaFile, "%*c");

    mapa.qtddeinimigos = i;

    jogo.map = mapa;

    return jogo;
}

tJogo CriaArq_Inicializacaotxt(tJogo jogo, char diretorio[])
{

    FILE *inicializacaoFile;

    tMapa mapa;

    char arquivoInicializacao[1000];

    sprintf(arquivoInicializacao, "%s/saida/inicializacao.txt", diretorio);

    inicializacaoFile = fopen(arquivoInicializacao, "w");

    if (!inicializacaoFile)
    {
        printf("Error creating file inicializacao.txt\n");
    }

    jogo.flagAnimacao = 0;

    int i, j;

    jogo = Preenche_Borda(jogo);
    jogo = Preenche_Jogador(jogo);
    jogo = Preenche_Inimigos(jogo);

    mapa = jogo.map;

    for (i = 1; i <= jogo.map.linha_com_borda; i++)
    {
        for (j = 1; j <= jogo.map.coluna_com_borda; j++)
        {
            fprintf(inicializacaoFile, "%c", mapa.matriz[i][j]);
            // printf("%c", mapa.matriz[i][j]);
        }
        if (j == jogo.map.coluna_com_borda + 1)
        {
            fprintf(inicializacaoFile, "\n");
            // printf("\n");
        }
    }

    fprintf(inicializacaoFile, "\n");
    // printf("\n");
    fprintf(inicializacaoFile, "A posicao central do jogador iniciara em (%d %d).", jogo.player.pos_x, jogo.player.pos_y);
    // printf("A posicao central do jogador iniciara em (%d %d).", jogo.player.pos_x, jogo.player.pos_y);
    // printf("\n");

    fclose(inicializacaoFile);

    return jogo;
}

FILE *AbrindoArq_Entradatxt(char diretorio[])
{

    char arquivoEntrada[1000];
    sprintf(arquivoEntrada, "%s/entrada.txt", diretorio);

    FILE *entradaFile;

    entradaFile = fopen(arquivoEntrada, "r");

    if (!entradaFile)
    {
        printf("ERROR opening %s", arquivoEntrada);
    }

    return entradaFile;
}

char Inicia_Jogada(FILE *entradaF)
{
    char carJogada;

    carJogada = Le_Jogada(entradaF);

    return carJogada;
}

char Le_Jogada(FILE *fEntrada)
{
    char car;

    while (!feof(fEntrada))
    {

        fscanf(fEntrada, "%c", &car);
        fscanf(fEntrada, "%*[^\n]");
        fscanf(fEntrada, "%*c");

        return car;
    }

    fclose(fEntrada);
}

tJogo InicializaStruct_Jogo(tJogo jogo)
{

    // tJogo//
    jogo.pontos = 0;
    jogo.inimigosMortos = 0;
    jogo.iteracoes = 0;
    jogo.flagMoveInimigo = 0;
    jogo.existeTiroAtivo = 0;
    jogo.rankingIndice = -1;
    jogo.flagAnimacao = 0;
    // tJogo//

    tEstatistica estatistica;

    // tEstatistica//
    estatistica.movimentos = 0;
    estatistica.numDescidas = 0;
    estatistica.tirosEfetivos = 0;
    estatistica.tirosErrados = 0;
    // tEstatistica//

    jogo.estatistica = estatistica;

    jogo = Inicializa_Matriz_HeatMap(jogo, jogo.map.l, jogo.map.c);

    return jogo;
}

void Imprime_Mapa(tJogo jogo, int iteracoes)
{

    tMapa mapa;
    mapa = jogo.map;

    int i, j;

    printf("| Iteracoes: %d\n", iteracoes);

    for (i = 1; i <= mapa.linha_com_borda; i++)
    {
        for (j = 1; j <= mapa.coluna_com_borda; j++)
        {
            printf("%c", mapa.matriz[i][j]);
        }
        if (j == mapa.coluna_com_borda + 1)
        {
            printf("\n");
        }
    }
}

int PerdeuJogo(tJogo jogo)
{
    tMapa mapa;
    mapa = jogo.map;
    tJogador jogador;
    jogador = jogo.player;
    int posY;

    int i;

    for (i = 0; i < mapa.qtddeinimigos; i++)
    {

        posY = jogo.enemy[i].pos_y;

        if (jogo.enemy[i].flagEliminado == 1)
        {
            if (posY + 1 == jogador.pos_y - 1)
            {
                return 1;
            }
        }
    }

    return 0;
}

int GanhouJogo(tJogo jogo)
{
    if (jogo.inimigosMortos == jogo.map.qtddeinimigos || !jogo.map.qtddeinimigos)
    {
        return 1;
    }
    return 0;
}

tJogo Preenche_Borda(tJogo jogo)
{
    tMapa mapa;
    tJogador jogador;

    jogador = jogo.player;

    mapa = jogo.map;

    int i, j;

    // preenchendo mapa inteiro com espacos vazios
    for (i = 1; i <= mapa.coluna_com_borda; i++)
    {
        for (j = 1; j <= mapa.linha_com_borda; j++)
        {
            mapa.matriz[j][i] = ' ';
        }
    }

    // preenchendo borda esquerda
    mapa.matriz[1][1] = '+';

    for (i = 2; i < jogador.pos_y - 1; i++)
    {
        mapa.matriz[i][1] = '|';
    }

    mapa.matriz[i][1] = '-';

    for (i = i + 1; i < mapa.linha_com_borda; i++)
    {
        mapa.matriz[i][1] = '|';
    }

    mapa.matriz[i][1] = '+';

    // preenchendo borda inferior
    for (i = 2; i < mapa.coluna_com_borda; i++)
    {
        mapa.matriz[mapa.linha_com_borda][i] = '-';
    }

    mapa.matriz[mapa.linha_com_borda][i] = '+';

    // preenchendo borda direita
    mapa.matriz[1][mapa.coluna_com_borda] = '+';

    for (i = 2; i < jogador.pos_y - 1; i++)
    {
        mapa.matriz[i][mapa.coluna_com_borda] = '|';
    }

    mapa.matriz[i][mapa.coluna_com_borda] = '-';

    for (i = i + 1; i < mapa.linha_com_borda; i++)
    {
        mapa.matriz[i][mapa.coluna_com_borda] = '|';
    }

    // preenchendo borda superior
    for (i = 2; i < mapa.coluna_com_borda; i++)
    {
        mapa.matriz[1][i] = '-';
    }

    jogo.map = mapa;

    return jogo;
}

tJogo Preenche_Primeiro_Tiro(tJogo jogo)
{

    tMapa mapa;
    mapa = jogo.map;

    tJogador jogador;
    jogador = jogo.player;

    mapa.matriz[jogador.pos_y - 1][jogador.pos_x + 1] = 'o';

    jogador.posX_tiro = jogador.pos_x + 1;
    jogador.posY_tiro = jogador.pos_y - 1;

    jogo.player = jogador;
    jogo.map = mapa;

    return jogo;
}

tJogo Move_Tiro(tJogo jogo)
{

    tMapa mapa;
    mapa = jogo.map;

    tJogador jogador;
    jogador = jogo.player;

    if (jogo.existeTiroAtivo == 1)
    {
        jogador.posY_tiro = jogador.posY_tiro - 1;

        mapa.matriz[jogador.posY_tiro][jogador.posX_tiro] = 'o';

        jogo.map = mapa;
        jogo.player = jogador;

        return jogo;
    }

    return jogo;
}

tJogo MoveJogador_Esquerda(tJogo jogo, char diretorio[])
{

    tJogador jogador;
    jogador = jogo.player;

    int posX = jogador.pos_x;
    int posY = jogador.pos_y;

    if (posX == 2)
    {

        Preenche_Jogador_Colisao_Borda_Esquerda_Resumotxt(diretorio, jogo.iteracoes);

        jogador.pos_x = posX;
        jogador.pos_y = posY;

        jogo.player = jogador;

        return jogo;
    }
    else
    {

        jogo.estatistica.movimentos = jogo.estatistica.movimentos + 1;

        posX = posX - 1;

        jogador.pos_x = posX;
        jogador.pos_y = posY;

        jogo.player = jogador;

        return jogo;
    }
}

tJogo MoveJogador_Direita(tJogo jogo, char diretorio[])
{

    tMapa mapa;
    mapa = jogo.map;

    tJogador jogador;
    jogador = jogo.player;

    int posX = jogador.pos_x;
    int posY = jogador.pos_y;

    if (posX + 2 >= mapa.coluna_com_borda - 1)
    {

        Preenche_Jogador_Colisao_Borda_Direita_Resumotxt(diretorio, jogo.iteracoes);

        jogador.pos_x = posX;
        jogador.pos_y = posY;

        jogo.player = jogador;

        return jogo;
    }
    else
    {

        jogo.estatistica.movimentos = jogo.estatistica.movimentos + 1;

        posX = posX + 1;

        jogador.pos_x = posX;
        jogador.pos_y = posY;

        jogo.player = jogador;

        return jogo;
    }
}

tJogo Preenche_Jogador(tJogo jogo)
{

    tMapa mapa;
    mapa = jogo.map;

    tJogador jogador;
    jogador = jogo.player;

    int posX = jogador.pos_x;
    int posY = jogador.pos_y;

    // primeira fileira
    mapa.matriz[posY][posX] = 'M';
    mapa.matriz[posY][posX + 1] = ' ';
    mapa.matriz[posY][posX + 2] = 'M';

    // segunda fileira
    mapa.matriz[posY + 1][posX] = 'M';
    mapa.matriz[posY + 1][posX + 1] = 'M';
    mapa.matriz[posY + 1][posX + 2] = 'M';

    // terceira fileira
    mapa.matriz[posY + 2][posX] = 'M';
    mapa.matriz[posY + 2][posX + 1] = 'M';
    mapa.matriz[posY + 2][posX + 2] = 'M';

    jogo.map = mapa;

    return jogo;
}

tJogo Move_Inimigo(tJogo jogo, int verificador, char diretorio[])
{

    tMapa mapa;
    mapa = jogo.map;

    // verificador == jogo.flagMoveInimigo

    if (!verificador)
    { // verifica se eh para o inimigo continuar se movendo para direita

        if (Verifica_Inimigo_Borda_Direita(mapa.qtddeinimigos, jogo, diretorio))
        {
            jogo.flagMoveInimigo = 1; // atualiza a flag para na proxima iteracao ele se mover para esquerda
            jogo = Move_Inimigo_Baixo(jogo, mapa.qtddeinimigos);
            jogo.estatistica.numDescidas = jogo.estatistica.numDescidas + 1;
        }
        else
        {
            jogo = Move_Inimigo_Direita(jogo, mapa.qtddeinimigos);
        }
    }
    else
    {

        if (Verifica_Inimigo_Borda_Esquerda(mapa.qtddeinimigos, jogo, diretorio))
        {
            jogo = Move_Inimigo_Baixo(jogo, mapa.qtddeinimigos);
            jogo.flagMoveInimigo = 0;
            jogo.estatistica.numDescidas = jogo.estatistica.numDescidas + 1;
        }
        else
        {
            jogo = Move_Inimigo_Esquerda(jogo, mapa.qtddeinimigos);
        }
    }

    return jogo;
}

tJogo Move_Inimigo_Baixo(tJogo jogo, int QTD)
{
    int i;

    for (i = 0; i < QTD; i++)
    {
        if (jogo.enemy[i].flagEliminado == 1)
        {
            jogo.enemy[i].pos_y = jogo.enemy[i].pos_y + 1;
        }
    }

    return jogo;
}

tJogo Move_Inimigo_Direita(tJogo jogo, int QTD)
{
    int i;

    for (i = 0; i < QTD; i++)
    {
        if (jogo.enemy[i].flagEliminado == 1)
        {
            jogo.enemy[i].pos_x = jogo.enemy[i].pos_x + 1;
        }
    }

    return jogo;
}

tJogo Move_Inimigo_Esquerda(tJogo jogo, int QTD)
{
    int i;

    for (i = 0; i < QTD; i++)
    {
        if (jogo.enemy[i].flagEliminado == 1)
        {
            jogo.enemy[i].pos_x = jogo.enemy[i].pos_x - 1;
        }
    }

    return jogo;
}

tJogo Preenche_Inimigos(tJogo jogo)
{
    tMapa mapa;
    mapa = jogo.map;

    tInimigo inimigo;
    int i;

    for (i = 0; i < mapa.qtddeinimigos; i++)
    {
        inimigo = jogo.enemy[i];
        int posX = inimigo.pos_x;
        int posY = inimigo.pos_y;

        if (inimigo.flagEliminado == 1)
        {

            // primeira fileira
            mapa.matriz[posY][posX] = jogo.desenhoEnemy[jogo.flagAnimacao][0][0];
            mapa.matriz[posY][posX + 1] = jogo.desenhoEnemy[jogo.flagAnimacao][0][1];
            mapa.matriz[posY][posX + 2] = jogo.desenhoEnemy[jogo.flagAnimacao][0][2];

            // segunda fileira
            mapa.matriz[posY + 1][posX] = jogo.desenhoEnemy[jogo.flagAnimacao][1][0];
            mapa.matriz[posY + 1][posX + 1] = jogo.desenhoEnemy[jogo.flagAnimacao][1][1];
            mapa.matriz[posY + 1][posX + 2] = jogo.desenhoEnemy[jogo.flagAnimacao][1][2];

            // terceira fileira
            mapa.matriz[posY + 2][posX] = jogo.desenhoEnemy[jogo.flagAnimacao][2][0];
            mapa.matriz[posY + 2][posX + 1] = jogo.desenhoEnemy[jogo.flagAnimacao][2][1];
            mapa.matriz[posY + 2][posX + 2] = jogo.desenhoEnemy[jogo.flagAnimacao][2][2];

            jogo.map = mapa;
        }
    }

    jogo.map = mapa;

    return jogo;
}

int Verifica_Tiro_Acertou_Inimigo(tJogo jogo, char diretorio[])
{

    tMapa mapa;
    mapa = jogo.map;

    tJogador jogador;
    jogador = jogo.player;

    int i;
    int posx, posy;

    if (jogo.existeTiroAtivo == 1)
    {
        for (i = 0; i < mapa.qtddeinimigos; i++)
        {
            posx = jogo.enemy[i].pos_x;
            posy = jogo.enemy[i].pos_y;

            if (jogo.enemy[i].flagEliminado == 1)
            {
                if ((posx == jogador.posX_tiro) || (posx + 1 == jogador.posX_tiro) || (posx + 2 == jogador.posX_tiro))
                {
                    if ((posy == jogador.posY_tiro) || (posy + 1 == jogador.posY_tiro) || (posy + 2 == jogador.posY_tiro))
                    {
                        Preenche_Tiro_Resumotxt(jogo.enemy[i], jogador.posX_tiro - 1, jogador.posY_tiro - 1, diretorio, jogo.iteracoes);
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int Verifica_Tiro_Acertou_Borda(tJogo jogo)
{

    tJogador jogador;
    jogador = jogo.player;

    if (jogo.existeTiroAtivo)
    {
        if (jogador.posY_tiro == 1)
        {
            return 1;
        }
    }

    return 0;
}

int Verifica_Inimigo_Borda_Esquerda(int QTD, tJogo jogo, char diretorio[])
{
    int i;
    int aux = 0;

    for (i = 0; i < QTD; i++)
    {
        if (jogo.enemy[i].flagEliminado == 1)
        {
            if (jogo.enemy[i].pos_x == 2)
            {
                Preenche_Inimigos_Colisao_Resumotxt(jogo.enemy[i], diretorio, 0, jogo.iteracoes);
                aux++;
            }
        }
    }

    if (aux > 0)
    {
        return 1;
    }

    return 0;
}

int Verifica_Inimigo_Borda_Direita(int QTD, tJogo jogo, char diretorio[])
{
    int i;
    tMapa mapa;
    mapa = jogo.map;
    int aux = 0;

    for (i = 0; i < QTD; i++)
    {
        if (jogo.enemy[i].flagEliminado == 1)
        {
            if (jogo.enemy[i].pos_x + 2 == mapa.coluna_com_borda - 1)
            {
                Preenche_Inimigos_Colisao_Resumotxt(jogo.enemy[i], diretorio, 1, jogo.iteracoes);
                aux++;
            }
        }
    }

    if (aux > 0)
    {
        return 1;
    }

    return 0;
}

tJogo Elimina_Inimigos(tJogo jogo)
{

    tMapa mapa;
    mapa = jogo.map;

    tJogador jogador;
    jogador = jogo.player;

    int i;
    int posx, posy;

    for (i = 0; i < mapa.qtddeinimigos; i++)
    {
        posx = jogo.enemy[i].pos_x;
        posy = jogo.enemy[i].pos_y;

        if (jogo.enemy[i].flagEliminado == 1)
        {
            if ((posx == jogador.posX_tiro) || (posx + 1 == jogador.posX_tiro) || (posx + 2 == jogador.posX_tiro))
            {
                if ((posy == jogador.posY_tiro) || (posy + 1 == jogador.posY_tiro) || (posy + 2 == jogador.posY_tiro))
                {
                    jogo.enemy[i].flagEliminado = 0;
                    posy = mapa.linha_com_borda - jogador.posY_tiro;
                    jogo = Atualiza_tRanking(jogo, jogo.enemy[i].ID, jogo.enemy[i].fileira, posy, jogo.iteracoes);
                    return jogo;
                }
            }
        }
    }

    return jogo;
}

int Calcula_Pontos(tJogo jogo, int linha)
{

    tMapa mapa;
    mapa = jogo.map;

    tJogador jogador;
    jogador = jogo.player;

    int i;
    int posx, posy;

    for (i = 0; i < mapa.qtddeinimigos; i++)
    {
        posx = jogo.enemy[i].pos_x;
        posy = jogo.enemy[i].pos_y;

        if (jogo.enemy[i].flagEliminado)
        {
            if ((posx == jogador.posX_tiro) || (posx + 1 == jogador.posX_tiro) || (posx + 2 == jogador.posX_tiro))
            {
                if ((posy == jogador.posY_tiro) || (posy + 1 == jogador.posY_tiro) || (posy + 2 == jogador.posY_tiro))
                {

                    posy = posy + 2;
                    posy = jogo.map.linha_com_borda - posy;

                    return posy * posx;
                }
            }
        }
    }
}

tJogo Desenha_tMapa(tJogo jogo, char carJogada, int iteracao, char diretorio[])
{

    int somaPontos;

    if (Verifica_Tiro_Acertou_Inimigo(jogo, diretorio))
    {

        somaPontos = Calcula_Pontos(jogo, jogo.player.posY_tiro);
        jogo = Elimina_Inimigos(jogo);
        jogo.pontos = jogo.pontos + somaPontos;
        jogo.existeTiroAtivo = 0;
        jogo.inimigosMortos++;
    }

    jogo = Preenche_Borda(jogo);

    jogo = Move_Inimigo(jogo, jogo.flagMoveInimigo, diretorio);

    if (carJogada == 'd')
    {
        jogo = MoveJogador_Direita(jogo, diretorio);
    }
    else if (carJogada == 'a')
    {
        jogo = MoveJogador_Esquerda(jogo, diretorio);
    }

    jogo = Preenche_Jogador(jogo);

    jogo = Preenche_Inimigos(jogo);

    jogo = Move_Tiro(jogo);

    if (Verifica_Tiro_Acertou_Borda(jogo))
    {
        jogo.map.matriz[jogo.player.posY_tiro][jogo.player.posX_tiro] = '-';
        jogo.existeTiroAtivo = 0;
        jogo.estatistica.tirosErrados = jogo.estatistica.tirosErrados + 1;
    }

    if (carJogada == ' ')
    {
        if (!jogo.existeTiroAtivo)
        {
            jogo = Preenche_Primeiro_Tiro(jogo);
            jogo.existeTiroAtivo = 1;
            jogo.estatistica.tirosEfetivos = jogo.estatistica.tirosEfetivos + 1;
        }
    }

    return jogo;
}

tJogo Atualiza_Flag_Animacao(tJogo jogo)
{

    if (jogo.flagDesenho)
    {
        jogo.flagAnimacao++;

        if (jogo.flagAnimacao > 2)
        {
            jogo.flagAnimacao = 0;
        }
    }

    return jogo;
}

tJogo Inicializa_Matriz_HeatMap(tJogo jogo, int l, int c)
{
    int i, j;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            jogo.heatMatriz[i][j] = 0;
        }
    }

    return jogo;
}

tJogo Atualiza_Matriz_HeatMap(tJogo jogo, int l, int c)
{
    tJogador jogador;
    jogador = jogo.player;

    int posx = jogador.pos_x - 2;
    int posy = jogador.pos_y - 2;

    // jogador primeira linha
    jogo.heatMatriz[posy][posx] = jogo.heatMatriz[posy][posx] + 1;
    jogo.heatMatriz[posy][posx + 1] = jogo.heatMatriz[posy][posx + 1] + 1;
    jogo.heatMatriz[posy][posx + 2] = jogo.heatMatriz[posy][posx + 2] + 1;
    // jogador segunda linha
    jogo.heatMatriz[posy + 1][posx] = jogo.heatMatriz[posy + 1][posx] + 1;
    jogo.heatMatriz[posy + 1][posx + 1] = jogo.heatMatriz[posy + 1][posx + 1] + 1;
    jogo.heatMatriz[posy + 1][posx + 2] = jogo.heatMatriz[posy + 1][posx + 2] + 1;
    // jogador terceira linha
    jogo.heatMatriz[posy + 2][posx] = jogo.heatMatriz[posy + 2][posx] + 1;
    jogo.heatMatriz[posy + 2][posx + 1] = jogo.heatMatriz[posy + 2][posx + 1] + 1;
    jogo.heatMatriz[posy + 2][posx + 2] = jogo.heatMatriz[posy + 2][posx + 2] + 1;

    int tirox = jogador.posX_tiro - 2;
    int tiroy = jogador.posY_tiro - 2;

    // tiro
    if (jogo.existeTiroAtivo)
    {
        jogo.heatMatriz[tiroy][tirox] = jogo.heatMatriz[tiroy][tirox] + 1;
    }

    return jogo;
}

void Cria_Arq_HeatMaptxt(int matriz[TAM_MAX_L][TAM_MAX_C], char diretorio[], int l, int c)
{

    int i, j;

    FILE *heatFile;
    char arqheat[1000];
    sprintf(arqheat, "%s/saida/heatmap.txt", diretorio);

    heatFile = fopen(arqheat, "w");

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            fprintf(heatFile, "%3d ", matriz[i][j]);
        }
        fprintf(heatFile, "\n");
    }

    fclose(heatFile);
}

void Cria_Arq_Estatisticatxt(tEstatistica status, char diretorio[])
{

    char arqStatus[1000];

    FILE *statusFile;

    sprintf(arqStatus, "%s/saida/estatisticas.txt", diretorio);

    statusFile = fopen(arqStatus, "w");

    fprintf(statusFile, "Numero total de movimentos (A ou D): %d;\n", status.movimentos);
    fprintf(statusFile, "Numero de tiros efetivos: %d;\n", status.tirosEfetivos);
    fprintf(statusFile, "Numero de tiros que nao acertaram: %d;\n", status.tirosErrados);
    fprintf(statusFile, "Numero de descidas dos inimigos: %d;\n", status.numDescidas);

    fclose(statusFile);
}

void Inicializa_Arq_Resumotxt(char diretorio[], tJogo jogo)
{
    char resumo[20] = {"resumo.txt"};

    char arqresumo[1000];

    sprintf(arqresumo, "%s/saida/%s", diretorio, resumo);

    FILE *resumoFile;

    resumoFile = fopen(arqresumo, "w");
    fclose(resumoFile);
}

void Preenche_Inimigos_Colisao_Resumotxt(tInimigo inimigo, char diretorio[], int lateral, int iteracao)
{

    FILE *resumoFile;

    char caminho[1000];

    sprintf(caminho, "%s/saida/resumo.txt", diretorio);

    resumoFile = fopen(caminho, "a");

    // variavel lateral ==> 1 para inimigo atingiu borda direita e 0 para esquerda

    if (lateral)
    {
        fprintf(resumoFile, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral direita.\n", iteracao - 1, inimigo.ID, inimigo.fileira);
    }
    else
    {
        fprintf(resumoFile, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral esquerda.\n", iteracao - 1, inimigo.ID, inimigo.fileira);
    }

    fclose(resumoFile);
}

void Preenche_Tiro_Resumotxt(tInimigo inimigo, int coluna, int linha, char diretorio[], int iteracao)
{

    FILE *resumoFile;

    char caminho[1000];

    sprintf(caminho, "%s/saida/resumo.txt", diretorio);

    resumoFile = fopen(caminho, "a");

    fprintf(resumoFile, "[%d] Inimigo de indice %d da fileira %d foi atingido na posicao (%d %d).\n", iteracao - 1, inimigo.ID, inimigo.fileira, coluna, linha);

    fclose(resumoFile);
}

void Preenche_Jogador_Colisao_Borda_Direita_Resumotxt(char diretorio[], int iteracao)
{

    FILE *resumoFile;

    char caminho[1000];

    sprintf(caminho, "%s/saida/resumo.txt", diretorio);

    resumoFile = fopen(caminho, "a");

    fprintf(resumoFile, "[%d] Jogador colidiu na lateral direita.\n", iteracao);

    fclose(resumoFile);
}

void Preenche_Jogador_Colisao_Borda_Esquerda_Resumotxt(char diretorio[], int iteracao)
{

    FILE *resumoFile;

    char caminho[1000];

    sprintf(caminho, "%s/saida/resumo.txt", diretorio);

    resumoFile = fopen(caminho, "a");

    fprintf(resumoFile, "[%d] Jogador colidiu na lateral esquerda.\n", iteracao);

    fclose(resumoFile);
}

tJogo Atualiza_tRanking(tJogo jogo, int indice, int fileira, int linha, int iteracao)
{

    tRanking ranking;
    ranking.ID = indice;
    ranking.linha = linha;
    ranking.iteracao = iteracao;
    ranking.fileira = fileira;

    jogo.ranking[jogo.rankingIndice + 1] = ranking;

    jogo.rankingIndice++;

    return jogo;
}

tJogo Ordena_tRanking(tJogo jogo)
{
    int ideMenor;
    int i;
    int j;
    for (i = 0; i < jogo.inimigosMortos - 1; i++)
    {

        ideMenor = Acha_Menor_AeB(jogo.ranking, i + 1, jogo.inimigosMortos);

        if (jogo.ranking[ideMenor].linha < jogo.ranking[i].linha)
        {
            Troca_Vetores_tRanking(jogo.ranking, ideMenor, i);
        }
    }

    // ordenando caso haja empate nas linhas
    for (i = 0; i < jogo.inimigosMortos - 1; i++)
    {

        for (j = i + 1; j < jogo.inimigosMortos; j++)
        {

            if (jogo.ranking[j].linha == jogo.ranking[i].linha)
            {
                if (jogo.ranking[j].iteracao < jogo.ranking[i].iteracao)
                {
                    Troca_Vetores_tRanking(jogo.ranking, j, i);
                }
            }
        }
    }

    return jogo;
}

int Acha_Menor_AeB(tRanking vet[], int i, int TAM)
{
    int menor = vet[i].linha;
    int ideMenor = i;
    int a;

    for (a = i + 1; a < TAM; a++)
    {

        if (vet[a].linha < menor)
        {
            menor = vet[a].linha;
            ideMenor = a;
        }
    }

    return ideMenor;
}

void Troca_Vetores_tRanking(tRanking vet[], int idexMenor, int i)
{

    tRanking aux;

    aux = vet[i];
    vet[i] = vet[idexMenor];
    vet[idexMenor] = aux;
}

void CriaArq_Rankingtxt(char diretorio[], tJogo jogo)
{
    jogo = Ordena_tRanking(jogo);
    int i;
    char arqRanking[1000];
    tRanking ranking;

    sprintf(arqRanking, "%s/saida/ranking.txt", diretorio);

    FILE *rankingFile;

    rankingFile = fopen(arqRanking, "w");
    fprintf(rankingFile, "indice,fileira,linha,iteracao\n");

    for (i = 0; i < jogo.inimigosMortos; i++)
    {
        ranking = jogo.ranking[i];

        fprintf(rankingFile, "%d,%d,%d,%d\n", ranking.ID, ranking.fileira, ranking.linha, ranking.iteracao - 1);
    }

    fclose(rankingFile);
}