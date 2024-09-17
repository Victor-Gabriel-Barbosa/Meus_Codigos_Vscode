#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <limits>
#include <string>
#include <tuple>
#include <sstream>
#include <algorithm>
using namespace std; 

namespace modtxt { // Namespace p/ modificações de texto
  const string reset = "\033[0m";
  const string negrito = "\033[1m";
  const string escuro = "\033[2m";
  const string itálico = "\033[3m";
  const string grifado = "\033[4m";
  const string inverso = "\033[7m";
  const string oculto = "\033[8m";
  const string risco = "\033[9m";
}

namespace cortxt { // Namespace p/ cores de texto
  const string roxo = "\033[38;5;201m";
  const string verde = "\033[38;5;46m";
  const string azul = "\033[38;5;39m";
  const string vermelho = "\033[38;5;196m";
  const string laranja = "\033[38;5;208m";
  const string amarelo = "\033[38;5;220m";
  const string ciano = "\033[38;5;51m";
  const string preto = "\033[38;5;232m";
  const string branco = "\033[38;5;15m"; 
  const string cinza = "\033[38;5;249m";
}

namespace corfnd { // Namespace p/ cores de fundo
  const string roxo = "\033[48;5;201m";
  const string verde = "\033[48;5;46m";
  const string azul = "\033[48;5;39m";
  const string vermelho = "\033[48;5;196m";
  const string laranja = "\033[48;5;208m";
  const string amarelo = "\033[48;5;220m";
  const string ciano = "\033[48;5;51m";
  const string preto = "\033[48;5;232m";
  const string branco = "\033[48;5;15m"; 
  const string cinza = "\033[48;5;249m";
}

namespace fmtbrd { // Namespace p/ formato de bordas
  const vector<string> sembrd = {" ", " ", " ", " ", " ", " ", " ", " "};
  const vector<string> leve1 = {"⎡", "⎺", "⎤", "⎢", "⎥", "⎣", "⎽", "⎦"};
  const vector<string> leve2 = {"╔", "─", "╗", "║", "║", "╚", "─", "╝"};
  const vector<string> linha1 = {"┌", "─", "┐", "│", "│", "└", "─", "┘"};
  const vector<string> linha2 = {"┏", "━", "┓", "┃", "┃", "┗", "━", "┛"};
  const vector<string> linha3 = {"╔", "═", "╗", "║", "║", "╚", "═", "╝"};
  const vector<string> curva1 = {"╭", "─", "╮", "│", "│", "╰", "─", "╯"};
  const vector<string> curva2 = {"╭", "═", "╮", "║", "║", "╰", "═", "╯"};
  const vector<string> risco1 = {"╒", "═", "╕", "│", "│", "╘", "═", "╛"};
  const vector<string> risco2 = {"┏", "╍", "┓", "╎", "╎", "┗", "╍", "┛"};
  const vector<string> preto1 = {"▛", "▀", "▜", "▌", "▐", "▙", "▄", "▟"};
  const vector<string> preto2 = {"▛", "▄", "▜", "▌", "▐", "▙", "▀", "▟"};
  const vector<string> espesso = {"╓", "─", "╖", "║", "║", "╙", "─", "╜"};
  const vector<string> tracejado = {"⟬", "⟶", "⟭", "⟪", "⟫", "⟯", "⟵", "⟰"};
  const vector<string> pontilhado1 = {"┌", "┈", "┐", "┆", "┆", "└", "┈", "┘"};
  const vector<string> pontilhado2 = {"┌", "┄", "┐", "┊", "┊", "└", "┄", "┘"};
}

namespace faux { // Namespace p/ funções auxiliares
  void fpurge() { // Função p/ limpar o buffer do teclado
    try { // Tenta limpar o buffer
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } catch (const exception &e) { cerr << cortxt::vermelho << "[Erro] " << e.what() << modtxt::reset << endl; } // ...
  }
  
  bool isAllSpaces(const string &str) { // Função p/ verificar se todos os caracteres de uma string são espaços
    return all_of(str.begin(), str.end(), [](char c) { return isspace(static_cast<unsigned char>(c)); });
  }
  
  size_t sizeMtbyIgANSI(const string &str) { // Função p/ descobrir o tamanho de uma string considerando caracteres multibyte (UTF-8) e ignorando sequência de escape ANSI
    size_t tam = 0;
    try { // Tenta descobrir o tamanho da string
      for (auto temp = str.begin(); temp != str.end();) {  // Percorre a string
        if (*temp == '\033') { // Verifica início de sequência de escape ANSI
          auto seqFim = find(temp, str.end(), 'm'); // Encontra o fim da sequência de escape ANSI
          if (seqFim != str.end()) { // Verifica se a sequência de escape ANSI foi encontrada
            temp = seqFim + 1; // Pula a sequência de escape
            continue;
          } else { throw runtime_error(cortxt::vermelho + "[Sequência de escape ANSI inválida detectada!]" + modtxt::reset); } // ...
        }
        unsigned char c = *temp; // Obtém o valor ASCII do caractere
        if (c < 0x80) { ++temp; } // Pula caracteres com menos de 8 bits
        else if (c < 0xE0) { temp += 2; } // Pula caracteres com 8 a 12 bits
        else if (c < 0xF0) { temp += 3; } // Pula caracteres com 13 a 16 bits
        else { temp += 4; } // Pula caracteres com 17 a 21 bits
        tam++;
      } 
    } catch (const exception &e) { cerr << cortxt::vermelho << "[Erro] " << e.what() << modtxt::reset << endl; } // ...
    return tam; // ...
  }

