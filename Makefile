build: clean
	mkdir build
	cp .env build/

	g++ -Wall -Wextra -O3 -g src/main.cpp src/dotenv_manager.cpp -o build/program -Iinclude


clean:
	rm -rf build