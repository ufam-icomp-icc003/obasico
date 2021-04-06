# Estrutura de dados II - ICC003
projeto contendo implementações de estruturas de dados neutralizadas.

## TADs implementados
+ Fila
+ Pilha
+ Fila de Prioridade
+ Heap

## ED neutralizadas
+ Vetor Dinâmico
+ Vetor Circular
+ Lista Encadeada

## Instalação da _libtad_
+ Linux e Mac
  + Baixe o tarball no obasico/Releases
  + Abra o tar e entre na pasta criada
  ```
  tar -xzvf tad[version].tar.gz
  cd tar[version]
  ```
  + Execute os scripts para validação de dependências e o construção da _libtad_
  ```
  ./configure
  make install
  ```

+ Windows
  + TO BE DONE
  
## Caso de uso
Se você chegou até aqui é porque a instalação foi bem sucedida. O diretório _exemplos_ tem código que faz uso da biblioteca.

+ Como compilar e executar código que usa o TAD fila
```
gcc -o usafila usafila.c inteiro.c -ltad
./usafila
```
o arquivo _inteiro.c_ contém a definição de operações de comparação e criação de tipo básico (nativo) quando esse é armazenado em estrutura neutralizada.

+ Como compilar e executar código que usa o TAD fila de prioridade
```
gcc -o usafilaprioridade usafilaprioridade.c aviao.c -ltad
./usafilaprioridade
```
o arquivo _aviao.c_ contém a definição de operações de comparação, impressão e criação de tipo definido.
