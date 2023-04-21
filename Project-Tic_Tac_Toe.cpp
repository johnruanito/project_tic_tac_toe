// Project-Tic_Tac_Toe.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
// 
#include <iostream>
#include <stdlib.h>
#include <string>

    /// matriz 3x3 que representa o tabuleiro do jogo. Ela é inicializada com numeros representando espaços em branco.
    signed char board[3][3] = { {'1','2','3'}, 
                                {'4','5','6'}, 
                                {'7','8','9'} 
     };

   // A variável currentPlayer guarda o marcador (X ou O) do jogador atual.
    signed char currentPlayer = 'X';
                                       
  // A função drawBoard() é responsável por exibir o tabuleiro atual na tela. 
  // Ela percorre a matriz board e exibe as posições ocupadas pelos marcadores de cada jogador.
    void drawBoard() {
        std::cout << "   |   |   " << std::endl;
        std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << std::endl;
        std::cout << "___|___|___" << std::endl;
        std::cout << "   |   |   " << std::endl;
        std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << std::endl;
        std::cout << "___|___|___" << std::endl;
        std::cout << "   |   |   " << std::endl;
        std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << std::endl;
        std::cout << "   |   |   " << std::endl;
}
// A função isBoardFull() verifica se o tabuleiro está cheio, ou seja, se todas as posições já foram ocupadas por algum jogador.
    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
            }
        }
        return true;
    }

// isWinner() é uma função que verifica se algum jogador ganhou o jogo. Ela verifica todas as possibilidades de vitória, ou seja, verifica
// se algum jogador conseguiu formar uma linha, coluna ou diagonal com os seus marcadores. Se algum jogador ganhou, a função retorna true. 
// Caso contrário, retorna false.
    bool isWinner() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;
        return false;
    }

// A função changePlayer() é responsável por trocar o jogador atual. Se o jogador atual é X, a função muda para O, e vice-versa.
    void changePlayer() {
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

// A função makeMove() é responsável por solicitar a jogada do jogador atual. Ela solicita que o jogador informe a linha e a coluna onde 
// deseja jogar. Se a jogada for inválida (fora do tabuleiro ou em uma posição já ocupada), a função chama a si mesma novamente para solicitar
// outra jogada. Caso contrário, a função atualiza a matriz board com o marcador do jogador atual e chama a função changePlayer() para trocar o jogador atual.
    bool makeMove() {
        int row, col;
        std::cout << "It's " << currentPlayer << "'s turn. Enter row (1-3) and column (1-3): ";
        std::cin >> row >> col;
        row--;
        col--;
        if (row < 0 || row>2 || col < 0 || col>2) {
            std::cout << "Invalid input. Please enter numbers between 1 and 3." << std::endl;
            return false;
        }
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            std::cout << "This cell is already occupied. Please choose a different one." << std::endl;
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

// A função startGame() chama as outras funções para executar o jogo.
// A função drawBoard() é chamada no início do jogo para exibir o tabuleiro. Em seguida, o programa entra em um loop
// enquanto não há um vencedor ou o tabuleiro não está cheio. Dentro do loop, a função makeMove() é chamada para solicitar
// a jogada do jogador atual e atualizar o tabuleiro. A função drawBoard() é chamada novamente para exibir o tabuleiro atualizado. 
// Quando o loop termina, o programa verifica se houve um vencedor ou se o jogo terminou empatado e exibe uma mensagem de acordo.
    void startGame() {

        while (!isBoardFull() && !isWinner()) {
            drawBoard();
            if (!makeMove())
                continue;
            if (isWinner()) {
                std::cout << currentPlayer << " wins!" << std::endl;
                break;
            }
            changePlayer();
        }
        if (!isWinner())
            std::cout << "It's a draw!" << std::endl;




    }

// A função menuInicia() é uma função que exibe um menu para o usuário com três opções: jogar, sobre e sair. 
// Ela é chamada no início do programa para exibir o menu principal.
    void menuInicia() {

        int opcao = 0;
        while (opcao < 1 || opcao >3)
        {
            //Essa linha limpa a tela do console para que o menu seja exibido novamente.
            system("cls");
            
            
        // Essas linhas formam um switch case que avalia a opção escolhida pelo usuário e executa a ação correspondente. 
        // Se o usuário escolher a opção 1 (jogar), a função startGame() é chamada para iniciar o jogo. 
        // Se o usuário escolher a opção 2 (sobre), é exibida uma mensagem com informações sobre o jogo. 
        // Se o usuário escolher a opção 3 (sair), uma mensagem de despedida é exibida e o programa é encerrado.
        std::cout << "Bem vindo ao Jogo \n";
        std::cout << "\n ===========ESCOLHA UMA OPCAO============= \n";
        std::cout << "\n 1 - JOGAR";
        std::cout << "\n 2 - SOBRE";
        std::cout << "\n 3 - SAIR \n";
        std::cin >> opcao;
       
        switch(opcao){
            
        case 1:
            system("cls");
            std::cout << "Iniciando o Jogo \n";
            startGame();
            break;
     
        case 2:
            system("cls");
            std::cout << "Informaçoes \n";

            break;

        case 3:
            system("cls");
            std::cout << "Ate mais \n";

            break;      }

        }

    }


    int main()
    {
     
        menuInicia();

        return 0;
    }

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
