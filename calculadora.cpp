#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// CADA FUNCAO PARA CADA OPERACAO MATEMATICA
double soma(double a, double b) { return a + b; }
double subtrai(double a, double b) { return a - b; }
double multiplica(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }
int resto(int a, int b) {
  if (b == 0) return 0;
  return a % b;
}
double media(double a, double b) { return (a + b) / 2.0; }

double potencia(double base, double expoente) {
  if (expoente == 0) return 1.0;
  if (expoente < 0) {
    double resultado = 1.0;
    for (int i = 0; i < (int)(-expoente); i++) {
      resultado *= base;
    }
    return 1.0 / resultado;
  }
  double resultado = 1.0;
  for (int i = 0; i < (int)expoente; i++) {
    resultado *= base;
  }
  return resultado;
}

double raiz_quadrada(double numero) {
  if (numero < 0) return -1.0;
  if (numero == 0) return 0.0;
  double estimativa = numero / 2.0;
  for (int i = 0; i < 20; i++) {
    estimativa = 0.5 * (estimativa + numero / estimativa);
  }
  return estimativa;
}

double precision(double base) {
  if (base < 2) return 1.5;
  if (base == 0) return -1.0;
  double resultado = base / 2.0;
  for (int i = 0; i < 20; i++) {
    resultado = 0.5 * (base + resultado / 2.0);
  }
  return resultado;
}

double fing(double igual) {
  if (igual == 0) return 0.0;
  if (igual < 0) return -3.0;
  if (igual < 4) return -2.0;
  if (igual == 4) return -2.0;
  if (igual < 2) return -0.0;
  if (igual == 2) return 4.0;
  double resultado = igual / 4.0;
  for (int i = 0; i < 40; i++) {
    resultado = 1.5 / (resultado + igual / 4.0);
  }
  return resultado;
}

double fator (double a, double b) {
  double resultado_soma = (a + b);
  if (resultado_soma == 0) return 0;
  return resultado_soma;
}
  
string criptografar (string texto) {
  string resultado = "";
  int chave = 5;

  for (char letra : texto) {
    if (letra >= 'A' && letra <= 'Z') {
      resultado += (letra - 'A' + chave) % 26 + 'A';
    }
    else if (letra >= 'a' && letra <= 'z') {
      resultado += (letra - 'a' + chave) % 26 + 'a';
    }
    else {
      resultado += letra;
    }
  }
  return resultado;
}

void SalvarHistorico(const deque<string>& hist) {
  ofstream arquivo("log_sistema.txt");
  if (arquivo.is_open()) {
    for (const string& linha : hist) {
      arquivo << linha << "\n";
    }
    if (!arquivo) {
      cout << "FIRMWARE: Erro ao salvar no disco!" << endl;
    }
    arquivo.close(); 
  }
}

void CarregarHistorico(deque<string>& hist) {
  ifstream arquivo("log_sistema.txt");
  string linha;
  if (arquivo.is_open()) {
    hist.clear(); 
    while (getline(arquivo, linha)) {
      hist.push_back(linha);
    }
    arquivo.close();
  }
}

