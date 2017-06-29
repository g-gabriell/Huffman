# •Sobre Compactador Huffman:


O algoritmo de Huffman é um método de compressão de arquivos de texto, este programa utiliza as frequências de ocorrência de cada símbolo do conjunto de dados para criar uma árvore onde as folhas representam os caracteres dos conjuntos de dados, sendo que os caracteres mais frequentes ficam próximos de sua raiz.


## •Instruções de uso:

	compactador
	
	Digite o caminho absoluto do arquivo a ser compactado

	descompactador
	
	Digite o caminho absoluto do arquivo ".hff" a ser descompactado

## •Testes de desempenho:

	• Memória alocada
	
	Para teste de memoria alocada o programa foi executado utilizando o valgrind.
	A alocação de memória do programa tem proporcionalidade com a quantidade de caracteres diferentes no arquivo.

	• Compactação 
	
	Os testes de compactação foram feitos comparando o tamanho em bytes do arquivo de saída da codificação com o mesmo arquivo compactado por um programa comercial, neste caso o Winrar.
	
	O resultado da compactação pode variar comforme a recorrência de caracteres do arquivo compactado, na média os arquivos de texto compactados tiveram uma redução de 45% de seu tamanho original.
	
	• Tempo de execução
	
	O tempo de execução não depende apenas do programa, mas também do sistema operacional.
	
	Teste arquivo exemplo:
	
		tamanho do arquivo: 196.195 caracteres
		
		•arquivo original: 191,7 KB
		•arquivo compactado(Compactador Huffman): 106,1 KB
		•arquivo compactado(Winrar): 93,4 KB
		

		•tempo compactação(média de vinte execuções): 0,032 s
		•tempo descompactação(média de vinte execuções): 0,072 s
