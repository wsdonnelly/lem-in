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
 - `make`
- (Ignore deprecation warnings associated with minilibx compilation, the ancient library used in the Visualizer)
- Usage: `./lem-in < <map_file>`
- sample map files can be found in the maps directory.
- ex: `./lem-in < maps/cases/augment_0.map`
- generator can be used to make random graphs. The generator graphs also state the number of lines expected as an accuracy estimate.
- ex: `./generator --flow-ten | ./lem-in`

## OUTPUT:
- details can be found in the suppplied subject
- ex: `./lem-in -l < maps/basic_maps/subject3.map` (used -l or line count mode to display lines used)
- The output consists of two parts:
1. A representation of the graph (undirected and unweighted):
- the number of "ants"
- the vertices (and their cooridinates as needed by the visualizer)
- the start and end vertices
- the edges (represented by vertex pairs)
2. the 'ant' moves:
- All ants are assumed to be at the start to begin
- only a single ant may occupy a 'room' at a time
- ex: L1-3 L2-1
- L1 is ant number 1, L2 is ant number 2
- L1-3 means ant 1 goes to room 3 and L2-1 means ant 2 goes to room 1
## THE RESULTS:
- In the above example:
- There are 5 ants and they take a total of 6 lines to move to the end.
- The object of this project is to minimize the line count for a given graph and number of ants


**VERBOSE MODE: Show paths taken**
- ex: `./lem-in -v < maps/basic_maps/108rooms.map`

**SHOW LINE COUNT MODE:**
- ex: `./lem-in -l < maps/basic_maps/108rooms.map`

## VISUALZER:
- `./lem-in < <map_file> | ./visualizer/visualizer`
- ex: `./lem-in < maps/basic_maps/108rooms.map | ./visualizer/visualizer`

## RANDOM MAP GENERATOR
- Example: 50 rooms piped to visualizer
- `./map_gen/map_gen 50  && ./lem-in < rando.map | ./visualizer/visualizer`

**TIME TRIALS:**
- `./generator --big > test.map && time ./lem-in < test.map`
- `./generator --big-superposition > test.map && time ./lem-in < test.map`

**ACCURACY TRIALS:**
- `./generator --big-superposition > test.map && ./lem-in -l < test.map && grep -m 1 '#Here is the number of lines required:' test.map`

## ANT_COP:
- `git clone git@github.com:wsdonnelly/ant_cop.git ant_cop`
- `make -C <path to ant_cop>`

Checks output for errors:
- same ant on same line
- same room on same line
- ants take valid paths
- all ants get to end
- counts lines

Usage: `./lem-in < <input.map> | <reletive path to ant_cop binary>`
- ex. `./generator --big > test.map && ./lem-in < test.map | ../ant_cop/ant_cop`

### EXAMPLE TESTING SCRIPTS:
- `for i in {1..10}; do ./generator --big-superposition > test.map && ./lem-in < test.map | ../ant_cop/ant_cop; done`
- `for i in {1..10}; do ./generator --big > test.map && ./lem-in < test.map | ../ant_cop/ant_cop; done`
- `for i in {1..10}; do ./generator --flow-one > test.map && ./lem-in < test.map | ../ant_cop/ant_cop; done`
- `for i in {1..10}; do ./generator --flow-ten > test.map && ./lem-in < test.map | ../ant_cop/ant_cop; done`
- `for i in {1..10}; do ./generator --flow-thousand > test.map && ./lem-in < test.map | ../ant_cop/ant_cop; done`
- `for FILE in maps/error_maps/*; do ./lem-in < $FILE; done`
- `for FILE in maps/basic_maps/*; do ./lem-in < $FILE | ../ant_cop/ant_cop; done` 
- `for FILE in maps/cases/*; do ./lem-in < $FILE | ../ant_cop/ant_cop; done` 