compile:
	g++ -Iinclude src/*.cpp main.cpp -o main.exe
	.\main.exe

remove-bin:
	rm *.bin
