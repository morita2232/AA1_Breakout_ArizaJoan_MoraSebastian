#include "CreditsScene.h"

void CreditsScene::Update() {
	if (GetAsyncKeyState('R') != 0) {
		nextScene = "Menu"; //Selects the next scene 
		finished = true; //Indicates that this scene is finished
	}
}

void CreditsScene::Render() {

	
	ConsoleSetColor(DARKGREEN, BLACK);
                                                                    
std::cout << "        ##### ##      # ###         ##            ##### #     ##    " << std::endl;
std::cout << "     ######  /### / /  /###      /####         ######  /#    #### / " << std::endl;
std::cout << "    /#   /  / ###/ /  /  ###    /  ###        /#   /  / ##    ###/  " << std::endl;
std::cout << "   /    /  /   ## /  ##   ###      /##       /    /  /  ##    # #   " << std::endl;
std::cout << "       /  /      /  ###    ###    /  ##          /  /    ##   #     " << std::endl;
std::cout << "      ## ##     ##   ##     ##    /  ##         ## ##    ##   #     " << std::endl;
std::cout << "      ## ##     ##   ##     ##   /    ##        ## ##     ##  #     " << std::endl;
std::cout << "    /### ##     ##   ##     ##   /    ##        ## ##     ##  #     " << std::endl;
std::cout << "   / ### ##     ##   ##     ##  /      ##       ## ##      ## #     " << std::endl;
std::cout << "      ## ##     ##   ##     ##  /########       ## ##      ## #     " << std::endl;
std::cout << "      ## ##      ##  ##     ## /        ##      #  ##       ###     " << std::endl;
std::cout << "      ## ##       ## #      /  #        ##         /        ###     " << std::endl;
std::cout << "      ## ##        ###     /  /####      ##    /##/          ##     " << std::endl;
std::cout << "      #  #          ######/  /   ####    ## / /  #####              " << std::endl;
std::cout << "  ##     /            ###   /     ##      #/ /     ##               " << std::endl;
std::cout << " ####   /                   #                #                      " << std::endl;
std::cout << " /  # #/                     ##               ##                    " << std::endl;
std::cout << "/    ##                                                             " << std::endl;
std::cout << "     #                                                              " << std::endl;


std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;

ConsoleSetColor(BLUE, BLACK);
std::cout << "      ___           ___           ___                                   ___     " << std::endl;
std::cout << "     /__/\\         /  /\\         /  /\\        ___           ___        /  /\\    " << std::endl;
std::cout << "    |  |::\\       /  /::\\       /  /::\\      /  /\\         /  /\\      /  /::\\   " << std::endl;
std::cout << "    |  |:|:\\     /  /:/\\:\\     /  /:/\\:\\    /  /:/        /  /:/     /  /:/\\:\\  " << std::endl;
std::cout << "  __|__|:|\\:\\   /  /:/  \\:\\   /  /:/~/:/   /__/::\\       /  /:/     /  /:/~/::\\ " << std::endl;
std::cout << " /__/::::| \\:\\ /__/:/ \\__\\:\\ /__/:/ /:/___ \\__\\/\\:\\__   /  /::\\    /__/:/ /:/\\:\\" << std::endl;
std::cout << " \\  \\:\\~~\\__\\/ \\  \\:\\ /  /:/ \\  \\:\\/:::::/    \\  \\:\\/\\ /__/:/\\:\\   \\  \\:\\/:/__\\/" << std::endl;
std::cout << "  \\  \\:\\        \\  \\:\\  /:/   \\  \\::/~~~~      \\__\\::/ \\__\\/  \\:\\   \\  \\::/     " << std::endl;
std::cout << "   \\  \\:\\        \\  \\:\\/:/     \\  \\:\\          /__/:/       \\  \\:\\   \\  \\:\\     " << std::endl;
std::cout << "    \\  \\:\\        \\  \\::/       \\  \\:\\         \\__\\/         \\__\\/    \\  \\:\\    " << std::endl;
std::cout << "     \\__\\/         \\__\\/         \\__\\/                                 \\__\\/    " << std::endl;

ConsoleSetColor(WHITE, BLACK);

std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;

std::cout << "Press R to go back..." << std::endl;


}