  string cntCx(const vector<string> &txts, string corTxt = cortxt::ciano, const vector<string> &fmtBrd = fmtbrd::curva1, string corBrd = cortxt::azul) { // Função p/ centralizar texto em uma caixa
    if (corTxt.find("\033") == string::npos || corTxt.find("m") == string::npos) { corTxt = cortxt::ciano; } // Verifica se a cor de texto é válida
    if (corBrd.find("\033") == string::npos || corBrd.find("m") == string::npos) { corBrd = cortxt::azul; } // Verifica se a cor de fundo é válida
    size_t i, tam = 0, tamMax = 0, espEsq = 0, espDir = 0, qtdBrd = fmtBrd.size(); // Variáveis p/ controle
    bool semBrd = ((qtdBrd == 0) || (fmtBrd == fmtbrd::sembrd)); // Verifica se a caixa não tem bordas
    const string brdSupEsq = (qtdBrd > 0) ? fmtBrd[0] : " "; // Obtém a borda superior esquerda
    const string brdCntSup = (qtdBrd > 1) ? fmtBrd[1] : " "; // Obtém a borda central superior
    const string brdSupDir = (qtdBrd > 2) ? fmtBrd[2] : " "; // Obtém a borda superior direita
    const string brdCntEsq = (qtdBrd > 3) ? fmtBrd[3] : " "; // Obtém a borda central esquerda
    const string brdCntDir = (qtdBrd > 4) ? fmtBrd[4] : " "; // Obtém a borda central direita
    const string brdInfEsq = (qtdBrd > 5) ? fmtBrd[5] : " "; // Obtém a borda inferior esquerda
    const string brdCntInf = (qtdBrd > 6) ? fmtBrd[6] : " "; // Obtém a borda central inferior
    const string brdInfDir = (qtdBrd > 7) ? fmtBrd[7] : " "; // Obtém a borda inferior direita
    vector<string> lins; // Vetor p/ armazenar as linhas do texto
    string txtFin, lin; // Variáveis p/ armazenar o texto final e uma linha individual
    try { // Tenta centralizar o texto
      for (const auto &txt : txts) { // Define o tamanho máximo de cada linha e salva as linhas em um vector
        istringstream stream(txt);
        while (getline(stream, lin)) {  // Lê cada linha do texto
          lins.push_back(lin); // Salva a linha em um vector
          tam = sizeMtbyIgANSI(lin); // Define o tamanho da linha
          if (tam > tamMax) { tamMax = tam; } // Define o tamanho máximo de cada linha
        } 
      }
      if (semBrd == false) { // Se a caixa tiver bordas
        txtFin += corBrd + brdSupEsq; // Adiciona a borda superior
        for (i = 0; i < tamMax + 2; ++i) { txtFin += brdCntSup; } // ...
        txtFin += brdSupDir + "\n" + modtxt::reset; // ...
      }
      for (const auto &lin : lins) { // Centraliza cada linha do texto
        tam = sizeMtbyIgANSI(lin); // Define o tamanho da linha
        espEsq = (tamMax - tam) / 2; // Define o número de espaços à esquerda
        espDir = tamMax - tam - espEsq; // Define o número de espaços à direita
        txtFin += corBrd + brdCntEsq + modtxt::reset; // Adiciona a borda esquerda
        txtFin += string(espEsq + 1, ' '); // Adiciona os espaços à esquerda
        txtFin += corTxt + lin + modtxt::reset; // Adiciona o texto
        txtFin += string(espDir + 1, ' '); // Adiciona os espaços à direita
        txtFin += corBrd + brdCntDir + modtxt::reset; // Adiciona a borda direita
        if ((semBrd == false) || (lin != lins.back())) { txtFin += "\n"; } // Adiciona "\n" se a caixa tiver bordas ou se não for a última linha
      }  
      if (semBrd == false) { // Se a caixa tiver bordas
        txtFin += corBrd + brdInfEsq; // Adiciona a borda inferior
        for (i = 0; i < tamMax + 2; ++i) { txtFin += brdCntInf; } // ...
        txtFin += brdInfDir + modtxt::reset; // ...
      }
    } catch (const exception &e) { cerr << cortxt::vermelho << "[Erro] " << e.what() << modtxt::reset << endl; } // ...
    return txtFin; // ...
  }

  string alinCx(const vector<string> &txts) { // Função p/ alinhar caixas de texto
    size_t i, linMax = 0; // Variáveis p/ controle
    string txtFin, lin; // Variáveis p/ armazenar o texto final e uma linha individual
    vector<vector<string>> cxTxts; // Vetor p/ armazenar as caixas de texto
    try { // Tenta alinhar as caixas de texto
      for (const auto &txt : txts) {  // Divide cada caixa de texto em linhas
        vector<string> linCx; // Vetor p/ armazenar as linhas da caixa de texto
        istringstream stream(txt); // Cria um stream a partir da caixa de texto
        while (getline(stream, lin)) { linCx.push_back(lin); } // Lê cada linha da caixa de texto
        cxTxts.push_back(linCx); // Salva as linhas da caixa de texto em um vector de vetores
        if (linCx.size() > linMax) { linMax = linCx.size(); } // Define o tamanho máximo de cada linha
      }
      for (i = 0; i < linMax; ++i) { // Alinha as linhas das duas strings lado a lado
        for (const auto &caixas : cxTxts) { // Percorre as duas caixas de texto
          if (i < caixas.size()) { txtFin += caixas[i]; } // Adiciona a linha da caixa de texto
          else { txtFin += string(caixas[0].size(), ' '); } // Adiciona espaços em branco para completar a linha
        }
        if (i < linMax - 1) { txtFin += "\n"; } // Adiciona uma quebra de linha a cada linha, exceto a última
      }
    } catch (const exception &e) { cerr << cortxt::vermelho << "[Erro] " << e.what() << modtxt::reset << endl; } // ...
    return txtFin; // ...
  }
  
  void limpTela() { // Função p/ limpar a tela
    string buffer; // Variável p/ armazenar a entrada do usuário
    cout << "\nAperte " << cortxt::ciano << "[ENTER] " << modtxt::reset << "p/ continuar...";
    getline(cin, buffer);
    if (system("clear") && system("cls")) { throw runtime_error(cortxt::vermelho + "[Erro ao limpar a tela!]" + modtxt::reset); } // ...
  }
  
  bool simOuNao(const string &msg) { // Função p/ confirmar ação
    char resposta;
    bool loop = false;
    do { // Repete até que a resposta seja válida
      limpTela();
      cout << cntCx({msg, cntCx({alinCx({cntCx({" SIM "}, corfnd::verde), " ", cntCx({" NÃO "}, corfnd::vermelho)})})}) << endl;
      cout << "⌨ : ";
      cin >> resposta;
      fpurge();
      resposta = tolower(resposta);
      loop = (resposta != 's' && resposta != 'n' && resposta != '1' && resposta != '0');
      if (resposta == '?') { // Ajuda
        cout << "\n" + cntCx({"▷ Digite [S/1] p/ confirmar ou [N/0] p/ negar ◁"}, cortxt::amarelo) << endl;
      } else if (loop) { cout << "\n" + cntCx({"▷ Resposta inválida! Tente novamente... ◁"}, cortxt::vermelho) << endl; }
    } while (loop);
    return (resposta == 's' || resposta == '1');
  }
}

namespace xadrez { // Namespace p/ funções de jogo de xadrez
  const string PEAO_B = "♟";
  const string PEAO_P = "♙";
  const string TORRE_B = "♜";
  const string TORRE_P = "♖";
  const string CAVALO_B = "♞";
  const string CAVALO_P = "♘";
  const string BISPO_B = "♝";
  const string BISPO_P = "♗";
  const string RAINHA_B = "♛";
  const string RAINHA_P = "♕";
  const string REI_B = "♚";
  const string REI_P = "♔";
  const string PECAS_V = "𒊹";
  const string PECAS_B = PEAO_B + TORRE_B + CAVALO_B + BISPO_B + RAINHA_B + REI_B;
  const string PECAS_P = PEAO_P + TORRE_P + CAVALO_P + BISPO_P + RAINHA_P + REI_P;
  vector<vector<string>> tabul(8, vector<string>(8, PECAS_V));

