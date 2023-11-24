#include "bibliografia.h"


Bibliografia::Bibliografia()
{

}

bool Bibliografia::agregarLibro()
{
    int numAutores;
    string nombreAutor;
    string publicacion;
    string titulo;
    int numPaginas;

    cout<<"Ingrese el numero de autores: ";
    cin>>numAutores;

    cout<<"Ingrese la publicacion: ";
    getline(cin>>ws,publicacion);
    cout<<"Ingrese el titulo: ";
    getline(cin>>ws,titulo);
    cout<<"Ingrese el numero de paginas: ";
    cin>>numPaginas;

    Libro* lbr = new Libro(numAutores,publicacion,titulo);
    lbr->setPaginas(numPaginas);
    for (int i=0;i<numAutores;i++){
        cout<<"Ingrese el nombre del autor "<< i+1<<" :";
        getline(cin>>ws,nombreAutor);
        lbr->agregarAutor(nombreAutor);
    }

    referencias.push_back(lbr);

    return true;

}

bool Bibliografia::agregarArticulo()
{
    int numAutores;
    string nombreAutor;
    string publicacion;
    string revista;
    string journal;

    cout<<"Ingrese el numero de autores: ";
    cin>>numAutores;
    cout<<"Ingrese el nombre de la publicacion: ";
    getline(cin>>ws,publicacion);
    cout<<"Ingrese el nombre de la revista: ";
    getline(cin>>ws,revista);
    cout<<"Journal [s/n]:  ";
    cin>>journal;

    Articulo* art = new Articulo(numAutores,publicacion,revista);

    if(journal=="si"){
        art->setJournal(true);
    }else{
        art->setJournal(false);
    }


    for (int i=0;i<numAutores;i++){
        cout<<"Ingrese el nombre del autor: "<< i+1<<" :";
        getline(cin>>ws,nombreAutor);
        art->agregarAutor(nombreAutor);
    }
    referencias.push_back(art);
    return true;
}

void Bibliografia::imprimirReferencias()
{
    for(int i=0;i<referencias.size();i++){
        cout<<endl<<referencias[i]->obtenerReferencia()<<endl;
    }
}

