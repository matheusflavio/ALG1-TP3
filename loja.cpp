#include "loja.hpp"

Store::Store(){
    this->rollArray = vector<int>(0);
    resetVectors();
}

void Store::setSize(int size) {
    this->size = size;
}
void Store::setSizeMore(int size) {
    this->sizeMore = size;
}
void Store::setSizeLess(int size) {
    this->sizeLess = size;
}

void Store::resetVectors() {
    this->moreThan = vector<int>(0);
    this->lessThan = vector<int>(0);
    this->exposed = vector<int>(0);
}

int Store::getSize() {
    return rollArray.size();
}

int Store::getSizeMore() {
    return moreThan.size();
}

int Store::getSizeLess() {
    return lessThan.size();
}

int Store::maxVectorSequence() {
    int sizeMore = getSizeMore();
    int sizeLess = getSizeLess();
    int res = 0;

    /* Caso exista um vetor não vazio de rolos de valor maior que o primeiro atual, executa o algoritmo de encontrar o maior subvetor
    crescente e acrescenta esse vetor ao vetor de rolos em exposição */
    if(sizeMore > 0) {
      res = longestIncreaseSubArray(moreThan, sizeMore);
    }
 
    /* Caso exista um vetor não vazio de rolos de valor menor que o primeiro atual, executa o algoritmo de encontrar o maior subvetor
    crescente para os valores menores, que, como foram adicionados sempre ao começo do vetor, encontra o maior subvetor decrescente de rolos
    com preço menor que o primeiro atual e acrescenta esse vetor ao vetor de rolos em exposição */
    if(sizeLess > 0) {
      res += longestIncreaseSubArray(lessThan, sizeLess);
    }
 
    /* Retorno da soma dos tamanhos das sequências dos subvetores acrescido em 1, que corresponde à soma dos tamanhos dos subvetores de preço
    maior e menor que o valor inicial, acrescidos em 1 correspondente ao valor que é desconsiderado nos subvetores */
    return res + 1;
}

int Store::longestIncreaseSubArray(vector<int>array, int size) {
    /* Adição de casos limite para teste */
    vector<int> lowestIndices(size, 0);
    vector<int> lastIndices(size, -1);
 
    int len = 1, res = 0;
    for (int i = 1; i < size; i++) {
 
        /* Caso seja maior que o último elemento do vetor, aumenta a maior subsequência */
        if (array[i] > array[lowestIndices[len - 1]]) {           
            lastIndices[i] = lowestIndices[len - 1];
            lowestIndices[len++] = i;
        }
 
        /* Atualiza o menor valor armazenado no vetor caso o valor atual seja menor que o armazenado */
        else if (array[i] < array[lowestIndices[0]])            
            lowestIndices[0] = i;
          
        /* Caso não seja menor que o menor valor e nem maior que o maior valor armazenado, o valor atual em i pode ser um candidato para uma 
        subsequência futura, então, substitui o valor de teto dos índices*/
        else {
            int pos = ceilBinarySearch(array, lowestIndices, -1, len - 1, array[i]);
            lastIndices[i] = lowestIndices[pos - 1];
            lowestIndices[pos] = i;
        }
    }
 
    /* Calcula o tamanho do maior subvetor crescente de rolos expostos */
    for (int i = lowestIndices[len - 1]; i >= 0; i = lastIndices[i])
        res++;

    return res;
}

/* Função de busca binária para o valor de teto dentro do subvetor a fim de acrescentar esse valor como sendo um valor potencial
futuro para uma subsequência */
int Store::ceilBinarySearch(vector<int> array, vector<int>& tailIndices, int left, int right, int key) {
    while (right - left > 1) {
        int middle = left + (right - left) / 2;
        if (array[tailIndices[middle]] >= key)
            right = middle;
        else
            left = middle;
    }
    return right;
}