  bool isFileEmpty(const string &nomeArqv) { // Função p/ verificar se um arquivo está vazio
    ifstream file(nomeArqv, ios::binary | ios::ate);
    return file.tellg() == 0;
  }
  
  void salvTabul(const vector<vector<string>> &tabul, const string &turn, const string &nomeArqv) { // Função p/ salvar tabuleiro em arquivo
    ofstream file(nomeArqv, ios::out); // Abre arquivo em modo de escrita
    if (!file.is_open()) { // Verifica se o arquivo foi aberto com sucesso
      cerr << "Erro ao abrir o arquivo p/ salvar o tabuleiro!" << endl;
      exit(1);
    }
    file << turn << endl;
    for (const auto &linha : tabul) { // Escreve cada linha do tabuleiro no arquivo
      for (size_t i = 0; i < linha.size(); ++i) { // Escreve cada elemento da linha no arquivo
        file << linha[i];
        if (i != linha.size() - 1) { file << " "; }
      }
      file << endl;
    }
    file << endl;
    file.close();
  }

  void salvHstXad(const vector<vector<string>> &tabul, const string &turn, const string &nomeArqv) { // Função p/ salvar tabuleiro em arquivo
    ofstream file(nomeArqv, ios::out | ios::app); // Abre arquivo em modo de escrita
    if (!file.is_open()) { // Verifica se o arquivo foi aberto com sucesso
      cerr << "Erro ao abrir o arquivo p/ salvar o tabuleiro!" << endl;
      exit(1);
    }
    file << turn << endl;
    for (const auto &linha : tabul) { // Escreve cada linha do tabuleiro no arquivo
      for (size_t i = 0; i < linha.size(); ++i) { // Escreve cada elemento da linha no arquivo
        file << linha[i];
        if (i != linha.size() - 1) { file << " "; }
      }
      file << endl;
    }
    file << endl;
    file.close();
  }

  string nomeDispArqv(const string &nomeArqv) { // Função p/ retornar um nome de arquivo válido
    string nomeArqvTemp = nomeArqv;
    size_t posiPnt = nomeArqvTemp.rfind('.');
    string nomeSemExt = (posiPnt == string::npos) ? nomeArqvTemp : nomeArqvTemp.substr(0, posiPnt);
    string ext = (posiPnt == string::npos) ? "" : nomeArqvTemp.substr(posiPnt);
    int cont = 1;
    string novoNomeArqv;
    do { // Verifica se o arquivo já existe
      novoNomeArqv = nomeSemExt + "(" + to_string(cont) + ")" + ext;
      ++cont;
    } while (ifstream(novoNomeArqv).good());
    return novoNomeArqv;
  }

  void carregarTabul(vector<vector<string>> &tabul, string &turn, const string &nomeArqv) { // Função p/ carregar tabuleiro de arquivo
    ifstream file(nomeArqv); // Abre arquivo em modo de leitura
    if (!file.is_open()) { // Verifica se o arquivo foi aberto com sucesso
      cerr << "Erro ao abrir o arquivo p/ carregar o tabuleiro!" << endl;
      exit(1);
    }
    if (!getline(file, turn)) { // Verifica se a primeira linha do arquivo contém o turno
      cerr << "Erro ao ler o turno do arquivo!" << endl;
      exit(1);
    }
    turn = (turn == REI_B) ? REI_P : REI_B;
    string linha;
    tabul.clear();
    while (getline(file, linha)) { // Lê cada linha do arquivo e adiciona à matriz tabul
      if (linha.empty()) continue; // Pula linhas em branco
      vector<string> linhaTabul;
      string peca;
      for (size_t i = 0; i < linha.size(); ++i) { // Separa cada elemento da linha em uma posição do vetor linhaTabul
        if (linha[i] != ' ') { peca += linha[i]; } 
        else {
          linhaTabul.push_back(peca);
          peca.clear();
        }
      }
      linhaTabul.push_back(peca); // Adiciona a última peça da linha
      tabul.push_back(linhaTabul);
    }
    if (tabul.size() != 8 || tabul[0].size() != 8) { // Verifica se a matriz tabul tem o tamanho correto
      cerr << "Erro: o tabuleiro carregado não tem as dimensões corretas!" << endl;
      exit(1);
    }
    file.close();
  }
  
  void preenchTabul() { // Função p/ preencher o tabuleiro
    /*Peças Pretas:  ♙♘♗♖♕♔↓↓*/
    tabul[0][0] = TORRE_P;  // 8a
    tabul[0][1] = CAVALO_P; // 8b
    tabul[0][2] = BISPO_P;  // 8c
    tabul[0][3] = RAINHA_P; // 8d
    tabul[0][4] = REI_P;    // 8e
    tabul[0][5] = BISPO_P;  // 8f
    tabul[0][6] = CAVALO_P; // 8g
    tabul[0][7] = TORRE_P;  // 8h
    tabul[1][0] = PEAO_P;   // 7a
    tabul[1][1] = PEAO_P;   // 7b
    tabul[1][2] = PEAO_P;   // 7c
    tabul[1][3] = PEAO_P;   // 7d
    tabul[1][4] = PEAO_P;   // 7e
    tabul[1][5] = PEAO_P;   // 7f
    tabul[1][6] = PEAO_P;   // 7g
    tabul[1][7] = PEAO_P;   // 7h
    /*Peças Brancas: ♟♞♝♜♛♚↓↓*/
    tabul[6][0] = PEAO_B;   // 2a
    tabul[6][1] = PEAO_B;   // 2b
    tabul[6][2] = PEAO_B;   // 2c
    tabul[6][3] = PEAO_B;   // 2d
    tabul[6][4] = PEAO_B;   // 2e
    tabul[6][5] = PEAO_B;   // 2f
    tabul[6][6] = PEAO_B;   // 2g
    tabul[6][7] = PEAO_B;   // 2h
    tabul[7][0] = TORRE_B;  // 1a
    tabul[7][1] = CAVALO_B; // 1b
    tabul[7][2] = BISPO_B;  // 1c
    tabul[7][3] = RAINHA_B; // 1d
    tabul[7][4] = REI_B;    // 1e
    tabul[7][5] = BISPO_B;  // 1f
    tabul[7][6] = CAVALO_B; // 1g
    tabul[7][7] = TORRE_B;  // 1h
    for (int i = 2; i < 6; i++) { // Preenche as casas vazias do tabuleiro
      for (int j = 0; j < 8; j++) { // ...
        tabul[i][j] = PECAS_V;
      }
    }
  }

  char corPeca(const string &peca) { // Retorna a cor da peça
    if (PECAS_B.find(peca) != string::npos) { return 'b'; } // Verifica se a peça é branca
    if (PECAS_P.find(peca) != string::npos) { return 'p'; } // Verifica se a peça é preta
    return 'v'; // Retorna 'v' se a peça não for branca nem preta
  }

