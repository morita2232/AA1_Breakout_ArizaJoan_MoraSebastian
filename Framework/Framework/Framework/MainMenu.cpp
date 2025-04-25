#include "MenuScene.h"

void MenuScene::Update()
{
	if (GetAsyncKeyState('2') != 0) {
		nextScene = "Ranking"; //Selects the next scene 
		finished = true; //Indicates that this scene is finished
	}
	else if (GetAsyncKeyState('1') != 0) {
		// Destruir la instancia anterior si existe
		if (scenes["Gameplay"]) {
			delete scenes["Gameplay"];
			scenes["Gameplay"] = nullptr;
		}

		// Crear una nueva instancia
		scenes["Gameplay"] = new GameplayScene(*gameManager, scenes, rankingScene);

		nextScene = "Gameplay";
		finished = true;

	}
	else if (GetAsyncKeyState('0') != 0) {
		nextScene = "Exit";
		finished = true;
	}

	
	else if (GetAsyncKeyState('3') != 0) {
	nextScene = "Credits";
	finished = true;
	}

	
}

void MenuScene::Render()
{	
	  
	ConsoleSetColor(CYAN, BLACK);

std::cout << "                                                                                                                                            dddddddd" << std::endl;
std::cout << "               AAA                                 kkkkkkkk                                                               iiii              d::::::d" << std::endl;
std::cout << "              A:::A                                k::::::k                                                              i::::i             d::::::d" << std::endl;
std::cout << "             A:::::A                               k::::::k                                                               iiii              d::::::d" << std::endl;
std::cout << "            A:::::::A                              k::::::k                                                                                 d:::::d " << std::endl;
std::cout << "           A:::::::::A          rrrrr   rrrrrrrrr   k:::::k    kkkkkkkaaaaaaaaaaaaa  nnnn  nnnnnnnn       ooooooooooo   iiiiiii     ddddddddd:::::d " << std::endl;
std::cout << "          A:::::A:::::A         r::::rrr:::::::::r  k:::::k   k:::::k a::::::::::::a n:::nn::::::::nn   oo:::::::::::oo i:::::i   dd::::::::::::::d " << std::endl;
std::cout << "         A:::::A A:::::A        r:::::::::::::::::r k:::::k  k:::::k  aaaaaaaaa:::::an::::::::::::::nn o:::::::::::::::o i::::i  d::::::::::::::::d " << std::endl;
std::cout << "        A:::::A   A:::::A       rr::::::rrrrr::::::rk:::::k k:::::k            a::::ann:::::::::::::::no:::::ooooo:::::o i::::i d:::::::ddddd:::::d " << std::endl;
std::cout << "       A:::::A     A:::::A       r:::::r     r:::::rk::::::k:::::k      aaaaaaa:::::a  n:::::nnnn:::::no::::o     o::::o i::::i d::::::d    d:::::d " << std::endl;
std::cout << "      A:::::AAAAAAAAA:::::A      r:::::r     rrrrrrrk:::::::::::k     aa::::::::::::a  n::::n    n::::no::::o     o::::o i::::i d:::::d     d:::::d " << std::endl;
std::cout << "     A:::::::::::::::::::::A     r:::::r            k:::::::::::k    a::::aaaa::::::a  n::::n    n::::no::::o     o::::o i::::i d:::::d     d:::::d " << std::endl;
std::cout << "    A:::::AAAAAAAAAAAAA:::::A    r:::::r            k::::::k:::::k  a::::a    a:::::a  n::::n    n::::no::::o     o::::o i::::i d:::::d     d:::::d " << std::endl;
std::cout << "   A:::::A             A:::::A   r:::::r           k::::::k k:::::k a::::a    a:::::a  n::::n    n::::no:::::ooooo:::::oi::::::id::::::ddddd::::::dd" << std::endl;
std::cout << "  A:::::A               A:::::A  r:::::r           k::::::k  k:::::ka:::::aaaa::::::a  n::::n    n::::no:::::::::::::::oi::::::i d:::::::::::::::::d" << std::endl;
std::cout << " A:::::A                 A:::::A r:::::r           k::::::k   k:::::ka::::::::::aa:::a n::::n    n::::n oo:::::::::::oo i::::::i  d:::::::::ddd::::d" << std::endl;
std::cout << "AAAAAAA                   AAAAAAArrrrrrr           kkkkkkkk    kkkkkkkaaaaaaaaaa  aaaa nnnnnn    nnnnnn   ooooooooooo   iiiiiiii   ddddddddd   ddddd" << std::endl;
                                                                                                                                                    
ConsoleSetColor(WHITE, BLACK);

std::cout << std::endl;

ConsoleSetColor(GREEN, BLACK);


                                 
std::cout << " ___             _____ _         " << std::endl;
std::cout << "|_  |     ___   |  _  | |___ _ _ " << std::endl;
std::cout << " _| |_   |___|  |   __| | .'| | |" << std::endl;
std::cout << "|_____|         |__|  |_|__,|_  |" << std::endl;
std::cout << "                            |___|" << std::endl;


                                               
std::cout << " ___           _____         _   _             " << std::endl;
std::cout << "|_  |   ___   | __  |___ ___| |_|_|___ ___ ___ " << std::endl;
std::cout << "|  _|  |___|  |    -| .'|   | '_| |   | . |_ -|" << std::endl;
std::cout << "|___|         |__|__|__,|_|_|_,_|_|_|_|_  |___|" << std::endl;
std::cout << "                                      |___|    " << std::endl;


                                           
std::cout << " ___           _____           _ _ _       " << std::endl;
std::cout << "|_  |   ___   |     |___ ___ _| |_| |_ ___ " << std::endl;
std::cout << "|_  |  |___|  |   --|  _| -_| . | |  _|_ -|" << std::endl;
std::cout << "|___|         |_____|_| |___|___|_|_| |___|" << std::endl;
                                           



ConsoleSetColor(MAGENTA, BLACK);


                               
std::cout << " ___           _____     _ _   " << std::endl;
std::cout << "|   |   ___   |   __|_ _|_| |_ " << std::endl;
std::cout << "| | |  |___|  |   __|_'_| |  _|" << std::endl;
std::cout << "|___|         |_____|_,_|_|_|  " << std::endl;
                               

                                                                                                                                                    
                                                                                                                                                    
                                                                                                                                                    
                                                                                                                                                    
                                                                                                                                                    

}
