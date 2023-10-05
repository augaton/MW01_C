#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include "IRLigne.h"
#include "IRClientUDP.h"

using namespace std;

void chiffrement(string message, string & messageChiffre)
{
	string cle = "CyberSecurite";
	for (int i = 0 ; i<message.length() ; i++)
	{
		messageChiffre[i] = message[i] ^ cle[i%cle.length()];
	}
}

int main()
{
  stringstream ss;

  IRLigne ligne;
  IRClientUDP client;

  int recommencer;
  recommencer = 1;

  client.FermerLaSocket();
  while (recommencer == 1){

  float val1, val2, choixoperation, resultat;
  char choix;

  cout << "Tout sur une ligne ou bien en manuel (1 ligne , 2 manuel)" << endl;
  cin >> choixoperation;

  if (choixoperation == 1) {
	  cout << "Saisir le calcul : ";
	  cin >> val1 >> choix >> val2;
  }
  if (choixoperation == 2) {
	 cout << "Saisir une premiere valeur : ";
	 cin >> val1;

	 cout << "Saisir une deuxieme valeur : ";
	 cin >> val2;

	 cout << "Choissisez l'operateur (+, -, /, *, %) : ";
	 cin >> choix;
  }


  switch (choix) {
	case '+':
		resultat = val1 + val2;
		cout << "le resultat est : " << resultat << endl ;
		break;
	case '-':
		resultat = val1 - val2;
		cout << "le resultat est : " << resultat << endl ;
		break;
	case '/':
		resultat = val1 / val2;
		cout << "le resultat est : " << resultat << endl ;
		break;
	case '*':
		resultat = val1 * val2;
		cout << "le resultat est : " << resultat << endl ;
		break;
	case '%':
		resultat = (int)val1 % (int)val2;
		cout << "le resultat est : " << resultat << endl ;
		break;
	default:
		cout << "Y'a pas de panneau" << endl;
		break;

  }

  time_t t = time(0);
  tm* now = localtime(&t);

  ofstream Fichierlog;
  Fichierlog.open("journal.log", ios_base::app);
  Fichierlog << (now->tm_mday) << "/" << (now->tm_mon + 1) << "/" << (now->tm_year + 1900) << " " << (now->tm_hour) << ":" << (now->tm_min) << ":" << (now->tm_sec) << " // " << val1 << " " << choix << " " << val2 << " = " << resultat << "\n";
  Fichierlog.close();

  stringstream ss;
  ss << val1 << " " << choix << " " << val2 << " = " << resultat;
  string operation = ss.str();

  ligne.ModifierMessage(operation);
  string trame = ligne.Trame();

  string trameChiffree = trame;
  chiffrement(trame, trameChiffree);

  cout << "Trame Normale: " << trame << "\n" ;
  cout << "Trame Chiffre: " << trameChiffree << "\n" ;

  client.OuvrirLaSocketDeCommunication("172.20.21.157",4020);
  client.EnvoyerUnMessage(trame);
  client.FermerLaSocket();

  // cout << "FIN DU PROGRAMME CALCULATRICE SANS ERREUR" << "\n";
  cout << "Recommencer ? (si 1 alors ==> oui)" << "\n";
  cin >> recommencer;
  }
  return 0;
}