  string buildTabul(const vector<vector<int>> &posiMov = {}, const int &linOrig = -1, const int &colOrig = -1, const string &corPeca = cortxt::verde, const string &corMov = cortxt::ciano) { // Exibe o tabuleiro com a peça selecionada e as jogadas possíveis
    string tabulFin;
    tabulFin += "┌┄┄┄┬──┬──┬❖✘ΔĐREZ❖┬──┬──┬──┐\n";
    for (int i = 0; i < tabul.size(); i++) { // Exibe cada linha do tabuleiro
      tabulFin += "┆ " + to_string(8 - i) + " |"; 
      for (int j = 0; j < tabul[i].size(); j++) { // Exibe cada elemento da linha
        for (int k = 0; k < posiMov.size(); k++) { // Exibe as jogadas possíveis da peça selecionada
          if (i == posiMov[k][0] && j == posiMov[k][1]) { // ...
            tabulFin += corMov;
            k = posiMov.size();
          }
        }
        if (i == linOrig && j == colOrig) { tabulFin += corPeca; } // ...
        tabulFin += tabul[i][j] + modtxt::reset + " |";
      }
      tabulFin += "\n├┄┄┄┼──┼──┼──┼──┼──┼──┼──┼──┤\n";
    }
    tabulFin += "┆L╱C┆ⓐ ┆ⓑ ┆ⓒ ┆ⓓ ┆ⓔ ┆ⓕ ┆ⓖ ┆ⓗ ┆\n"; 
    tabulFin += "└┄┄┄┴┄┄┴┄┄┴┄┄┴┄┄┴┄┄┴┄┄┴┄┄┴┄┄┘";
    return tabulFin;
  }

  tuple<int, char> escolhPosi(const string &msg) { // Função p/ escolher a posição de jogada
    string entrada = " ";
    char coluna = ' ';
    int linha = 0;
    cout << msg << endl;
    cout << "⌨ : ";
    getline(cin, entrada);
    for (int i = 0; i < entrada.length(); i++) { // Converte a entrada p/ int e char
      if (isdigit(entrada[i])) { linha = linha * 10 + (entrada[i] - '0'); } // Converte a entrada p/ int
      else coluna = entrada[i]; // Converte a entrada p/ char
    }
    return make_tuple(((linha >= 0 && linha <= 8) ? 8 - linha : linha), tolower(coluna));
  }

  bool isColisao(const int &linOrig, const int &colOrig, const int &linDest, const int &colDest, const string &pecaOrig) { // Função p/ verificar se existe uma peça no caminho da jogada
    if (colOrig == colDest) { // Movimento vertical
      int passo = linDest > linOrig ? 1 : -1; // Define o passo p/ percorrer as linhas
      for (int i = linOrig + passo; i != linDest; i += passo) { // Verifica se há peças no caminho
        if (tabul[i][colOrig] != PECAS_V) { return true; } // ...
      } 
    } 
      else if (linOrig == linDest) { // Movimento horizontal
        int passo = colDest > colOrig ? 1 : -1; // Define o passo p/ percorrer as colunas
        for (int i = colOrig + passo; i != colDest; i += passo) { // Verifica se há peças no caminho
          if (tabul[linOrig][i] != PECAS_V) { return true; } // ...
        }
      } 
        else if (abs(linOrig - linDest) == abs(colOrig - colDest)) { // Movimento diagonal
          int linPasso = linDest > linOrig ? 1 : -1; // Define o passo p/ percorrer as linhas
          int colPasso = colDest > colOrig ? 1 : -1; // Define o passo p/ percorrer as colunas
          for (int i = 1; i < abs(linDest - linOrig); i++) { // Verifica se há peças no caminho
            if (tabul[linOrig + i * linPasso][colOrig + i * colPasso] != PECAS_V) { return true; } // ...
          }
        }
    return false;
  }

  bool movPeao(const string &peao, const int &linOrig, const int &colOrig, const int &linDest, const int &colDest, const string &pecaDest) { // Verifica se o movimento do peão é válido
    int dir = (peao == PEAO_B) ? -1 : 1;
    int linIni = (peao == PEAO_B) ? 6 : 1;
    if ((colDest == colOrig && pecaDest == PECAS_V) || (abs(colOrig - colDest) == 1 && pecaDest != PECAS_V)) { // Movimento para frente
      if (linDest == linOrig + dir || (linDest == linOrig + 2 * dir && linOrig == linIni && colDest == colOrig && pecaDest == PECAS_V)) { // Verifica se a posição de destino é válida
        return true;
      }
    }
    return false;
  }

  bool movTorre(const int &linOrig, const int &colOrig, const int &linDest, const int &colDest) { // Verifica se o movimento da torre é válido
    return (linOrig == linDest || colOrig == colDest);
  }

  bool movCavalo(const int &linOrig, const int &colOrig, const int &linDest, const int &colDest) { // Verifica se o movimento do cavalo é válido
    return (abs(linOrig - linDest) + abs(colOrig - colDest) == 3) && linOrig != linDest && colOrig != colDest;
  }

  bool movBispo(const int &linOrig, const int &colOrig, const int &linDest, const int &colDest) { // Verifica se o movimento do bispo é válido
    return (abs(linOrig - linDest) == abs(colOrig - colDest));
  }

  bool movRainha(const int &linOrig, const int &colOrig, const int &linDest, const int &colDest) { // Verifica se o movimento da rainha é válido
    return movTorre(linOrig, colOrig, linDest, colDest) || movBispo(linOrig, colOrig, linDest, colDest);
  }

  bool movRei(const int &linOrig, const int &colOrig, const int &linDest, const int &colDest) { // Verifica se o movimento do rei é válido
    return (abs(linOrig - linDest) <= 1 && abs(colOrig - colDest) <= 1);
  }

  bool verLance(const int &linOrig, const int &colOrig, const int &linDest, const int &colDest) { // Verifica se o lance é válido
    if (linOrig == linDest && colOrig == colDest) { return false; }
    if ((linDest < 0 || linDest > 7) || (colDest < 0 || colDest > 7)) { return false; }
    const string pecaOrig = tabul[linOrig][colOrig];
    const string pecaDest = tabul[linDest][colDest];
    if (corPeca(pecaOrig) == corPeca(pecaDest)) { return false; }
    if (isColisao(linOrig, colOrig, linDest, colDest, pecaOrig)) { return false; }
    if (pecaOrig == PEAO_B || pecaOrig == PEAO_P) { // Verifica se o movimento do peão é válido
      return movPeao(pecaOrig, linOrig, colOrig, linDest, colDest, pecaDest);
    }
    if (pecaOrig == TORRE_B || pecaOrig == TORRE_P) { // Verifica se o movimento da torre é válido
      return movTorre(linOrig, colOrig, linDest, colDest);
    }
    if (pecaOrig == CAVALO_B || pecaOrig == CAVALO_P) { // Verifica se o movimento do cavalo é válido
      return movCavalo(linOrig, colOrig, linDest, colDest);
    }
    if (pecaOrig == BISPO_B || pecaOrig == BISPO_P) { // Verifica se o movimento do bispo é válido
      return movBispo(linOrig, colOrig, linDest, colDest);
    }
    if (pecaOrig == RAINHA_B || pecaOrig == RAINHA_P) { // Verifica se o movimento da rainha é válido
      return movRainha(linOrig, colOrig, linDest, colDest);
    }
    if (pecaOrig == REI_B || pecaOrig == REI_P) { // Verifica se o movimento do rei é válido
      return movRei(linOrig, colOrig, linDest, colDest);
    }
    return false;
  }
  
