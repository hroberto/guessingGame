FROM centos:8

MAINTAINER Henrique Martins Roberto <henrique.roberto@gmail.com>
LABEL authors="Henrique Martins Roberto <henrique.roberto@gmail.com>"


#Proxy Config (optional)
ARG http_proxy=""
ARG https_proxy=$http_proxy
RUN if [[ -n $http_proxy  || $http_proxy != "" ]]; \
	then \
	 echo "proxy=$http_proxy" >> /etc/yum.conf; \
	fi


#Configurao de plataforma
ENV SO_PLATAFORM x86_64
ENV SO_DIST el8

#instalação de utilitários e libs para compilação

RUN yum update -y && \
	yum install \
	vim iputils cifs-utils file \
	git \
	gcc gcc-c++ \
	make  automake  autoconf  libtool \
	unzip-6.0 gzip 
	openssl  openssl-devel \
	apr  apr-devel libtool-ltdl libtool-ltdl-devel  gnutls \
	-y

#cria diretorios de trabalho
RUN mkdir -p /opt/workspace

#adiciona atalho para execução de scripts no .bashrc

ENV LANG en_US.UTF-8

#BASE DIR LIBS

ENV BASE_BOOST /opt/src-c-dep/boost_1_63_0
ENV POCO_BASE /opt/src-c-dep/poco-1.4.6p2-all
ENV ZLIB_BASE /opt/src-c-dep/zlib-1.2.3


#LIBS

ENV BASE_BOOST_LIBS ${BASE_BOOST}/stage/lib
ENV POCO_BASE_LIBS ${POCO_BASE}/lib/Linux/${SO_PLATAFORM}

#diversos

ENV THREADLIB POSIX


ENV LD_LIBRARY_PATH ${BASE_BOOST_LIBS}:${POCO_BASE_LIBS}

#definindo workdir em /opt/workspace

WORKDIR /opt/workspace

VOLUME /opt/workspace

CMD ["/bin/bash"]
