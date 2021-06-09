//
//  main.cpp
//  BMOAulasCpp20ArraysInCpp
//
//  Created by Breno Medeiros on 08/06/21.
//

#include <iostream>
#include <array>

class Entidade {
public:
    
    static const int exemploTamanho = 5;
    //Se voce olhar a memoria de uma instancia dessa class, sera que para cada um desses:
    int exemploComum[exemploTamanho];            //As 5 primeiras posicoessao justamete de exemploComum
    int* exemploComNew =new int[exemploTamanho]; //Somente contem o endereco para onde o Array esta na memoria
    
    Entidade() {
        for (int i=0; i < exemploTamanho; i++) {
            exemploComum[i]=2;
            exemploComNew[i]=2;
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int exemplo[5];
    exemplo[0] = 2;
    exemplo[4] = 4;
    
    int a = exemplo[0];
    
    std::cout << exemplo[0] << std::endl;
    std::cout << a << std::endl;
    std::cout << "Endereco do array/ponteiro 'exemplo': " << exemplo << std::endl;
    
    //CUIDADO PARA NAO ACESSAR POSICOES DE MEMORIA DESCONHECIDOS, COMO NAS 2 LINHAS ABAIXO.
    //ISSO PODE DAR ERROS NA EXECUCAO IMPREVISIVEIS E DIFICEIS DE CORRIGIR!
    //int foraDoIntervaloA = exemplo[-1];
    //int foraDoIntervaloB = exemplo[5];
    
    //Iterando sobre o Array manualmente: (Isso nao é bom)
    exemplo[0]=2;
    exemplo[1]=2;
    exemplo[2]=2;
    exemplo[3]=2;
    exemplo[4]=2;
    //Iterando sobre o Array com um Loop 'For': (Isso é bom)
    int tamanho = (sizeof(exemplo)/sizeof(int));
    for (int i=0; i < tamanho; i++) {
        exemplo[i]=2;
    }
    
    //Se você ver na memoria Ram o penteiro 'exemplo', vera dividoes entre cada posicao
    // desse mesmo array. Inclusive, como setamos todas as 5 posicoes para o inteiro 2,
    // voce devera ver algo semehante a isso:
    // 02 00 00 00 | 02 00 00 00 | 02 00 00 00 | 02 00 00 00 | 02 00 00 00
    // O que quer dizer que, como um inteiro é composto por 4 Bytes, entao exemplo usa 5Bytes.
    // E agora vamos ver como avancar manualmente duas posicoes e alterar um valor do array:
    int* ptr = exemplo;
    *(ptr + 2) = 6; //Isso equivale a: exemplo[2]=6;
    //Dessa forma, agora ao vermos na memoria ram o conteudo de 'exemplo', temos:
    // 02 00 00 00 | 02 00 00 00 | 06 00 00 00 | 02 00 00 00 | 02 00 00 00
    // E agora vamos mostrar que o compilador sabe que quando somamos '2' ao ponteiro, ele
    // deveria na verdade somar '8'(Pois se 'exemplo' é um ponteiro de 'int's, e cada int
    // tem '4 Bytes', e nos queremos somar/deslocar '2 endereos': "2*4 = 8").
    // E para explicitar isso converteremos o tipo do ponteiro para 'char', e depois desconverter:
    *(int*)((char*)ptr + 8) = 7; //Isso equivale a: exemplo[2]=6;
    //Dessa forma, agora ao vermos na memoria ram o conteudo de 'exemplo', temos:
    // 02 00 00 00 | 02 00 00 00 | 07 00 00 00 | 02 00 00 00 | 02 00 00 00
    
    
    //Fazendo array com a PalavraChave/KeyWord 'new':
    int* outro =new int[5]; //Isso equivale a: "int exemplo[5];", mas o LifeTime desse n acabe em '5'
    
    for (int i=0; i < 5; i++) {
        outro[i]=2;
    }
    
    delete[] outro; // Porem tem a desvantagem de voce ter que encerrar seu LifeTime manualmente assim
    
    Entidade e;
    
    
    
    //Outra forma mais simples de usar Arrays sabendo exatamente qual o seu tamanho(pra poder usar um 'for'):
    std::array<int, 5> outroArray; //Isso aqui so é possivel a partir do C++ 11 em diante, usando "#include <array>"
    for (int i=0; i < outroArray.size(); i++) {
        outroArray[i]=2;
    }
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