  tuple<int, int> localPosiPeca(const string &peca) { // Função p/ localizar a posição de uma peça
    for (int i = 0; i < tabul.size(); i++) { // Procura a posição da peça
      for (int j = 0; j < tabul[i].size(); j++) { // ...
        if (tabul[i][j] == peca) { return make_tuple(i, j); }  // ...
      }
    }
    return make_tuple(-1, -1);
  }

  void movPeca(const int &linOrig, const int &colOrig, const int &linDest, const int &colDest) { // Função p/ mover uma peça
    tabul[linDest][colDest] = tabul[linOrig][colOrig];
    tabul[linOrig][colOrig] = PECAS_V;
    if (linDest == 0 && tabul[linDest][colDest] == PEAO_B) { tabul[linDest][colDest] = RAINHA_B; } // Transforma o peão em rainha
    else if (linDest == 7 && tabul[linDest][colDest] == PEAO_P) { tabul[linDest][colDest] = RAINHA_P; } // ...
  }

  void desfMovPeca(const int &linOrig, const int &colOrig, const int &linDest, const int &colDest, const string &pecaOrig, const string &pecaDest) { // Função p/ desfazer o movimento de uma peça
    tabul[linOrig][colOrig] = pecaOrig;
    tabul[linDest][colDest] = pecaDest;
  }

  bool isXeque(const string &rei) { // Função p/ verificar se há xeque
    int linRei = 0, colRei = 0;
    tie(linRei, colRei) = localPosiPeca(rei);
    for (int i = 0; i < tabul.size(); i++) { // Verifica se existe alguma peça que possa atacar o rei
      for (int j = 0; j < tabul[i].size(); j++) { // ...
        if (verLance(i, j, linRei, colRei)) { return true; } // ...
      }
    }
    return false;
  }

  vector<vector<int>> posiMovPoss(const int &linOrig, const int &colOrig, const string &rei) { // Função p/ calcular todas as posições possíveis de movimento que não resultam em xeque
    bool xeque = false;
    string pecaOrig = tabul[linOrig][colOrig], pecaDest;
    vector<vector<int>> posiPoss;
    for (int i = 0; i < tabul.size(); i++) { // Verifica todas as jogadas possíveis
      for (int j = 0; j < tabul[i].size(); j++) { // ...
        if (verLance(linOrig, colOrig, i, j)) { // Verifica se a jogada é válida
          pecaDest = tabul[i][j]; // Armazena a peça p/ desfazer o movimento
          movPeca(linOrig, colOrig, i, j); // Move a peça p/ teste
          xeque = isXeque(rei); // Verifica se há xeque
          desfMovPeca(linOrig, colOrig, i, j, pecaOrig, pecaDest); // Desfaz o movimento
          if (!xeque) { posiPoss.push_back({i, j}); } // Adiciona a posição na lista de posições possíveis
        }
      }
    } 
    return posiPoss;
  }

  bool isMovPoss(const vector<vector<int>> &posiMov, const int &linDest, const int &colDest) { // Função p/ verificar se o destino é válido
    for (int i = 0; i < posiMov.size(); i++) { // Verifica se a posição de destino é válida
      if (posiMov[i][0] == linDest && posiMov[i][1] == colDest) { return true; } // ...
    }
    return false;
  }  

  bool isXequeMate(const string &rei) { // Função p/ verificar se o xeque-mate ocorreu
    for (int i = 0; i < tabul.size(); i++) { // Verifica se há alguma peça que possa defender o rei
      for (int j = 0; j < tabul[i].size(); j++) { // ...
        if ((corPeca(tabul[i][j]) == corPeca(rei)) && (!posiMovPoss(i, j, rei).empty())) { return false; } // ...
      }
    }
    return true; // ...
  }

  void modoCheat(bool &cheat) { // Função p/ executar o modo de cheat
    if (!cheat && faux::simOuNao("Ativar Cheat?")) { // Verifica se o jogador deseja ativar o modo cheat
      cheat = true; 
      cout << "\n" + faux::cntCx({"▷ Cheat ativado! ◁"}, cortxt::roxo) << endl;
    }
      else if (cheat && faux::simOuNao("Desativar Cheat?")) { // Verifica se o jogador deseja desativar o modo cheat
        cheat = false;
        cout << "\n" + faux::cntCx({"▷ Cheat desativado! ◁"}, cortxt::roxo) << endl;
      }
  }

