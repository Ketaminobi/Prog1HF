#include "menu.h"

void menu_belep(Zenek *zene, Lemezek *lemez){
    system("cls");
    int opcio;
    do {
        fejlec("Belepes");
        printf("\n\n");
        kozepen("1.Belepes\n");
        kozepen("2.Kilepes\n");
        printf("=> ");
        scanf("%u", &opcio);
        switch (opcio) {
            case 1:
                system("cls");
                udvozles();
                sleep(2);
                menu_fo(zene, lemez);
                break;
            case 2:
                system("cls");
                zenek_free(zene);
                lemezek_free(lemez);
                exit(1);
            default:
                system("cls");
                error();
                sleep(2);
        }
    } while(opcio != 2);
}

void menu_fo(Zenek *zene, Lemezek *lemez){
    system("cls");
    int opcio;
    do{
        fejlec("Menu");
        kozepen("1.Hozzaadas\n");
        kozepen("2.Torles\n");
        kozepen("3.Kereses\n");
        kozepen("4.Listazas\n");
        kozepen("5.Kilepes\n");
        printf("=> ");
        scanf("%d", &opcio);
        switch(opcio){
            case 1:
                menu_hozzaad(zene, lemez);
                break;
            case 2:
                menu_torles(zene, lemez);
                break;
            case 3:
                menu_kereses(zene, lemez);
                break;
            case 4:
                menu_kiiras(zene, lemez);
                break;
            case 5:
                zenek_save(zene);
                lemezek_save(lemez);
                zenek_free(zene);
                lemezek_free(lemez);
                system("cls");
                tavozas();
                sleep(3);
                exit(1);
            default:
                system("cls");
                error();
                sleep(2);
                break;
        }
    }while(opcio!=5);
}

void menu_hozzaad(Zenek *zene, Lemezek *lemez){
    system("cls");
    int opcio;
    do{
        fejlec("Hozzaad");
        kozepen("1.Zene hozzaadasa\n");
        kozepen("2.Lemez hozzaadasa\n");
        kozepen("3.Visszalepes\n");
        printf("=> ");
        scanf("%d",&opcio);
        switch(opcio){
        case 1:
            zene = zene_hozzaad(zene);
            zenek_save(zene);
            break;
        case 2:
            lemez_hozzad(lemez);
            lemezek_save(lemez);
            break;
        case 3:
            return;
        default:
            system("cls");
                error();
                sleep(2);
                break;
        }
    }while(opcio!=3);
}

void menu_kiiras(Zenek *zene, Lemezek *lemez){
    system("cls"); //kepernyo tisztitasa
    int opcio;
    do{
        fejlec("Listazas");
        kozepen("1.Lemez zeneinek listazasa\n");
        kozepen("2.Minden listazasa\n");
        kozepen("3.Visszalepes\n");
        printf("=> ");
        scanf("%d",&opcio);
        switch(opcio){
        case 1:
            system("cls");
            fejlec("Valasztas");
            printf("\n");
            zenek_to_lemez(zene, lemez);
            getch();
            break;
        case 2:
            system("cls");
            fejlec("Minden");
            kozepen("Zenek\n");
            zenek_kiir(zene);
            printf("------------------------------------------------\n");
            kozepen("Lemezek\n");
            lemezek_kiir(lemez);
            getch();
            break;
        case 3:
            return;
        default:
            system("cls");
                error();
                sleep(2);
                break;
        }
    }while(opcio!=3);
}

void menu_torles(Zenek *zene, Lemezek *lemez){
    system("cls");
    int opcio;
    do{
        fejlec("Torles");
        kozepen("1.Zene torlese\n");
        kozepen("2.Lemez torlese\n");
        kozepen("3.Visszalepes\n");
        printf("=> ");
        scanf("%d",&opcio);
        switch(opcio){
        case 1:
            zene_torol(zene);
            zenek_save(zene);
            getch();
            break;
        case 2:
            lemez_torol(lemez);
            lemezek_save(lemez);
            getch();
            break;
        case 3:
            return;
        default:
            system("cls");
                error();
                sleep(2);
                break;
        }
    }while(opcio!=3);
}

void menu_kereses(Zenek *zene, Lemezek *lemez){
    system("cls");
    int opcio;
    do{
        fejlec("Kereses");
        kozepen("1.Zene keresese\n");
        kozepen("2.Lemez keresese\n");
        kozepen("3.Visszalepes\n");
        printf("=> ");
        scanf("%d",&opcio);
        switch(opcio){
        case 1:
            zene_keres(zene);
            getch();
            break;
        case 2:
            lemez_keres(lemez);
            getch();
            break;
        case 3:
            return;
        default:
            system("cls");
                error();
                sleep(2);
                break;
        }
    }while(opcio!=3);
}
