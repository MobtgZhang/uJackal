# include "MainMenu.h"
# include "MenuOption.h"
# include "CFG.h"
# include "Application.h"

# include<iostream>

MainMenu::MainMenu(){
    this->lMO.push_back(new MenuOption("START",384,224));
    this->lMO.push_back(new MenuOption("OPTIONS",384,256));
    this->lMO.push_back(new MenuOption("ABOUT",384,288));

    rSelectLevel.x = 122;
	rSelectLevel.y = 280;
	rSelectLevel.w = 306;
	rSelectLevel.h = 72;

    this->numOfMenuOptions = lMO.size();
    this->activeMenuOption = mainSTART;
    this->selectLevel = false;
    this->activeLevelID = 0;

}

MainMenu::~MainMenu(){

}

void MainMenu::Draw(SDL_Renderer* rR){
    CCFG::getLogo()->Draw(rR,160,0);
    Menu::Draw(rR);
    CCFG::getText()->Draw(rR, "MOBTGZHANG",20,CCFG::GAME_HEIGHT - 16, 255, 255, 255);
    CCFG::getText()->Draw(rR, "TM AND COPYRIGHT 1988",320,320, 255, 255, 255);
    CCFG::getText()->Draw(rR, "KONAMI INDUSTRY CO.,LTD.",320,352, 255, 255, 255);
    CCFG::getText()->Draw(rR, "LICENSED BY",320,384, 255, 255, 255);
    CCFG::getText()->Draw(rR, "NINTENDO OF AMERICA INC.",320,416, 255, 255, 255);
    if(selectLevel){
        SDL_SetRenderDrawBlendMode(rR,SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(rR,251,251,251,60);
        SDL_RenderFillRect(rR, &rSelectLevel);
		SDL_SetRenderDrawColor(rR, 255, 255, 255, 255);
        rSelectLevel.x += 1;
		rSelectLevel.y += 1;
		rSelectLevel.h -= 2;
		rSelectLevel.w -= 2;
		SDL_RenderDrawRect(rR, &rSelectLevel);
		rSelectLevel.x -= 1;
		rSelectLevel.y -= 1;
		rSelectLevel.h += 2;
		rSelectLevel.w += 2;

        //CCFG::getText()->Draw(rR, "SELECT LEVEL", rSelectLevel.x + rSelectLevel.w/2 - CCFG::getText()->getTextWidth("SELECT WORLD")/2, rSelectLevel.y + 16, 16, 255, 255, 255);


        SDL_SetRenderDrawBlendMode(rR, SDL_BLENDMODE_NONE);
		//Application::getMap()->setBackgroundColor(rR);
    }
}

void MainMenu::escape(){
    selectLevel = false;
}

void MainMenu::enter(){
    switch(activeMenuOption){
        case mainSTART:
            if(!selectLevel){
                selectLevel = true;
            }else{
                //这里进入到某一个关卡当中
            }
            break;
        case mainOPTIONS:
            CCFG::getMM()->getOptions()->setEscapeToMainMenu(true);
            CCFG::getMM()->resetGameState(CCFG::getMM()->eOptions);
            CCFG::getMM()->getOptions()->updateVolumeRect();
            CCFG::getMM()->setGameState(CCFG::getMM()->eOptions);
            break;
        case mainABOUT:
            //关于菜单
            break;
    }
}

void MainMenu::updateActiveButton(int iDir){
    switch(iDir){
        case iUP_ITEM:case iDOWN_ITEM:
            if(!selectLevel){
                Menu::updateActiveButton(iDir);
            }
            break;
        case iLEFT_ITEM:
            if(selectLevel){
                if(activeLevelID >0){
                    --activeLevelID;
                }else{
                    activeLevelID = 7;
                }
            }
            std::cout<<"Push the left"<<std::endl;
            break;
        case iRIGHT_ITEM:
            if(selectLevel){
                if(activeLevelID < 7) {
					++activeLevelID;
				} else {
					activeLevelID = 0;
				}
            }
            std::cout<<"Push the right"<<std::endl;
            break;
    }
    std::cout<<"The Level,activeMenuOption is "<<activeLevelID<<","<<activeMenuOption<<std::endl;
}

void MainMenu::Update(){

    Menu::Update();
}