COMPILE:
make
(ignore deprecation warnings associated with minilibx compilation)

NORMINETTE:
./norm.sh
(ignores minilibx, checks lem-in, map_gen, visualizer and libft)

VERBOSE MODE:
./lem-in -v < <map_file>
eg. ./lem-in -v < maps/basic_maps/108rooms.map

SHOW LINE COUNT MODE:
./lem-in -l < <map_file>
eg. ./lem-in -l < maps/basic_maps/108rooms.map

VISUALZER:
lem-in < <map_file> | ./visualizer/visualizer
eg. ./map_gen/map_gen 50  && ./lem-in < rando.map | ./visualizer/visualizer

TIME TRIALS:
./generator --big > test.map && time ./lem-in < test.map
./generator --big-superposition > test.map && time ./lem-in < test.map

RANDOM MAP EXAMPLE (50 rooms piped to visualizer)
./map_gen/map_gen 50  && ./lem-in < rando.map | ./visualizer/visualizer

ANT_COP
git@github.com:wsdonnelly/ant_cop.git
Checks output for errors:
-same ant on same line
-same room on same line
-ants take valid paths
-all ants get to end
and counts lines
./lem-in < <input.map> | <reletive path to ant_cop binary>
eg. ./generator --big > test.map && ./lem-in < test.map | ../ant_cop/ant_cop

EXAMPLE TEST SCRIPTS:
for i in {1..10}; do ./generator --big-superposition > test.map && ./lem-in < test.map | ../ant_cop/ant_cop; done
for i in {1..10}; do ./generator --big > test.map && ./lem-in < test.map | ../ant_cop/ant_cop; done
for i in {1..10}; do ./generator --flow-one > test.map && ./lem-in < test.map | ../ant_cop/ant_cop; done
for i in {1..10}; do ./generator --flow-ten > test.map && ./lem-in < test.map | ../ant_cop/ant_cop; done
for i in {1..10}; do ./generator --flow-thousand > test.map && ./lem-in < test.map | ../ant_cop/ant_cop; done
for FILE in maps/error_maps/*; do ./lem-in < $FILE; done
for FILE in maps/basic_maps/*; do ./lem-in < $FILE | ../ant_cop/ant_cop; done 
for FILE in maps/cases/*; do ./lem-in < $FILE | ../ant_cop/ant_cop; done 