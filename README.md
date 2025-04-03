# Tabela-Campeonato-Futebol
Este projeto implementa um programa para simular a tabela de classificação de um campeonato de futebol com 10 equipes.

# Simulação de Tabela de Campeonato de Futebol

Este projeto simula a tabela de classificação de um campeonato de futebol com 10 equipes. O programa lê os resultados dos jogos a partir de um arquivo `.txt` e calcula a pontuação dos times, gerando ao final a classificação completa no formato de um arquivo `.txt`.

## Regras do Campeonato

1. **Pontuação por vitória**: 3 pontos para o time vencedor.
2. **Pontuação por empate**: 1 ponto para cada time quando o jogo terminar empatado.
3. **Critério de desempate**: Se dois ou mais times tiverem a mesma pontuação, o desempate será feito pelo **saldo de gols**.

## Funcionalidades

- **Entrada de dados**: O programa lê os resultados dos jogos a partir de um arquivo `.txt`. O formato do arquivo de entrada contém o nome das equipes e a quantidade de gols de cada time em cada jogo.
- **Saída de dados**: Ao final da execução, o programa gera um arquivo `classificacao.txt` com a tabela final, incluindo a posição, pontos e saldo de gols de cada equipe.

## Formato do Arquivo de Entrada

O arquivo de entrada (exemplo: `TimesGols.txt`)
