COMPILE (ignore deprecation warnings for minilibx)
make && make -C visualizer

NORMINETTE:
./norm.sh

VERBOSE MODE:
./lem-in -v < maps/other_maps/108rooms.map

VISUALZER:
./lem-in < maps/other_maps/108rooms.map | visualizer/./visualizer

TIME TRIALS:
maps/./generator --big-superposition > big.map && time ./lem-in < big.map