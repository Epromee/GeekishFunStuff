#include <iostream>
#include <string>
#include <vector>

/*
	Coded by Egor Promyshlennikov 09 November 2019.
	I do not have any ownership of this song lyrics.
*/

int main() {
	
	using cstring = const char*;
	using pool = std::vector<cstring>;
	
	pool animals = {"chick", "hen", "cock", "turkey", "pigeon", "cat",
		"dog", "goat", "lamb", "cow", "bull", "tractor"};
		
	pool sounds = {"CHEEP", "CO-CO", "DOODLE-DOO",
		"GOBBLE-GOBBLE", "CRU CRU", "MEW", "WOOF", "MAH", "BAH", "MOW", "MUU", "BRUMM"};
		
	std::vector<int> repetitions = {5, 4, 3, 2, 3, 2, 3, 2, 3, 4, 3, 1};
	
	cstring little = "On the radio there's a little ";
	cstring a_th = "And the ";
	cstring th = "The ";
	cstring endverse = "\n";
	cstring delimiter = " ";
	
	/* Verse: */
	for (ssize_t cur = 0; cur < 12; ++cur) {
		
		std::cout << little << animals[cur] << '\n';
		std::cout << little << animals[cur] << '\n';
		
		int begin = 0;

		if (cur == 11) {
			begin = 9;
			sounds[0] = "...";
			animals[9] = animals[10] = animals[11];
			sounds[9] = sounds[10] = sounds[11];
			endverse = "Oh oh!";
			delimiter = "";
		}
		
		for (ssize_t prev = cur; prev >= begin; prev--) {
			
            cstring and_the = (
				(cur >= 9) && (prev == (cur - 1) || prev == (cur - 2))
			) ? th : a_th;

			std::cout << and_the << animals[prev] << ' ' << sounds[prev] << '\n';
		}
		
		for (int rep = 0; rep < repetitions[cur]; ++rep)
			std::cout << a_th << animals[0] << delimiter << sounds[0] << '\n';
			
		std::cout << endverse;
	}

    std::cout << "Oh oh!";
	
	return 0;
}
