#include <iostream>
#include <string>
#include <cstdlib> 
#include <fstream>
#include <windows.h>

using namespace std;
class Muzyka
{
	public:
		void set_tytul(string t)
		{
			tytul_m = t;	
		}
		void set_autor(string a)
		{
			autor_m = a;	
		}
		void set_gatunek(string g)
		{
			gatunek_m = g;	
		}
		string get_tytul()
		{
			return tytul_m;	
		}
		string get_autor()
		{
			return autor_m;	
		}
		string get_gatunek()
		{
			return gatunek_m;	
		}
	private:
		string tytul_m;
		string autor_m;
		string gatunek_m;
	public:
		static const int MAX_M;
		
};
int const Muzyka::MAX_M=100;
Muzyka muzyka[Muzyka::MAX_M];

class Aktor
{
	public:
		void set_wiek(int rok_biezacy,int rok_urodzenia)
		{
			wiek = rok_biezacy - rok_urodzenia;
		}
		int get_wiek()
		{
			return wiek;
		}
		void set_imie_naz(string t)
		{
			imie_i_nazwisko = t;
		}
		void set_wzrost(int a)
		{
			wzrost = a;
		}
		string get_imie_naz()
		{
			return imie_i_nazwisko;	
		}
		int get_wzrost()
		{
			return wzrost;	
		}

	private:
		string imie_i_nazwisko;
		int wiek;
		int wzrost;
	public:
		static const int MAX_A;
		
};
int const Aktor::MAX_A=100;
Aktor aktor[Aktor::MAX_A];

class Film
{
	public:
		void set_tytul(string a)
		{
			tytul = a;	
		}
		void set_rezysera(string a)
		{
			rezyser = a;	
		}
		void set_gatunek(string a)
		{
			gatunek = a;	
		}
		void set_rok(int a)
		{
			rok = a;	
		}
		void set_obejrzany(string a)
		{
			obejrzany = a;	
		}
		void set_ocene(int a)
		{
			ocena = a;
		}
		
		string get_tytul()
		{
			return tytul;	
		}
		string get_rezysera()
		{
			return rezyser;	
		}
		string get_gatunek()
		{
			return gatunek;	
		}
		int get_rok()
		{
			return rok;	
		}
		string get_obejrzany()
		{
			return obejrzany;	
		}
		int get_ocene()
		{
			return ocena;	
		}
	public:
		string tytul;
		string rezyser;
		string gatunek;
		int rok;
		string obejrzany;
		int ocena;
	public:
		static const int MAX_F;
};
int const Film::MAX_F=100;
Film filmy[Film::MAX_F];

class Manager
{
	public:
		int id;
	public:
	int sprawdz_id()
	{
		id = 0;
		ofstream plik("filmy.txt", ios::app);
		if(plik.good())
		{
			plik.close();
		}
		string wiersz;
		ifstream odczyt("filmy.txt");
		if(odczyt.good())
		{
		  	while(getline(odczyt, wiersz))
		  	{
		  		id++;
		  	} 
			id = (id/6);
		}
		odczyt.close();
		return id;
	}
};

class Manager_Operacji
{
	public:
	virtual void add_film(int id) = 0;
	virtual void baza_filmow(int id) = 0;
	virtual void delete_film(int id) = 0;
};

