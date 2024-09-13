#include <iostream>
#include <fstream>

using namespace std;
	
	struct libro
	{
		string nome;
		string autore;
		string editore;
		int dataPubblicazione;
		float prezzo;
	};
	
	struct scaffale
	{
		int numeroLibri;
		libro libri[40];
	};
	
	scaffale biblioteca[10][8];

int menu()
{
	int scelta;
    cout<<"[0] Chiudere il programma!\n";
    cout<<"[1] Inserire un libro!\n";
    cout<<"[2] Trovare un libro in una data posizione!\n";
    cout<<"[3] Trovare un libro in base all'autore!\n";
    cout<<"[4] Trovare un libro in base al titolo!\n";
    cout<<"[5] Stampare tutti i libri dato un autore!\n";
    cout<<"[6] Stampare tutti i libri dato l'anno di pubblicazione (indicazione posizione)!\n";
    cout<<"[7] Calcolare il valore della biblioteca!\n";
    cout<<"[8] Salvare i dati su un file!\n";
    cout<<"[9] Aggiornare la libreria da file!\n";
    
	cin>>scelta;

    return scelta; 	
}

void inserimentoLibri(int &scf,int &sc,int &nLib,int maxScf,int maxSc,int maxLib,int &libIns,int &scIns,int &scfIns)
{
	fflush(stdin);
	cout<<"\tInserimento libro\n";
	cout<<"Nome:";
	cin>>biblioteca[scf][sc].libri[nLib].nome;
	cout<<"\nAutore:";
	cin>>biblioteca[scf][sc].libri[nLib].autore;
	cout<<"\nCasa Editrice:";
	cin>>biblioteca[scf][sc].libri[nLib].editore;
	cout<<"\nData di pubblicazione:";
	cin>>biblioteca[scf][sc].libri[nLib].dataPubblicazione;
	cout<<"\nPrezzo:";
	cin>>biblioteca[scf][sc].libri[nLib].prezzo;
	fflush(stdin);
	cout<<"\nSalvataggio libro...\n";
	cout<<"Libro Salvato!";
	
	libIns++;
	if(libIns==maxLib)
	{
		libIns=0;
		scIns++;
	}
	if(scIns==maxSc)
	{
		scIns=0;
		scfIns++;
	}
	if(scfIns>maxScf)
	{
		cout<<"\nLa Biblioteca e' attualmente piena!\n";
	}
	
}

void trovaLibro(int scfIns,int sfIns,int libIns)
{
	int i,j,q;
	cout<<"Indicare la scaffalatura in cui si trova il libro:";
	cin>>i;
	cout<<"\nindicare lo scaffale in cui si trova il libro:";
	cin>>j;
	cout<<"\nIndicare la posizione del libro:";
	cin>>q;
	if(i<=scfIns && j<=sfIns && q<=libIns)
	{
	    cout<<"\nRisultato:\n\n";
	    cout<<"Nome:\t"<<biblioteca[i][j].libri[q].nome<<"\n";
	    cout<<"Autore:\t"<<biblioteca[i][j].libri[q].autore<<"\n";
	    cout<<"Casa editrice:\t"<<biblioteca[i][j].libri[q].editore<<"\n";
	    cout<<"Anno di pubblicazione:\t"<<biblioteca[i][j].libri[q].dataPubblicazione<<"\n";
	    cout<<"Prezzo:\t"<<biblioteca[i][j].libri[q].prezzo<<"\n";
    }
    else
    {
    	cout<<"\nLa posizione indicata non ha nessun libro assegnato\n";
	}
	
	return;
}

void trovaAutore(int scf,int sc,int nLib)
{
	string ricercato;
	int i=0,j=0,q=0;
	
	cout<<"inserire parola:\n";
	fflush(stdin);
	cin>>ricercato;
	fflush(stdin);
	
	for(i=0;i<=scf;i++)
		{
		for(j=0;j<=sc;j++)
			{
			for(q=0;q<=nLib;q++)
				{
                  if(ricercato==biblioteca[i][j].libri[q].autore)
				  {
				  	cout<<"Nome:\t"<<biblioteca[i][j].libri[q].nome<<"\n";
	                cout<<"Autore:\t"<<biblioteca[i][j].libri[q].autore<<"\n";
	                cout<<"Casa editrice:\t"<<biblioteca[i][j].libri[q].editore<<"\n";
	                cout<<"Anno di pubblicazione:\t"<<biblioteca[i][j].libri[q].dataPubblicazione<<"\n";
	                cout<<"Prezzo:\t"<<biblioteca[i][j].libri[q].prezzo<<"\n";
				  }					
                }
            }
        }	
	return;
}

