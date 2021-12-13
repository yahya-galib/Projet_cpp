#ifndef CONTENEUR_HPP
#define CONTENEUR_HPP

#include<iostream>
#include<ostream>
#include<vector>
#include<string>

using namespace std;

template<typename T>
class Conteneur
{
protected:
    vector<T*>* lesObjets;
public:
    Conteneur();
    Conteneur(vector<T*>*);
    int getNbObjets() const;
    bool contient(T*);
    int nbOccurence(T*);
    vector<T*>* getObjets();
    void ajouter(T*);
    void retirer(T*);
    void retirerByIndex(int);
    ~Conteneur();

    bool operator==(const T*);
};

template<typename T>
bool Conteneur<T>::operator==(const T* obj){
    if (this == obj)
    {
        return true;
    }
    return false;
}

template<typename T>
Conteneur<T>::Conteneur() : lesObjets{new vector<T*>()} {}

template<typename T>
Conteneur<T>::Conteneur(vector<T*>* cont) : lesObjets{cont}{}

template<typename T>
int Conteneur<T>::getNbObjets() const{
    return (int) lesObjets->size();
}

template<typename T>
bool Conteneur<T>::contient(T* x){
    for(T* s: *lesObjets){
        if (s == x)
            return true;
    }
    return false;
}

template<typename T>
int Conteneur<T>::nbOccurence(T* x){
    int count{0};
    for(T* s: *lesObjets){
        if (s == x)
            count++;
    }
    return count;
}

template<typename T>
vector<T*>* Conteneur<T>::getObjets(){
    return lesObjets;
}

template<typename T>
void Conteneur<T>::ajouter(T* x){
    lesObjets->push_back(x);
}

template<typename T>
void Conteneur<T>::retirer(T* x){
    for (int i = 0; i < (int) lesObjets->size(); i++)
    {
        if (lesObjets->at(i) == x)
            lesObjets->erase(lesObjets->begin()+i);
    }
}

template<typename T>
void Conteneur<T>::retirerByIndex(int k){
    lesObjets->erase(lesObjets->begin()+k);
}

template<typename T>
Conteneur<T>::~Conteneur(){
    for (int i = 0; i < lesObjets->size(); i++)
    {
        delete lesObjets->at(i);
    }
}

#endif