class Operacje_na_plikach: public Manager
{
	public:	
	void zapisz_do_pliku(int id)
	{
		ofstream plik1 ("filmy.txt", ios::app); 
		if(plik1.is_open()) 
		{ 
			plik1 << filmy[id].get_tytul() << endl; 
			plik1 << filmy[id].get_rezysera() << endl; 
			plik1 << filmy[id].get_gatunek() << endl;
			plik1 << filmy[id].get_rok() << endl;
			plik1 << filmy[id].get_obejrzany() << endl;
			plik1 << filmy[id].get_ocene() << endl;
		}
		else
		{
			cout << "Error";
		} 
		plik1.close();
		
		ofstream plik2 ("muzyka.txt", ios::app); 
		if(plik2.is_open()) 
		{ 
			plik2 << muzyka[id].get_tytul() << endl;
			plik2 << muzyka[id].get_autor() << endl; 
			plik2 << muzyka[id].get_gatunek() << endl;
		}
		else
		{
			cout << "Error";
		} 
		plik2.close();
		
		ofstream plik3 ("aktor.txt", ios::app); 
		if(plik3.is_open()) 
		{ 
			plik3 << aktor[id].get_imie_naz() << endl;
			plik3 << aktor[id].get_wiek() << endl; 
			plik3 << aktor[id].get_wzrost() << " cm" << endl; 
		}
		else
		{
			cout << "Error";
		} 
		plik3.close();
		
		cout << endl;	
	}
	
	void wczytaj_z_pliku(int id)
	{
		if(id!=0)
		{
			cout << endl;
			cout << "Baza filmow:"<< endl;
			string wiersz;
			string Tab_fil[6]={"Tytul:        ","Rezyser:      ","Gatunek:      ","Rok produkcji:","Obejrzany:    ","Ocena:        "};
			string Tab_muz[3]={"Tytul muzyki:  ","Autor muzyki:  ","Gatunek muzyki:"};
			string Tab_akt[3]={"Imie i naz. aktora:","Wiek aktora:       ","Wrost aktora:      "};
			for(int nr = 1; nr<=id; nr++)
			{
				int w=0;
				cout << nr << "." << endl;
				int warunek = 0;
				ifstream odczyt1("filmy.txt");
				if(odczyt1.good())
				{
			  			while(getline(odczyt1, wiersz))
			  			{
			  				if((warunek>=nr*6-6)&&(warunek<nr*6))
			  				{
			  					cout<<Tab_fil[w]<<"       "<< wiersz << endl;
			  					w++;
			  					warunek++;
			  				}
			  				else
			  				{
			  					warunek++;
			  				}
			  			} 
				}
				odczyt1.close();
				warunek=0;
				w=0;
				ifstream odczyt2("muzyka.txt");
				if(odczyt2.good())
				{
			  			while(getline(odczyt2, wiersz))
			  			{
							if((warunek>=nr*3-3)&&(warunek<nr*3))
			  				{
			  					cout<<Tab_muz[w]<<"      "<< wiersz << endl;
			  					w++;
			  					warunek++;
			  				}
			  				else
			  				{
			  					warunek++;
			  				}
			  			} 
				}
				odczyt2.close();
				warunek=0;
				w=0;
				ifstream odczyt3("aktor.txt");
				if(odczyt3.good())
				{
			  			while(getline(odczyt3, wiersz))
			  			{
							if((warunek>=nr*3-3)&&(warunek<nr*3))
			  				{
			  					cout<<Tab_akt[w]<<"  "<< wiersz << endl;
			  					w++;
			  					warunek++;
			  				}
			  				else
			  				{
			  					warunek++;
			  				}
			  			} 
				}
				odczyt3.close();
			}
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "Brak filmow w bazie..." << endl;
		}
	}
	void wypisz_same_filmy()
	{
		string wiersz;
		int warunek = 0;
		int nr = 1;
		ifstream odczyt("filmy.txt");
		if(odczyt.good())
		{
			cout << "===================================" << endl;
			  	while(getline(odczyt, wiersz))
			  	{
			  		if(warunek == 0)
			  		{
			  			warunek=5; 
			  			cout << nr << ".   " << wiersz << endl;
			  			nr++;
			  		}
			  		else
			  		{
			  			warunek--;
			  		}
			  	} 
			  	cout << "===================================" << endl;
		}
		else
		{
			cout << "Error";
		} 
		odczyt.close();
		cout << endl;
	}
};

