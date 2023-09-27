#include <iostream>

int main()
{
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

  system("PAUSE");

  return 0;
}
