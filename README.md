# Lem-in: get n ants through a network in the fewest number of moves
Hive Helsinki graph algorithm project.
As per 42 School pedegogy C library functions are limited to:
- malloc
- free
- write
- read
- exit
All other functions are re-coded library functions or specific to the project

Subject is here:
https://cdn.intra.42.fr/pdf/pdf/6610/lem-in.en.pdf

## COMPILE:
 - make
(Ignore deprecation warnings associated with minilibx compilation, the ancient library used in the Visualizer)
- Usage: ./lem-in < <map_file>
- generator can be used to make random graphs. The generator graphs also state the number of lines expected as an accuracy estimate.
- ex: ./generator --flow-ten | ./lem-in

**VERBOSE MODE: Show paths taken**
- ./lem-in -v < <map_file>
- ./lem-in -v < maps/basic_maps/108rooms.map

**SHOW LINE COUNT MODE:**
- ./lem-in -l < <map_file>
- ./lem-in -l < maps/basic_maps/108rooms.map

## VISUALZER:
- ./lem-in < <map_file> | ./visualizer/visualizer
- ./lem-in < maps/basic_maps/108rooms.map | ./visualizer/visualizer

## RANDOM MAP GENERATOR
- Example: 50 rooms piped to visualizer
- ./map_gen/map_gen 50  && ./lem-in < rando.map | ./visualizer/visualizer

**TIME TRIALS:**
- ./generator --big > test.map && time ./lem-in < test.map
- ./generator --big-superposition > test.map && time ./lem-in < test.map

**ACCURACY TRIALS:**
- ./generator --big-superposition > test.map && ./lem-in -l < test.map && grep -m 1 '#Here is the number of lines required:' test.map

## ANT_COP:
git clone git@github.com:wsdonnelly/ant_cop.git ant_cop && make -C ant_cop

Checks output for errors:
- same ant on same line
- same room on same line
- ants take valid paths
- all ants get to end
- counts lines

Usage: ./lem-in < <input.map> | <reletive path to ant_cop binary>
eg. ./generator --big > test.map && ./lem-in < test.map | ./ant_cop/ant_cop

### EXAMPLE TESTING SCRIPTS:
- for i in {1..10}; do ./generator --big-superposition > test.map && ./lem-in < test.map | ./ant_cop/ant_cop; done
- for i in {1..10}; do ./generator --big > test.map && ./lem-in < test.map | ./ant_cop/ant_cop; done
- for i in {1..10}; do ./generator --flow-one > test.map && ./lem-in < test.map | ./ant_cop/ant_cop; done
- for i in {1..10}; do ./generator --flow-ten > test.map && ./lem-in < test.map | ./ant_cop/ant_cop; done
- for i in {1..10}; do ./generator --flow-thousand > test.map && ./lem-in < test.map | ./ant_cop/ant_cop; done
- for FILE in maps/error_maps/*; do ./lem-in < $FILE; done
- for FILE in maps/basic_maps/*; do ./lem-in < $FILE | ./ant_cop/ant_cop; done 
- for FILE in maps/cases/*; do ./lem-in < $FILE | ./ant_cop/ant_cop; done 