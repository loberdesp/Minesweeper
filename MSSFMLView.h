class MSSFMLView {
    int mouseX, mouseY;
    sf::Texture txtVec[15];
    sf::Sprite sprite[5];
    double scaleX,scaleY, spriteX, spriteY;
    minesweeperBoard &msboard;
    help &msctrl;

    public:
        MSSFMLView(minesweeperBoard &board, help &msctrl);
        void draw(sf::RenderWindow &window);
        void handleClick(sf::RenderWindow &window, sf::Event event);
        void handleExit(sf::RenderWindow &window, sf::Event event);
};