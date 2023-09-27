#include <iostream>
int main()
{
  int recommencer;
  recommencer = 1;
  while (recommencer == 1){

  float val1, val2;

  std::cout << "Saisir une premiere valeur : ";
  std::cin >> val1;

  std::cout << "Saisir une deuxieme valeur : ";
  std::cin >> val2;

  char choix;
  std::cout << "Choissisez l'operateur (+, -, /, *, %) : ";
  std::cin >> choix;

  float resultat;

  switch (choix) {
	case '+':
		resultat = val1 + val2;
        std::cout << "le resultat est : " << resultat << std::endl ;
		break;
	case '-':
		resultat = val1 - val2;
		std::cout << "le resultat est : " << resultat << std::endl ;
		break;
	case '/':
		resultat = val1 / val2;
		std::cout << "le resultat est : " << resultat << std::endl ;
		break;
	case '*':
		resultat = val1 * val2;
		std::cout << "le resultat est : " << resultat << std::endl ;
		break;
	case '%':
		resultat = (int)val1 % (int)val2;
		std::cout << "le resultat est : " << resultat << std::endl ;
		break;
	default:
		std::cout << "Y'a pas de panneau" << std::endl;

  }

  std::cout << "FIN DU PROGRAMME CALCULATRICE SANS ERREUR" << std::endl;
  std::cout << "Recommencer ? (si 1 alors oui)" << std::endl;
  std::cin >> recommencer;
  }
  return 0;
}
