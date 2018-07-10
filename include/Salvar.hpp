#include <iostream>
#include <fstream>
#include <string.h>
#include "../src/Salvar.cpp"

void removepeca(char (*tabuleiro)[8][8], char peca);
void carregaTab(char (*tabuleiro)[8][8]);
void salvarTab(char (*tabuleiro)[8][8]);
bool verificar(char (*tabuleiro)[8][8], char peca);
void editar(char (*tabuleiro)[8][8]);