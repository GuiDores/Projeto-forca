# Projeto-forca
# 🎮 Quem é Esse Pokémon? (Jogo da Forca em C)

<div align="center">
    <img src="https://img.shields.io/badge/Linguagem-C-blue.svg" alt="Linguagem C">
    <img src="https://img.shields.io/badge/Licença-MIT-green.svg" alt="Licença MIT">
</div>

Um divertido jogo da forca implementado em C, com um toque especial: as palavras secretas são nomes de Pokémon! Teste seus conhecimentos e tente adivinhar o nome do Pokémon antes que o boneco seja enforcado.

## ✨ Funcionalidades

* **Tema Pokémon:** A palavra secreta a ser adivinhada é o nome de um Pokémon (lido de um arquivo `palavras.txt`).
* **Controle de Tentativas:** O jogador tem um número limitado de erros para adivinhar a palavra.
* **Desenho da Forca:** A forca e o boneco são desenhados no terminal (ASCII Art), evoluindo com os erros.
* **Gerenciamento de Palavras:** O jogo permite que o usuário adicione novas palavras (nomes de Pokémon) ao arquivo `palavras.txt` ao final de cada partida.
* **Cross-Plataforma (Básico):** Inclui ajustes para melhor compatibilidade de caracteres em ambientes Windows (`_WIN32`).

## ⚙️ Como Compilar e Executar

### Pré-requisitos

Você precisará de um compilador C, como **GCC** ou **Clang**, instalado em seu sistema.

### Passo a Passo

1.  **Clone o repositório** (se estiver em um):
    ```bash
    git clone [LINK_DO_SEU_REPOSITORIO]
    cd [pasta-do-projeto]
    ```

2.  **Crie o arquivo de palavras:**
    Certifique-se de ter um arquivo chamado **`palavras.txt`** na mesma pasta do código-fonte. A primeira linha deve conter a quantidade total de palavras, e as linhas seguintes, as palavras em **letras maiúsculas**, uma por linha.

    Exemplo de `palavras.txt`:
    ```
    3
    PIKACHU
    CHARMANDER
    BULBASAUR
    ```

3.  **Compile o código:**
    Assumindo que o arquivo principal é `forca.c` (ou o nome que você deu) e há um arquivo de cabeçalho `forca.h` (mencionado no código):

    ```bash
    # Para compilar, substitua 'nome_do_executavel' e 'forca.c' pelos nomes corretos
    gcc forca.c -o nome_do_executavel
    ```
    *Se você tiver o código dividido em mais de um arquivo C, liste-os todos na compilação.*

4.  **Execute o jogo:**
    ```bash
    ./nome_do_executavel
    ```

## 🕹️ Como Jogar

1.  O jogo irá sortear um nome de Pokémon do arquivo `palavras.txt`.
2.  O título **"Quem é Esse Pokémon"** e o estado atual da forca serão exibidos.
3.  Digite uma letra por vez quando solicitado.
4.  As letras corretas preencherão a palavra. As letras erradas farão o boneco ser enforcado.
5.  O jogo termina quando você adivinhar a palavra ou for enforcado (5 erros).
6.  Ao final, você terá a opção de adicionar um novo nome de Pokémon à lista!

## 🛠️ Detalhes da Implementação (para Desenvolvedores)

O projeto utiliza funções modulares para:

* `ft_cabecalho()`: Exibe o título do jogo.
* `ft_chute()`: Captura a letra chutada pelo jogador.
* `ft_desenhar_forca()`: Renderiza o estado atual do boneco e da palavra.
* `ft_escolher_palavra()`: Seleciona uma palavra aleatória do `palavras.txt`.
* `ft_adicionar_palavra()`: Permite adicionar novas palavras ao arquivo.
* `ft_enforcou()` e `ft_acertou()`: Lógicas de fim de jogo.
* `toUpperCase()` e `toUpperCaseString()`: Funções utilitárias para garantir que todos os inputs sejam tratados em maiúsculas.

---

## 🤝 Contribuições

Sinta-se à vontade para sugerir melhorias, como:

* Aumento no limite de erros.
* Gráficos ASCII Art mais detalhados.
* Melhor tratamento de erros de input.
* Adicionar um contador de tentativas restantes.

1.  Faça um Fork do projeto.
2.  Crie uma branch para sua funcionalidade (`git checkout -b feature/NovaFuncionalidade`).
3.  Faça o Commit das suas alterações (`git commit -m 'feat: Adiciona Nova Funcionalidade'`).
4.  Faça o Push para a Branch (`git push origin feature/NovaFuncionalidade`).
5.  Abra um Pull Request.

## 📝 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE] (se você criar um) para mais detalhes.

## ✉️ Contato

[GuiDores] - [guilhermedores20@gmail.com]

Link do Projeto: [LINK_DO_SEU_REPOSITORIO]
