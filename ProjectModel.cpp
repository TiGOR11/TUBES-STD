#include "ProjectModel.h"

void CreateMLL(MLL &M){
    FirstProject(M) = NULL;
}

adrProject CreateProject(int ID){
    adrProject P = new Project;
    nextProject(P) = NULL;
    FirstTugas(P) = NULL;
    LastTugas(P) = NULL;
    InputProject(P,ID);
    return P;
}

adrTugas CreateTugas(int ID){
    adrTugas T = new Tugas;
    nextTugas(T) = NULL;
    InputTugas(T,ID);
    return T;
}

void InputProject(adrProject &P, int ID){
    infoProject(P).IDProject = ID;
    printf("Masukkan Nama Project :");
    cin >> infoProject(P).NamaProject;
    printf("Masukkan Nama Kepala Project :");
    cin >> infoProject(P).KepalaProject;
    printf("Masukkan Deskripsi Project :");
    cin >> infoProject(P).DeskripsiProject;
    infoProject(P).DurasiProject = CalculateDurationProject(P);
    infoProject(P).ProjectSelesai = CalculateStatusProject(P);
}

void InsertFirstProject(MLL &M, adrProject P){
    if (FirstProject(M) != NULL){
        nextProject(P) = FirstProject(M);
        FirstProject(M) = P;
    } else {
        FirstProject(M) = P;
        LastProject(M) = P;
    }
}

void InsertLastProject(MLL &M, adrProject P){
    if (FirstProject(M) != NULL){
        nextProject(LastProject(M)) = P;
        LastProject(M) = P;
    } else {
        FirstProject(M) = P;
        LastProject(M) = P;
    }
}

void ShowProject(MLL M){
    adrProject P = FirstProject(M);
    string tes;
    printf("%4s | %10s | %10s | %10s | %6s | %8s |\n","ID", "Nama", "Kepala", "Deskripsi", "Durasi", "Status");
    printf("-----------------------------------------------------------------\n");
    string status;
    while (P != NULL){
        if(infoProject(P).ProjectSelesai){
            status = "Selesai";
        } else {
            status = "Berjalan";
        }
        printf("%4d | %10s | %10s | %10s | %6d | %8s |\n", infoProject(P).IDProject, infoProject(P).NamaProject, infoProject(P).KepalaProject
               , infoProject(P).DeskripsiProject, infoProject(P).DurasiProject, status);
        P = nextProject(P);
    }
    int out=-1;
    cin >> out;
    while(out !=0){
        cin >> out;
    }
}

void DeleteFirstProject(MLL &M, adrProject &P){
    if (FirstProject(M) == NULL){
        printf("Tidak Ada Project\n");
    } else if (FirstProject(M) == LastProject(M)){
        P = FirstProject(M);
        FirstProject(M) = NULL;
        LastProject(M) = NULL;
    } else {
        P = FirstProject(M);
        FirstProject(M) = nextProject(P);
        nextProject(P) = NULL;
    }
}

void DeleteLastProject(MLL &M, adrProject &P){
    if (FirstProject(M) == NULL){
        P = NULL;
        printf("Tidak Ada Project yang dapat dihapus\n");
    } else if(FirstProject(M) == LastProject(M)) {
        P = LastProject(M);
        FirstProject(M) = NULL;
        LastProject(M) = NULL;
    } else {
        P = LastProject(M);
        adrProject prevLast = FirstProject(M);
        while (nextProject(prevLast) != LastProject(M)){
            prevLast = nextProject(prevLast);
        }
        LastProject(M) = prevLast;
        nextProject(prevLast) = NULL;
    }
}

adrProject SearchIDProject(MLL M, int x){
    adrProject P = FirstProject(M);
    while (P != NULL){
        if (infoProject(P).IDProject == x){
            return P;
        }
        P = nextProject(P);
    }
    return NULL;

}
void SearchNamaProject(MLL M, string x){
    adrProject P = FirstProject(M);
    string tes;
    printf("%4s | %10s | %10s | %10s | %6s | %8s |\n","ID", "Nama", "Kepala", "Deskripsi", "Durasi", "Status");
    printf("-----------------------------------------------------------------\n");
    string status;
    while (P != NULL){
        if (infoProject(P).NamaProject == x){
            if(infoProject(P).ProjectSelesai){
                status = "Selesai";
            } else {
                status = "Berjalan";
            }
            printf("%4d | %10s | %10s | %10s | %6d | %8s |\n", infoProject(P).IDProject, infoProject(P).NamaProject,
                    infoProject(P).KepalaProject, infoProject(P).DeskripsiProject,infoProject(P).DurasiProject, status);
        }
        P = nextProject(P);
    }
}

