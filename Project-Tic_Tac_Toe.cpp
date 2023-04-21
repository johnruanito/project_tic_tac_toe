// Project-Tic_Tac_Toe.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <iostream>
#include <stdlib.h>
#include <string>

    signed char board[3][3] = { {'1','2','3'}, 
                                {'4','5','6'}, 
                                {'7','8','9'} 
     };

    signed char currentPlayer = 'X';
                                       

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

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
            }
        }
        return true;
    }

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

    void changePlayer() {
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

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


    void menuInicia() {

        int opcao = 0;
        while (opcao < 1 || opcao >3)
        {
            system("cls");
        
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