class Operacje: public Manager, Operacje_na_plikach, Manager_Operacji
{
	public:
		int rok_biezacy;
	void add_film(int id)
	{
		if(id==100)
		{
			cout << endl;
			cout << "Baza filmow pelna!"<<endl;
		}
		else
		{
			cout << endl;
			cout << "Tytul: ";
			string tytul;
			getline(cin,tytul);
			while(tytul=="")
			{
				cout << "Tytul: ";
				getline(cin,tytul);
			}
			filmy[id].set_tytul(tytul);
			cout << "Rezyser: ";
			string rezyser;
			getline(cin,rezyser);
			while(rezyser=="")
			{
				cout << "Rezyser: ";
				getline(cin,rezyser);
			}
			filmy[id].set_rezysera(rezyser);
			cout << "Gatunek: ";
			string gatunek;
			getline(cin,gatunek);
			while(gatunek=="")
			{
				cout << "Gatunek: ";
				getline(cin,gatunek);
			}
			filmy[id].set_gatunek(gatunek);
			cout << "Rok produkcji: ";
			int rok;
			while(!(cin>>rok) || !(rok<=2050) || !(rok>=1800))
			{
		  		cout << "Rok produkcji: ";
		  		cin.clear();
		  		cin.sync();
			}
			filmy[id].set_rok(rok);
			int x = 0;
			string obejrzany;
			while(x==0)
			{
				cout << "Obejrzany? (tak/nie): ";
				cin >> obejrzany;
		  		if(obejrzany=="tak")
				{
					filmy[id].set_obejrzany(obejrzany);
					x++;
					cout << "Ocena (od 1 do 10): ";
					int ocena;
					while(!(cin>>ocena) || !(ocena<=10) || !(ocena>=1))
					{
				  		cout << "Ocena (od 1 do 10): ";
				  		cin.clear();
				  		cin.sync();
					}
					filmy[id].set_ocene(ocena);
				}
				else if(obejrzany=="nie")
				{
					filmy[id].set_obejrzany(obejrzany);
					filmy[id].set_ocene(0);
					x++;
				}
		  		cin.clear();
		  		cin.sync();
			}
			cout<<"MUZYKA Z FILMU"<<endl;
			cout<<"Podaj tytul: ";
			string ttytul;
			getline(cin,ttytul);
			while(ttytul=="")
			{
				cout << "Podaj tytul: ";
				getline(cin,ttytul);
			}
			muzyka[id].set_tytul(ttytul);
			cout<<"Podaj autora: ";
			string aautor;
			getline(cin,aautor);
			while(aautor=="")
			{
				cout << "Podaj autora: ";
				getline(cin,aautor);
			}
			muzyka[id].set_autor(aautor);
			cout<<"podaj gatunek: ";
			string ggatunek;
			getline(cin,ggatunek);
			while(ggatunek=="")
			{
				cout << "Podaj gatunek: ";
				getline(cin,ggatunek);
			}
			muzyka[id].set_gatunek(ggatunek);
			
			cout<<"AKTOR"<<endl;
			cout<<"Podaj imie i nazwisko aktora: ";
			string imie_naz;
			getline(cin,imie_naz);
			while(imie_naz=="")
			{
				cout << "Podaj imie i nazwisko aktora: ";
				getline(cin,imie_naz);
			}
			aktor[id].set_imie_naz(imie_naz);
			cout<<"Podaj rok urodzenia aktora: ";
			int rok_urodzenia;
			while(!(cin>>rok_urodzenia) || !(rok_urodzenia<=2015) || !(rok_urodzenia>=1800))
			{
		  		cout << "Podaj poprawny rok urodzenia aktora ";
		  		cin.clear();
		  		cin.sync();
			}
			aktor[id].set_wiek(rok_biezacy,rok_urodzenia);
			cout<<"podaj wzrost aktora (cm): ";
			int wzrost;
			while(!(cin>>wzrost) || !(wzrost<=250) || !(wzrost>=30))
			{
		  		cout << "Podaj poprawny wzrost aktora (cm): ";
		  		cin.clear();
		  		cin.sync();
			}
			aktor[id].set_wzrost(wzrost);
			zapisz_do_pliku(id);
			cout << "Film zostal dodany do bazy filmow..." << endl;
		}

	}
	
	
	void baza_filmow(int id)
	{
		wczytaj_z_pliku(id);
	}
	
	
	void delete_film(int id)
	{
		int nr_filmu;
		if(id==0)
		{
			cout << endl;
			cout << "Nie mozesz usunac filmu, poniewaz baza filmow jest pusta..." << endl;
		}
		else
		{
			cout << endl;
			wypisz_same_filmy();
			
			cout << "Podaj numer filmu, ktory chcesz usunac ('0' aby anulowac): ";
			while(!(cin>>nr_filmu) || !(nr_filmu>-1) || !(nr_filmu<=id))
			{
				cout << "Podaj poprawny numer filmu, ktory chcesz usunac('0' aby anulowac): ";
				cin.clear();
				cin.sync();
			}
			if(nr_filmu==0){
			}
			else
			{
				string wiersz;
				string T_F[1000];
				string T_M[1000];
				string T_A[1000];
				int y = 0;

				ifstream odczyt("muzyka.txt");
				if(odczyt.good())
				{
				  	while(getline(odczyt, wiersz))
				  	{
				  		T_M[y] = wiersz;
				  		y++;
				  	}
				}
				odczyt.close();
				y=0;
				ifstream odczyt1("aktor.txt");
				if(odczyt1.good())
				{
				  	while(getline(odczyt1, wiersz))
				  	{
				  		T_A[y] = wiersz;
				  		y++;
				  	}
				}
				odczyt1.close();
				y=0;
				ifstream odczyt2("filmy.txt");
				if(odczyt2.good())
				{
				  	while(getline(odczyt2, wiersz))
				  	{
				  		T_F[y] = wiersz;
				  		y++;
				  	}
				}
				odczyt2.close();
				int k=0;
				ofstream plik ("filmy.txt", ios::trunc); 
				if(plik.is_open()) 
				{
					for(k; k<y; k=k+6)
					{
						if(k!=((nr_filmu*6)-6))
						{
							plik << T_F[k] << endl; 
							plik << T_F[k+1] << endl;
							plik << T_F[k+2] << endl;
							plik << T_F[k+3] << endl;
							plik << T_F[k+4] << endl;
							plik << T_F[k+5] << endl;
						}		
					}		
				} 
				else
				{
					cout << "Error";
				}
				k=0;
				ofstream plik2 ("muzyka.txt", ios::trunc); 
				if(plik2.is_open()) 
				{
					for(k; k<y/2; k=k+3)
					{
						if(k!=((nr_filmu*3)-3))
						{
							plik2 << T_M[k] << endl; 
							plik2 << T_M[k+1] << endl;
							plik2 << T_M[k+2] << endl;
						}	
					}		
				} 
				else
				{
					cout << "Error";
				}
				k=0;
				ofstream plik3 ("aktor.txt", ios::trunc); 
				if(plik3.is_open()) 
				{
					for(k; k<y/2; k=k+3)
					{
						if(k!=((nr_filmu*3)-3))
						{
							plik3 << T_A[k] << endl; 
							plik3 << T_A[k+1] << endl;
							plik3 << T_A[k+2] << endl;
						}		
					}		
				} 
				else
				{
					cout << "Error";
				} 
				plik.close();
				cout << endl;
				cout << "Film nr " << nr_filmu << " zostal usuniety z bazy filmow..." << endl;
				id--;
			}
		}
	}
};

