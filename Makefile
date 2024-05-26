# 326627635 | adi.peisach@gmail.com

CXX=clang++
CXXFLAGS=-std=c++14 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

DOCTEST_INCLUDE = -I /usr/include/doctest
BUILDING_SOURCES = Board/Buildings/Road.cpp Board/Buildings/Settlement.cpp
TILES_SOURCES = Board/Tiles/Field.cpp Board/Tiles/Forest.cpp Board/Tiles/Mine.cpp Board/Tiles/Mountains.cpp Board/Tiles/Pasture.cpp Board/Tiles/Tile.cpp Board/Tiles/Direction.cpp
CODE_SOURCES = $(BUILDING_SOURCES) $(TILES_SOURCES) Board/Board.cpp Cards/Card.cpp Player.cpp Demo.cpp Game.cpp
CODE_HEADERS = $(subst .cpp,.h,$(CODE_SOURCES))
CODE_OBJECTS = $(subst .cpp,.o,$(CODE_SOURCES))
TEST_SOURCES = Board/TestBoard.cpp
TEST_OBJECTS = $(subst .cpp,.o,$(TEST_SOURCES))

run: demo
	./$^

all: demo test

demo: $(CODE_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo -lstdc++

test: $(TEST_OBJECTS) $(CODE_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test -lstdc++ -lm $(DOCTEST_INCLUDE)

tidy:
	clang-tidy $(CODE_SOURCES) \
        -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory \
        -warnings-as-errors=-* \
        -header-filter=".*" \
        -extra-arg=-Wno-shorten-64-to-32

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo Cards/*.o Board/Buildings/*.o Board/Tiles/*.o Board/*.o