1-Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, 
porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
2-Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário.
3-Cada pessoa tem nome[10], idade e telefone. 
4-Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
5-Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro).
6-Não pode usar struct em todo o programa.
7-Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
8-Implementar a base de dados da agenda usando lista duplamente ligada
9-Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.

Link: https://drive.google.com/drive/folders/1wOqWNeBQwGfHBgDG3ocCx0zzq7-YcyAN?usp=sharing
