#include <iostream>
#include "loja.hpp"

using namespace std;

int main() {
  /* Criação das variáveis responsáveis pela contagem da quantidade de execuções e quantidade de rolos */
  int testAmount, rollAmount;

  /* Leitura da quantidade de testes que será executada */
  cin >> testAmount;
  
  // Condição para parada da execução do loop de execução do programa
  while(testAmount >= 1) {
    // Criação de variáveis auxiliares
    int aux, totalSum = 0, actualSum = 0, actualValue = 0;

    /* Leitura da quantidade de rolos da execução atual */
    cin >> rollAmount;

    /* Criação da instância store */
    Store *store = new Store();

    /* Leitura dos dados referentes aos rolos e adição deles ao vetor de rolos */
    for(int i = 0; i < rollAmount; i++) {
      cin >> aux;
      store->rollArray.push_back(aux);
    }

    /* Remoção do primeiro valor para execução do algoritmo no subvetor com exceção do primeiro elemento */
    actualValue = store->rollArray[0];
    store->rollArray.erase(store->rollArray.begin());

    /* Loop em que a execução do algoritmo é feita recursivamente em um vetor cada vez menor, sempre removendo o primeiro elemento
    antes da próxima execução, a execução termina assim que o tamanho do vetor é igual ou menor que a quantidade de elementos do vetor
    qeu armazena a quantidade de rolos, pois é impossível gerar um vetor maior partindo de um menor */
    while(store->getSize() > totalSum) {

      /* Resetando os valores dos vetores intermediários para execução do algoritmo */
      store->resetVectors();

      /* Criação de dois subvetores, sendo um deles com elementos de valor menor que o elemento inicial do vetor e o outro
      vetor contendo apenas os elementos maiores que o primeiro elemento do vetor */
      for(int i = 0; i < store->getSize(); i++) {
        if(actualValue > store->rollArray[i])
          /* Adicionando o valor ao início do subvetor criando um vetor reverso para achar o maior subvetor decrescente para a configuração
          atual de valor de início e vetor alterado */
          store->lessThan.insert(store->lessThan.begin(), store->rollArray[i]);
        else
          /* Adicionando o valor ao final do subvetor para achar o maior subvetor crescente para a configuração atual de valor de início e
          vetor alterado */
          store->moreThan.push_back(store->rollArray[i]);
      }

      /* Setando o valor atual da quantidade de rolos para exibição */
      actualSum = store->maxVectorSequence();

      /* Comparando se o valor antigo da quantidade de rolos é menor que o valor atual. Caso seja, é atualizado. Caso não seja, continua com o mesmo
      valor de antes */
      totalSum = (totalSum < actualSum) ? actualSum : totalSum;

      /* Atualização do valor inicial do vetor e remoção dele para execução do próximo subvetor em análise */
      actualValue = store->rollArray[0];
      store->rollArray.erase(store->rollArray.begin());
    }

    /* Impressão do valor final da quantidade de rolos para a instância atual */
    cout << totalSum << endl;

    /* Redução da quantidade de testes para parar o loop while de execução */
    testAmount--;
  }

  return(0);
}
