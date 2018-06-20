#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

typedef struct{
    char rua[30], bairro[20];
    int numero;
}ENDERECO;

typedef struct{
    int codigo;
    char nome[50], cpf[15];
    int dia, mes, ano;
    ENDERECO e;
}PACIENTE;

typedef struct{
    int matricula;
    char nome[30], curso[30], cpf[15];
}ALUNO;

typedef struct{
    char nome[30], curso[20];
    int codigo;
}SUPERVISOR;

typedef struct{
    char nome[50], area[20];
    int codAgen, codPac;
    int dia, mes, ano;
}AGENDAMENTO;

typedef struct{
    char nomeAlu[50], nomePac[50], nomeSup[50], area[20];
    int codAlu, codPac, codSup, codAten, codAgen;
    int dia, mes, ano;
}ATENDIMENTO;

void menuprincipal(){
    int opc;
    do{
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t\tMENU\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t 1- Paciente\t\t บ");
        printf("\n\t\t\t\t\tบ\t 2- Aluno\t\t บ");
        printf("\n\t\t\t\t\tบ\t 3- Supervisor\t\t บ");
        printf("\n\t\t\t\t\tบ\t 4- Agendamento\t\t บ");
        printf("\n\t\t\t\t\tบ\t 5- Atendimento\t\t บ");
        printf("\n\t\t\t\t\tบ\t 6- Sair\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        scanf("%d", &opc);
        system("cls");
        switch (opc){
            case 1: menuPaciente(); break;
            case 2: menuAluno(); break;
            case 3: menuSupervisor(); break;
            case 4: menuAgendamento(); break;
            case 5: menuAtendimento(); break;
            system("cls");
        }
    }
    while(opc!=6);
}

void menuPaciente(){
    int opc;
    do{
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t PACIENTE\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t 1- Cadastra Paciente\t บ");
        printf("\n\t\t\t\t\tบ\t 2- Editar paciente\t บ");
        printf("\n\t\t\t\t\tบ\t 3- Remover paciente\t บ");
        printf("\n\t\t\t\t\tบ\t 4- Listar pacientes\t บ");
        printf("\n\t\t\t\t\tบ\t 5- Voltar\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        scanf("%d", &opc);
        system("cls");
        switch (opc){
            case 1: cadastroPaciente(); break;
            case 2: editarPaciente(); break;
            case 3: removerPaciente(); break;
            case 4: listarPacientes(); break;
            system("cls");
        }
    }
    while(opc!=5);
}

void cadastroPaciente(){

    FILE *arq;
    arq = fopen("paciente.txt","rb");

    int cod, ativo=1;
    PACIENTE p;

    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Codigo: ");
    scanf("%d", &p.codigo);
    cod=p.codigo;
    rewind(arq);
    while(fread(&p,sizeof(PACIENTE),1,arq)==1){
        if(cod==p.codigo){
            system("cls");
            printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
            printf("\n\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ Paciente ja cadastrado");
            printf("\n\t\t\t\t\tบ 1-Voltar");
            getch();
            ativo=0;
            system("cls");
            break;
        }
    }
    fclose(arq);

    if(ativo==1){
        FILE *arq;
        arq = fopen("paciente.txt","ab");
        p.codigo=cod;
        fflush (stdin);
        printf("\t\t\t\t\tบ Nome: ");
        gets(p.nome);
        fflush (stdin);
        printf("\t\t\t\t\tบ CPF: ");
        gets(p.cpf);
        printf("\t\t\t\t\tบ Data de nascimento: ");
        scanf("%d%d%d", &p.dia, &p.mes, &p.ano);
        printf("\t\t\t\t\tบ Rua: ");
        fflush (stdin);
        gets(p.e.rua);
        printf("\t\t\t\t\tบ Bairro: ");
        gets(p.e.bairro);
        printf("\t\t\t\t\tบ Numero da casa: ");
        scanf("%d", &p.e.numero);
        system("cls");
        fwrite(&p,sizeof(PACIENTE),1,arq);
        fclose(arq);
    }
}

void editarPaciente(){
    FILE *arq;
    arq = fopen("paciente.txt", "rb");

    PACIENTE p;

    int cod,opc,ativo=0;
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Digite codigo do paciente: ");
    scanf("%d", &cod);

    while(fread(&p,sizeof(PACIENTE),1,arq)==1){
        if(cod==p.codigo){
            printf("\t\t\t\t\tบ Nome: %s", p.nome);
            printf("\n\t\t\t\t\tบ CPF: %s", p.cpf);
            ativo=1;
            break;
        }

    }
    fclose(arq);
    if(ativo==1){
        printf("\n\t\t\t\t\tบ");
        printf("\n\t\t\t\t\tบ Deseja editar? ");
        printf("\n\t\t\t\t\tบ 1-SIM/2-NAO");
        scanf("%d", &opc);
        if(opc==1){
             system("cls");
             FILE *arq;
             arq = fopen("paciente.txt","rb");

             FILE *arq2;
             arq2 = fopen("paciente2.txt","wb");
             while(fread(&p,sizeof(PACIENTE),1,arq)==1){
                    if(cod==p.codigo){
                        p.codigo=cod;
                        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                        printf("\n\t\t\t\t\tบ Nome: ");
                        fflush (stdin);
                        gets(p.nome);
                        fflush (stdin);
                        printf("\t\t\t\t\tบ CPF: ");
                        gets(p.cpf);
                        printf("\t\t\t\t\tบ Data de nascimento: ");
                        scanf("%d%d%d", &p.dia, &p.mes, &p.ano);
                        printf("\t\t\t\t\tบ Rua: ");
                        fflush (stdin);
                        gets(p.e.rua);
                        printf("\t\t\t\t\tบ Bairro: ");
                        gets(p.e.bairro);
                        printf("\t\t\t\t\tบ Numero da casa: ");
                        scanf("%d", &p.e.numero);
                        system("cls");
                        fwrite(&p,sizeof(PACIENTE),1,arq2);
                    }
                    else{
                        fwrite(&p,sizeof(PACIENTE),1,arq2);
                    }
             }
             fclose(arq);
             fclose(arq2);
             remove("paciente.txt");
             system("ren paciente2.txt paciente.txt");

             system("cls");
             printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
             printf("\n\t\t\t\t\tบ");
             printf("\n\t\t\t\t\tบ Paciente Editado");
             printf("\n\t\t\t\t\tบ 1-Voltar");
             getch();
        }
    }
    else{

        printf("\t\t\t\t\tบ");
        printf("\n\t\t\t\t\tบ Paciente nao encontrado");
        printf("\n\t\t\t\t\tบ 1-Voltar");
        getch();
    }
    system("cls");
}

void removerPaciente(){
    FILE *arq;
    arq = fopen("paciente.txt","rb");
    PACIENTE p;

    int cod,opc,ativo=0;
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Digite o codigo do paciente: ");
    scanf("%d", &cod);

    while(fread(&p,sizeof(PACIENTE),1,arq)==1){
        if(cod==p.codigo){
            printf("\t\t\t\t\tบ Nome: %s", p.nome);
            printf("\n\t\t\t\t\tบ CPF: %s", p.cpf);
            ativo=1;
            break;
        }
    }
    fclose(arq);
    if(ativo==1){
            printf("\n\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ Deseja remover? ");
            printf("\n\t\t\t\t\tบ 1-SIM/2-NAO");
            scanf("%d", &opc);

            if(opc==1){

                system("cls");
                FILE *arq;
                arq = fopen("paciente.txt","rb");

                 FILE *arq2;
                 arq2 = fopen("paciente2.txt","wb");
                 while(fread(&p,sizeof(PACIENTE),1,arq)==1){
                        if(cod!=p.codigo){
                            fwrite(&p,sizeof(PACIENTE),1,arq2);
                        }
                 }
                 fclose(arq);
                 fclose(arq2);
                 remove("paciente.txt");
                 system("ren paciente2.txt paciente.txt");

                 printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                 printf("\n\t\t\t\t\tบ Removido");
                 printf("\n\t\t\t\t\tบ 1-voltar");
                 getch();
            }
    }
    else{
        system("cls");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Paciente nao encontrado");
        printf("\n\t\t\t\t\tบ 1-voltar");
        getch();
    }
    system("cls");
}

void listarPacientes(){
    FILE *arq;
    arq = fopen("paciente.txt","rb");
    PACIENTE p;

    while(fread(&p,sizeof(PACIENTE),1,arq)==1){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Codigo: %d", p.codigo);
        printf("\n\t\t\t\t\tบ Nome: %s", p.nome);
        printf("\n\t\t\t\t\tบ CPF: %s", p.cpf);
        printf("\n\t\t\t\t\tบ Nascimento: %d/%d/%d", p.dia,p.mes,p.ano);
        printf("\n\t\t\t\t\tบ Bairro: %s", p.e.bairro);
        printf("\n\t\t\t\t\tบ Rua: %s", p.e.rua);
        printf("\n\t\t\t\t\tบ Numero: %d ", p.e.numero);
        printf("\n\t\t\t\t\tบ");
    }
    rewind(arq);
    if(fread(&p,sizeof(PACIENTE),1,arq)==NULL){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Sem Paciente");
    }
    fclose(arq);
    printf("\n\t\t\t\t\tบ ");
    printf("\n\t\t\t\t\tบ 1-Voltar");
    getch();
    system("cls");
}

void menuAluno(){
    int opc;
    do{
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t ALUNO\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t 1- Cadastrar aluno\t บ");
        printf("\n\t\t\t\t\tบ\t 2- Editar aluno\t บ");
        printf("\n\t\t\t\t\tบ\t 3- Remover aluno\t บ");
        printf("\n\t\t\t\t\tบ\t 4- Listar alunos\t บ");
        printf("\n\t\t\t\t\tบ\t 5- Voltar\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        scanf("%d", &opc);
        system("cls");
        switch (opc){
            case 1: cadastraAluno(); break;
            case 2: editarAluno(); break;
            case 3: removerAluno(); break;
            case 4: listarAluno(); break;
            system("cls");
        }
    }
    while(opc!=5);
}

void cadastraAluno(){
    FILE *arq;
    arq = fopen("aluno.txt","rb");

    int cod, ativo=1;
    ALUNO a;
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Matricula: ");
    scanf("%d", &cod);
    rewind(arq);
    while(fread(&a,sizeof(ALUNO),1,arq)==1){
        if(cod==a.matricula){
            system("cls");
            printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
            printf("\n\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ Aluno ja cadastrado");
            printf("\n\t\t\t\t\tบ 1-Voltar");
            getch();
            ativo=0;
            system("cls");
            break;
        }
    }
    fclose(arq);

    if(ativo==1){
        FILE *arq;
        arq = fopen("aluno.txt","ab");
        ALUNO a;

        a.matricula=cod;
        fflush (stdin);
        printf("\t\t\t\t\tบ Nome: ");
        gets(a.nome);
        fflush (stdin);
        printf("\t\t\t\t\tบ CPF: ");
        gets(a.cpf);
        printf("\t\t\t\t\tบ Curso: ");
        printf("\n\t\t\t\t\tบ -Fisioterapia ");
        printf("\n\t\t\t\t\tบ -Odontologia ");
        printf("\n\t\t\t\t\tบ -Psicologia ");
        printf("\n\t\t\t\t\tบ ");
        gets(a.curso);
        strupr(a.curso);
        system("cls");
        fwrite(&a,sizeof(ALUNO),1,arq);
        fclose(arq);
    }
}

void editarAluno(){
    FILE *arq;
    arq = fopen("aluno.txt", "rb");
    ALUNO a;

    int cod,opc,ativo=0;
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Digite codigo do aluno: ");
    scanf("%d", &cod);

    while(fread(&a,sizeof(ALUNO),1,arq)==1){
        if(cod==a.matricula){
            printf("\t\t\t\t\tบ Nome: %s", a.nome);
            printf("\n\t\t\t\t\tบ CPF: %s", a.cpf);
            ativo=1;
            break;
        }

    }
    fclose(arq);
    if(ativo==1){
        printf("\n\t\t\t\t\tบ");
        printf("\n\t\t\t\t\tบ Deseja editar? ");
        printf("\n\t\t\t\t\tบ 1-SIM/2-NAO");
        scanf("%d", &opc);
        if(opc==1){
             system("cls");
             FILE *arq;
             arq = fopen("aluno.txt","rb");

             FILE *arq2;
             arq2 = fopen("aluno2.txt","wb");
             while(fread(&a,sizeof(ALUNO),1,arq)==1){
                    if(cod==a.matricula){
                        a.matricula=cod;
                        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                        printf("\n\t\t\t\t\tบ Nome: ");
                        fflush (stdin);
                        gets(a.nome);
                        fflush (stdin);
                        printf("\t\t\t\t\tบ CPF: ");
                        gets(a.cpf);
                        printf("\t\t\t\t\tบ Curso: ");
                        gets(a.curso);
                        strupr(a.curso);
                        system("cls");
                        fwrite(&a,sizeof(ALUNO),1,arq2);
                    }
                    else{
                        fwrite(&a,sizeof(ALUNO),1,arq2);
                    }
             }
             system("cls");
             fclose(arq);
             fclose(arq2);
             remove("aluno.txt");
             system("ren aluno2.txt aluno.txt");

             system("cls");
             printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
             printf("\n\t\t\t\t\tบ");
             printf("\n\t\t\t\t\tบ Aluno Editado");
             printf("\n\t\t\t\t\tบ 1-Voltar");
             getch();
        }
    }
    else{
        printf("\t\t\t\t\tบ");
        printf("\n\t\t\t\t\tบ Aluno nao encontrado");
        printf("\n\t\t\t\t\tบ 1-Voltar");
        getch();
    }
    system("cls");
}

void removerAluno(){
    FILE *arq;
    arq = fopen("aluno.txt","rb");
    ALUNO a;

    int cod,opc,ativo=0;
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Digite o codigo do aluno: ");
    scanf("%d", &cod);

    while(fread(&a,sizeof(ALUNO),1,arq)==1){
        if(cod==a.matricula){
            printf("\t\t\t\t\tบ Nome: %s", a.nome);
            printf("\n\t\t\t\t\tบ Curso %s", a.curso);
            ativo=1;
            break;
        }
    }
    fclose(arq);

    if(ativo==1){
            printf("\n\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ Deseja remover? ");
            printf("\n\t\t\t\t\tบ 1-SIM/2-NAO");
            scanf("%d", &opc);

            if(opc==1){

                system("cls");
                FILE *arq;
                arq = fopen("aluno.txt","rb");

                 FILE *arq2;
                 arq2 = fopen("aluno2.txt","wb");
                 while(fread(&a,sizeof(ALUNO),1,arq)==1){
                        if(cod!=a.matricula){
                            fwrite(&a,sizeof(ALUNO),1,arq2);
                        }
                 }
                 fclose(arq);
                 fclose(arq2);
                 remove("aluno.txt");
                 system("ren aluno2.txt aluno.txt");

                 printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                 printf("\n\t\t\t\t\tบ Removido");
                 printf("\n\t\t\t\t\tบ 1-voltar");
                 getch();
            }
    }
    else{
        system("cls");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Aluno nao encontrado");
        printf("\n\t\t\t\t\tบ 1-voltar");
        getch();
    }
    system("cls");
}

void listarAluno(){
    FILE *arq;
    arq = fopen("aluno.txt","rb");
    ALUNO a;

    while(fread(&a,sizeof(ALUNO),1,arq)==1){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Matricula: %d", a.matricula);
        printf("\n\t\t\t\t\tบ Nome: %s", a.nome);
        printf("\n\t\t\t\t\tบ CPF: %s", a.cpf);
        printf("\n\t\t\t\t\tบ Curso: %s", a.curso);
        printf("\n\t\t\t\t\tบ");
    }
    rewind(arq);
    if(fread(&a,sizeof(ALUNO),1,arq)==NULL){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Sem Aluno");
    }
    fclose(arq);
    printf("\n\t\t\t\t\tบ ");
    printf("\n\t\t\t\t\tบ 1-Voltar");
    getch();
    system("cls");
}

void menuSupervisor(){
    int opc;
    do{
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t SUPERVISOR\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ 1- Cadastrar supervisor\t บ");
        printf("\n\t\t\t\t\tบ 2- Editar supervisor\t\t บ");
        printf("\n\t\t\t\t\tบ 3- Remover supervisor\t\t บ");
        printf("\n\t\t\t\t\tบ 4- Listar supervisores\t บ");
        printf("\n\t\t\t\t\tบ 5- Voltar\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        scanf("%d", &opc);
        system("cls");
        switch (opc){
            case 1: cadastroSupervisor(); break;
            case 2: editarSupervisor(); break;
            case 3: removerSupervisor(); break;
            case 4: listarSupervisor(); break;
            system("cls");
        }
    }
    while(opc!=5);
}

void cadastroSupervisor(){
    FILE *arq;
    arq = fopen("supervisor.txt","rb");

    int cod, ativo=1;
    SUPERVISOR s;

    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Codigo: ");
    scanf("%d", &cod);
    rewind(arq);
    while(fread(&s,sizeof(SUPERVISOR),1,arq)==1){
        if(cod==s.codigo){
            system("cls");
            printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
            printf("\n\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ Supervisor ja cadastrado");
            printf("\n\t\t\t\t\tบ 1-Voltar");
            getch();
            ativo=0;
            system("cls");
            break;
        }
    }
    fclose(arq);

    if(ativo==1){
        FILE *arq;
        arq = fopen("supervisor.txt","ab");

        SUPERVISOR s;

        s.codigo=cod;
        printf("\t\t\t\t\tบ Nome: ");
        fflush (stdin);
        gets(s.nome);
        fflush (stdin);
        printf("\t\t\t\t\tบ Curso: ");
        gets(s.curso);
        strupr(s.curso);
        system("cls");
        fwrite(&s,sizeof(SUPERVISOR),1,arq);
        fclose(arq);
    }
}

void editarSupervisor(){
    FILE *arq;
    arq = fopen("supervisor.txt", "rb");

    SUPERVISOR s;

    int cod,opc,ativo=0;
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Digite codigo do supervisor: ");
    scanf("%d", &cod);

    while(fread(&s,sizeof(SUPERVISOR),1,arq)==1){
        if(cod==s.codigo){
            printf("\t\t\t\t\tบ Nome: %s", s.nome);
            printf("\n\t\t\t\t\tบ Curso: %s", s.curso);
            ativo=1;
            break;
        }

    }
    fclose(arq);
    if(ativo==1){

        printf("\n\t\t\t\t\tบ");
        printf("\n\t\t\t\t\tบ Deseja editar? ");
        printf("\n\t\t\t\t\tบ 1-SIM/2-NAO");
        scanf("%d", &opc);
        if(opc==1){
             system("cls");
             FILE *arq;
             arq = fopen("supervisor.txt","rb");

             FILE *arq2;
             arq2 = fopen("supervisor2.txt","wb");
             while(fread(&s,sizeof(SUPERVISOR),1,arq)==1){
                    if(cod==s.codigo){
                        s.codigo=cod;
                        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                        printf("\n\t\t\t\t\tบ Nome: ");
                        fflush (stdin);
                        gets(s.nome);
                        fflush (stdin);
                        printf("\t\t\t\t\tบ Curso: ");
                        gets(s.curso);
                        strupr(s.curso);
                        system("cls");
                        fwrite(&s,sizeof(SUPERVISOR),1,arq2);
                    }
                    else{
                        fwrite(&s,sizeof(SUPERVISOR),1,arq2);
                    }
             }
             fclose(arq);
             fclose(arq2);
             remove("supervisor.txt");
             system("ren supervisor2.txt supervisor.txt");

             system("cls");
             printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
             printf("\n\t\t\t\t\tบ");
             printf("\n\t\t\t\t\tบ Supervisor Editado");
             printf("\n\t\t\t\t\tบ 1-Voltar");
             getch();
        }
    }
    else{
        printf("\t\t\t\t\tบ");
        printf("\n\t\t\t\t\tบ Supervisor nao encontrado");
        printf("\n\t\t\t\t\tบ 1-Voltar");
        getch();
    }
    system("cls");
}

void removerSupervisor(){
    FILE *arq;
    arq = fopen("supervisor.txt","rb");
    SUPERVISOR s;

    int cod,opc,ativo=0;
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Digite o codigo do supervisor: ");
    scanf("%d", &cod);

    while(fread(&s,sizeof(SUPERVISOR),1,arq)==1){
        if(cod==s.codigo){
            printf("\t\t\t\t\tบ Nome: %s", s.nome);
            printf("\n\t\t\t\t\tบ Curso: %s", s.curso);
            ativo=1;
            break;
        }
    }
    fclose(arq);
    if(ativo==1){
            printf("\n\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ Deseja remover? ");
            printf("\n\t\t\t\t\tบ 1-SIM/2-NAO");
            scanf("%d", &opc);

            if(opc==1){
                system("cls");
                FILE *arq;
                arq = fopen("supervisor.txt","rb");

                 FILE *arq2;
                 arq2 = fopen("supervisor2.txt","wb");
                 while(fread(&s,sizeof(SUPERVISOR),1,arq)==1){
                        if(cod!=s.codigo){
                            fwrite(&s,sizeof(SUPERVISOR),1,arq2);
                        }
                 }
                 fclose(arq);
                 fclose(arq2);
                 remove("supervisor.txt");
                 system("ren supervisor2.txt supervisor.txt");

                 printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                 printf("\n\t\t\t\t\tบ Removido");
                 printf("\n\t\t\t\t\tบ 1-voltar");
                 getch();
            }
    }
    else{
        system("cls");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Supervisor nao encontrado");
        printf("\n\t\t\t\t\tบ 1-voltar");
        getch();
    }
    system("cls");
}

void listarSupervisor(){
    FILE *arq;
    arq = fopen("supervisor.txt","rb");
    SUPERVISOR s;

    while(fread(&s,sizeof(SUPERVISOR),1,arq)==1){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Codigo: %d", s.codigo);
        printf("\n\t\t\t\t\tบ Nome: %s", s.nome);
        printf("\n\t\t\t\t\tบ Curso: %s", s.curso);
        printf("\n\t\t\t\t\tบ ");
    }
    rewind(arq);
    if(fread(&s,sizeof(SUPERVISOR),1,arq)==NULL){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Sem Supervivor");
    }
    fclose(arq);
    printf("\n\t\t\t\t\tบ ");
    printf("\n\t\t\t\t\tบ 1-Voltar");
    getch();
    system("cls");
}

void menuAgendamento(){
    int opc;
    do{
        system("cls");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t AGENDAMENTO\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ 1- criar novo agendamento\t บ");
        printf("\n\t\t\t\t\tบ 2- cancelar agendamento\t บ");
        printf("\n\t\t\t\t\tบ 3- listar agendamento\t\t บ");
        printf("\n\t\t\t\t\tบ 4- Voltar\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        scanf("%d", &opc);
        system("cls");
        switch (opc){
            case 1: novoAgendamento(); break;
            case 2: removerAgendamento(); break;
            case 3: listarAgendamento(); break;
            system("cls");
        }
    }
    while(opc!=4);
}

void novoAgendamento(){

    char nome[50], fisi[20]={"Fisioterapia"},odon[20]={"Odontologia"},psic[20]={"Psicologia"}, curso[20];
    int codA, codP, ativo=0;

    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Codigo do agendamento: ");
    scanf("%d", &codA);

    FILE *arq;
    arq = fopen("agendamento.txt","rb");
    AGENDAMENTO ag;

    while(fread(&ag,sizeof(AGENDAMENTO),1,arq)==1){
        if(codA==ag.codAgen){
            ativo=1;
            break;
        }
    }

    if(ativo==0){

    fflush(stdin);
    printf("\t\t\t\t\tบ Nome do paciente: ");
    gets(nome);
    printf("\t\t\t\t\tบ Codigo do paciente: ");
    scanf("%d", &codP);

    FILE *arq;
    arq = fopen("paciente.txt","rb");
    PACIENTE p;
    rewind(arq);
    while(fread(&p,sizeof(PACIENTE),1,arq)==1){
        if(codP==p.codigo){
            ativo=1;
            break;
        }
    }
    fclose(arq);

    if(ativo==1){
        printf("\t\t\t\t\tบ Area da consulta: ");
        printf("\n\t\t\t\t\tบ -Fisioterapia ");
        printf("\n\t\t\t\t\tบ -Odontologia ");
        printf("\n\t\t\t\t\tบ -Psicologia ");
        printf("\n\t\t\t\t\tบ ");
        fflush(stdin);
        gets(curso);
        strupr(curso);

        FILE *arq;
        arq = fopen("agendamento.txt","rb");

        AGENDAMENTO ag;

        rewind(arq);
        while(fread(&ag,sizeof(AGENDAMENTO),1,arq)==1){
            if((strcmp(curso,ag.area)==0) && (codP==ag.codPac)){
                ativo=0;
                break;
            }
        }
        fclose(arq);

        if(ativo==1){
            FILE *arq;
            arq = fopen("agendamento.txt","ab");
            AGENDAMENTO ag;

            strcpy(ag.nome,nome);
            strcpy(ag.area,curso);
            ag.codAgen=codA;
            ag.codPac=codP;
            printf("\t\t\t\t\tบ Data da consulta: ");
            scanf("%d%d%d", &ag.dia,&ag.mes,&ag.ano);
            printf("\t\t\t\t\tบ Area da consulta: ");
            fwrite(&ag,sizeof(AGENDAMENTO),1,arq);
            fclose(arq);

            system("cls");
            printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
            printf("\n\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ Agendamento feito");
            printf("\n\t\t\t\t\tบ 1-Voltar");
            getch();
            }
            else{
                system("cls");
                printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                printf("\n\t\t\t\t\tบ Ja possui consulta na mesma area");
                printf("\n\t\t\t\t\tบ 1-Voltar");
                getch();
                }
    }
    else{
        system("cls");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Codigo nao encontrado");
        printf("\n\t\t\t\t\tบ 1-Voltar");
        getch();
    }
    }
    else{
        system("cls");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Codigo de agendamento ja usado");
        printf("\n\t\t\t\t\tบ 1-Voltar");
        getch();
    }
}

void removerAgendamento(){
    FILE *arq;
    arq = fopen("agendamento.txt","rb");
    AGENDAMENTO ag;

    int cod,opc,ativo=0;
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Digite o codigo do agendamento: ");
    scanf("%d", &cod);

    while(fread(&ag,sizeof(AGENDAMENTO),1,arq)==1){
        if(cod==ag.codAgen){
            printf("\t\t\t\t\tบ Paciente: %s", ag.nome);
            printf("\n\t\t\t\t\tบ Codigo do paciente: %d", ag.codPac);
            printf("\n\t\t\t\t\tบ Area: %s", ag.area);
            printf("\n\t\t\t\t\tบ Data da consulta: %d/%d/%d", ag.dia,ag.mes,ag.ano);
            ativo=1;
            break;
        }
    }
    fclose(arq);
    if(ativo==1){
            printf("\n\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ Deseja remover? ");
            printf("\n\t\t\t\t\tบ 1-SIM/2-NAO");
            scanf("%d", &opc);

            if(opc==1){

                system("cls");
                AGENDAMENTO ag1;

                FILE *arq1;
                arq1 = fopen("agendamento.txt","rb");

                FILE *arq2;
                arq2 = fopen("agendamento2.txt","wb");
                while(fread(&ag1,sizeof(AGENDAMENTO),1,arq1)==1){
                    if(cod!=ag1.codAgen){
                        fwrite(&ag1,sizeof(AGENDAMENTO),1,arq2);
                    }
                }
                fclose(arq1);
                fclose(arq2);

                remove("agendamento.txt");

                system("ren agendamento2.txt agendamento.txt");

                printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                printf("\n\t\t\t\t\tบ Removido");
                printf("\n\t\t\t\t\tบ 1-voltar");
                getch();
            }
    }
    else{
        system("cls");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Agendamento nao encontrado");
        printf("\n\t\t\t\t\tบ 1-voltar");
        getch();
    }
    system("cls");
}

void listarAgendamento(){
    FILE *arq;
    arq = fopen("agendamento.txt","rb");
    AGENDAMENTO ag;

    while(fread(&ag,sizeof(AGENDAMENTO),1,arq)==1){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Codigo do Agendamento: %d", ag.codAgen);
        printf("\n\t\t\t\t\tบ Nome do Paciente: %s", ag.nome);
        printf("\n\t\t\t\t\tบ Codigo do Paciente: %d", ag.codPac);
        printf("\n\t\t\t\t\tบ Area da Consulta: %s", ag.area);
        printf("\n\t\t\t\t\tบ Data da Consulta: %d/%d/%d", ag.dia,ag.mes,ag.ano);
        printf("\n\t\t\t\t\tบ");
    }
    rewind(arq);
    if(fread(&ag,sizeof(AGENDAMENTO),1,arq)==NULL){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Sem Agendamento");
    }
    fclose(arq);
    printf("\n\t\t\t\t\tบ 1-Voltar");
    getch();
    system("cls");
}

void menuAtendimento(){
    int opc;
    do{
        system("cls");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t ATENDIMENTO\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ 1- Criar Atendimento\t\t บ");
        printf("\n\t\t\t\t\tบ 2- Cancelar Atendimento\t บ");
        printf("\n\t\t\t\t\tบ 3- Listar Atendimento\t\t บ");
        printf("\n\t\t\t\t\tบ 4- Voltar\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        scanf("%d", &opc);
        system("cls");
        switch (opc){
            case 1: criarAtendimento(); break;
            case 2: removerAtendimento(); break;
            case 3: listarAtendimento(); break;
            system("cls");
        }
    }
    while(opc!=4);
}

void criarAtendimento(){
    int codAte, codAg, codAl, codPa, codSu, ativo=0;
    int dia, mes, ano;
    char nomeAl[50], nomePa[50],nomeSu[50],area[30];

    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Codio de atendimento: ");
    scanf("%d", &codAte);
    printf("\t\t\t\t\tบ Codigo do agendamento: ");
    scanf("%d", &codAg);

    FILE *arq;
    arq = fopen("agendamento.txt","rb");
    AGENDAMENTO ag;
    while(fread(&ag,sizeof(AGENDAMENTO),1,arq)==1){
        if(codAg==ag.codAgen){
            ativo=1;
            dia=ag.dia;
            mes=ag.mes;
            ano=ag.ano;
            break;
        }
    }
    fclose(arq);
    if(ativo==1){
        ativo=0;
        printf("\t\t\t\t\tบ Codigo do aluno: ");
        scanf("%d", &codAl);
        FILE *arq;
        arq = fopen("aluno.txt","rb");
        ALUNO a;
        while(fread(&a,sizeof(ALUNO),1,arq)==1){
            if(codAl==a.matricula){
                ativo=1;
                printf("\t\t\t\t\tบ Aluno: %s", a.nome);
                strcpy(nomeAl,a.nome);
                strcpy(area,a.curso);
                break;
            }
        }
        fclose(arq);
        if(ativo==1){
            ativo=0;
            printf("\n\t\t\t\t\tบ Codigo do paciente: ");
            scanf("%d", &codPa);
            FILE *arq;
            arq = fopen("paciente.txt","rb");
            PACIENTE p;
            while(fread(&p,sizeof(PACIENTE),1,arq)==1){
                if(codPa==p.codigo){
                    ativo=1;
                    printf("\t\t\t\t\tบ Paciente: %s", p.nome);
                    strcpy(nomePa,p.nome);
                    break;
                }
            }
            fclose(arq);
            if(ativo==1){
                ativo=0;
                printf("\n\t\t\t\t\tบ Codigo do supervisor: ");
                scanf("%d", &codSu);
                FILE *arq;
                arq = fopen("supervisor.txt","rb");
                SUPERVISOR s;
                while(fread(&s,sizeof(SUPERVISOR),1,arq)==1){
                    if(codSu==s.codigo){
                        ativo=1;
                        printf("\t\t\t\t\tบ Supervisor: %s", s.nome);
                        strcpy(nomeSu,s.nome);
                        break;
                    }
                }
                fclose(arq);
                if(ativo==1){
                    // FUNCAO DE HORA PEGA NO https://pt.stackoverflow.com/questions/158195/como-pegar-hora-do-sistema-e-guardar-em-uma-vari%C3%A1vel
                    struct tm agora_data= {0};
                    time_t tempo_data;

                    time(&tempo_data);
                    agora_data = *localtime(&tempo_data);

                    if(dia==(agora_data.tm_mday) && mes==(agora_data.tm_mon+1) && ano==(agora_data.tm_year+1900)){
                        FILE *arq3;
                        arq3 = fopen("atendimento.txt","wb");
                        ATENDIMENTO at;
                        at.codAten=codAte;
                        at.codAgen=codAg;
                        at.codAlu=codAl;
                        strcpy(at.nomeAlu,nomeAl);
                        at.codPac=codPa;
                        strcpy(at.nomePac,nomePa);
                        at.codSup=codSu;
                        strcpy(at.nomeSup,nomeSu);
                        strcpy(at.area,area);
                        at.dia=dia;
                        at.mes=mes;
                        at.ano=ano;
                        fwrite(&at,sizeof(ATENDIMENTO),1,arq3);
                        fclose(arq3);

                        system("cls");

                        AGENDAMENTO ag1;
                        FILE *arq1;
                        arq1 = fopen("agendamento.txt","rb");

                        FILE *arq2;
                        arq2 = fopen("agendamento2.txt","wb");
                        while(fread(&ag1,sizeof(AGENDAMENTO),1,arq1)==1){
                            if(codAg!=ag1.codAgen){
                                fwrite(&ag1,sizeof(AGENDAMENTO),1,arq2);
                            }
                        }
                        fclose(arq1);
                        fclose(arq2);

                        //remove("agendamento.txt");
                        //system("ren agendamento2.txt agendamento.txt");

                        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                        printf("\n\t\t\t\t\tบ");
                        printf("\n\t\t\t\t\tบ Atendimento feito");
                        printf("\n\t\t\t\t\tบ 1-Voltar");
                        getch();

                    }
                    else{
                        printf("\n\t\t\t\t\tบ");
                        printf("\n\t\t\t\t\tบ Data nao valida");
                        printf("\n\t\t\t\t\tบ 1-Voltar");
                        getch();
                    }
                }
                else{
                    printf("\t\t\t\t\tบ");
                    printf("\n\t\t\t\t\tบ Codigo do supervisor nao encontrado");
                    printf("\n\t\t\t\t\tบ 1-Voltar");
                    getch();
                }
            }
            else{
                printf("\t\t\t\t\tบ");
                printf("\n\t\t\t\t\tบ Codigo do paciente nao encontrado");
                printf("\n\t\t\t\t\tบ 1-Voltar");
                getch();
            }
        }
        else{
            printf("\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ Codigo de aluno nao encontrado");
            printf("\n\t\t\t\t\tบ 1-Voltar");
            getch();
        }
    }
    else{
        printf("\t\t\t\t\tบ");
        printf("\n\t\t\t\t\tบ Codigo de agendamento nao encontrado");
        printf("\n\t\t\t\t\tบ 1-Voltar");
        getch();
    }
}

void removerAtendimento(){
    FILE *arq;
    arq = fopen("atendimento.txt","rb");
    ATENDIMENTO at;

    int cod,opc,ativo=0;
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Digite o codigo do atendimento: ");
    scanf("%d", &cod);

    while(fread(&at,sizeof(ATENDIMENTO),1,arq)==1){
        if(cod==at.codAten){
            printf("\t\t\t\t\tบ Nome do Paciente: %s", at.nomePac);
            printf("\n\t\t\t\t\tบ Nome do Aluno: %s", at.nomeAlu);
            printf("\n\t\t\t\t\tบ Area: %s", at.area);
            printf("\n\t\t\t\t\tบ Data: %d/%d/%d", at.dia,at.mes,at.ano);
            ativo=1;
            break;
        }
    }
    fclose(arq);
    if(ativo==1){
            printf("\n\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ Deseja remover? ");
            printf("\n\t\t\t\t\tบ 1-SIM/2-NAO");
            scanf("%d", &opc);

            if(opc==1){

                system("cls");
                FILE *arq;
                arq = fopen("atendimento.txt","rb");

                 FILE *arq2;
                 arq2 = fopen("atendimento2.txt","wb");
                 while(fread(&at,sizeof(ATENDIMENTO),1,arq)==1){
                        if(cod!=at.codAten){
                            fwrite(&at,sizeof(ATENDIMENTO),1,arq2);
                        }
                 }
                 fclose(arq);
                 fclose(arq2);

                 remove("atendimento.txt");
                 system("ren atendimento2.txt atendimento.txt");

                 printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                 printf("\n\t\t\t\t\tบ Removido");
                 printf("\n\t\t\t\t\tบ 1-voltar");
                 getch();
            }
    }
    else{
        system("cls");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Atendimento nao encontrado");
        printf("\n\t\t\t\t\tบ 1-voltar");
        getch();
    }
    system("cls");
}

void listarAtendimento(){
    int opc;
    do{
        system("cls");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t ATENDIMENTO\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบ 1- Todos atendimentos\t\t บ");
        printf("\n\t\t\t\t\tบ 2- Por area especifico\t บ");
        printf("\n\t\t\t\t\tบ 3- Por aluno especifico\t บ");
        printf("\n\t\t\t\t\tบ 4- Por paciente especifico\t บ");
        printf("\n\t\t\t\t\tบ 5- Voltar\t\t\t บ");
        printf("\n\t\t\t\t\tบ\t\t\t\t บ");
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        scanf("%d", &opc);
        system("cls");
        switch (opc){
            case 1: listarTodos(); break;
            case 2: listarArea(); break;
            case 3: listarPoraluno(); break;
            case 4: listarPorpaciente(); break;
        }
    }
    while(opc!=5);
}

void listarTodos(){
    FILE *arq;
    arq = fopen("atendimento.txt","rb");
    ATENDIMENTO at;
    while(fread(&at,sizeof(ATENDIMENTO),1,arq)==1){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Codigo do Atendimento: %d", at.codAten);
        printf("\n\t\t\t\t\tบ Paciente: %s", at.nomePac);
        printf("\n\t\t\t\t\tบ Codigo do Paciente: %d", at.codPac);
        printf("\n\t\t\t\t\tบ Aluno: %s", at.nomeAlu);
        printf("\n\t\t\t\t\tบ Codigo do Aluno: %d", at.codAlu);
        printf("\n\t\t\t\t\tบ Supervisor : %s", at.nomeSup);
        printf("\n\t\t\t\t\tบ Codigo do Supervisor: %d", at.codSup);
        printf("\n\t\t\t\t\tบ Area da Consulta: %s", at.area);
        printf("\n\t\t\t\t\tบ Data da Consulta: %d/%d/%d", at.dia,at.mes,at.ano);
        printf("\n\t\t\t\t\tบ");
    }
    rewind(arq);
    if(fread(&at,sizeof(ATENDIMENTO),1,arq)==NULL){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Sem Atendiemnto");
    }
    fclose(arq);
    printf("\n\t\t\t\t\tบ");
    printf("\n\t\t\t\t\tบ 1-Voltar");
    getch();
}

void listarArea(){
    int opc;
    char fisi[20]={"FISIOTERAPIA"},odon[20]={"ODONTOLOGIA"},psic[20]={"PSICOLOGIA"};
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Escolha a area");
    printf("\n\t\t\t\t\tบ 1-Fisioterapia ");
    printf("\n\t\t\t\t\tบ 2-Odontologia ");
    printf("\n\t\t\t\t\tบ 3-Psicologia ");
    scanf("%d", &opc);
    system("cls");

    if(opc==1){
        FILE *arq;
        arq = fopen("atendimento.txt","rb");
        ATENDIMENTO at;
        while(fread(&at,sizeof(ATENDIMENTO),1,arq)==1){
            if(strcmp(fisi,at.area)==0){
                printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                printf("\n\t\t\t\t\tบ Codigo do Atendimento: %d", at.codAten);
                printf("\n\t\t\t\t\tบ Paciente: %s", at.nomePac);
                printf("\n\t\t\t\t\tบ Codigo do Paciente: %d", at.codPac);
                printf("\n\t\t\t\t\tบ Aluno: %s", at.nomeAlu);
                printf("\n\t\t\t\t\tบ Codigo do Aluno: %d", at.codAlu);
                printf("\n\t\t\t\t\tบ Supervisor : %s", at.nomeSup);
                printf("\n\t\t\t\t\tบ Codigo do Supervisor: %d", at.codSup);
                printf("\n\t\t\t\t\tบ Area da Consulta: %s", at.area);
                printf("\n\t\t\t\t\tบ Data da Consulta: %d/%d/%d", at.dia,at.mes,at.ano);
                printf("\n\t\t\t\t\tบ");
            }
        }
        rewind(arq);
        if(fread(&at,sizeof(ATENDIMENTO),1,arq)==NULL){
            printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
            printf("\n\t\t\t\t\tบ Sem Atendiemnto");
        }
        fclose(arq);
        printf("\n\t\t\t\t\tบ");
        printf("\n\t\t\t\t\tบ 1-Voltar");
        getch();
    }
    else{
        if(opc==2){
            FILE *arq;
            arq = fopen("atendimento.txt","rb");
            ATENDIMENTO at;
            while(fread(&at,sizeof(ATENDIMENTO),1,arq)==1){
                if(strcmp(odon,at.area)==0){
                    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                    printf("\n\t\t\t\t\tบ Codigo do Atendimento: %d", at.codAten);
                    printf("\n\t\t\t\t\tบ Paciente: %s", at.nomePac);
                    printf("\n\t\t\t\t\tบ Codigo do Paciente: %d", at.codPac);
                    printf("\n\t\t\t\t\tบ Aluno: %s", at.nomeAlu);
                    printf("\n\t\t\t\t\tบ Codigo do Aluno: %d", at.codAlu);
                    printf("\n\t\t\t\t\tบ Supervisor : %s", at.nomeSup);
                    printf("\n\t\t\t\t\tบ Codigo do Supervisor: %d", at.codSup);
                    printf("\n\t\t\t\t\tบ Area da Consulta: %s", at.area);
                    printf("\n\t\t\t\t\tบ Data da Consulta: %d/%d/%d", at.dia,at.mes,at.ano);
                    printf("\n\t\t\t\t\tบ");
                }
            }
            rewind(arq);
            if(fread(&at,sizeof(ATENDIMENTO),1,arq)==NULL){
                printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                printf("\n\t\t\t\t\tบ Sem Atendiemnto");
            }
            fclose(arq);
            printf("\n\t\t\t\t\tบ");
            printf("\n\t\t\t\t\tบ 1-Voltar");
            getch();
        }
        else{
            if(opc==3){
                FILE *arq;
                arq = fopen("atendimento.txt","rb");
                ATENDIMENTO at;
                while(fread(&at,sizeof(ATENDIMENTO),1,arq)==1){
                    if(strcmp(psic,at.area)==0){
                        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                        printf("\n\t\t\t\t\tบ Codigo do Atendimento: %d", at.codAten);
                        printf("\n\t\t\t\t\tบ Paciente: %s", at.nomePac);
                        printf("\n\t\t\t\t\tบ Codigo do Paciente: %d", at.codPac);
                        printf("\n\t\t\t\t\tบ Aluno: %s", at.nomeAlu);
                        printf("\n\t\t\t\t\tบ Codigo do Aluno: %d", at.codAlu);
                        printf("\n\t\t\t\t\tบ Supervisor : %s", at.nomeSup);
                        printf("\n\t\t\t\t\tบ Codigo do Supervisor: %d", at.codSup);
                        printf("\n\t\t\t\t\tบ Area da Consulta: %s", at.area);
                        printf("\n\t\t\t\t\tบ Data da Consulta: %d/%d/%d", at.dia,at.mes,at.ano);
                        printf("\n\t\t\t\t\tบ");
                    }
                }
                rewind(arq);
                if(fread(&at,sizeof(ATENDIMENTO),1,arq)==NULL){
                    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                    printf("\n\t\t\t\t\tบ Sem Atendiemnto");
                }
                fclose(arq);
                printf("\n\t\t\t\t\tบ");
                printf("\n\t\t\t\t\tบ 1-Voltar");
                getch();
            }
            else{
                printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
                printf("\n\t\t\t\t\tบ");
                printf("\n\t\t\t\t\tบ Opcao Invalida");
                printf("\n\t\t\t\t\tบ 1-voltar");
                getch();
            }
        }
    }
}

void listarPoraluno(){
    char nome[50];
    fflush(stdin);
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Nome do Aluno: ");
    gets(nome);
    system("cls");
    FILE *arq;
    arq = fopen("atendimento.txt","rb");
    ATENDIMENTO at;
    while(fread(&at,sizeof(ATENDIMENTO),1,arq)==1){
        if(strcmp(nome,at.nomeAlu)==0){
            printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
            printf("\n\t\t\t\t\tบ Codigo do Atendimento: %d", at.codAten);
            printf("\n\t\t\t\t\tบ Paciente: %s", at.nomePac);
            printf("\n\t\t\t\t\tบ Codigo do Paciente: %d", at.codPac);
            printf("\n\t\t\t\t\tบ Aluno: %s", at.nomeAlu);
            printf("\n\t\t\t\t\tบ Codigo do Aluno: %d", at.codAlu);
            printf("\n\t\t\t\t\tบ Supervisor : %s", at.nomeSup);
            printf("\n\t\t\t\t\tบ Codigo do Supervisor: %d", at.codSup);
            printf("\n\t\t\t\t\tบ Area da Consulta: %s", at.area);
            printf("\n\t\t\t\t\tบ Data da Consulta: %d/%d/%d", at.dia,at.mes,at.ano);
            printf("\n\t\t\t\t\tบ");
        }
    }
    rewind(arq);
    if(fread(&at,sizeof(ATENDIMENTO),1,arq)==NULL){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Sem Atendiemnto");
    }
    fclose(arq);
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ");
    printf("\n\t\t\t\t\tบ 1-Voltar");
    getch();
}

void listarPorpaciente(){
    char nome[50];
    fflush(stdin);
    printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
    printf("\n\t\t\t\t\tบ Nome do Paciente: ");
    gets(nome);
    system("cls");
    FILE *arq;
    arq = fopen("atendimento.txt","rb");
    ATENDIMENTO at;
    while(fread(&at,sizeof(ATENDIMENTO),1,arq)==1){
        if(strcmp(nome,at.nomePac)==0){
            printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
            printf("\n\t\t\t\t\tบ Codigo do Atendimento: %d", at.codAten);
            printf("\n\t\t\t\t\tบ Paciente: %s", at.nomePac);
            printf("\n\t\t\t\t\tบ Codigo do Paciente: %d", at.codPac);
            printf("\n\t\t\t\t\tบ Aluno: %s", at.nomeAlu);
            printf("\n\t\t\t\t\tบ Codigo do Aluno: %d", at.codAlu);
            printf("\n\t\t\t\t\tบ Supervisor : %s", at.nomeSup);
            printf("\n\t\t\t\t\tบ Codigo do Supervisor: %d", at.codSup);
            printf("\n\t\t\t\t\tบ Area da Consulta: %s", at.area);
            printf("\n\t\t\t\t\tบ Data da Consulta: %d/%d/%d", at.dia,at.mes,at.ano);
            printf("\n\t\t\t\t\tบ");
        }
    }
    rewind(arq);
    if(fread(&at,sizeof(ATENDIMENTO),1,arq)==NULL){
        printf("\n\t\t\t\t\tบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ");
        printf("\n\t\t\t\t\tบ Sem Atendiemnto");
    }
    fclose(arq);
    printf("\n\t\t\t\t\tบ");
    printf("\n\t\t\t\t\tบ 1-Voltar");
    getch();
}

int main(){
    system ("color 79");
    menuprincipal();
    return 0;
}
