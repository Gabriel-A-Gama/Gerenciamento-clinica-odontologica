#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
typedef struct
{
    int codPac, fone;
    char nome[30];
} pacientes;

typedef struct
{
    int dia,mes,ano;

} Data;
typedef struct
{
    char nomecon[30];
    int codConsu, horas, minutos,segundos, codpacicons;
    pacientes cadastrarconsultaa;
    Data cadastrarData;
} consulta;

int main()
{
    pacientes cadastrarpaciente[10];
    consulta cadastrarconsulta[10];
    int cont = 0, contdupli = 0, op = NULL, auxc, contduplicon = 0, codigop = 0, contdupliconsulta =0, contconsult=0, auxduplico = 0, listarpac = 0, contlistar = 0, codigoc = 0, alterarpac = 0, contalterar =0,codc=0, mesconsul = 0, anoconsult = 0;
    while(op != 8)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("\nMenu de opcoes. \n[1] Cadastro de paciente \n[2] Cadastrar consulta de paciente \n[3] Listar consultas agendadas \n[4] Alterar horario \n[9] Sair \n");
        // printf("Caso queira sair digite 9.\n");
        printf("\nEscolha: ");
        scanf("%d", &op);
        switch (op)
        {
//------------------------------------------------------------------------
        case 1:

            system("CLS");
            printf("Digite o codigo do paciente a ser cadastrado (cpf): ");
            setbuf(stdin,NULL);
            scanf("%d", &cadastrarpaciente[cont].codPac);
            contdupli = 0;
            for(int j = 0; j<cont; j++)
            {
                if( cadastrarpaciente[cont].codPac == cadastrarpaciente[j].codPac)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    printf("\nPaciente ja no sistema.\n");
                    contdupli = contdupli + 1;
                    // getch();
                }
            }
            if (contdupli == 0)
            {
                printf("Digite o nome do paciente: ");
                setbuf(stdin,NULL);
                fgets(cadastrarpaciente[cont].nome,29,stdin);
                printf("Telefone do paciente: ");
                setbuf(stdin,NULL);
                scanf("%d", &cadastrarpaciente[cont].fone);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf("\nPaciente cadastrado com sucesso.\n");
                cont++;
            }
            break;
//------------------------------------------------------------------------
        case 2:
            system("CLS");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("Para cadastrar uma nova consulta\n");
            printf("Digite o codigo do paciente: ");
            scanf("%d", &auxc);
            contduplicon = 0;
            codc = 0;
            for(int j = 0; j<cont; j++)
            {
                if(auxc == cadastrarpaciente[j].codPac)
                {

                    contduplicon = contduplicon + 1;
                    codigop  = j;
                }
            }


            if(contduplicon == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("Paciente nao existente.");
                break;
            }
            if (contduplicon == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                printf("\nCadastrando consulta para: %s \n",cadastrarpaciente[codigop].nome);
                setbuf(stdin,NULL);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cadastrarconsulta[contconsult].codpacicons = cadastrarpaciente[codigop].codPac;
                codc = 0;
                printf("Digite o codigo da consulta: ");
                scanf("%d",&codc);
                for(int j =0; j< contconsult; j++)
                {
                    if(auxc == cadastrarpaciente[j].codPac)
                    {
                        if (codc == cadastrarconsulta[j].codConsu)
                        {
                            while(codc == cadastrarconsulta[j].codConsu)
                            {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                                printf("Codigo de consulta ja existe para este paciente, tente novamente.\n");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                                printf("Digite o codigo da consulta: ");
                                scanf("%d",&codc);
                            }
                        }
                    }

                }

            }
//               cadastrarconsulta[contconsult].nomecon = cadastrarpaciente[codigop].nome;
            //printf("Digite o codigo da consulta: ");
            //scanf("%d", &cadastrarconsulta[contconsult].codConsu);
            cadastrarconsulta[contconsult].codConsu = codc;
            codc = 0;
            do
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("Digite Horarios validos.\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("Horario da consulta [hora]: ");
                scanf("%d",&cadastrarconsulta[contconsult].horas);
            }
            while(cadastrarconsulta[contconsult].horas > 23 || cadastrarconsulta[contconsult].horas < 0);
            do
            {
                printf("Horario da consulta [minutos]: ");
                scanf("%d",&cadastrarconsulta[contconsult].minutos);
            }
            while(cadastrarconsulta[contconsult].minutos > 59 || cadastrarconsulta[contconsult].minutos < 0);
            do
            {
                printf("Horario da consulta [segundos]: ");
                scanf("%d",&cadastrarconsulta[contconsult].segundos );
            }
            while(cadastrarconsulta[contconsult].segundos > 59 || cadastrarconsulta[contconsult].segundos < 0);
            do
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                printf("Digite Datas validas.\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("Data da consulta [dia]: ");
                scanf("%d",&auxduplico);
            }
            while(auxduplico > 31 || auxduplico < 1);
            do
            {
                printf("Data da consulta [mes]: ");
                scanf("%d",&mesconsul);
            }
            while(mesconsul>12 || mesconsul<1);
            do
            {
                printf("Data da consulta [ano]: ");
                scanf("%d",&anoconsult);
            }
            while(anoconsult<2022);

            contdupliconsulta = 0;
            for(int j = 0; j<contconsult; j++)
            {

                if(auxc == cadastrarconsulta[j].codpacicons)
                {

                    if(anoconsult == cadastrarconsulta[j].cadastrarData.ano)
                    {

                        if(mesconsul == cadastrarconsulta[j].cadastrarData.mes)
                        {


                            if(auxduplico == cadastrarconsulta[j].cadastrarData.dia)
                            {

                                contdupliconsulta = contdupliconsulta + 1;
                                //contdupliconsulta = contdupliconsulta + 1;

                            }
                        }
                    }
                }
            }
            if (contdupliconsulta == 1)
            {

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("\nConsulta deste paciente ja agendada para dia %d.\n",auxduplico);
                printf("Agende para outro dia.\n");
                getch();
                break;

            }
            if (contdupliconsulta == 0)
            {

                cadastrarconsulta[contconsult].cadastrarData.dia = auxduplico;
                cadastrarconsulta[contconsult].cadastrarData.mes = mesconsul;
                cadastrarconsulta[contconsult].cadastrarData.ano = anoconsult;

                //do{
                // printf("Data da consulta [mes]: ");
                // scanf("%d",&cadastrarconsulta[contconsult].cadastrarData.mes);
                // }while(cadastrarconsulta[contconsult].cadastrarData.mes > 12 || cadastrarconsulta[contconsult].cadastrarData.mes < 1);
                //  do{
                //  printf("Data da consulta [ano]: ");
                //  scanf("%d",&cadastrarconsulta[contconsult].cadastrarData.ano);
                //  }while(cadastrarconsulta[contconsult].cadastrarData.ano < 2022 );
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf("\nConsulta cadastrada com sucesso!\n");
                contconsult++;
            }



            break;
//------------------------------------------------------------------------
        case 3:
            system("CLS");
            printf("Para listar consultas agendadas digite o codigo do paciente: ");
            scanf("%d",&listarpac);
            contlistar = 0;
            for(int j = 0; j<cont; j++)
            {
                if(listarpac == cadastrarpaciente[j].codPac)
                {
                    contlistar = contlistar + 1;
                    codigoc  = j;
                }
            }

            if(contlistar == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("Paciente nao existente.");
                break;
            }

            if (contlistar == 1)
            {
                for(int j = 0; j<contconsult; j++)
                {

                    if (listarpac == cadastrarconsulta[j].codpacicons)
                    {
                        printf("\n====Consultas Agendadas====\n");
                        printf("Consulta agendada para: %s",cadastrarpaciente[codigoc].nome);
                        printf("Codigo da consulta: %d\n",cadastrarconsulta[j].codConsu);
                        printf("Data da consulta: %d/%d/%d\n", cadastrarconsulta[j].cadastrarData.dia, cadastrarconsulta[j].cadastrarData.mes, cadastrarconsulta[j].cadastrarData.ano);
                        printf("Horario da consulta: %d:%d:%d\n",cadastrarconsulta[j].horas,cadastrarconsulta[j].minutos, cadastrarconsulta[j].segundos);

                    }
                }
            }
            break;
//------------------------------------------------------------------------


        case 4:
            system("CLS");
            printf("Para alterar horario digite o codigo do paciente: ");
            scanf("%d",&listarpac);
            contlistar = 0;
            for(int j = 0; j<cont; j++)
            {
                if(listarpac == cadastrarpaciente[j].codPac)
                {
                    contlistar = contlistar + 1;
                    codigoc  = j;
                }
            }

            if(contlistar == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("Paciente nao existente.");
                break;
            }

            if (contlistar == 1)
            {
                for(int j = 0; j<contconsult; j++)
                {

                    if (listarpac == cadastrarconsulta[j].codpacicons)
                    {
                        printf("\n====Consultas Agendadas====\n");
                        printf("Consulta agendada para: %s",cadastrarpaciente[codigoc].nome);
                        printf("Codigo da consulta: %d\n",cadastrarconsulta[j].codConsu);
                        printf("Data da consulta: %d/%d/%d\n", cadastrarconsulta[j].cadastrarData.dia, cadastrarconsulta[j].cadastrarData.mes, cadastrarconsulta[j].cadastrarData.ano);
                        printf("Horario da consulta: %d:%d:%d\n",cadastrarconsulta[j].horas,cadastrarconsulta[j].minutos, cadastrarconsulta[j].segundos);

                    }
                }

                printf("\nPara alterar horario digite o codigo da consulta: ");
                scanf("%d",&alterarpac);
                for(int j =0; j<contconsult; j++)
                {

                    if(listarpac == cadastrarconsulta[j].codpacicons){
                    if(alterarpac == cadastrarconsulta[j].codConsu)
                    {
                        do
                        {
                            printf("Digite Horarios validos.\n");
                            printf("Digite o novo horario seguindo o padrao (h m s): ");
                            scanf("%d %d %d", &cadastrarconsulta[j].horas,&cadastrarconsulta[j].minutos, &cadastrarconsulta[j].segundos );
                        }
                        while(cadastrarconsulta[j].horas>23 || cadastrarconsulta[j].horas < 0 || cadastrarconsulta[j].minutos > 59 || cadastrarconsulta[j].minutos < 0 || cadastrarconsulta[j].segundos > 59 || cadastrarconsulta[j].segundos <0);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                        printf("\nHorario alterado com sucesso.\n");

                    }

                    }

                }


            }
            break;



//------------------------------------------------------------------------
        case 9:
            op = 8;
            break;

//------------------------------------------------------------------------
        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printf("Opcao invalida.");
            break;
//------------------------------------------------------------------------
        }
    }
    return 0;
}




