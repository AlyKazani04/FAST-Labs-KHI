src = main.cpp letter.cpp line.cpp word.cpp
o_files = build/main.o build/letter.o build/line.o build/word.o
output = task4_o

# how this works:
# make build > adds all .o files to build/ and builds an executable
# make run > runs the executable, if available, else makes it first
# make clean > removes all .o files
# make full_clean > resets the directory

.PHONY: run build clean full_clean # not files

build: $(output)

$(output): $(o_files)
	g++ $(o_files) -o $(output)

build/%.o: %.cpp
	mkdir -p build
	g++ -c $< -o $@

run: $(output)
	./$(output)

clean:
	rm -rf build

full_clean: clean
	rm -f $(output)