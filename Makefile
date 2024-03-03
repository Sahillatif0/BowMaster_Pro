all:
	g++ -o Animations *.cpp -I../SFML/include -L../SFML/lib -lSFML-graphics -lSFML-window -lSFML-system