void SearchKepalaProject(MLL M, string x){
    adrProject P = FirstProject(M);
    string tes;
    printf("%4s | %10s | %10s | %10s | %6s | %8s |\n","ID", "Nama", "Kepala", "Deskripsi", "Durasi", "Status");
    printf("-----------------------------------------------------------------\n");
    string status;
    while (P != NULL){
        if (infoProject(P).KepalaProject == x){
            if(infoProject(P).ProjectSelesai){
                status = "Selesai";
            } else {
                status = "Berjalan";
            }
            printf("%4d | %10s | %10s | %10s | %6d | %8s |\n", infoProject(P).IDProject, infoProject(P).NamaProject
                   , infoProject(P).KepalaProject, infoProject(P).DeskripsiProject, infoProject(P).DurasiProject, status);
        }
        P = nextProject(P);
    }
}
void SearchDurasiProject(MLL M, int x){
    adrProject P = FirstProject(M);
    string tes;
    printf("%4s | %10s | %10s | %10s | %6s | %8s |\n","ID", "Nama", "Kepala", "Deskripsi", "Durasi", "Status");
    printf("-----------------------------------------------------------------\n");
    string status;
    while (P != NULL){
        if (infoProject(P).DurasiProject == x){
            if(infoProject(P).ProjectSelesai){
                status = "Selesai";
            } else {
                status = "Berjalan";
            }
            printf("%4d | %10s | %10s | %10s | %6d | %8s |\n", infoProject(P).IDProject, infoProject(P).NamaProject,
                   infoProject(P).KepalaProject, infoProject(P).DeskripsiProject,infoProject(P).DurasiProject, status);
        }
        P = nextProject(P);
    }
}
void SearchStatusProject(MLL M, bool x){
    adrProject P = FirstProject(M);
    string tes;
    printf("%4s | %10s | %10s | %10s | %6s | %8s |\n","ID", "Nama", "Kepala", "Deskripsi", "Durasi", "Status");
    printf("-----------------------------------------------------------------\n");
    string status;
    while (P != NULL){
        if (infoProject(P).ProjectSelesai == x){
            if(infoProject(P).ProjectSelesai){
                status = "Selesai";
            } else {
                status = "Berjalan";
            }
            printf("%4d | %10s | %10s | %10s | %6d | %8s |\n", infoProject(P).IDProject, infoProject(P).NamaProject,
                   infoProject(P).KepalaProject, infoProject(P).DeskripsiProject, infoProject(P).DurasiProject, status);
        }
        P = nextProject(P);
    }
}

void InputTugas(adrTugas &T, int ID){
    infoTugas(T).IDTugas = ID;
    printf("Masukkan Nama Tugas :");
    cin >> infoTugas(T).NamaTugas;
    printf("Masukkan Deskripsi Tugas :");
    cin >> infoTugas(T).DeskripsiTugas;
    printf("Masukkan Durasi Tugas :");
    cin >> infoTugas(T).DurasiTugas;
    infoTugas(T).TugasSelesai = false;

}

void InsertFirstTugas(MLL &M, int ID, adrTugas T){
    adrProject P = SearchIDProject(M,ID);
    if (P != NULL){
        if (FirstTugas(P) != NULL){
            nextTugas(T) = FirstTugas(P);
            FirstTugas(P) = T;
        } else {
            FirstTugas(P) = T;
            LastTugas(P) = T;
        }
    } else {
        printf("ID Project Tidak Ditemukan\n");
    }
}

void InsertLastTugas(MLL &M, int ID, adrTugas T){
    adrProject P = SearchIDProject(M,ID);
    if (P != NULL){
        if (FirstTugas(P) != NULL){
            nextTugas(LastTugas(P)) = T;
            LastTugas(P) = T;
        } else {
            FirstTugas(P) = T;
            LastTugas(P) = T;
        }
    } else {
        printf("ID Project Tidak Ditemukan\n");
    }
}

void EditProject(MLL &M, int ID, infotypeProject x){
    adrProject P = SearchIDProject(M, ID);
    if (P != NULL){
        /*edit*/
        infoProject(P) = x;
    } else {
        printf("ID Project Tidak Ditemukan");
    }
}
void EditTugas(MLL &M, int IDProject, int IDTugas, infotypeTugas y){
    adrProject P = SearchIDProject(M, IDProject);
    if (P != NULL){
        adrTugas T = SearchIDTugas(M,P,IDTugas);
        if (T != NULL){
            infoTugas(T) = y;
        }
    }
}

