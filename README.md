
# AVALIA��O PARA ENTREVISTA NA PSAFE

Este documento visa descrever os passos para a montagem de ambiente, da aplica��o para teste de conhecimento t�cnico, sugerido pela [PSAFE](https://www.psafe.com/pt-br/).


#INFORMA��ES DO CANDIDATO

> **Data Criacao:** 27/06/2021
> **Autor:** HENRIQUE MARTINS ROBERTO
> **E-mail:** henrique.roberto@gmail.com


#SOBRE O AMBIENTE DE DESENVOLVIMENTO

O desenvolvimento foi realizado na plataforma LINUX, com o compilador GNU. Portanto, para possibilitar a utilizacao e teste pelo avaliador, o ambiente a seguir foi documentado utilizando o DOCKER.


#CRIACAO DO AMBIENTE DOCKER PARA DESENVOLVIMENTO

> PS: Antes de iniciar os passos abaixo, verifique as configuracoes de DNS em /etc/docker/daemon.json, e caso necess�rio, inclua o IP "8.8.8.8" no mesmo.


```sh
    ## Construindo a nova imagem
    docker build -t  el8-hmartins:1.00 .

    ## Executando a imagem montada
    docker run --rm -it --name el8-hmartins  --cpus 1 -v ${PWD}:/opt/workspace  el8-hmartins:1.00  /bin/bash

    ## compilando a aplicacao
    make -s

    ## executando o programa
    ./guessingGame

 ```