void trovaTitolo(int scf,int sc,int nLib)
{
	string ricercato;
	int i=0,j=0,q=0;
	
	cout<<"inserire parola:\n";
	fflush(stdin);
	cin>>ricercato;
	fflush(stdin);
	
	for(i=0;i<=scf;i++)
		{
		for(j=0;j<=sc;j++)
			{
			for(q=0;q<=nLib;q++)
				{
                  if(ricercato==biblioteca[i][j].libri[q].nome)
				  {
				  	cout<<"Nome:\t"<<biblioteca[i][j].libri[q].nome<<"\n";
	                cout<<"Autore:\t"<<biblioteca[i][j].libri[q].autore<<"\n";
	                cout<<"Casa editrice:\t"<<biblioteca[i][j].libri[q].editore<<"\n";
	                cout<<"Anno di pubblicazione:\t"<<biblioteca[i][j].libri[q].dataPubblicazione<<"\n";
	                cout<<"Prezzo:\t"<<biblioteca[i][j].libri[q].prezzo<<"\n";
				  }					
                }
            }
        }	
	return;
}

void trovaAnno(int scf,int sc,int nLib)
{
	int ricercato;
	int i=0,j=0,q=0;
	
	cout<<"inserire parola:\n";
	fflush(stdin);
	cin>>ricercato;
	fflush(stdin);
	
	for(i=0;i<=scf;i++)
		{
		for(j=0;j<=sc;j++)
			{
			for(q=0;q<=nLib;q++)
				{
                  if(ricercato==biblioteca[i][j].libri[q].dataPubblicazione)
				  {
				  	cout<<"Nome:\t"<<biblioteca[i][j].libri[q].nome<<"\n";
	                cout<<"Autore:\t"<<biblioteca[i][j].libri[q].autore<<"\n";
	                cout<<"Casa editrice:\t"<<biblioteca[i][j].libri[q].editore<<"\n";
	                cout<<"Anno di pubblicazione:\t"<<biblioteca[i][j].libri[q].dataPubblicazione<<"\n";
	                cout<<"Prezzo:\t"<<biblioteca[i][j].libri[q].prezzo<<"\n";
	                cout<<"\n\nIl libro sta nella scaffalatura n."<<i<<", nello scaffale n."<<j<<", nella posizione n."<<q;
				  }					
                }
            }
        }	
	return;
}

float valoreBiblio(int scf,int sc,int nLib)
{
	int i=0,j=0,q=0;
	float somma=0;
	for(i=0;i<=scf;i++)
		{
		for(j=0;j<=sc;j++)
			{
			for(q=0;q<=nLib;q++)
				{
                  somma=somma+biblioteca[i][j].libri[q].prezzo;					
                }
            }
        }
    return somma;
}

//la stampa funziona ma c'e' bisogno di interromperla e che non vadano avanti i contatori
//inserire contatore nella funzione di inserimento che tenga conto di quanti libri si ha inserito
void stampaSuFile(int scf,int sc,int nLib,fstream &file)
{
	fstream file1;
    int i=0,j=0,q=0;

	file.open("bbl.txt",ios::out);
	
		for(i=0;i<=scf;i++)
		{
			for(j=0;j<=sc;j++)
			{
				for(q=0;q<=nLib;q++)
				{
					 file<<biblioteca[i][j].libri[q].nome<<"\t";
					 file<<biblioteca[i][j].libri[q].autore<<"\t";
                     file<<biblioteca[i][j].libri[q].editore<<"\t";
					 file<<biblioteca[i][j].libri[q].dataPubblicazione<<"\t";
					 file<<biblioteca[i][j].libri[q].prezzo<<"\n";					
					if(q==40)
					{
						q=0;
					}
				}
				if(j==10)
				{
					j=0;
				}
				if(i==8)
				{
					cout<<"\nLibreria piena!\n";
				}
			}	
		}
	file.close();	
	return;		
}

