COMPILE:
make

NORMINETTE:
./norm.sh

VERBOSE MODE:
./lem-in -v < <map_file>
eg. ./lem-in -v < maps/other_maps/108rooms.map

VISUALZER:
lem-in < <map_file> | ./visualizer/visualizer
eg. ./lem-in < maps/other_maps/108rooms.map | ./visualizer/visualizer

TIME TRIALS:
./generator --big > test.map && time ./lem-in < test.map
./generator --big-superposition > test.map && time ./lem-in < test.map

RANDOM MAP EXAMPLE (50 rooms piped to visualizer)
./map_gen/map_gen 50  && ./lem-in < rando.map | ./visualizer/visualizer

ANT_COP
Checks output for errors
and counts lines
./lem-in < <input.map> | ant_cop/./ant_cop
eg. ./generator --big > test.map && ./lem-in < test.map | ant_cop/./ant_cop