  string simulGame(const string &jgdr_B, const string &jgdr_P) { // Função p/ simular um jogo de xadrez
    const string nomeArqv = nomeDispArqv(jgdr_B + " VS " + jgdr_P + ".txt");
    int linOrig = 0, linDest = 0, linRei = 0, colRei = 0;
    char colOrig = ' ', colDest = ' ';
    vector<vector<int>> posiMovPeca;
    bool loop = false, xequeMate = false, cheat = false;
    string turn = REI_B;
    preenchTabul();
    while (true) { // Loop p/ simular o jogo
      xequeMate = isXequeMate((turn == REI_B) ? REI_P : REI_B); // Verifica se o xeque-mate ocorreu
      if (isXeque((turn == REI_B) ? REI_P : REI_B)) { // Verifica se o rei inimigo está em xeque
        faux::limpTela();
        tie(linRei, colRei) = localPosiPeca((turn == REI_B) ? REI_P : REI_B);
        cout << buildTabul({}, linRei, colRei, cortxt::vermelho) << endl;
        if (xequeMate) { // Verifica se o rei inimigo está em xeque-mate
          cout << "\n" + faux::cntCx({"▷ Xeque-mate!: " + ((turn == REI_B) ? jgdr_P + " ♔ ▷PRETAS◁" : jgdr_B + " ♚ ▷BRANCAS◁") + " ◁"}, cortxt::vermelho) << endl;
          return turn; // Retorna o vencedor
        }
        cout << "\n" + faux::cntCx({"▷ Xeque: " + ((turn == REI_B) ? jgdr_P + " ♔ ▷PRETAS◁" : jgdr_B + " ♚ ▷BRANCAS◁") + " ◁"}, cortxt::vermelho) << endl;  
      }
        else if (xequeMate) { // Verifica se o jogador inimigo não pode fazer nenhum movimento e o rei dele não está em xeque
          faux::limpTela();
          cout << buildTabul() << endl;
          cout << "\n" + faux::cntCx({"▷ Empate!: " + jgdr_B + " ♚ ▷BRANCAS◁ ╳ " + jgdr_P + "♔ ▷PRETAS◁ ◁"}, cortxt::vermelho) << endl;
          return (REI_B + REI_P); // Retorna empate
        }
      do { // Loop p/ repetição de jogada
        do { // Loop p/ selecionar a peça
          faux::limpTela();
          cout << buildTabul() << endl;
          cout << "\n" + faux::cntCx({"▷ Turno: " + ((turn == REI_B) ? jgdr_B + " ♚ ▷BRANCAS◁" : jgdr_P + " ♔ ▷PRETAS◁") + " ◁"}) << endl;
          tie(linOrig, colOrig) = escolhPosi(faux::cntCx({"▷ Aperte a tecla 'z' p/ desistir ◁"}, cortxt::amarelo) + "\n▷ Escolha uma peça ◁");
          loop = ((linOrig >= 0 && linOrig <= 7) && 
                 (colOrig >= 'a' && colOrig <= 'h') && 
                 (tabul[linOrig][colOrig - 'a'] != PECAS_V) && 
                 (corPeca(turn) == corPeca(tabul[linOrig][colOrig - 'a']))); // Verifica se a posição de origem é válida
          if (linOrig == 1043 && colOrig == '#') { modoCheat(cheat); } // Verifica se o jogador deseja ativar/desativar o modo cheat
          else if (colOrig == 'z') { // Verifica se o jogador deseja desistir
            if (faux::simOuNao("Tem certeza que deseja desistir\n▷" + ((turn == REI_B) ? jgdr_B : jgdr_P) + "◁ ?")) { // Confirma desistência
              cout << "\n" + faux::cntCx({"▷ Jogador ▷" + ((turn == REI_B) ? jgdr_B : jgdr_P) + "◁ desistiu! ◁"}, cortxt::vermelho) << endl;
              return (turn == REI_B) ? REI_P : REI_B;
            } else { cout << "\n" + faux::cntCx({"▷ Jogador ▷" + ((turn == REI_B) ? jgdr_B : jgdr_P) + "◁ segue! ◁"}, cortxt::roxo) << endl; }
          }
          else if (!loop) { cout << "\n" + faux::cntCx({"▷ Posição inválida! ◁"}, cortxt::vermelho) << endl; } // ...
        } while (!loop);
        posiMovPeca = posiMovPoss(linOrig, colOrig - 'a', turn); // Calcula as posições possíveis de movimento da peça escolhida
        do { // Loop p/ selecionar a posição de destino
          faux::limpTela();
          cout << buildTabul(posiMovPeca, linOrig, colOrig - 'a') << endl;
          cout << "\n" + faux::alinCx({faux::cntCx({"▷ Turno: " + ((turn == REI_B) ? jgdr_B + " ♚ ▷BRANCAS◁" : jgdr_P + " ♔ ▷PRETAS◁") + " ◁"}), faux::cntCx({"▷ Peça: " + tabul[linOrig][colOrig - 'a'] + " ◁"}, cortxt::verde)}) << endl;      
          tie(linDest, colDest) = escolhPosi(faux::cntCx({"▷ Aperte a tecla 'r' p/ voltar ◁", "▷ Aperte a tecla 'z' p/ desistir ◁"}, cortxt::amarelo) + "\n▷ Escolha a posição de destino ◁");
          loop = (colDest == 'r') ||
                 (isMovPoss(posiMovPeca, linDest, colDest - 'a') && 
                 (tabul[linDest][colDest - 'a'] != REI_B && 
                 (tabul[linDest][colDest - 'a'] != REI_P))); // Verifica se a posição de destino é válida
          if (colDest == 'z') { // Verifica se o jogador deseja desistir
            if (faux::simOuNao("Tem certeza que deseja desistir\n▷" + ((turn == REI_B) ? jgdr_B : jgdr_P) + "◁ ?")) {
              cout << "\n" + faux::cntCx({"▷ Jogador ▷" + ((turn == REI_B) ? jgdr_B : jgdr_P) + "◁ desistiu! ◁"}, cortxt::vermelho) << endl;
              return (turn == REI_B) ? REI_P : REI_B;
            } else { cout << "\n" + faux::cntCx({"▷ Jogador ▷" + ((turn == REI_B) ? jgdr_B : jgdr_P) + "◁ segue! ◁"}, cortxt::roxo) << endl; }
          }
          else if (!loop) { cout << "\n" + faux::cntCx({"▷ Posição inválida! ◁"}, cortxt::vermelho) << endl; } // ...
        } while (!loop);      
      } while (colDest == 'r');
      movPeca(linOrig, colOrig - 'a', linDest, colDest - 'a');
      salvHstXad(tabul, turn, nomeArqv);
      xequeMate = isXequeMate((turn == REI_B) ? REI_P : REI_B); // Verifica se o xeque-mate ocorreu
      if (isXeque((turn == REI_B) ? REI_P : REI_B)) { // Verifica se o rei inimigo está em xeque
        faux::limpTela();
        tie(linRei, colRei) = localPosiPeca((turn == REI_B) ? REI_P : REI_B);
        cout << buildTabul({}, linRei, colRei, cortxt::vermelho) << endl;
        if (xequeMate) { // Verifica se o rei inimigo está em xeque-mate
          cout << "\n" + faux::cntCx({"▷ Xeque-mate!: " + ((turn == REI_B) ? jgdr_P + " ♔ ▷PRETAS◁" : jgdr_B + " ♚ ▷BRANCAS◁") + " ◁"}, cortxt::vermelho) << endl;
          return turn; // Retorna o vencedor
        } 
        cout << "\n" + faux::cntCx({"▷ Xeque: " + ((turn == REI_B) ? jgdr_P + " ♔ ▷PRETAS◁" : jgdr_B + " ♚ ▷BRANCAS◁") + " ◁"}, cortxt::vermelho) << endl; 
      }
        else if (xequeMate) { // Verifica se o jogador inimigo não pode fazer nenhum movimento e o rei dele não está em xeque
          faux::limpTela();
          cout << buildTabul() << endl;
          cout << "\n" + faux::cntCx({"▷ Empate!: " + jgdr_B + " ♚ ▷BRANCAS◁ ╳ " + jgdr_P + "♔ ▷PRETAS◁ ◁"}, cortxt::vermelho) << endl;
          return (REI_B + REI_P); // Retorna empate
        }
      if (!cheat) { turn = (turn == REI_B) ? REI_P : REI_B; }; // Troca o turno
    }
  }

  class Jogador { // Classe p/ armazenar os dados dos jogadores
  public:
    string nome;
    int qtdVit_B, qtdDer_B, qtdEmp_B, qtdVit_P, qtdDer_P, qtdEmp_P;
    Jogador(string n) : nome(n), qtdVit_B(0), qtdDer_B(0), qtdEmp_B(0), qtdVit_P(0), qtdDer_P(0), qtdEmp_P(0) {}
  };
  vector<Jogador> jogadores; // Vetor p/ armazenar os jogadores

