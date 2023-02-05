#pragma once

# ifndef MENUOPTION_H
# define MENUOPTION_H

# include <string>

class MenuOption{
private:
    std::string sText;
    int iXPos,iYPos;
public:
    MenuOption(std::string sText,int XPos,int YPos);
    ~MenuOption();

    std::string getText();
    void setText(std::string sText);

    int getXPos();
    int getYPos();
};

# endif

