#include <iostream>
#include <vector>

using namespace std;

class Store {
    private:
        /* Criação de valores referentes aos tamanhos dos subvetores utilizados */
        int size, sizeMore, sizeLess;

    public:
        /* Criação dos vetores com a totalidade de rolos, e subvetores com valores maiores e menores que o
        valor atual do início do vetor */
        vector<int>rollArray, moreThan, lessThan;

        /* Criação do vetor de rolos que serão expostos na vitrine */
        vector<int>exposed;

        /* Função de inicialização da classe com valores predefinidos*/
        Store();

        /* Função que seta o valor passado como argumento como sendo o valor de tamanho do vetor com todos os rolos*/
        void setSize(int size);

        /* Função que seta o valor passado como argumento como sendo o valor de tamanho do subvetor com os rolos de preço maior que o inicial */
        void setSizeMore(int size);

        /* Função que seta o valor passado como argumento como sendo o valor de tamanho do subvetor com os rolos de preço menor que o inicial */
        void setSizeLess(int size);

        /* Função que retorna o tamanho do vetor com todos os rolos */
        int getSize();

        /* Função que retorna o tamanho do subvetor de rolos com preços maiores que o rolo inicial */
        int getSizeMore();

        /* Função que retorna o tamanho do subvetor de rolos com preços menores que o rolo inicial */
        int getSizeLess();

        /* Função que reseta os vetores intermediários e de resposta para uma nova execução do programa */
        void resetVectors();

        /* Função que retorna um inteiro que corresponde à maior sequência de rolos para exibição */
        int maxVectorSequence();

        /* Função que retorn o maior subVetor crescente dentro do vetor de rolos. É utilizada para achar também o maior vetor decrescente por meio da
        inversão do vetor e execução do mesmo algoritmo */
        void longestIncreaseSubArray(vector<int>array, int n);

        /* Função de busca binária para o valor de teto dentro do subvetor a fim de acrescentar esse valor como sendo um valor potencial
        futuro para uma subsequência */
        int ceilBinarySearch(vector<int> array, vector<int>& T, int left, int right, int key);
};