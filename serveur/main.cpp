#include "IRJournalLumineux.h"
#include "IRServeurUDP.h"
#include "IRClientUDP.h" 
#include "IRLigne.h"

using namespace std;

int main()
{
    IRServeurUDP serveur;
    IRJournalLumineux journal;
    string msg;

    while(true)
    {
    serveur.OuvrirLaSocketDEcoute(4020);
    serveur.RecevoirUnMessage(msg);
    serveur.FermerLaSocket();

    journal.OuvrirPortSerie("/dev/ttyUSB0");
    journal.EnvoyerTrame(msg);
    journal.FermerPortSerie();
    }
}
  