  void salvJogadores(const string &nomeArqv) { // Função p/ salvar os dados dos jogadores em um arquivo
    ofstream file(nomeArqv, ios::out); // Abre arquivo em modo de escrita
    if (!file.is_open()) { // Verifica se o arquivo foi aberto corretamente
      cout << "Erro ao abrir o arquivo p/ salvar os jogadores!" << endl;
      exit(1);
    }
    for (int i = 0; i < jogadores.size(); i++) { // Salva os dados dos jogadores no arquivo
      file << jogadores[i].nome << " " << jogadores[i].qtdVit_B << " " << jogadores[i].qtdDer_B << " " << jogadores[i].qtdEmp_B << " " << jogadores[i].qtdVit_P << " " << jogadores[i].qtdDer_P << " " << jogadores[i].qtdEmp_P << "\n";
    }
    file.close();      
  }

  void carregJogadores(const string &nomeArqv) { // Função p/ carregar os dados dos jogadores de um arquivo
    ifstream file(nomeArqv); // Abre arquivo em modo de leitura
    if (!file.is_open()) { // Verifica se o arquivo foi aberto corretamente
      cout << "Erro ao abrir o arquivo p/ carregar os jogadores!" << endl;
      exit(1);
    }
    jogadores.clear(); // Limpa o vetor de jogadores atual p/ carregar os novos dados
    string nome;
    int qtdVit_B, qtdDer_B, qtdEmp_B, qtdVit_P, qtdDer_P, qtdEmp_P;
    while (file >> nome >> qtdVit_B >> qtdDer_B >> qtdEmp_B >> qtdVit_P >> qtdDer_P >> qtdEmp_P) { // Lê os dados dos jogadores do arquivo
      jogadores.emplace_back(nome);
      jogadores.back().qtdVit_B = qtdVit_B;
      jogadores.back().qtdDer_B = qtdDer_B;
      jogadores.back().qtdEmp_B = qtdEmp_B;
      jogadores.back().qtdVit_P = qtdVit_P;
      jogadores.back().qtdDer_P = qtdDer_P;
      jogadores.back().qtdEmp_P = qtdEmp_P;
    }
    if (file.bad()) { // Verifica se houve algum erro durante a leitura do arquivo
      cerr << "Erro ao ler o arquivo!" << endl;
      exit(1);
    }
    file.close();
  }

  void exibArqv(const string &nomeArqv, const string &corTxt = cortxt::roxo) { // Função p/ exibir o conteúdo de arquivos
    ifstream file(nomeArqv); // Abre arquivo em modo de leitura
    if (!file.is_open()) { // Verifica se o arquivo foi aberto corretamente
      cerr << "Erro ao abrir o arquivo!" << endl;
      exit(1);
    }
    string linha;
    cout << corTxt;
    while (getline(file, linha)) { // Lê cada linha do arquivo e exibe na tela
      cout << linha << endl;
    }
    cout << modtxt::reset;
    file.close();
  }

  void cadastJogador() { // Função p/ cadastrar jogador
    string nome;
    bool loop = false;
    do { // Loop p/ garantir que o nome do jogador seja válido
      faux::limpTela();
      cout << "\n" + faux::cntCx({"▷ Digite o [nome] do jogador ◁"}) << endl;
      cout << "⌨ : ";
      getline(cin, nome);
      loop = (nome.empty() || faux::isAllSpaces(nome) || nome.size() > 20);
      if (loop) { cout << "\n" + faux::cntCx({"▷ Nome inválido! ◁"}, cortxt::vermelho) << endl; }
    } while (loop);
    if (faux::simOuNao("Tem certeza que deseja cadastrar o jogador\n▷" + nome + "◁ ?")) { // Confirma cadastro
      jogadores.push_back(Jogador(nome)); // Adiciona o jogador ao vetor de jogadores
      cout << "\n" + faux::cntCx({"▷ Jogador ▷" + nome + "◁ cadastrado com sucesso! ◁"}) << endl;
    } else { cout << "\n" + faux::cntCx({"▷ Retornando ao menu... ◁"}) << endl; } // ...
  }

  void exibJogadores() { // Função p/ exibir jogadores
    cout << faux::cntCx({"   ▷ Lista dos Jogadores ◁   "}) << endl;
    for (size_t i = 0; i < jogadores.size(); ++i) { // Exibe os dados dos jogadores
      cout << faux::cntCx({"⌠" + to_string(i + 1) + "⌡" + jogadores[i].nome, 
                           "─────────────────────────",
              faux::cntCx({"Vitórias [♚ ▷BRANCAS◁]: " + to_string(jogadores[i].qtdVit_B),
                           "Derrotas [♚ ▷BRANCAS◁]: " + to_string(jogadores[i].qtdDer_B),
                           "Empates  [♚ ▷BRANCAS◁]: " + to_string(jogadores[i].qtdEmp_B)}),
              faux::cntCx({"Vitórias [♔ ▷PRETAS ◁]: " + to_string(jogadores[i].qtdVit_P),
                           "Derrotas [♔ ▷PRETAS ◁]: " + to_string(jogadores[i].qtdDer_P),
                           "Empates  [♔ ▷PRETAS ◁]: " + to_string(jogadores[i].qtdEmp_P)})}) << endl;
    }
  }

  void exclJogador() { // Função p/ excluir jogador
    string entrada = " ";
    int indice = 0;
    bool loop = false;
    do { // Loop p/ garantir que o índice do jogador seja válido
      faux::limpTela();
      exibJogadores();
      cout << "\n" + faux::cntCx({"▷ Aperte '0' p/ cancelar a exclusão ◁"}, cortxt::amarelo) << endl;
      cout << faux::cntCx({"Digite o [número] do Jogador p/ excluir"}) << endl;
      cout << "⌨ : ";
      getline(cin, entrada);
      if (entrada == "0") { // Verifica se o jogador deseja cancelar a exclusão
        cout << "\n" + faux::cntCx({"▷ Voltando... ◁"}, cortxt::amarelo) << endl;
        return; 
      }
      loop = (entrada < "0" || entrada > to_string(jogadores.size()));
      if (loop) { cout << "\n" + faux::cntCx({"▷ Jogador não encontrado! Tente novamente... ◁"}, cortxt::vermelho) << endl; }
    } while (loop);
    indice = stoi(entrada) - 1;
    if (faux::simOuNao("Deseja realmente excluir\n▷" + jogadores[indice].nome + "◁?")) { // Verifica se deseja excluir o jogador
      jogadores.erase(jogadores.begin() + indice);
      cout << "\n" + faux::cntCx({"▷ Jogador excluído com sucesso! ◁"}) << endl;
    } else { cout << "\n" + faux::cntCx({"▷ Exclusão cancelada! ◁"}) << endl; }
  }