void ShowAll(MLL M){
    adrProject P = FirstProject(M);
    string status;
    while (P != NULL){
        if(infoProject(P).ProjectSelesai){
            status = "Selesai";
        } else {
            status = "Berjalan";
        }
        printf("-----------------------------------------------------------------\n");
        printf("Project %d :\n Nama : %s\n Kepala Project : %s\n Deskripsi Project : %s\n Durasi Project : %d\n Status Project : %s\n",
               infoProject(P).IDProject, infoProject(P).NamaProject, infoProject(P).DeskripsiProject, infoProject(P).DurasiProject, status);
        adrTugas T = FirstTugas(P);
        while (T != NULL){
            string statusT;
            printf("-------------------------------------------------------\n");
            printf("%4s | %10s | %10s | %6s | %8s |\n","ID", "Nama", "Deskripsi", "Durasi", "Status");
            if (infoTugas(T).TugasSelesai){
                statusT = "Selesai";
            } else {
                statusT = "Berjalan";
            }
                printf("%4d | %10s | %10s | %6d | %8s |\n", infoTugas(T).IDTugas, infoTugas(T).NamaTugas, infoTugas(T).DeskripsiTugas,
                       infoTugas(T).DurasiTugas, statusT);
        }
        printf("-------------------------------------------------------\n");
        P = nextProject(P);
    }
}

adrTugas SearchIDTugas(MLL M, adrProject P, int ID){
    adrTugas T = FirstTugas(P);
    while (T != NULL){
        if (infoTugas(T).IDTugas == ID){
            return T;
        }
    }
    return NULL;
}

void DeleteFirstTugas(MLL &M, int IDProject, adrTugas &T){
    adrProject P = SearchIDProject(M, IDProject);
    if (P == NULL){
        printf("ID Project tidak ditemukan\n");
    } else {
        if (FirstTugas(P) == NULL){
            printf("Tidak ada Project yang di delete\n");
        } else if (FirstTugas(P) == LastTugas(P)){
            T = FirstTugas(P);
            FirstTugas(P) = NULL;
            LastTugas(P) = NULL;
        } else {
            T = FirstTugas(P);
            FirstTugas(P) = nextTugas(T);
            nextTugas(T) = NULL;
        }
    }
}

void DeleteLastTugas(MLL &M, int IDProject, adrTugas &T){
    adrProject P = SearchIDProject(M, IDProject);
    if (P == NULL){
        printf("ID Project tidak ditemukan\n");
    } else {
        if (FirstTugas(P) == NULL){
            printf("Tidak ada Project yang di delete\n");
        } else if (FirstTugas(P) == LastTugas(P)){
            T = LastTugas(P);
            FirstTugas(P) = NULL;
            LastTugas(P) = NULL;
        } else {
            T = LastTugas(P);
            adrTugas prevLast = FirstTugas(P);
            while (nextTugas(prevLast) != LastTugas(P)){
                prevLast = nextTugas(prevLast);
            }
            LastTugas(P) = prevLast;
            nextTugas(prevLast) = NULL;
        }
    }
}

int CalculateDurationProject(adrProject P){
    int durationTotal =0;
    adrTugas T = FirstTugas(P);
    while (T != NULL){
        durationTotal += infoTugas(T).DurasiTugas;
        T = nextTugas(T);
    }
    return durationTotal;
}

bool CalculateStatusProject(adrProject P){
    bool StatusProject = true;
    adrTugas T = FirstTugas(P);
    while (T != NULL){
        StatusProject &= infoTugas(T).TugasSelesai;
        T = nextTugas(T);
    }
    return StatusProject;
}

void Menu(MLL &M, int IDProject, int IDTugas){
    string identifierLokasi;
    int MenuInput = -1;
    while (MenuInput != 0){
        system("CLS");
        printf("1. Membuat Project Baru\n2. Membuat Tugas Baru\n3. Edit Project\n4. Edit Tugas\n");
        printf("5. Tampilkan List Project\n6. Tampilkan List Project dan Tugas\n7. Delete Project\n");
        printf("8. Delete Tugas\n9. Search Project\n10. Search Tugas\n0.Exit\n");
        printf("Masukkan nomor Menu: ");
        cin >> MenuInput;
        if (MenuInput == 1){
            system("CLS");
            printf("Masukkan di awal atau akhir list (awal/akhir): ");
            cin >> identifierLokasi;
            if (identifierLokasi == "awal"){
                InsertFirstProject(M,CreateProject(IDProject));
                IDProject++;
            } else if (identifierLokasi == "akhir"){
                InsertLastProject(M,CreateProject(IDProject));
                IDProject++;
            } else {
                printf("Input Tidak Valid\n");
            }
        } else if (MenuInput == 2){
            system("CLS");
            ShowProject(M);
            printf("\nMasukkan ID Project yang ingin dimasukkan Tugasnya : ");
            int inputIDProject;
            cin >> inputIDProject;
            printf("Masukkan di awal atau akhir list (awal/akhir): ");
            cin >> identifierLokasi;
            if (identifierLokasi == "awal"){
                InsertFirstTugas(M,inputIDProject,CreateTugas(IDTugas));
                IDTugas++;
            } else if (identifierLokasi == "akhir"){
                InsertLastTugas(M,inputIDProject,CreateTugas(IDTugas));
                IDTugas++;
            } else {
                printf("Input Tidak Valid\n");
            }
        } else if(MenuInput == 3) {
            infotypeProject newInfoP;

        } else if(MenuInput == 5){
            ShowProject(M);
        }
    }
}
