# \# 🖥️ Sistema Operacional Calculadora Avançada (Regra-Kernel)

# 

# Este é um sistema completo de calculadora científica desenvolvido em \*\*C++ Puro\*\*, projetado para rodar direto na linha de comando (CLI). O projeto não utiliza bibliotecas matemáticas prontas, focando em lógica de baixo nível, persistência de dados segura e arquitetura inspirada em sistemas operacionais reais.

# 

# \## 🚀 Funcionalidades da Lógica do Sistema

# 

# \### 1. Métodos Matemáticos de Baixo Nível (Sem `<cmath>`)

# \* \*\*Método de Newton-Raphson:\*\* Cálculo de raiz quadrada por aproximação numérica avançada, configurado com exatamente \*\*20 iterações\*\* para garantir precisão máxima de hardware direto no processador.

# \* \*\*Potência Personalizada:\*\* Lógica estruturada na marra usando laços de repetição (`for`), tratando perfeitamente expoentes positivos, negativos e base zero.

# \* \*\*Operações Avançadas:\*\* Menu completo incluindo Soma, Subtração, Multiplicação, Divisão (com proteção contra divisão por zero), Média, Operação Fator (aritmética modular `% 5`), Precisão e Fing.

# 

# \### 2. Segurança, Criptografia e Rings de Proteção

# O sistema simula a arquitetura de proteção de processadores modernos (como os anéis de segurança Intel/AMD):

# \* \*\*Ring -3:\*\* Ordem Auditoria e FIRMWARE

* # \*\*Ring -2:\*\* Regras do Sistema
* # \*\*Ring -1:\*\* Controlador da Memoria

# \* \*\*Ring 0:\*\* Regra-Kernel 

* # \*\*Ring 3:\*\* Sistema
* # \*\*Ring 2:\*\* Utilitario de Limpeza

# \* \*\*Ring 1:\*\* Usuário

# \* \*\*Cifra de César de Persistência:\*\* Todos os logs salvos no disco passam por uma função de criptografia com deslocamento modular `% 26`. Os dados reais nunca ficam expostos no arquivo físico.

# \* \*\*Sistema de Autenticação:\*\* Bloqueio e banimento automático do usuário após 3 tentativas de senha incorretas (validação baseada em hexadecimal `0x3FF`).

# 

# \### 3. Persistência de Dados Otimizada

# \* Utilização da estrutura de dados `std::deque` para gerenciar a fila do histórico na memória RAM.

# \* Limitador lógico inteligente que impede o histórico de passar de \*\*50 operações\*\*.

# \* Uso de `<fstream>` (`ofstream` e `ifstream`) para gravação, leitura e o módulo especial de "Limpeza de Histórico" pelo personagem Utilitário.

# 

# \---

# 

# \## 👥 Como Colaborar e Entrar na Equipe

# 

# Estamos montando uma equipe profissional de \*\*5 a 10 pessoas\*\* para expandir este ecossistema de segurança e comandos!

# 

# &#x20;Se você quer colaborar com o projeto:

# 1\. Faça um \*\*Fork\*\* deste repositório para o seu GitHub.

# 2\. Crie uma nova Branch para as suas modificações.

# 3\. Entre em contato pelo nosso e-mail oficial de desenvolvimento: \*\*joaoanandalima@gmail.com\*\*

# 4\. Enviaremos o link do nosso servidor focado em programação no \*\*Discord\*\* para começarmos a trabalhar juntos!

# 

# \---

# \*Desenvolvido inteiramente por João Guilherme da Silva Freitas Lima.\*



