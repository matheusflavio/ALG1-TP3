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

    if(sizeMore > 0) {
      // find LIS of array 1 in reverse form
      longestIncreaseSubArray(moreThan, sizeMore);
    }
 
    // reverse res to get LIS of first array
 
    if(sizeLess > 0) {
      /* Inversão do vetor menor que o valor inicial atual para achar o maior subvetor decrescente para terminar
      a criaçã do vetor de exposição */
      longestIncreaseSubArray(lessThan, sizeLess);
    }
 
    /* Retorno da soma das sequências dos subvetores acrescido em 1, que corresponde ao valor inicial do vetor que é desconsiderado nos subvetores */
    return exposed.size() + 1;
}

void Store::longestIncreaseSubArray(vector<int>array, int n) {
    // Add boundary case, when array n is zero
    // Depend on smart pointers
    vector<int> tailIndices(n, 0); // Initialized with 0
    vector<int> prevIndices(n, -1); // initialized with -1
 
    int len = 1; // it will always point to empty location
    for (int i = 1; i < n; i++) {
 
        // new smallest value
        if (array[i] < array[tailIndices[0]])            
            tailIndices[0] = i;
 
        // arr[i] wants to extend largest subsequence
        else if (array[i] > array[tailIndices[len - 1]]) {           
            prevIndices[i] = tailIndices[len - 1];
            tailIndices[len++] = i;
        }
          
        // ararrayr[i] wants to be a potential candidate of
        // future subsequence
        // It will replace ceil value in tailIndices
        else {
            int pos = ceilBinarySearch(array, tailIndices, -1,
                                        len - 1, array[i]);
            prevIndices[i] = tailIndices[pos - 1];
            tailIndices[pos] = i;
        }
    }
 
    // put LIS into vector
    for (int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i])
        exposed.push_back(array[i]);
}

/* Função de busca binária para o valor de teto dentro do subvetor a fim de acrescentar esse valor como sendo um valor potencial
futuro para uma subsequência */
int Store::ceilBinarySearch(vector<int> array, vector<int>& T, int left, int right, int key) {
    while (right - left > 1) {
        int middle = left + (right - left) / 2;
        if (array[T[middle]] >= key)
            right = middle;
        else
            left = middle;
    }
    return right;
}