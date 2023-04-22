MSSFMLView::MSSFMLView(minesweeperBoard &board, help &ctrl) : msboard(board), msctrl(ctrl) {
    txtVec[0].loadFromFile("txt.png", sf::IntRect(0, 0, 16, 16));
    txtVec[1].loadFromFile("txt.png", sf::IntRect(16, 0, 16, 16));
    txtVec[2].loadFromFile("txt.png", sf::IntRect(32, 0, 16, 16));
    txtVec[3].loadFromFile("txt.png", sf::IntRect(48, 0, 16, 16));
    txtVec[4].loadFromFile("txt.png", sf::IntRect(0, 16, 16, 16));
    txtVec[5].loadFromFile("txt.png", sf::IntRect(16, 16, 16, 16));
    txtVec[6].loadFromFile("txt.png", sf::IntRect(32, 16, 16, 16));
    txtVec[7].loadFromFile("txt.png", sf::IntRect(48, 16, 16, 16));
    txtVec[8].loadFromFile("txt.png", sf::IntRect(0, 16, 16, 16));
    txtVec[9].loadFromFile("txt.png", sf::IntRect(16, 32, 16, 16));
    txtVec[10].loadFromFile("txt.png", sf::IntRect(32, 32, 16, 16));
    txtVec[11].loadFromFile("txt.png", sf::IntRect(0, 48, 16, 16));
    txtVec[12].loadFromFile("txt.png", sf::IntRect(16, 48, 16, 16));
    txtVec[13].loadFromFile("restart.png");
    txtVec[14].loadFromFile("win.png");
    sprite[1].setTexture(txtVec[13]);
    sprite[2].setTexture(txtVec[14]);
    sprite[1].setScale(2,2);
    sprite[2].setScale(2,2);
    int restartX = (windowX/2)-(sprite[1].getTexture()->getSize().x);
    int restartY = (windowY/2)-(sprite[1].getTexture()->getSize().y);
    int winX = (windowX/2)-(sprite[2].getTexture()->getSize().x);
    int winY = (windowY/2)-(sprite[2].getTexture()->getSize().y);
    sprite[1].setPosition(restartX,restartY);
    sprite[2].setPosition(winX,winY);
}


void MSSFMLView::draw(sf::RenderWindow &window)  {
    scaleX = windowX / double((msboard.getBoardWidth()*TILE_SIZE));
    scaleY = windowY / double((msboard.getBoardHeight()*TILE_SIZE));
    spriteX = TILE_SIZE*scaleX;
    spriteY = TILE_SIZE*scaleY;
    sprite[0].setScale(scaleX,scaleY);
    for(int i=0;i<msboard.getBoardHeight();i++) {
        for(int j=0;j<msboard.getBoardWidth();j++) {
            switch(msboard.getFieldInfo(i,j)) {
                case '_':
                    sprite[0].setTexture(txtVec[9]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case 'F':
                    sprite[0].setTexture(txtVec[10]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case 'x':
                    sprite[0].setTexture(txtVec[12]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case '0':
                    sprite[0].setTexture(txtVec[0]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case '1':
                    sprite[0].setTexture(txtVec[1]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case '2':
                    sprite[0].setTexture(txtVec[2]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case '3':
                    sprite[0].setTexture(txtVec[3]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case '4':
                    sprite[0].setTexture(txtVec[4]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case '5':
                    sprite[0].setTexture(txtVec[5]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case '6':
                    sprite[0].setTexture(txtVec[6]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case '7':
                    sprite[0].setTexture(txtVec[7]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
                case '8':
                    sprite[0].setTexture(txtVec[8]);
                    sprite[0].setPosition(j*spriteX, i*spriteY);
                break;
            }
            window.draw(sprite[0]);
        }
    }
    if(msboard.getGameState()==2) {
        window.draw(sprite[1]);
    }
    if(msboard.getGameState()==1) {
        window.draw(sprite[2]);
    }
}

void MSSFMLView::handleClick(sf::RenderWindow &window, sf::Event event) {
    if(event.type == sf::Event::MouseButtonPressed && msboard.getGameState()==RUNNING) {
        mouseX = (msboard.getBoardWidth()*event.mouseButton.x) / window.getSize().x;
        mouseY = (msboard.getBoardHeight()*event.mouseButton.y) / window.getSize().y;
        if(event.mouseButton.button==sf::Mouse::Left) {
            msboard.revealField(mouseY,mouseX);
        } else if (event.mouseButton.button==sf::Mouse::Right) {
            msboard.toggleFlag(mouseY,mouseX);
        }
    }
    if(event.type == sf::Event::KeyPressed && msboard.getGameState()!=RUNNING) {
        if(event.key.code == sf::Keyboard::R) {
            msctrl.toggleRestart();
            
        }
    }
}

void MSSFMLView::handleExit(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::Closed || msctrl.getRestartState()==1) {
        window.close();
    }
}