void caricaDaFile(fstream &file,int &nLib,int &nScaf,int &nScaffalature)
{
	int i=0,j=0,q=0;
	file.open("catalogo.txt",ios::in);
	cout<<"\nCaricando da file...";
	
	while(!file.eof())
	{
	    file>>biblioteca[i][j].libri[q].nome;
		file>>biblioteca[i][j].libri[q].autore;
        file>>biblioteca[i][j].libri[q].editore;
		file>>biblioteca[i][j].libri[q].dataPubblicazione;
		file>>biblioteca[i][j].libri[q].prezzo;			
		
		q++;
		
		if(q==40)
		{
			j++; 
		}
		if(j==10)
		{
			i++;
		}
		if(i==8)
		{
			cout<<"\nLibreria totalmente riempita!";
		}
	}
	file.close();
	
	nLib=q;
	nScaf=j;
	nScaffalature=i;
	
	return;
}

bool rp()
{
	char scelta;
	system("cls");
	cout<<"Si ha finito o si desidera fare altro? [S/N]\n";
	cin>>scelta;
	if(scelta=='s' || scelta=='S')
	{
		return true;
	}
	if(scelta=='n' || scelta=='N')
	{
		return false;
    }
   return false; 
}
		
int main()
{
	int const nLibri=40;
	int const nScaffalature=10;
	int const nScaffali=8;
	int libriIns=0;
	int scaffalatura=0;
	int scaffale=0;
	int nLibIns=0;
	int nScaffalatureRiem=0;
	int nScaffaliRiem=0;
	fstream file1;
	fstream file2;
	bool rpt;
	float somma;
	
	cout<<"Benvenuti alla biblioteca del kennedy!\n";
	cout<<"Cosa si desidera fare?\n";
	do
	{		
	switch(menu())
	{
		case 0:
			{
				system("cls");
			    cout<<"Grazie per la preferenza accordataci!\n\tArrivederci!";
			    break;	
			}
		case 1:
			{
				system("cls");
				inserimentoLibri(scaffalatura,scaffale,libriIns,nScaffalature,nScaffali,nLibri,nLibIns,nScaffalatureRiem,nScaffaliRiem);
				//stampaSuFile(nScaffaliRiem,nScaffalatureRiem,nLibIns,file1);  //prova
				rpt=rp();
				break;
			}
		case 2:
			{
				system("cls");
				trovaLibro(nScaffalatureRiem,nScaffaliRiem,nLibIns);
				rpt=rp();
				break;
			}
		case 3:
			{
				system("cls");
				trovaAutore(nScaffalatureRiem,nScaffaliRiem,nLibIns);
				rpt=rp();
				break;
			}
		case 4:
			{
				system("cls");
				trovaTitolo(nScaffalatureRiem,nScaffaliRiem,nLibIns);
				rpt=rp();
				break;
			}			
		case 5:
			{
				system("cls");
				trovaAutore(nScaffalatureRiem,nScaffaliRiem,nLibIns);
				rpt=rp();
				break;
			}		
		case 6:
			{
				system("cls");
				trovaAnno(nScaffalatureRiem,nScaffaliRiem,nLibIns);
				rpt=rp();
				break;
			}				
		case 7:
			{
				system("cls");
				somma=valoreBiblio(nScaffalatureRiem,nScaffaliRiem,nLibIns);
				cout<<"Il valore totale della biblioteca e' di: "<<somma<<" euro!\n\n";
				rpt=rp();
				break;
			}
		case 8:
			{
				system("cls");
				stampaSuFile(nScaffali,nScaffalature,nLibri,file1);
				break;
			}
		case 9:
			{
				system("cls");
				caricaDaFile(file2,nLibIns,nScaffaliRiem,nScaffalatureRiem);
				rpt=rp();
				break;
			}									
	}
    }while(rpt);
	
	cout<<"\n";
	system("pause");
	return 0;
}