class Menu
{
	public:
	int wybor;
	void wyswietl(string tab[], int MAX_LICZBA_OPCJI, string nazwa_menu)
	{
		for(int i = 0; i<MAX_LICZBA_OPCJI; i++)
		{
			if(i==0)
			{
				cout<<endl;
				cout<<"========================================="<<endl;
				cout<<" "<<nazwa_menu<<endl;
			}
			cout<<"["<<i+1<<"] "<<tab[i]<<endl;
			if(i==MAX_LICZBA_OPCJI-1)
			{
				cout<<"========================================="<<endl;
			}
		}
	}

	void wczytaj_wybor_uz(int wwybor, int liczba_opcji)
	{
		cout << "Wybierz numer: ";
			
		while(!(cin>>wwybor) || !(wwybor<=liczba_opcji) || !(wwybor>=1))
		{
	  		cout << "Wybierz numer: ";
		  		cin.clear();
		  		cin.sync();
		}
		cin.ignore();
		wybor = wwybor;
	}
	
	int get_wybor()
	{
		return wybor;
	}
	
	void add_opcje(string opcje[], string opcja, int liczba)
	{
		opcje[liczba++] = opcja;
		
	}
};

class Menu_Glowne : public Menu
{
	public:
			int liczba_opcji = 0;
			static const int MAX_LICZBA_OPCJI = 5;
			string opcje[MAX_LICZBA_OPCJI];
			int gmwybor;
};

