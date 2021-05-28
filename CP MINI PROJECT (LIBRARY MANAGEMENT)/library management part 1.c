#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Librarian();
int Lpasswords();
int Student();
char addBooks();
char deleteBooks();
char viewBooks();
int Bkissue();
char BORROW();
char sBk(char a);
char RETURN();
void openFile();
void openSFile();
void openBFile();
void openRFile();
void openT1File();
void openT2File();
void openT3File();
int check(int d);
int checkBList(int b);
char editbooks();
char searchBk(char a);
char registration();
char StuList();
int smenu(int id, char sname[40]);
void showRbook(int id);
char Bbook(int id, char sname[40]);
int checkBbook(int id);
char Rbook(int id, char sname[40]);

struct library{
                int id;
                char bookname[40];
                char authur[40];
                int rackNo;
                int quantity;
              };

struct sinfo{
                int m;
                char name[40];
                char course[40];
                long int phone;
                int passwords;
            };

struct BkList{
                int ID;
                char bkname[40];
                char authur[40];

            };

struct RList{
                int BookId;
                char BookName[40];
                char authur[40];
                int sId;
                char sName[40];
            };

void main()
{
    int a,L;

    openFile();
    openSFile();
    openBFile();
    openRFile();


    do
    {
        system("cls");
        printf("WELCOME TO THE LIBRARY SYSTEM!!!\n");
        printf("1.Librarian\n");
        printf("2.Student\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &a);

        switch(a)
        {
            case 1 : L=Librarian();
                    break;
            case 2 : L=Student();
                    break;
            case 3 : return;
                    break;
            default: L=1;
        }
    }while(L==1);
}


int Librarian()
{
    int a, i, n;
    char b;

    n=Lpasswords();

    if(n==1)
    {
        do
        {
            system("cls");
            printf("Main Manu\n");
            printf("1. Add Books.\n");
            printf("2. Edit Books.\n");
            printf("3. Delete Books.\n");
            printf("4. View Books.\n");
            printf("5. Issue Books\n");
            printf("6. Student's registration\n");
            printf("7. Student's List\n");
            printf("8. Exit\n");
            printf("Enter Your Choice:");
            scanf("%d", &a);

            switch(a)
            {
                case 1: {b=addBooks();}
                        break;
                case 2: {b=editbooks();}
                        break;
                case 3: {b=deleteBooks();}
                        break;
                case 4: {b=viewBooks();}
                        break;
                case 5: {i=Bkissue();}
                        break;
                case 6: {b=registration();}
                        break;
                case 7: {b=StuList();}
                        break;
                case 8: return 1;
                        break;
                default: i=8;
            }
        }while(b=='N' || b=='n' || i==8);
    }

    return 1;

}


int Lpasswords()
{
    int p;
    char c;

    do
    {
        system("cls");
        printf("Passwords: ");
        scanf("%d", &p);

        if(p==1234)
        {
            return 1;
        }

        printf("WRONG PASSWORD!!!\n\n\n\n\n");
        printf("Press 'R' to reenter password.\n");
        printf("Press 'E' to return to main menu.\n");
        getchar();
        scanf("%c", &c);

    }while( c=='r' || c=='R');

    return 0;
}



void openFile()
{   int n;

    struct library books={0,0,0,0,0};

    FILE *add;
        if((add = fopen("booklist.txt", "a"))== NULL)
    {
        printf("File can't be open.");
    }
    else
    {
        for(n=0; n<=1000; n++);
        {
            fwrite(&books, sizeof(struct library), 1, add);
        }

    }
    fclose(add);
    return;
}

void openSFile()
{
    long int i;
    FILE *ps;
    struct sinfo student={0,0,0,0,0};

    ps=fopen("sinfo.txt", "a");

    for(i=0; i<1000; i++)
    {
        fwrite(&student, sizeof(struct sinfo), 1, ps);
    }

    fclose(ps);

    return;
}

void openBFile()
{
    int i;
    struct BkList Bbook={0,0,0};

    FILE *bf;
    bf=fopen("borrowbook.txt", "a");

    for(i=0; i<1000; i++)
    {
        fwrite(&Bbook, sizeof(struct BkList), 1, bf);
    }

    fclose(bf);
}

void openRFile()
{
    int i;
    struct RList Return={0,0,0,0};

    FILE *rb;
    rb=fopen("returnBook.txt", "a");

    for(i=0; i<1000; i++)
    {
        fwrite(&Return, sizeof(struct RList), 1, rb);
    }

    fclose(rb);
}

void openT1File()
{
    int n;
    struct library books={0,0,0,0,0};

    FILE *tp;
    tp=fopen("temp_file.txt", "a");

        for(n=0; n<=1000; n++);
        {
            fwrite(&books, sizeof(struct library), 1, tp);
        }


    fclose(tp);
    return;
}



void openT2File()
{
    struct BkList Bbook={0,0,0,0,0};
    int n;

    FILE *tp;
    tp=fopen("temp2_file.txt", "a");

        for(n=0; n<=1000; n++);
        {
            fwrite(&Bbook.ID, sizeof(struct BkList), 1, tp);
        }


    fclose(tp);
    return;
}

void openT3File()
{
    int n;
    struct RList Return={0,0,0};

    FILE *tp;
    tp=fopen("temp3_file.txt", "a");

        for(n=0; n<=1000; n++);
        {
            fwrite(&Return, sizeof(struct RList), 1, tp);
        }


    fclose(tp);
    return;
}


char addBooks()
{

    int n,ch;
    struct library books;
    struct BkList Bbook;
    char a, k;

    FILE *add;
    FILE *bbook;

    do
    {

        add = fopen("booklist.txt", "r+");
        bbook = fopen("borrowbook.txt", "r+");

            system("cls");
            printf("Book's id: ");
            scanf("%d", &books.id);



            ch=check(books.id);

            if(ch==1)
            {
                printf("The book is already exists.\n\n");
            }
            else
            {


                printf("Book's name: ");
                getchar();
                scanf("%[^\n]s", &books.bookname);



                printf("Authur: ");
                getchar();
                scanf("%[^\n]s", &books.authur);

                printf("Rack no.: ");
                scanf("%d", &books.rackNo);

                printf("Quantity of the books: ");
                scanf("%d", &books.quantity);

                fseek(add, (books.id - 1)*sizeof(struct library), SEEK_SET);
                fwrite(&books, sizeof(struct library), 1, add);

                Bbook.ID=books.id;
                strcpy(Bbook.bkname, books.bookname);
                strcpy(Bbook.authur, books.authur);

                fseek(bbook, (Bbook.ID-1)*sizeof(struct BkList), SEEK_SET);
                fwrite(&Bbook, sizeof(struct BkList ), 1, bbook);

            }
            fclose(add);
            fclose(bbook);

            printf("\n\nPress 'Y' to input another books. ");
            printf("\nPress 'N' to return to main menu.\n");
            getchar();
            scanf("%c", &a);


    }while(a == 'Y' || a == 'y');


    return (a);
}

int check(int d)
{
    FILE *CK;
    struct library books;
    char r;
    CK=fopen("booklist.txt", "r");

        while(!feof(CK))
        {
            fread(&books, sizeof(struct library), 1, CK);

            if(books.id == d)
            {
                fclose(CK);
                return (1);
            }


        }
                fclose(CK);
                return (0);

}

char editbooks()
{
    struct library books;
    struct BkList Bbook;
    char e, r;
    int ch=0, chB=0;
    FILE *ed;
    FILE *bbook;

    do
    {
        ed=fopen("booklist.txt", "r+");
        bbook = fopen("borrowbook.txt", "r+");


            system("cls");
            printf("Book's id: ");
            scanf("%d", &books.id);

            chB=checkBList(books.id);

            if(chB==0)
            {
                printf("Book does can't be edit or does not exist.\n");
            }
            else
            {
                printf("New book's name: ");
                getchar();
                scanf("%[^\n]s", &books.bookname);

                printf("Authur: ");
                getchar();
                scanf("%[^\n]s", &books.authur);

                printf("New rack no.: ");
                scanf("%d", &books.rackNo);

                printf("Quantity of the books: ");
                scanf("%d", &books.quantity);


                fseek(ed, (books.id - 1)*sizeof(struct library), SEEK_SET);
                fwrite(&books, sizeof(struct library), 1, ed);

                Bbook.ID=books.id;
                strcpy(Bbook.bkname, books.bookname);
                strcpy(Bbook.authur, books.authur);

                fseek(bbook, (Bbook.ID-1)*sizeof(struct BkList), SEEK_SET);
                fwrite(&Bbook, sizeof(struct BkList ), 1, bbook);

              }

        fclose(ed);
        fclose(bbook);

        printf("Press 'C' to continue edit books.\n");
        printf("Press 'N' to return to main menu.\n");
        getchar();
        scanf("%c", &e);
    }while( e == 'c' || e == 'C');

    return (e);
}




char deleteBooks()
{
    int d;
    int ch;
    char a;
    struct library books;
    struct BkList Bbook;
    FILE *fp;
    FILE *fn;

    FILE *fbp;
    FILE *fbn;

    do
    {
        system("cls");
        printf("The id of the book that need to delete: ");
        scanf("%d", &d);

        ch=checkBList(d);
        if(ch==0)
        {
            printf("Book cannot be deleted.\n");
        }
        else
        {
            fp=fopen("booklist.txt", "rb");

            openT1File();

            if((fn=fopen("temp_file.txt", "r+"))==NULL)
            {
                printf("File cant open.");
            }
            else
            {

                while(!feof(fp))
                {
                    fread(&books, sizeof(struct library), 1, fp);
                    if(books.id==d)
                    {
                        printf("Books had successfully deleted\n");
                    }
                    else
                    {
                        fseek(fn, (books.id-1)*sizeof(struct library), SEEK_SET);
                        fwrite(&books, sizeof(struct library), 1, fn);
                    }
                }
            }

            fclose(fp);
            fclose(fn);

            remove("booklist.txt");
            rename("temp_file.txt", "booklist.txt");


            fbp=fopen("borrowbook.txt", "r");
            openT2File();

            if((fbn=fopen("temp2_file.txt", "r+"))==NULL)
            {
                printf("File cant open.");
            }
            else
            {

                while(!feof(fbp))
                {
                    fread(&Bbook, sizeof(struct BkList), 1, fbp);
                    if(Bbook.ID==d)
                    {

                    }
                    else
                    {
                        fseek(fbn, (Bbook.ID-1)*sizeof(struct BkList), SEEK_SET);
                        fwrite(&Bbook, sizeof(struct BkList), 1, fbn);
                    }
                }
            }

            fclose(fbp);
            fclose(fbn);

            remove("borrowbook.txt");
            rename("temp2_file.txt", "borrowbook.txt");
        }

        printf("Press 'Y' to continue delete book.\n");
        printf("Press 'N' to return to main menu.\n");
        getchar();
        scanf("%c",&a);

    }while(a=='Y'||a=='y');

    return (a);
}


int checkBList(int b)
{
    int c=0;
    int e=0;
    struct library books;
    struct BkList Bbook;
    FILE *fp;
    FILE *fbp;

    fp=fopen("booklist.txt", "r");
    fbp=fopen("borrowbook.txt", "r");

    while(!feof(fp))
    {
        fread(&books, sizeof(struct library), 1, fp);
        if(books.id==b)
        { c=1;}
    }

    while(!feof(fbp))
    {
        fread(&Bbook, sizeof(struct BkList), 1, fbp);
        if(Bbook.ID==b)
        { e=1;}
    }

    fclose(fp);
    fclose(fbp);

    if( c==1 && e==1 )
    {
        return(1);
    }
    else
    {
        return(0);
    }

}


char viewBooks()
{
    int l, id;
    char a, search;
    FILE *list;
    struct library books;

    do
    {
        if((list=fopen("booklist.txt", "r"))==NULL)
        {
            printf("File can't be opened.");
        }
        else
        {

            system("cls");


            for(l=1; l<=98; l++)
            {printf("-");}
            printf("\n|%-12s|%-30s|%-30s|%-10s|%-10s|\n", "Books'ID", "Books' name", "Books' Authur", "Rack No.", "Quantity");

            while(!feof(list))
            {

                fread(&books, sizeof(struct library), 1, list);

                if(books.id!=0)
                {
                    for(l=1; l<=98; l++)
                    {printf("-");}

                    printf("\n|%-12d|%-30s|%-30s|%-10d|%-10d|\n", books.id, books.bookname, books.authur, books.rackNo, books.quantity);
                }

            }

            for(l=1; l<=98; l++)
            {printf("-");}
            printf("\n");

            printf("Press 'S' to search\n");
            printf("Press 'N' to return to main menu.\n");
            getchar();
            scanf("%c", &a);

            if(a == 's' || a == 'S')
            {
                a=searchBk(a);
            }


        }
        fclose(list);

    }while( a == 'r' || a == 'R');
    return (a);
}




char searchBk(char a)
{
    int l, id;
    FILE *list;
    struct library books;

    while(a == 'S' || a == 's')
    {
        if((list=fopen("booklist.txt", "r"))==NULL)
        {
            printf("File can't be opened.");
        }
        else
        {

                system("cls");
                printf("Book id : ");
                scanf("%d", &books.id);

                fseek(list, (books.id-1)*sizeof(struct library), SEEK_SET);
                fread(&books, sizeof(struct library), 1, list);

                    if(books.id!=0)
                    {
                        for(l=1; l<=98; l++)
                        {printf("-");}

                        printf("\n|%-12s|%-30s|%-30s|%-10s|%-10s|\n", "Books'ID", "Books' name", "Books' Authur", "Rack No.", "Quantity");
                        for(l=1; l<=98; l++)
                        {printf("-");}

                        printf("\n|%-12d|%-30s|%-30s|%-10d|%-10d|\n", books.id, books.bookname, books.authur, books.rackNo, books.quantity);
                        for(l=1; l<=98; l++)
                        {printf("-");}
                    }
                    else
                    {
                        printf("Book does not exist.\n");
                    }



            }
        fclose(list);
        printf("\nPress 'R' to return to the booklist.\n");
        printf("Press 'S' to search again.\n");
        printf("Press 'N' to return to main menu.\n");
        getchar();
        scanf("%c", &a);
    }
    return (a);
}





char registration()
{
    char a;
    struct sinfo student;
    do
    {
        FILE *ps;

        ps=fopen("sinfo.txt", "r+");



            system("cls");
            printf("Student id.: ");
            scanf("%d", &student.m);

            printf("Student's name: ");
            getchar();
            scanf("%[^\n]s", &student.name);

            printf("Course: ");
            getchar();
            scanf("%[^\n]s", &student.course);

            printf("Phone No.: ");
            scanf("%d", &student.phone);


            printf("Password: ");
            scanf("%d", &student.passwords);


            fseek(ps, (student.m-1)*sizeof(struct sinfo), SEEK_SET);
            fwrite(&student, sizeof(struct sinfo), 1, ps);

            fclose(ps);

            printf("Press 'R' to register other student.\n");
            printf("Press 'N' to return to the main menu.\n");
            getchar();
            scanf("%c", &a);

    }while(a =='r' || a == 'R');

    return (a);
}





char StuList()
{
    char a;
    int l;
    FILE *list;
    struct sinfo student;

    do
    {
        if((list=fopen("sinfo.txt", "r"))==NULL)
        {
            printf("File can't be opened.");
        }
        else
        {

            system("cls");


            for(l=1; l<=93; l++)
            {printf("-");}
            printf("\n|%-12s|%-30s|%-30s|%-15s|\n", "Students'ID", "Students' name", "Course", "Phone No.");

            while(!feof(list))
            {

                fread(&student, sizeof(struct sinfo), 1, list);

                if(student.m!=0)
                {
                    for(l=1; l<=93; l++)
                    {printf("-");}

                    printf("\n|%-12d|%-30s|%-30s|%-15d|\n", student.m, student.name, student.course, student.phone);
                }

            }

            for(l=1; l<=93; l++)
            {printf("-");}
            printf("\n");

            printf("Press 'N' to return to main menu.\n");
            getchar();
            scanf("%c", &a);



        }
        fclose(list);

    }while( a == 'r' || a == 'R');

    return (a);
}



int Bkissue()
{
    int a;
    char b;

    do
    {
        system("cls");
        printf("Book Issues Menu\n");
        printf("1. View booklist that still can be borrow.\n");
        printf("2. View booklist thet still not return.\n");
        printf("3. Return to Main Menu.\n");
        printf("Enter Your Choice: ");
        scanf("%d", &a);

        switch(a)
        {
            case 1: b=BORROW();
                    break;
            case 2: b=RETURN();
                    break;
            case 3: return(8);
                    break;
            default: b='n';
        }

    }while(b == 'n'|| b == 'N');
}

char BORROW()
{
        int l, id;
    char a;
    FILE *list;
    struct BkList Bbook;
    do
    {
        if((list=fopen("borrowbook.txt", "r"))==NULL)
        {
            printf("File can't be opened.");
        }
        else
        {

            system("cls");

            for(l=1; l<=76; l++)
            {printf("-");}
            printf("\n|%-12s|%-30s|%-30s|\n", "Books'ID", "Books' name", "Books' Authur");

            while(!feof(list))
            {

                fread(&Bbook, sizeof(struct BkList), 1, list);

                if(Bbook.ID!=0)
                {
                    for(l=1; l<=76; l++)
                    {printf("-");}

                    printf("\n|%-12d|%-30s|%-30s|\n", Bbook.ID, Bbook.bkname, Bbook.authur);
                }

            }

            for(l=1; l<=76; l++)
            {printf("-");}
            printf("\n");

            printf("Press 'B' to search book\n");
            printf("Press 'N' to return to the front.\n");
            getchar();
            scanf("%c", &a);

           if(a == 'b' || a == 'B')
            {
                a=sBk(a);
            }

        }
        fclose(list);

    }while( a == 'r' || a == 'R');

    return (a);
}



char sBk(char a)
{
    int l, id;
    FILE *list;
    struct BkList Bbook;


        list=fopen("borrowbook.txt", "r");

        system("cls");
        printf("Book id : ");
        scanf("%d", &Bbook.ID);

        fseek(list, (Bbook.ID-1)*sizeof(struct BkList), SEEK_SET);
        fread(&Bbook, sizeof(struct BkList), 1, list);

        if(Bbook.ID!=0)
                {

                    for(l=1; l<=76; l++)
                    {printf("-");}
                    printf("\n|%-12s|%-30s|%-30s|\n", "Books'ID", "Books' name", "Books' Authur");

                    for(l=1; l<=76; l++)
                    {printf("-");}

                    printf("\n|%-12d|%-30s|%-30s|\n", Bbook.ID, Bbook.bkname, Bbook.authur);
                    for(l=1; l<=76; l++)
                    {printf("-");}

                }
                else
                {
                    printf("Book had been borrowed.\n");
                }

        fclose(list);
        printf("\nPress 'R' to return to the booklist.\n");
        getchar();
        scanf("%c", &a);

    return (a);
}



char RETURN()
{
    int l, id;
    char a;
    FILE *list;
    struct RList Return;;

        list=fopen("returnBook.txt", "r");

        system("cls");

        for(l=1; l<=120; l++)
        {printf("-");}

        printf("\n");

        printf("\n|%-12s|%-30s|%-30s|%-11s|%-30s|\n", "Books'ID", "Books' name", "Books' authur" ,"Student's ID", "Student's name");

        while(!feof(list))
        {

            fread(&Return, sizeof(struct RList), 1, list);

            if(Return.BookId!=0)
            {
                    printf("\n");
                    for(l=1; l<=120; l++)
                    {printf("-");}

                    printf("\n");

                    printf("\n|%-12d|%-30s|%-30s|%-12d|%-30s|\n", Return.BookId, Return.BookName, Return.authur ,Return.sId, Return.sName);
            }

            }
            printf("\n");
            for(l=1; l<=120; l++)
            {printf("-");}
            printf("\n");

            printf("\nPress 'N' to back\n");
            getchar();
            scanf("%c", &a);

        fclose(list);

    return (a);
}


int Student()
{
    int p;
    char a;
    struct sinfo student;

    FILE *cp;


    do
    {
        system("cls");
        cp=fopen("sinfo.txt", "r");

        printf("Student id: ");
        scanf("%d", &student.m);

        fseek(cp, (student.m-1)*sizeof(struct sinfo), SEEK_SET);
        fread(&student, sizeof(struct sinfo), 1, cp);

        printf("Password: ");
        scanf("%d", &p);

        if(student.passwords == p && student.m != 0 )
        {
            a=smenu(student.m, student.name);

        }
        else
        {
            printf("Student Id or password wrong\n");
            printf("Press 'R' to retry login.\n");
            getchar();
            scanf("%c", &a);
        }

        fclose(cp);

    }while(a == 'r' || a == 'R');

    return 1;
}


int smenu(int id, char sname[40])
{
    int a;
    char c;

    do
    {
        system("cls");

        printf("WELCOME TO THE LIBRARY!\n\n\n");


        printf("Student's Main Menu\n");
        printf("1. Booklist\n");
        printf("2. Borrow Books\n");
        printf("3. Return Books\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        getchar();
        scanf("%d", &a);

        switch(a)
        {
            case 1: {
                        c=viewBooks();
                        c='r';
                    }
                    break;
            case 2: {c=Bbook(id, sname);}
                    break;
            case 3: {c=Rbook(id, sname);}
                    break;
            case 4: {return (1);}
                    break;
            default: { c='r'; }
        }

    }while( c == 'r' || c == 'R');

}

void showRbook(int id)
{
    int n=0;
    struct RList Return;
    FILE *op;
    op=fopen("returnBook.txt", "r");

    while(!feof(op))
    {
        fread(&Return, sizeof(struct RList), 1, op);
        if(Return.sId == id)
        {
            printf("Book that you borrow: \n\n");
            printf("Book's name: %s\t\t", Return.BookName);
            printf("Return date:\n\n\n\n");

            n++;
        }
    }


            printf("Number of Book that you borrow: %d\n\n", n);



    fclose(op);
    return;

}

char Bbook(int id, char sname[40])
{
    int d, c;
    char a;
    struct BkList Bbook;
    struct RList Return;
    struct sinfo student;

    FILE *fp;
    FILE *fn;
    do
    {
        system("cls");

        showRbook(id);

        printf("Press 'L' to see which book can be borrow.\n");
        printf("Press 'B' to borrow book.\n");
        printf("Press 'R' to return Student's Main Menu.\n");
        printf("Enter Your Choice.\n");
        getchar();
        scanf("%c", &a);


        if( a == 'l' || a == 'L')
        {   a = BORROW(); }
        else if( a == 'B' || a =='b')
        {



            printf("The id of the book that want to borrow: ");
            scanf("%d", &d);

            c=checkBbook(d);

            if( c==1 )
            {
                fp=fopen("borrowbook.txt", "r");
                openT2File();
                fn=fopen("temp2_file.txt", "r+");

                system("cls");
                /*printf("The id of the book that want to borrow: ");
                scanf("%d", &d);*/

                while(!feof(fp))
                {   fread(&Bbook, sizeof(struct BkList), 1, fp);
                    if(Bbook.ID==d)
                    {
                        FILE *rb;
                        rb=fopen("returnBook.txt", "r+");

                        Return.BookId = Bbook.ID;
                        strcpy(Return.BookName, Bbook.bkname);
                        strcpy(Return.authur, Bbook.authur);
                        Return.sId=id;
                        strcpy(Return.sName, sname);

                        fseek(rb, (Return.BookId - 1)*sizeof(struct RList), SEEK_SET);
                        fwrite(&Return, sizeof(struct RList), 1, rb);
                        fclose(rb);

                        printf("Books had successfully been borrowed.\n");
                    }
                    else
                    {
                        fseek(fn, (Bbook.ID-1)*sizeof(struct BkList), SEEK_SET);
                        fwrite(&Bbook, sizeof(struct BkList), 1, fn);
                    }
                }
                fclose(fp);
                fclose(fn);

                remove("borrowbook.txt");
                rename("temp2_file.txt", "borrowbook.txt");
            }

            printf("Press 'R' to return to Student's Main Menu.\n");
            getchar();
            scanf("%c",&a);
        }

    }while( a == 'n' || a == 'N');

    return(a);
}


int checkBbook(int id)
{
    struct BkList Bbook;

    FILE *list;

    Bbook.ID=id;

    list=fopen("borrowbook.txt", "r");

        fseek(list, (Bbook.ID-1)*sizeof(struct BkList), SEEK_SET);
        fread(&Bbook, sizeof(struct BkList), 1, list);

        if(Bbook.ID!=0)
        {
            fclose(list);
            return 1;

        }
        else
        {
            printf("Book had been borrowed.\n");
            fclose(list);

            return 0;
        }


}


char Rbook(int id, char sname[40])
{
    int d;
    char a;
    struct BkList Bbook;
    struct RList Return;
    struct sinfo student;

    FILE *fp;
    FILE *fn;

    do
    {
        system("cls");
        showRbook(id);

        printf("Press 'Y' to return books.\n");
        printf("Press 'R' to return to Student's Main Menu.");
        getchar();
        scanf("%c",&a);



        if( a=='y' || a=='y')
        {
            system("cls");
            fp=fopen("returnBook.txt", "r");

            openT3File();
            fn=fopen("temp3_file.txt", "r+");

            printf("The id of the book that want to return: \n");
            scanf("%d", &d);

                while(!feof(fp))
                {   fread(&Return, sizeof(struct RList), 1, fp);
                    if(Return.BookId)
                    {
                        FILE *rb;
                        rb=fopen("borrowbook.txt", "r+");

                        Bbook.ID=Return.BookId;
                        strcpy(Bbook.bkname, Return.BookName);
                        strcpy(Bbook.authur, Return.authur);

                        fseek(rb, (Bbook.ID - 1)*sizeof(struct BkList), SEEK_SET);
                        fwrite(&Bbook.ID, sizeof(struct BkList), 1, rb);
                        fclose(rb);

                        printf("Books had successfully been returned.\n");
                    }
                    else
                    {
                        fseek(fn, (Return.BookId-1)*sizeof(struct RList), SEEK_SET);
                        fwrite(&Return, sizeof(struct RList), 1, fn);
                    }
                }
            fclose(fp);
            fclose(fn);

            remove("returnBook.txt");
            rename("temp3_file.txt", "returnBook.txt");

            printf("Press 'B' to back to the return book 1st page.\n");
            printf("Press 'R' to return to Student's Main Menu.\n");
            getchar();
            scanf("%c", &a);
            }

    }while( a=='b' || a=='B');


    return a;
}

