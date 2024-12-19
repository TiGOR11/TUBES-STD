#include "ProjectModel.h"

void CreateMLL(MLL &M){
    FirstProject(M) = NULL;
}

adrProject CreateProject(int ID){
    adrProject P = new Project;
    nextProject(P) = NULL;
    prevProject(P) = NULL;
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
    infoProject(P).DurasiProject = 0;
    infoProject(P).ProjectSelesai = false;
}

void InsertFirstProject(MLL &M, adrProject P){
    if (FirstProject(M) != NULL){
        nextProject(P) = FirstProject(M);
        prevProject(P) = NULL;
        FirstProject(M) = P;
    } else {
        FirstProject(M) = P;
        LastProject(M) = P;
    }
}

void InsertLastProject(MLL &M, adrProject P){
    if (FirstProject(M) != NULL){
        nextProject(LastProject(M)) = P;
        prevProject(P) = LastProject(M);
        LastProject(M) = P;
    } else {
        FirstProject(M) = P;
        LastProject(M) = P;
    }
}

void ShowProject(MLL M){
    adrProject P = FirstProject(M);
    if (P != NULL){
        string tes;
        printf("%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|\n","ID", "Nama", "Kepala", "Deskripsi", "Durasi", "Status");
        printf("---------------------------------------------------------\n");
        string status;
        while (P != NULL){
            if(infoProject(P).ProjectSelesai){
                status = "Selesai";
            } else {
                status = "Berjalan";
            }
            cout << infoProject(P).IDProject << "\t|" << infoProject(P).NamaProject << "\t|" << infoProject(P).KepalaProject << "\t|"
            << infoProject(P).DeskripsiProject << "\t\t|" << infoProject(P).DurasiProject << "\t|" << status << "| \n";
            P = nextProject(P);
        }
        printf("---------------------------------------------------------\n");
    } else {
        cout << "Tidak ada Project\n";
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
        prevProject(nextProject(P)) = NULL;
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
        LastProject(M) = prevProject(P);
        nextProject(prevProject(P)) = NULL;
        prevProject(P) = NULL;
    }
}

void DeleteAfterProject(MLL &M, adrProject &P, adrProject &prec){
    P = nextProject(prec);
    nextProject(prec) = nextProject(P);
    prevProject(nextProject(P)) = prec;
    nextProject(P) = NULL;
    prevProject(P) = NULL;

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
    string status;
    while (P != NULL){
        if (infoProject(P).NamaProject == x){
            if(infoProject(P).ProjectSelesai){
                status = "Selesai";
            } else {
                status = "Berjalan";
            }
            printf("-----------------------------------------------------------------\n");
            cout << "Project " << infoProject(P).IDProject << endl << "Kepala Project : " << infoProject(P).NamaProject << endl <<
             "Deskripsi Project : " << infoProject(P).DeskripsiProject << endl << "Durasi Project : " << infoProject(P).DurasiProject <<
             endl << "Status Project : " << status << endl;
            adrTugas T = FirstTugas(P);
            if (T != NULL){
                printf("-----------------------------------------------------------------\n");
                printf("%s\t|%s\t|%s\t\t|%s\t|%s\t\t|\n","ID", "Nama", "Deskripsi", "Durasi", "Status");
            }
            while (T != NULL){
                string statusT;
                if (infoTugas(T).TugasSelesai){

                    statusT = "Selesai";
                } else {
                    statusT = "Berjalan";
                }
                cout << infoTugas(T).IDTugas << "\t|" << infoTugas(T).NamaTugas << "\t|"
                << infoTugas(T).DeskripsiTugas << "\t\t\t|" << infoTugas(T).DurasiTugas << "\t|" << statusT << "\t| \n";
                T = nextTugas(T);
            }
            printf("-----------------------------------------------------------------\n");
        }
        P = nextProject(P);
    }
}

