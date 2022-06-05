COMPILE:
make

NORMINETTE:
./norm.sh

VERBOSE MODE:
./lem-in -v < <map_file>
eg. ./lem-in -v < maps/other_maps/108rooms.map

VISUALZER:
lem-in < <map_file> | visualizer/./visualizer
eg. ./lem-in < maps/other_maps/108rooms.map | visualizer/./visualizer

TIME TRIALS:
./generator --big > big.map && time ./lem-in < big.map
./generator --big-superposition > big.map && time ./lem-in < big.map

RANDOM MAP EXAMPLE (50 rooms piped to visualizer)
maps/map_gen/./map_gen 50  && ./lem-in < rando.map | visualizer/./visualizer