#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  int recommencer;
  recommencer = 1;
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
  else

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

  ofstream Fichierlog;
  Fichierlog.open("journal.log", ios_base::app);
  Fichierlog << val1 << choix << val2 << ":" << resultat << "\n";
  Fichierlog.close();

  cout << "FIN DU PROGRAMME CALCULATRICE SANS ERREUR" << "\n";
  cout << "Recommencer ? (si 1 alors ==> oui)" << "\n";
  cin >> recommencer;
  }
  return 0;
}
