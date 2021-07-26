.SUFFIXES:
.SUFFIXES: .o .ec .cpp

#pathprj=$(shell dirname $(shell dirname `pwd`))
pathprj=${PWD}
dirAplicacao=$(pathprj)
dirBiblioteca=$(pathprj)/lib

nomeAplicacao=$(dirAplicacao)/guessingGame



## More Informations : https://gcc.gnu.org/projects/cxx-status.html

GCC_VERSION := $(shell echo `g++ -dumpversion | cut -f1-2  -d.` )
GCC_VERSION_C11 := $(shell echo $(GCC_VERSION) | awk '{if ($$1 >= 4.8 ) print 1;}' )
GCC_VERSION_C14 := $(shell echo $(GCC_VERSION) | awk '{if ($$1 >= 4.9 ) print 1;}' )
GCC_VERSION_C17 := $(shell echo $(GCC_VERSION) | awk '{if ($$1 >= 8 ) print 1;}' )
GCC_VERSION_C20 := $(shell echo $(GCC_VERSION) | awk '{if ($$1 >= 11 ) print 1;}' )

ifeq ($(GCC_VERSION_C20),1)
   CC = g++ -std=c++20  $(CCFLAGS)
else ifeq ($(GCC_VERSION_C17),1)
   CC = g++ -std=c++17  $(CCFLAGS)
else ifeq ($(GCC_VERSION_C14),1)
   CC = g++ -std=c++14  $(CCFLAGS)
else ifeq ($(GCC_VERSION_C11),1)
   CC = g++ -std=c++11 $(CCFLAGS)
else
	CC = g++ -std=c++98  $(CCFLAGS)
endif


SO_KERNEL_NAME	= $(shell uname)
SO_PLATAFORM	= $(shell uname -i)

AR = ar

DIR_SRC= ./src/

#-----------------------------------------------------
#Diretorios dos arquivos header (.h) do ESPECIFICO
#-----------------------------------------------------
INCLUDE_DIR	  =  -I$(DIR_SRC)


#-----------------------------------------------------
#Especifico
#-----------------------------------------------------
SRCS_CPP    = $(shell ls $(DIR_SRC)/*.cpp 2> /dev/null)
OBJS 		= $(SRCS_CPP:.cpp=.o)

ifeq ($(SO_KERNEL_NAME),Linux)
	LIB_SYS 		= -lpthread -ldl -lcrypt -lc
else
	LIB_SYS			= <<especificar para o SO>>
endif

#Link das Bibliotecas
LINK		= $(LIB_SYS)

.cpp.o:
	@echo "Compilando >>> $<"
	$(CC) -Wno-deprecated  $(INCLUDE_DIR) -c $< -o $@

all: $(OBJS)
	@echo "------------------------------------------------------------------------------"
	@[ -d $(dirAplicacao) ] || mkdir $(dirAplicacao)

	@echo "Criando autorizador <$(nomeAplicacao)>"
	@rm -f $(nomeAplicacao)
	$(CC)  $(LINK) -o $(nomeAplicacao) $?

	@chmod 770 $(nomeAplicacao)
	@echo "<<<<<< Feito >>>>>>"
	@echo "------------------------------------------------------------------------------"

local: $(OBJS)
	@echo "----------------------------------------"
	@echo "Criando autorizador <$(nomeAplicacao)>"
	@rm -f $(nomeAplicacao)
	@$(CC) $?  $(LINK) -o $(nomeAplicacao)
	@chmod 770 $(nomeAplicacao)
	@echo "<<<<<< Feito >>>>>>"
	@echo "----------------------------------------"

clean:
	@echo "-------------------------------------------------"
	@echo "Apagando Objs/dependencias de <$(nomeAplicacao)>"
	rm -f $(OBJS:.o=.d) $(OBJS) core* $(nomeAplicacao)
	@echo "<<<<<< Feito >>>>>>"
	@echo "-------------------------------------------------"

-include $(OBJS:.o=.d)
