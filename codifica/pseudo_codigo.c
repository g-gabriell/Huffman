


    while(fread(&c, 1, 1, input))
    {

        for(j=0; c != tabela[j]->simbolo; j++);
        tam_code = strlen(tabela[j]->codigo);

        for(m = 0; m < tam_code; m++)
        {
            if(tabela[j]->codigo[m] == '1')
                bitset(buffer_escrita, index++);
            if(tabela[j]->codigo[m] == '0')
                bitclr(buffer_escrita, index++);
            if(index == 8)
            {
                fwrite(&buffer_escrita, 1, 1,output);
                index = 0;
            }
        }
    }

    index = 0   // indice da mascara de bits

    para cada caractere c no arquivo

        caractere = busca_endereco(c, lista) // Ponteiro da struct caractere correspondente

        para m de 0 até tamanho_string(caractere->código)

            se caractere->código[m] == 1
                set_bit(buffer, index++)
            fim se

            se caractere->código[m] == 0
                clr_bit(buffer, index++)
            fim se

            se index == 8
                fwrite(buffer, output_file)
                index = 0
            fim se
        fim para
    fim enquanto



