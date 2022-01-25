CXX=g++ -std=c++17
CXXFLAGS=-Wall -Wextra

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: body/Capacite.o body/Creature.o body/Terrain.o body/Deck.o body/Bibliotheque.o body/EnJeu.o body/Affiche.o body/Joueur.o body/Encyclopedie.o body/main.o
	$(CXX) $^ -o $@

.PHONY: run clean

run: main
	./$<

clean:
	rm -f body/*.o body/*~ body/*.cores