void SearchKepalaProject(MLL M, string x){
    adrProject P = FirstProject(M);
    string tes;
    string status;
    while (P != NULL){
        if (infoProject(P).KepalaProject == x){
            if(infoProject(P).ProjectSelesai){
                status = "Selesai";
            } else {
                status = "Berjalan";
            }
            printf("-----------------------------------------------------------------\n");
            cout << "Project " << infoProject(P).IDProject << endl << "Kepala Project : " << infoProject(P).NamaProject << endl <<
             "Deskripsi Project : " << infoProject(P).DeskripsiProject << endl << "Durasi Project : " << infoProject(P).DurasiProject <<
             endl << "Status Project : " << status << endl;
            adrTugas T = FirstTugas(P);
            if (T != NULL){
                printf("-----------------------------------------------------------------\n");
                printf("%s\t|%s\t|%s\t\t|%s\t|%s\t\t|\n","ID", "Nama", "Deskripsi", "Durasi", "Status");
            }
            while (T != NULL){
                string statusT;
                if (infoTugas(T).TugasSelesai){

                    statusT = "Selesai";
                } else {
                    statusT = "Berjalan";
                }
                cout << infoTugas(T).IDTugas << "\t|" << infoTugas(T).NamaTugas << "\t|"
                << infoTugas(T).DeskripsiTugas << "\t\t\t|" << infoTugas(T).DurasiTugas << "\t|" << statusT << "\t| \n";
                T = nextTugas(T);
            }
            printf("-----------------------------------------------------------------\n");
        }
        P = nextProject(P);
    }
}
void SearchDurasiProject(MLL M, int x){
    adrProject P = FirstProject(M);
    string tes;
    string status;
    while (P != NULL){
        if (infoProject(P).DurasiProject == x){
            if(infoProject(P).ProjectSelesai){
                status = "Selesai";
            } else {
                status = "Berjalan";
            }
            printf("-----------------------------------------------------------------\n");
            cout << "Project " << infoProject(P).IDProject << endl << "Kepala Project : " << infoProject(P).NamaProject << endl <<
             "Deskripsi Project : " << infoProject(P).DeskripsiProject << endl << "Durasi Project : " << infoProject(P).DurasiProject <<
             endl << "Status Project : " << status << endl;
            adrTugas T = FirstTugas(P);
            if (T != NULL){
                printf("-----------------------------------------------------------------\n");
                printf("%s\t|%s\t|%s\t\t|%s\t|%s\t\t|\n","ID", "Nama", "Deskripsi", "Durasi", "Status");
            }
            while (T != NULL){
                string statusT;
                if (infoTugas(T).TugasSelesai){

                    statusT = "Selesai";
                } else {
                    statusT = "Berjalan";
                }
                cout << infoTugas(T).IDTugas << "\t|" << infoTugas(T).NamaTugas << "\t|"
                << infoTugas(T).DeskripsiTugas << "\t\t\t|" << infoTugas(T).DurasiTugas << "\t|" << statusT << "\t| \n";
                T = nextTugas(T);
            }
            printf("-----------------------------------------------------------------\n");
        }
        P = nextProject(P);
    }
}
void SearchStatusProject(MLL M, bool x){
    adrProject P = FirstProject(M);
    string tes;
    string status;
    while (P != NULL){
        if (infoProject(P).ProjectSelesai == x){
            if(infoProject(P).ProjectSelesai){
                status = "Selesai";
            } else {
                status = "Berjalan";
            }
            printf("-----------------------------------------------------------------\n");
            cout << "Project " << infoProject(P).IDProject << endl << "Kepala Project : " << infoProject(P).NamaProject << endl <<
             "Deskripsi Project : " << infoProject(P).DeskripsiProject << endl << "Durasi Project : " << infoProject(P).DurasiProject <<
             endl << "Status Project : " << status << endl;
            adrTugas T = FirstTugas(P);
            if (T != NULL){
                printf("-----------------------------------------------------------------\n");
                printf("%s\t|%s\t|%s\t\t|%s\t|%s\t\t|\n","ID", "Nama", "Deskripsi", "Durasi", "Status");
            }
            while (T != NULL){
                string statusT;
                if (infoTugas(T).TugasSelesai){

                    statusT = "Selesai";
                } else {
                    statusT = "Berjalan";
                }
                cout << infoTugas(T).IDTugas << "\t|" << infoTugas(T).NamaTugas << "\t|"
                << infoTugas(T).DeskripsiTugas << "\t\t\t|" << infoTugas(T).DurasiTugas << "\t|" << statusT << "\t| \n";
                T = nextTugas(T);
            }
            printf("-----------------------------------------------------------------\n");
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
    printf("Masukkan Durasi Tugas (hari) :");
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

void EditProject(MLL &M, int ID){
    adrProject P = SearchIDProject(M, ID);
    if (P != NULL){
        InputProject(P, ID);
    } else {
        printf("ID Project Tidak Ditemukan\n");
    }
}
void EditTugas(MLL &M, int IDProject, int IDTugas){
    adrProject P = SearchIDProject(M, IDProject);
    if (P != NULL){
        adrTugas T = SearchIDTugas(M,P,IDTugas);
        if (T != NULL){
            InputTugas(T, IDTugas);
        }
    } else {
        printf("ID Project Tidak Ditemukan\n");
    }
}

void ShowAll(MLL M){
    adrProject P = FirstProject(M);
    string status;
    if (P != NULL){
        while (P != NULL){
            if(infoProject(P).ProjectSelesai){
                status = "Selesai";
            } else {
                status = "Berjalan";
            }
            printf("-----------------------------------------------------------------\n");
            cout << "Project " << infoProject(P).IDProject << endl << "Kepala Project : " << infoProject(P).NamaProject << endl <<
             "Deskripsi Project : " << infoProject(P).DeskripsiProject << endl << "Durasi Project : " << infoProject(P).DurasiProject <<
             endl << "Status Project : " << status << endl;
            adrTugas T = FirstTugas(P);
            if (T != NULL){
                printf("-----------------------------------------------------------------\n");
                printf("%s\t|%s\t|%s\t\t|%s\t|%s\t\t|\n","ID", "Nama", "Deskripsi", "Durasi", "Status");
            }
            while (T != NULL){
                string statusT;
                if (infoTugas(T).TugasSelesai){

                    statusT = "Selesai";
                } else {
                    statusT = "Berjalan";
                }
                cout << infoTugas(T).IDTugas << "\t|" << infoTugas(T).NamaTugas << "\t|"
                << infoTugas(T).DeskripsiTugas << "\t\t\t|" << infoTugas(T).DurasiTugas << "\t|" << statusT << "\t| \n";
                T = nextTugas(T);
            }
            printf("-----------------------------------------------------------------\n");
            P = nextProject(P);
        }
    } else {
        printf("Tidak ada Project\n");
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

void DeleteFirstTugas(MLL &M, adrProject P, adrTugas &T){
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

void DeleteLastTugas(MLL &M, adrProject P, adrTugas &T){
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

void DeleteAfterTugas(MLL &M, adrProject P, adrTugas &T,adrTugas &prec){
    if (P == NULL){
        printf("ID Project tidak ditemukan\n");
    } else {
        if (FirstTugas(P) == NULL){
            printf("Tidak ada Project yang di delete\n");
        } else {
            T = nextTugas(prec);
            nextTugas(prec) = nextTugas(T);
            nextTugas(T) = NULL;
        }
    }
}

int CalculateDurationProject(adrProject P){
    int durationTotal =0;
    adrTugas T = FirstTugas(P);
    while (T != NULL){
        durationTotal = max(durationTotal, infoTugas(T).DurasiTugas);
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

void UpdateProject(MLL &M, int IDProject){
    adrProject p = SearchIDProject(M, IDProject);
    infoProject(p).DurasiProject = CalculateDurationProject(p);
    infoProject(p).ProjectSelesai = CalculateStatusProject(p);
}

void Menu(MLL &M, int IDProject, int IDTugas){
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
            adrProject newProject = CreateProject(IDProject);
            InsertLastProject(M, newProject);
            IDProject++;
        } else if (MenuInput == 2){
            system("CLS");
            ShowProject(M);
            if (FirstProject(M) != NULL){
                printf("\nMasukkan ID Project yang ingin dimasukkan Tugasnya : ");
                int inputIDProject;
                cin >> inputIDProject;
                if (inputIDProject < IDProject){
                    adrTugas newTugas = CreateTugas(IDTugas);
                    InsertLastTugas(M,inputIDProject,newTugas);
                    IDTugas++;
                    UpdateProject(M,inputIDProject);
                } else {
                    printf("Tidak ada ID Project\n");
                    BackHandler();
                }
            } else {
                BackHandler();
            }
        } else if(MenuInput == 3) {
            system("CLS");
            ShowProject(M);
            int IDProjectPilih;
            printf("Pilih Project yang akan diubah (Masukkan ID) : ");
            cin >> IDProjectPilih;
            if (IDProjectPilih < IDProject){
                EditProject(M,IDProjectPilih);
            } else {
                printf("ID Tidak Ada\n");
            }
        } else if (MenuInput == 4){
            system("CLS");
            ShowAll(M);
            int IDProjectPilih;
            printf("Pilih Project yang akan diubah (Masukkan ID) : ");
            cin >> IDProjectPilih;
            if (IDProjectPilih < IDProject){
                int IDTugasPilih;
                printf("Pilih Tugas yang akan diubah (Masukkan ID) : ");
                cin >> IDProjectPilih;
                if (IDTugasPilih < IDTugas){
                    EditTugas(M,IDProjectPilih, IDTugasPilih);
                } else {
                    printf("ID Tugas Tidak ada");
                }
            } else {
                printf("ID Project tidak Ada\n");
            }
        } else if(MenuInput == 5){
            system("CLS");
            ShowProject(M);
            BackHandler();
        } else if(MenuInput == 6){
            system("CLS");
            ShowAll(M);
            BackHandler();
        } else if(MenuInput == 7){
            system("CLS");
            ShowProject(M);
            adrProject PTerhapus;
            printf("Masukkan IDProject yang ingin dihapus : ");
            int IDProjectHapus;
            cin >> IDProjectHapus;
            if (infoProject(FirstProject(M)).IDProject == IDProjectHapus){
                DeleteFirstProject(M, PTerhapus);
            } else if (infoProject(LastProject(M)).IDProject == IDProjectHapus){
                DeleteLastProject(M,PTerhapus);
            } else {
                adrProject prec = prevProject(SearchIDProject(M,IDProjectHapus));
                DeleteAfterProject(M,PTerhapus,prec);
            }
            system("CLS");
            ShowProject(M);
            BackHandler();
        }else if(MenuInput == 8){
            system("CLS");
            ShowAll(M);
            adrTugas TTerhapus;
            printf("Masukkan ID Project dari tugas yang ingin dihapus : ");
            int IDProjectTerhapusT;
            cin >> IDProjectTerhapusT;
            printf("Masukkan ID Tugas yang ingin dihapus :");
            int IDTugasTerhapus;
            cin >> IDTugasTerhapus;
            adrProject PTugasTerhapus = SearchIDProject(M, IDProjectTerhapusT);
            if (infoTugas(FirstTugas(PTugasTerhapus)).IDTugas == IDTugasTerhapus){
                DeleteFirstTugas(M,PTugasTerhapus,TTerhapus);
            } else if (infoTugas(LastTugas(PTugasTerhapus)).IDTugas == IDTugasTerhapus){
                DeleteLastTugas(M,PTugasTerhapus,TTerhapus);
            } else {
                adrTugas prec = FirstTugas(PTugasTerhapus);
                while (infoTugas(nextTugas(prec)).IDTugas != IDTugasTerhapus){
                    prec = nextTugas(prec);
                }
                DeleteAfterTugas(M,PTugasTerhapus,TTerhapus,prec);
            }
            system("CLS");
            ShowAll(M);
            BackHandler();
        }else if(MenuInput == 9){
            int inputMenuSearch = -1;
            while (inputMenuSearch != 0){
                system("CLS");
                printf("1.Search Nama Project\n2.Search Kepala Project\n3.Search Durasi Project\n4.Search Status Project\n0.Kembali\nMasukkan Nomor Menu Search : ");
                cin >> inputMenuSearch;
                if (inputMenuSearch == 1){
                    system("CLS");
                    printf("Masukkan Nama Project yang dicari : ");
                    string inputNamaP;
                    cin >> inputNamaP;
                    SearchNamaProject(M,inputNamaP);
                    BackHandler();
                } else if(inputMenuSearch == 2){
                    system("CLS");
                    printf("Masukkan Kepala Project yang dicari : ");
                    string inputKplP;
                    cin >> inputKplP;
                    SearchKepalaProject(M,inputKplP);
                    BackHandler();
                } else if(inputMenuSearch == 3){
                    system("CLS");
                    printf("Masukkan Durasi Project yang dicari : ");
                    int inputDurP;
                    cin >> inputDurP;
                    SearchDurasiProject(M, inputDurP);
                    BackHandler();
                } else if(inputMenuSearch == 4){
                    system("CLS");
                    printf("Masukkan Status Project yang dicari : ");
                    string inputStatP;
                    cin >> inputStatP;
                    if (inputStatP == "Selesai" || inputStatP == "selesai"){
                        SearchStatusProject(M,true);
                    } else if (inputStatP == "Berjalan" || inputStatP == "berjalan"){
                        SearchStatusProject(M,false);
                    } else {
                        printf("Project tidak ditemukan\n");
                    }
                    BackHandler();
                }
            }
        }else if(MenuInput == 10){
            system("CLS");
            ShowAll(M);
            printf("Pilih ID Project : ");
            int IDProjectSearchTT;
            int inputMenuSearchT;
            cin >> IDProjectSearchTT;
            adrProject PSearchT = SearchIDProject(M,IDProjectSearchTT);
            while (inputMenuSearchT != 0){
                system("CLS");
                printf("1.Search Nama Tugas\n2.Search Durasi Tugas\n3.Search Status Tugas\n0.Kembali\nMasukkan Nomor Menu Search : ");
                cin >> inputMenuSearchT;
                if (inputMenuSearchT == 1){
                    system("CLS");
                    printf("Masukkan Nama Tugas yang dicari : ");
                    string inputNamaT;
                    cin >> inputNamaT;
                    SearchNamaTugas(M,PSearchT,inputNamaT);
                    BackHandler();
                } else if(inputMenuSearchT == 2){
                    system("CLS");
                    printf("Masukkan Durasi Tugas yang dicari : ");
                    int inputDurT;
                    cin >> inputDurT;
                    SearchDurasiTugas(M,PSearchT,inputDurT);
                    BackHandler();
                } else if(inputMenuSearchT == 3){
                    system("CLS");
                    printf("Masukkan Status Tugas yang dicari : ");
                    string inputStatT;
                    cin >> inputStatT;
                    bool inputStatTBool;
                    if (inputStatT == "Selesai" || inputStatT == "selesai"){
                        inputStatTBool = true;
                        SearchDurasiTugas(M,PSearchT,inputStatTBool);
                    } else if(inputStatT == "Berjalan" || inputStatT == "berjalan"){
                        inputStatTBool = false;
                        SearchDurasiTugas(M,PSearchT,inputStatTBool);
                    } else {
                        cout << "Input tidak valid\n";
                    }
                    BackHandler();
                }
            }
        }
    }
}


void BackHandler(){
    int out=-1;
    cout << "Masukkan 0 untuk kembali : ";
    cin >> out;
    while(out !=0){
        cin >> out;
    }
}


void SearchNamaTugas(MLL &M,adrProject P, string x){
    string status;
    if(infoProject(P).ProjectSelesai){
        status = "Selesai";
    } else {
        status = "Berjalan";
    }
    printf("-----------------------------------------------------------------\n");
    cout << "Project " << infoProject(P).IDProject << endl << "Kepala Project : " << infoProject(P).NamaProject << endl <<
    "Deskripsi Project : " << infoProject(P).DeskripsiProject << endl << "Durasi Project : " << infoProject(P).DurasiProject <<
    endl << "Status Project : " << status << endl;
    adrTugas T = FirstTugas(P);
    if (T != NULL){
        printf("-----------------------------------------------------------------\n");
        printf("%s\t|%s\t|%s\t\t|%s\t|%s\t\t|\n","ID", "Nama", "Deskripsi", "Durasi", "Status");
    }
    while (T != NULL){
        if(infoTugas(T).NamaTugas == x){
            string statusT;
            if (infoTugas(T).TugasSelesai){
                statusT = "Selesai";
            } else {
                statusT = "Berjalan";
            }
            cout << infoTugas(T).IDTugas << "\t|" << infoTugas(T).NamaTugas << "\t|"
            << infoTugas(T).DeskripsiTugas << "\t\t\t|" << infoTugas(T).DurasiTugas << "\t|" << statusT << "\t| \n";
        }
        T = nextTugas(T);
    }
    printf("-----------------------------------------------------------------\n");
}
void SearchDurasiTugas(MLL &M, adrProject P,int x){
    string status;
    if(infoProject(P).ProjectSelesai){
        status = "Selesai";
    } else {
        status = "Berjalan";
    }
    printf("-----------------------------------------------------------------\n");
    cout << "Project " << infoProject(P).IDProject << endl << "Kepala Project : " << infoProject(P).NamaProject << endl <<
    "Deskripsi Project : " << infoProject(P).DeskripsiProject << endl << "Durasi Project : " << infoProject(P).DurasiProject <<
    endl << "Status Project : " << status << endl;
    adrTugas T = FirstTugas(P);
    if (T != NULL){
        printf("-----------------------------------------------------------------\n");
        printf("%s\t|%s\t|%s\t\t|%s\t|%s\t\t|\n","ID", "Nama", "Deskripsi", "Durasi", "Status");
    }
    while (T != NULL){
        if(infoTugas(T).DurasiTugas == x){
            string statusT;
            if (infoTugas(T).TugasSelesai){
                statusT = "Selesai";
            } else {
                statusT = "Berjalan";
            }
            cout << infoTugas(T).IDTugas << "\t|" << infoTugas(T).NamaTugas << "\t|"
            << infoTugas(T).DeskripsiTugas << "\t\t\t|" << infoTugas(T).DurasiTugas << "\t|" << statusT << "\t| \n";
        }
        T = nextTugas(T);
    }
    printf("-----------------------------------------------------------------\n");
}

void SearchStatusTugas(MLL &M, adrProject P, bool x){
    string status;
    if(infoProject(P).ProjectSelesai){
        status = "Selesai";
    } else {
        status = "Berjalan";
    }
    printf("-----------------------------------------------------------------\n");
    cout << "Project " << infoProject(P).IDProject << endl << "Kepala Project : " << infoProject(P).NamaProject << endl <<
    "Deskripsi Project : " << infoProject(P).DeskripsiProject << endl << "Durasi Project : " << infoProject(P).DurasiProject <<
    endl << "Status Project : " << status << endl;
    adrTugas T = FirstTugas(P);
    if (T != NULL){
        printf("-----------------------------------------------------------------\n");
        printf("%s\t|%s\t|%s\t\t|%s\t|%s\t\t|\n","ID", "Nama", "Deskripsi", "Durasi", "Status");
    }
    while (T != NULL){
        if(infoTugas(T).TugasSelesai == x){
            string statusT;
            if (infoTugas(T).TugasSelesai){
                statusT = "Selesai";
            } else {
                statusT = "Berjalan";
            }
            cout << infoTugas(T).IDTugas << "\t|" << infoTugas(T).NamaTugas << "\t|"
            << infoTugas(T).DeskripsiTugas << "\t\t\t|" << infoTugas(T).DurasiTugas << "\t|" << statusT << "\t| \n";
        }
        T = nextTugas(T);
    }
    printf("-----------------------------------------------------------------\n");
}

