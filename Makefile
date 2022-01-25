CXX=g++ -std=c++17
CXXFLAGS=-Wall -Wextra

out/%.o: body/%.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: out/Capacite.o out/Creature.o out/Terrain.o out/Deck.o out/Bibliotheque.o out/EnJeu.o out/Affiche.o out/Joueur.o out/Encyclopedie.o out/main.o
	$(CXX) $^ -o $@

.PHONY: run clean

run: main
	./$<

clean:
	rm -f out/*.o out/*~ out/*.cores