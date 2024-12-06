#ifndef PROJECTMODEL_H_INCLUDED
#define PROJECTMODEL_H_INCLUDED

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define infoProject(P) P->infoProject
#define infoTugas(T) T->infoTugas
#define nextProject(P) P->nextProject
#define nextTugas(T) T->nextTugas
#define FirstTugas(P) P->FirstTugas
#define FirstProject(M) M.FirstProject
#define LastProject(M) M.LastProject
#define LastTugas(P) P->LastTugas


using namespace std;

typedef struct Project *adrProject;
typedef struct Tugas *adrTugas;

struct infotypeProject{
    int IDProject;
    string NamaProject;
    string KepalaProject;
    int DurasiProject;
    string DeskripsiProject;
    bool ProjectSelesai;
};

struct infotypeTugas{
    int IDTugas;
    string NamaTugas;
    string DeskripsiTugas;
    int DurasiTugas;
    bool TugasSelesai;
};

struct Project{
    infotypeProject infoProject;
    adrProject nextProject;
    adrTugas FirstTugas;
    adrTugas LastTugas;
};

struct Tugas{
    infotypeTugas infoTugas;
    adrTugas nextTugas;
};

struct MLL{
    adrProject FirstProject;
    adrProject LastProject;
};

void CreateMLL(MLL &M);
adrProject CreateProject(int ID);
adrTugas CreateTugas(int ID);

void InputProject(adrProject &P, int ID);

void InsertFirstProject(MLL &M, adrProject P);
void InsertLastProject(MLL &M, adrProject P);
void ShowProject(MLL M);
void DeleteFirstProject(MLL &M, adrProject &P);
void DeleteLastProject(MLL &M, adrProject &P);

adrProject SearchIDProject(MLL M, int x);
void SearchNamaProject(MLL M, string x);
void SearchKepalaProject(MLL M, string x);
void SearchDurasiProject(MLL M, int x);
void SearchStatusProject(MLL M, bool x);

void InputTugas(adrTugas &T, int ID);

void InsertFirstTugas(MLL &M, int ID, adrTugas T);
void EditProject(MLL &M, int ID);
void EditTugas(MLL &M, int IDProject, int IDTugas, infotypeTugas y);
void ShowAll(MLL M);
adrTugas SearchIDTugas(MLL M, adrProject P, int ID);
void DeleteFirstTugas(MLL &M, int IDProject, adrTugas &T);
void DeleteLastTugas(MLL &M, int IDProject, adrTugas &T);
int CalculateDurationProject(adrProject P);

bool CalculateStatusProject(adrProject P);

void Menu(MLL &M, int IDProject, int IDTugas);




#endif // PROJECTMODEL_H_INCLUDED