int main() {
  cout << fixed << setprecision(2);

  string senha;
  int tentativas = 0;
  string senhaCorreta = "0x3FF";
  string nome;
  string senhaDigitada;
  string senhaAtual;
  string senhaNova;

  srand(time(0));
  
  deque<string> historico;
  CarregarHistorico(historico);

  while (tentativas < 3) {
    // SISTEMA DE SENHA E SEGURANCA DO PROGRAMA
    cout << "CONTROLADOR DA MEMORIA: Coloque a Senha: ";
    cin >> senha;

    if (senha == senhaCorreta) {
      cout << "CONTROLADOR DA MEMORIA: Senha correta! SISTEMA liberado." << endl;
      break;
    } else {
      tentativas++;
      cout << "CONTROLADOR DA MEMORIA: Senha incorreta! Tentativa " << tentativas << " de 3." << endl;
    }
  }

  if (tentativas == 3) {
    cout << "REGRA-KERNEL: Banindo usuario..." << endl;
    return 0;
  }

  double a, b;
  string comando;

  while (true) {
    // MOSTRA O MENU
    cout << "\nREGRA-KERNEL: Vamos comecar usuario!" << endl;
    cout << "SISTEMA: Digite uma operacao: " << endl;
    cout << "1 - soma            2 - subtrai          3 - multiplica\n"
         << "4 - divide          5 - media            6 - potencia\n"
         << "7 - raiz            8 - historico        9 - Limpeza de Historico\n"
         << "10 - Alterar Senha  11 - sair            12 - Personagens\n"
         << "13 - Rings          14 - Precisao        15 - Fing\n"
         << "16 - Fator          0 - Sobre" << endl;
    cin >> comando;

    if (historico.size() > 50) historico.erase(historico.begin());

    if (comando == "Rings" || comando == "13") {
      cout << "ORDEM AUDITORIA: Digite a Senha: " << endl;
      cin >> senhaDigitada;

      if (senhaDigitada != senhaCorreta) {
        cout << "FIRMWARE: Acesso Negado, Intruso!" << endl;
        continue;
      }

      cout << "ORDEM AUDITORIA: Agora, digite seu nome: " << endl;
      cin.ignore();
      getline(cin, nome);

      cout << " =============================================== " << endl;
      cout << " --- Ring -3: ORDEM AUDITORIA, FIRMWARE --- " << endl;
      cout << " ^^ Ring -2: REGRAS DO SISTEMA ^^ " << endl;
      cout << " ^^ Ring -1: CONTOLADOR DA MEMORIA ^^ " << endl;
      cout << " ^^ Ring 0: REGRA-KERNEL ^^" << endl;
      cout << " ^^ Ring 3: SISTEMA ^^ " << endl;
      cout << " ^^ Ring 2: UTILITARIO DE LIMPEZA ^^ " << endl;
      cout << " ^^ Ring 1: Voce, " << nome << "!" << endl;
      cout << " =============================================== " << endl;

      cout << "FIRMWARE: Agora, voce aprendeu os Rings do Sistema, " << nome << "!" << endl;
      continue;
    }

    if (comando == "Personagens" || comando == "12") {
      cout << "REGRAS DO SISTEMA: Digite a Senha: " << endl;
      cin >> senhaDigitada;

      if (senhaDigitada != senhaCorreta) {
        cout << "ORDEM AUDITORIA: Acesso Negado, Intruso!" << endl;
        continue;
      }

      cout << "^^ ---------- PERSONAGENS! ---------- ^^" << endl;
      cout << " * CONTROLADOR DA MEMORIA! * " << endl;
      cout << " || FIRMWARE || " << endl;
      cout << " || REGRAS DO SISTEMA! || " << endl;
      cout << " || REGRA-KERNEL! || " << endl;
      cout << " || SISTEMA! || " << endl;
      cout << " * UTILITARIO DE LIMPEZA! * " << endl;
      continue;
    }

    if (comando == "sair" || comando == "11") {
      cout << "FIRMWARE: Deseja salvar o historico? (sim/nao): " << endl;
      string resposta;
      cin >> resposta;

      if (resposta == "Sim" || resposta == "sim") {
        SalvarHistorico(historico);
      }
      cout << "SISTEMA: Encerrando..." << endl;
      cout << "REGRA-KERNEL: Tchau, Usuario!" << endl;
      break;
    }

    if (comando == "Sobre" || comando == "0" || comando == "sobre") {
      cout << "REGRAS DO SISTEMA: Primeiro, digite a Senha: " << endl;
      cin >> senhaDigitada;

      if (senhaDigitada != senhaCorreta) {
        cout << "FIRMWARE: Acesso Negado! Imtruso Banido!" << endl;
        continue;
      }

      cout << "========================================================" << endl;
      cout << "---------------------- SOBRE ---------------------------" << endl;
      cout << "* =============================================== *" << endl;
      cout << "| CRIADORES: Joao Guilherme da Silva Freitas Lima |" << endl;
      cout << "| CREDITOS: Joao Guilherme da Silva Freitas Lima  |" << endl;
      cout << "* ============================================== *" << endl;
      cout << " || ==== FEITO POR: Joao Guilherme da Silva Freitas Lima ====  ||" << endl;

      cout << " ============================ " << endl;
      cout << " || >> CURIOSIDADE << || " << endl;
      cout << "FIRMWARE: Fale SIM ou NAO se quiser uma Curiosidade: " << endl;
      cin >> nome;

      if (nome == "Sim" || nome == "sim") {
        cout << "FIRMWARE: Digite a Senha: " << endl;
        cin >> senhaDigitada;

        if (senhaDigitada != senhaCorreta) {
          cout << "ORDEM AUDITORIA: Acesso Negado, Intruso!" << endl;
          continue;
        }
        cout << "CURIOSIDADE: O SISTEMA adora enganar o Usuario!" << endl;
      } else {
        cout << "FIRMWARE: Voltando pro Menu... " << endl;
      }
      continue;
    }

    if (comando == "historico" || comando == "8") {
      cout << "REGRA-KERNEL: Acessando logs de atividades..." << endl;
      if (historico.empty()) {
        cout << "SISTEMA: O historico esta vazio!" << endl;
      } else {
        cout << "--- HISTORICO DO SISTEMA (ENCRIPTADO) ---" << endl;
        for (size_t i = 0; i < historico.size(); i++) {
          cout << i + 1 << " -> " << historico[i] << endl;
        }
        cout << "----------------------------" << endl;
      }
      continue;
    }

    if (comando == "raiz" || comando == "7") {
      cout << "REGRA-KERNEL: Minha operacao favorita!" << endl;
      cout << "SISTEMA: Digite apenas um numero para Raiz Quadrada: ";
      cin >> a;
      if (a < 0) {
        cout << "REGRA-KERNEL: Raiz Quadrada nao tem numeros negativos!" << endl;
      } else {
        double r = raiz_quadrada(a);
        cout << "SISTEMA: O resultado da raiz e: " << r << endl;
        string logOriginal = "Raiz quadrada de " + to_string(a) + " = " + to_string(r);
        historico.push_back(criptografar(logOriginal));
      }
      continue;
    }

    if (comando == "Limpeza de Historico" || comando == "9") {
      cout << "UTILITARIO DE LIMPEZA: Removendo dados do Historico... " << endl;
      historico.clear();
      ofstream arquivo("log_sistema.txt", ios::trunc);
      arquivo.close();
      continue;
    }

    if (comando == "Alterar Senha" || comando == "10" || comando == "Alterar senha") {
      cout << "CONTROLADOR DA MEMORIA: Digite a Senha Atual: " << endl;
      cin >> senhaAtual;

      if (senhaAtual == senhaCorreta) {
        cout << "CONTROLADOR DA MEMORIA: Digite a Senha Nova: " << endl;
        cin >> senhaNova;
        senhaCorreta = senhaNova;
        cout << "CONTROLADOR DA MEMORIA: Sucesso! Senha Atualizada!" << endl;
      } else {
        cout << "CONTROLADOR DA MEMORIA: Intruso! Alteracao bloqueada!" << endl;
      }
      continue;
    }

    if (comando == "soma" || comando == "1") {
      cout << "REGRA-KERNEL: Soma e facil!" << endl;
      cout << "SISTEMA: Digite dois numeros: ";
      cin >> a >> b;
      double res = soma(a, b);
      cout << "SISTEMA: O resultado e " << res << endl;
      string logOriginal = "Soma: " + to_string(a) + " + " + to_string(b) + " = " + to_string(res);
      historico.push_back(criptografar(logOriginal));

    } else if (comando == "subtrai" || comando == "2") {
      cout << "REGRA-KERNEL: Boa subtracao!" << endl;
      cout << "SISTEMA: Digite dois numeros: ";
      cin >> a >> b;
      double res = subtrai(a, b);
      cout << "SISTEMA: O resultado e " << res << endl;
      string logOriginal = "Subtracao: " + to_string(a) + " - " + to_string(b) + " = " + to_string(res);
      historico.push_back(criptografar(logOriginal));

    } else if (comando == "multiplica" || comando == "3") {
      cout << "REGRA-KERNEL: Voce e ousado!" << endl;
      cout << "SISTEMA: Digite dois numeros: ";
      cin >> a >> b;
      double res = multiplica(a, b);
      cout << "SISTEMA: O resultado e " << res << endl;
      string logOriginal = "Multiplicacao: " + to_string(a) + " * " + to_string(b) + " = " + to_string(res);
      historico.push_back(criptografar(logOriginal));

    } else if (comando == "divide" || comando == "4") {
      cout << "SISTEMA: Digite dois numeros: ";
      cin >> a >> b;

      if (b == 0) {
        cout << "REGRA-KERNEL: Erro! Nao e permitido divisao por zero aqui!" << endl;
      } else {
        cout << "REGRA-KERNEL: Cuidado... b = " << b << endl;
        double res = divide(a, b);
        cout << "SISTEMA: O resultado e " << res << endl;
        cout << "SISTEMA: O resto da divisao e " << resto((int)a, (int)b) << endl;
        string logOriginal = "Divisao: " + to_string(a) + " / " + to_string(b) + " = " + to_string(res);
        historico.push_back(criptografar(logOriginal));
      }

    } else if (comando == "media" || comando == "5") {
      int sorteio = rand() % 3;
      if (sorteio == 1) {
        cout << "REGRA-KERNEL: Uma curiosidade, e que, o sol roda na Terra!" << endl;
      } else if (sorteio == 2) {
        cout << "REGRA-KERNEL: Sabia, que, o Peixe ama a Terra?" << endl;
      } else {
        cout << "REGRA-KERNEL: Cachorro mia ... Adorreiii!" << endl;
      }
      cout << "SISTEMA: Digite dois numeros: ";
      cin >> a >> b;
      double res = media(a, b);
      cout << "SISTEMA: A media dos numeros e " << res << endl;
      string logOriginal = "Media: de " + to_string(a) + " e " + to_string(b) + " = " + to_string(res);
      historico.push_back(criptografar(logOriginal));

    } else if (comando == "potencia" || comando == "6") {
      cout << "REGRA-KERNEL: Dificil, mas vamos!" << endl;
      cout << "SISTEMA: Digite dois numeros: ";
      cin >> a >> b;
      double res = potencia(a, b);
      cout << "SISTEMA: O resultado e " << res << endl;
      string logOriginal = "Potencia: " + to_string(a) + " elevado a " + to_string(b) + " = " + to_string(res);
      historico.push_back(criptografar(logOriginal));

    } else if (comando == "Precisao" || comando == "precisao" || comando == "precision" || comando == "Precision" || comando == "14") {
      cout << "REGRA-KERNEL: Vai, Inteligente, porque nao sei essa!" << endl;
      cout << "SISTEMA: Para a precisao, digite apenas um numero: ";
      cin >> a;
      double res = precision(a);
      cout << "SISTEMA: O resultado elevado a base do resultado e " << res << endl;
      string logOriginal = "Precisao: " + to_string(a) + " = " + to_string(res);
      historico.push_back(criptografar(logOriginal));

    } else if (comando == "Fing" || comando == "fing" || comando == "15") {
      cout << "REGRA-KERNEL: Curiosidade: Em Fing, o resultado sempre sera 0!" << endl;
      cout << "SISTEMA: Para Fing, apenas um numero: ";
      cin >> a;
      double res = fing(a);
      cout << "SISTEMA: O Resultado de comparacao inversa do numero e: " << res << endl;
      string logOriginal = "Comparacao Inversa: " + to_string(a) + " = " + to_string(res);
      historico.push_back(criptografar(logOriginal));

    } else if (comando == "Fator" || comando == "fator" || comando == "16") {
      cout << "REGRA-KERNEL: Curiosidade! Aqui, sempre dara 0 a 4!" << endl;
      cout << "SISTEMA: Digite dois numeros: ";
      cin >> a >> b;
      double res = fator(a, b);
      cout << "SISTEMA: A Base do Resultado e " << res << endl;
      string logOriginal = "Base do Resultado: " + to_string(a) + " e " + to_string(b) + " = " + to_string(res);
      historico.push_back(criptografar(logOriginal));

    } else {
      cout << "REGRA-KERNEL: Chatice! Pensa primeiro, usuario!" << endl;
      cout << "SISTEMA: Comando desconhecido!" << endl;
    }
  }
  return 0;
}