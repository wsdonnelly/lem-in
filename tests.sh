#!/bin/bash
for i in {1..10}; do ./generator --big-superposition > test.map && ./lem-in < test.map | ant_cop/./ant_cop; done
#for i in {1..3}; do ./generator --big > test.map && ./lem-in < test.map | ant_cop/./ant_cop; done
#for FILE in maps/error_maps/*; do ./lem-in < $FILE; done
#for FILE in maps/other_maps/*; do ./lem-in < $FILE | ../ant_cop/./ant_cop; done