CXX=g++ -std=c++17
CXXFLAGS=-Wall -Wextra

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: Capacite.o Creature.o Terrain.o Deck.o Bibliotheque.o EnJeu.o Affiche.o Joueur.o  main.o
	$(CXX) $^ -o $@

.PHONY: run clean

run: main
	./$<

clean:
	rm -f *.o *~ *.cores