class Statystyka : public Menu, Manager
{
	public:
		int liczba_opcji = 0;
		static const int MAX_LICZBA_OPCJI = 7;
		static const int MAX_LICZBA_FILMOW = 1000;
		static const int MAX_LICZBA_AKTOROW = 1000;
		string opcje[MAX_LICZBA_OPCJI];
		int swybor;
		int rok;
		string Tab_f[MAX_LICZBA_FILMOW];
		string Tab_a[MAX_LICZBA_AKTOROW];
		
		void wypelnij_tablice_filmow()
		{
			int y=0;
			string wiersz;
				
			ifstream odczyt("filmy.txt");
			if(odczyt.good())
			{
			  	while(getline(odczyt, wiersz))
			 	{
			  		Tab_f[y++]=wiersz;
			  	}
			}
			odczyt.close();
		}
		void wypelnij_tablice_aktorow()
		{
			int y=0;
			string wiersz;
				
			ifstream odczyt("aktor.txt");
			if(odczyt.good())
			{
			  	while(getline(odczyt, wiersz))
			 	{
			  		Tab_a[y++]=wiersz;
			  	}
			}
			odczyt.close();
		}
		
		void ranking(int id)
		{
			if(id!=0)
			{
				string Tab_ocena[10]={"10","9","8","7","6","5","4","3","2","1"};
				cout<<endl;
				cout<<"RANKING"<<endl<<endl;
				cout<<"ocena             tytul"<<endl;
				cout<<"========================================="<<endl;
				for(int z=0; z<10; z++)
				{
					for(int i=5; i<id*6; i=i+6)
					{
						if(Tab_f[i]==Tab_ocena[z])
						{
							if(z==0)
							cout<<" "<<Tab_ocena[z]<<"               "<<Tab_f[i-5]<<endl;
							else
							cout<<"  "<<Tab_ocena[z]<<"               "<<Tab_f[i-5]<<endl;
						}
					}
				}
				cout<<"========================================="<<endl;
			}
			else
			cout<<endl<<"Brak filmow w bazie..."<<endl;
		}
		
		
		void wyszukaj_rok(int id)
		{
			if(id!=0)
			{
				cout << endl;
				cout << "Podaj rok: ";
				while(!(cin>>rok) || !(rok<=2050) || !(rok>=1800))
				{
			  		cout << "Podaj poprawny rok produkcji: ";
			  		cin.clear();
			  		cin.sync();
				}
				int czypusty=0;
				int nr=1;
				char rokx[10];
				sprintf(rokx,"%i",rok);
				string rok_napis=rokx;
				
				cout << endl;
				cout << "Filmy z "<<rok << " roku:" << endl;
				
				for(int i=3; i<id*6; i=i+6)
				{
					if(Tab_f[i]==rok_napis)
					{
						if(czypusty==0)
			  			{
			  				cout << "=========================================" << endl;
			  			}
						cout<<nr<<".  "<<Tab_f[i-3]<<endl;
						czypusty++;
						nr++;
					}
				}
				if(czypusty!=0)
				{
				  	cout << "=========================================" << endl;
				}
				if(czypusty==0)
				{
					cout << endl;
					cout << "Brak filmow o podanym roku produkcji..."<< endl;
				}
			}
			else
			cout<<endl<<"Brak filmow w bazie..."<<endl;
		}
		
