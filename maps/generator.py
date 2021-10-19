#!/usr/bin/env python

from sys import argv
from random import randint
import os

if len(argv) != 4:
    print("Incorrect! Please, input next params: 'x', 'y', 'map name'")
    exit(1)

if argv[3][-4:] != ".ber" or len(argv[3]) < 5:
    print("Incorrect map name! Need 'name' + '.ber'")
    exit(1)

x = int(argv[1])
y = int(argv[2])
filename = argv[3]

if x * y <= 15:
    print("Incorrect! Little size map!")
    exit(1)

map = [['1' if (i == 0 or j == 0 or i == x - 1 or j == y - 1) else '0' for i in range(x)] for j in range(y)]

elements = int(x * y * 0.3) - 2


def add_elements(count, char):
    while count:
        cord_y, cord_x = randint(1, y - 1), randint(1, x - 1)
        if map[cord_y][cord_x] == '0':
            map[cord_y][cord_x] = char
            count -= 1


add_elements(1, 'P')
add_elements(1, 'E')
add_elements(elements // 2, '1')
add_elements(elements // 2, 'C')

if os.getcwd()[-7:] == 'so_long':
    os.chdir(os.getcwd() + '/maps')

with open(filename, 'w') as file:
    print("New map:\n")
    for line in map:
        print(''.join(line))
        file.write(''.join(line) + '\n')
