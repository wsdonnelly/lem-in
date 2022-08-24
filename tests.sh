#!/bin/bash
for i in {1..30}; do ./generator --big-superposition > test.map && ./lem-in < test.map | ../ant_cop/./ant_cop; done
#for i in {1..3}; do ./generator --big > test.map && ./lem-in < test.map | ../ant_cop/./ant_cop; done