		void obejrzane(int id, string obejrzane, string napis1, string napis2)
		{
			if(id!=0)
			{
				int czypusty=0;
				int nr=1;
				cout << endl;
				cout << "Filmy "<<napis2<<":"<< endl;
				
				for(int i=4; i<id*6; i=i+6)
				{
					if(Tab_f[i]==obejrzane)
					{
						if(czypusty==0)
			  			{
			  				cout << "=========================================" << endl;
			  			}
						cout<<nr<<".  "<<Tab_f[i-4]<<endl;
						czypusty++;
						nr++;
					}
				}
				if(czypusty!=0)
				{
				  	cout << "=========================================" << endl;
				}
				if(czypusty==0)
				{
					cout << endl;
					cout << "Brak filmow "<<napis1<<"..."<< endl;
				}
			}
			else
			cout<<endl<<"Brak filmow w bazie..."<<endl;
		}
		
		void gatunek(int id)
		{
			if(id!=0)
			{
				int czypusty=0;
				int nr=1;
				string gatunek;
				cout<<endl;
				cout<<"Podaj gatunek: ";
				cin>>gatunek;
				cout << endl;
				cout << "Filmy z gatunku "<<gatunek<<":"<< endl;
				
				for(int i=2; i<id*6; i=i+6)
				{
					if(Tab_f[i]==gatunek)
					{
						if(czypusty==0)
			  			{
			  				cout << "=========================================" << endl;
			  			}
						cout<<nr<<".  "<<Tab_f[i-2]<<endl;
						czypusty++;
						nr++;
					}
				}
				if(czypusty!=0)
				{
				  	cout << "=========================================" << endl;
				}
				if(czypusty==0)
				{
					cout << endl;
					cout<<"Brak filmow z podanym gatunkiem..."<< endl;
				}
			}
			else
			cout<<endl<<"Brak filmow w bazie..."<<endl;
		}
		void aktor(int id)
		{
			if(id!=0)
			{
				int czypusty=0;
				int nr=1;
				string aktor;
				cout<<endl;
				cout<<"Podaj imie i nazwisko aktora: ";
				getline(cin,aktor);
				cout << endl;
				cout << "Filmy z podanym aktorem: "<< endl;
				
				for(int i=0; i<id*3; i=i+3)
				{
					if(Tab_a[i]==aktor)
					{
						if(czypusty==0)
			  			{
			  				cout << "=========================================" << endl;
			  			}
						cout<<nr<<".  "<<Tab_f[i*2]<<endl;
						czypusty++;
						nr++;
					}
				}
				if(czypusty!=0)
				{
				  	cout << "=========================================" << endl;
				}
				if(czypusty==0)
				{
					cout << endl;
					cout << "Brak filmow z podanym aktorem..."<< endl;
				}
			}
			else
			cout<<endl<<"Brak filmow w bazie..."<<endl;
		}
};

