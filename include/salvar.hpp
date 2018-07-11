#ifndef SALVAR_HPP
#define SALVAR_HPP

#include <iostream>
#include <fstream>
#include <string.h>

void removepeca(char (*tabuleiro)[8][8], char peca, int x, int y);
void carregaTab(char (*tabuleiro)[8][8]);
void salvarTab(char (*tabuleiro)[8][8]);
bool verificar(char (*tabuleiro)[8][8], char peca);
void editar(char (*tabuleiro)[8][8]);


#endif