  void iniciarJogo() { // Função p/ iniciar uma partida de xadrez
    string entrada = " ";
    int indJgd1 = 0, indJgd2 = 0;
    bool loop = false;
    do { // Loop p/ garantir que o índice do jogador 1 seja válido
      faux::limpTela();
      exibJogadores();
      cout << "\n" + faux::cntCx({"▷ Aperte '0' p/ voltar ◁"}, cortxt::amarelo) << endl;
      cout << faux::cntCx({"Digite o número do Jogador [♚ ▷BRANCAS◁]"}) << endl;
      cout << "⌨ : ";
      getline(cin, entrada);
      if (entrada == "0") { // Verifica se o jogador deseja voltar
        cout << "\n" + faux::cntCx({"▷ Voltando... ◁"}, cortxt::amarelo) << endl;
        return; 
      }
      loop = (entrada < "0" || entrada > to_string(jogadores.size())); // Verifica se o índice do jogador 1 é válido
      if (loop) { cout << "\n" + faux::cntCx({"▷ Número de Jogador inválido! ◁"}, cortxt::vermelho) << endl; }
    } while (loop);
    indJgd1 = stoi(entrada) - 1; // Converte a entrada do jogador 1 para um índice númerico
    cout << "\n" + faux::cntCx({"▷ Jogador ▷" + jogadores[indJgd1].nome + "◁ selecionado! ◁"}) << endl;
    do { // Loop p/ garantir que o índice do jogador 2 seja válido
      faux::limpTela();
      exibJogadores();
      cout << "\n" + faux::cntCx({"▷ Aperte '0' p/ voltar ◁"}, cortxt::amarelo) << endl;
      cout << faux::cntCx({"Digite o número do Jogador [♔ ▷PRETAS◁]"}) << endl;
      cout << "⌨ : ";
      getline(cin, entrada);
      if (entrada == "0") { // Verifica se o jogador deseja voltar
        cout << "\n" + faux::cntCx({"▷ Voltando... ◁"}, cortxt::amarelo) << endl;
        return; 
      }
      loop = (entrada < "0" || entrada > to_string(jogadores.size()) || to_string(indJgd1 + 1) == entrada); // Verifica se o índice do jogador 2 é válido e diferente do jogador 1
      if (loop) { cout << "\n" + faux::cntCx({"▷ Número de Jogador inválido! ◁"}, cortxt::vermelho) << endl; } // ...
    } while (loop);
    indJgd2 = stoi(entrada) - 1; // Converte a entrada do jogador 2 para um índice númerico
    cout << "\n" + faux::cntCx({"▷ Jogador ▷" + jogadores[indJgd2].nome + "◁ selecionado! ◁"}) << endl;
    string vencedor = simulGame(jogadores[indJgd1].nome, jogadores[indJgd2].nome);
    if (vencedor == REI_B) { // Jogador 1 venceu
      cout << "\n" + faux::cntCx({"▷ Vitória do Jogador ▷" + jogadores[indJgd1].nome + "◁ ◁"}) << endl;
      jogadores[indJgd1].qtdVit_B++; 
      jogadores[indJgd2].qtdDer_P++;
    }
      else if (vencedor == REI_P) { // Jogador 2 venceu
        cout << "\n" + faux::cntCx({"▷ Vitória do Jogador ▷" + jogadores[indJgd2].nome + "◁ ◁"}) << endl;
        jogadores[indJgd2].qtdVit_P++; 
        jogadores[indJgd1].qtdDer_B++;
      }
        else if (vencedor == (REI_B + REI_P)) { // Empate
          cout << "\n" + faux::cntCx({"▷ A partida terminou em empate! ◁"}) << endl;
          jogadores[indJgd1].qtdEmp_B++;
          jogadores[indJgd2].qtdEmp_P++;
        }
          else { // Erro
            cout << "\n" + faux::cntCx({"▷ Erro ao simular a partida! ◁"}) << endl;
            exit(1);
          }
  }

  int menuPrincipal() { // Função p/ exibir menu principal
    string escolha;
    do { // Loop p/ garantir que a escolha seja válida
      faux::limpTela();
      cout << faux::cntCx({" ♚  Menu Principal ♔ ", 
                           "──────────────────────────",
                           "⟪1⟫➤ Cadastrar Jogador ✦", 
                           "⟪2⟫➤ Exibir Jogadores  ✧", 
                           "⟪3⟫➤ Excluir Jogador   ✦", 
                           "⟪4⟫➤ Jogar Partida     ✧", 
                           "⟪0⟫➤ Sair              ✦"}) << endl;
      cout << "⌨ : ";
      getline(cin, escolha);
      if (escolha < "0" || escolha > "4") { cout << "\n" + faux::cntCx({"▷ Escolha inválida! Tente novamente... ◁"}, cortxt::vermelho) << endl; }
    } while (escolha < "0" || escolha > "4");
    return stoi(escolha);
  }

  void inicio() { // Função p/ as funções do menu
    int escolha = 0;
    bool loop = true;
    carregJogadores("jogadores.txt");
    exibArqv("logo.txt", cortxt::azul);
    do { // Loop p/ funcionamento do menu principal
      escolha = menuPrincipal();
      if (escolha == 0) { // Sair
        if (faux::simOuNao("Deseja realmente sair?")) { // Verifica se deseja sair
          cout << "\n" + faux::cntCx({"▷ Saindo... ◁"}) << endl;
          salvJogadores("jogadores.txt");
          faux::limpTela();
          exibArqv("mensagem.txt", cortxt::verde);
          loop = false;
        } else { cout << "\n" + faux::cntCx({"▷ Retornando ao menu... ◁"}) << endl; }
      }
        else if (escolha == 1) { // Cadastrar Jogador
          cadastJogador();
        }
          else if (escolha == 2) { // Exibir Jogadores
            if (jogadores.size() > 0) { // Verifica se há jogadores cadastrados
              faux::limpTela();
              exibJogadores(); 
            } else { cout << "\n" + faux::cntCx({"▷ Nenhum jogador cadastrado! ◁"}, cortxt::vermelho) << endl; }
          }
            else if (escolha == 3) { // Excluir Jogador
              if (jogadores.size() > 0) { exclJogador(); } // Verifica se há jogadores cadastrados
              else { cout << "\n" + faux::cntCx({"▷ Nenhum jogador cadastrado! ◁"}, cortxt::vermelho) << endl; }
            }
              else if (escolha == 4) { // Jogar Partida
                if (jogadores.size() >= 2) { iniciarJogo(); } 
                else { cout << "\n" + faux::cntCx({"▷ Não há jogadores suficientes p/ jogar! ◁"}, cortxt::vermelho) << endl; }
              }
                else { // Caso ocorra algum erro
                  cout << "\n" + faux::cntCx({"▷ Escolha inválida! Tente novamente... ◁"}, cortxt::vermelho) << endl;
                }
    } while (loop);
  }
};

int main() {
  xadrez::inicio();
  return 0;
}