int main()
{
	Operacje op;
	Manager manager;
	manager.sprawdz_id();
	Menu_Glowne glowne_menu;
	Statystyka statystyki;
	Aktor aktor;
	SYSTEMTIME st;
   	GetLocalTime(&st);
   	int rok_biezacy=st.wYear;
   	op.rok_biezacy=rok_biezacy;
	
	glowne_menu.add_opcje(glowne_menu.opcje,"DODAJ FILM",glowne_menu.liczba_opcji);
	glowne_menu.liczba_opcji++;
	glowne_menu.add_opcje(glowne_menu.opcje,"USUN FILM",glowne_menu.liczba_opcji);
	glowne_menu.liczba_opcji++;
	glowne_menu.add_opcje(glowne_menu.opcje,"BAZA FILMOW",glowne_menu.liczba_opcji);
	glowne_menu.liczba_opcji++;
	glowne_menu.add_opcje(glowne_menu.opcje,"STATYSTYKI",glowne_menu.liczba_opcji);
	glowne_menu.liczba_opcji++;
	glowne_menu.add_opcje(glowne_menu.opcje,"WYJSCIE",glowne_menu.liczba_opcji);
	glowne_menu.liczba_opcji++;
	
	
	statystyki.add_opcje(statystyki.opcje,"RANKING",statystyki.liczba_opcji);
	statystyki.liczba_opcji++;
	statystyki.add_opcje(statystyki.opcje,"WYSZUKAJ FILMU WG. ROKU PRODUKCJI",statystyki.liczba_opcji);
	statystyki.liczba_opcji++;
	statystyki.add_opcje(statystyki.opcje,"WYSZUKAJ FILMY NIEOBEJRZANE",statystyki.liczba_opcji);
	statystyki.liczba_opcji++;
	statystyki.add_opcje(statystyki.opcje,"WYSZUKAJ FILMY OBEJRZANE",statystyki.liczba_opcji);
	statystyki.liczba_opcji++;
	statystyki.add_opcje(statystyki.opcje,"WYSZUKAJ FILMY WG GATUNKU",statystyki.liczba_opcji);
	statystyki.liczba_opcji++;
	statystyki.add_opcje(statystyki.opcje,"WYSZUKAJ FILMY Z PODANY AKTOREM",statystyki.liczba_opcji);
	statystyki.liczba_opcji++;
	statystyki.add_opcje(statystyki.opcje,"POWROT DO MENU",statystyki.liczba_opcji);
	statystyki.liczba_opcji++;
	int warunek1=1;
	while(warunek1==1)
	{
		glowne_menu.wyswietl(glowne_menu.opcje,glowne_menu.MAX_LICZBA_OPCJI, "MENU");
		glowne_menu.wczytaj_wybor_uz(glowne_menu.gmwybor, glowne_menu.liczba_opcji);
		switch(glowne_menu.get_wybor())
		{
			case 1: op.add_film(manager.sprawdz_id()); break;
			case 2: op.delete_film(manager.sprawdz_id()); break;
			case 3: op.baza_filmow(manager.sprawdz_id()); break;
			case 4:
			{
				int warunek=1;
				statystyki.wypelnij_tablice_filmow();
				statystyki.wypelnij_tablice_aktorow();
				while(warunek==1)
				{
					statystyki.wyswietl(statystyki.opcje,statystyki.MAX_LICZBA_OPCJI, "STATYSTYKI");
					statystyki.wczytaj_wybor_uz(statystyki.swybor,statystyki.liczba_opcji);
					switch(statystyki.get_wybor())
					{
						case 1: statystyki.ranking(manager.sprawdz_id()); break;
						case 2: statystyki.wyszukaj_rok(manager.sprawdz_id()); break;
						case 3: statystyki.obejrzane(manager.sprawdz_id(),"nie","nieobejrzanych","nieobejrzane"); break;
						case 4: statystyki.obejrzane(manager.sprawdz_id(),"tak","obejrzanych","obejrzane"); break;
						case 5: statystyki.gatunek(manager.sprawdz_id()); break;
						case 6: statystyki.aktor(manager.sprawdz_id()); break;
						case 7: warunek=0;
					}
				}
			}; break;
			case 5: warunek1=0;
		}
	}
	
	
}


