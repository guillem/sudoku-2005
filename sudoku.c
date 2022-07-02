
/*
	sudoku.c - Quick & Really Dirty Sudoku Solver - Version 0.9-beta
	Copyright (C) 2005 Guillem Cantallops Ramis <guillem@cantallops.net>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char **argv) {
	char x, y, z, xx, yy, zz, xxx, yyy, zzz;
	char board [9] [9];
	char possi [10];
	char changed, zeros;

	if (argc != 2) {
		return -1;
	}
	for (x = 0; x < 9; x++) {
		for (y = 0; y < 9; y++) {
			board [x] [y] = argv [1] [x * 9 + y] - '0';
			if ( (board [x] [y] < 0) || (board [x] [y] > 9) ) {
				return -1;
			}
		}
	}
	if (argv [1] [9*9]) {
		return -1;
	}

	do {
		changed = 0;
		zeros = 0;
		for (x = 0; x < 9; x++) {
			for (y = 0; y < 9; y++) {
				if (board [x] [y]) {
					continue;
				}
				memset (possi, 0, sizeof (possi));
				for (xx = 0; xx < 9; xx++) {
					if (board [xx] [y] > 0 ) {
						possi [board [xx] [y]] = 1;
					}
				}
				for (yy = 0; yy < 9; yy++) {
					if (board [x] [yy] > 0) {
						possi [board [x] [yy]] = 1;
					}
				}
				for (xx = x - (x % 3); xx < x - (x % 3) + 3; xx++) {
					for (yy = y - (y % 3); yy < y - (y % 3) + 3; yy++) {
						if (board [xx] [yy] > 0) {
							possi [board [xx] [yy]] = 1;
						}
					}
				}
				for (z = 1; z <= 9; z++) {
					if (possi [z]) {
						possi [0] ++;
					}
					else {
						zz = z;
					}
				}
				switch (9 - possi [0]) {
					case 0:
						return -1;
						break;
					case 1:
						board [x] [y] = zz;
						changed = 1;
						break;
					default:
						xxx = x;
						yyy = y;
						zeros ++;
						break;
				}
			}
		}
		if (!changed) {
			for (zzz = 1; zzz <= 9; zzz++) {
				if (! possi [zzz]) {
					if (! fork ()) {
						board [xxx] [yyy] = zzz;
						changed = 1;
						break;
					}
				}
			}
			if (!changed) {
				return -1;
			}
		}
	}
	while (zeros);

	printf ("\n");
	for (x = 0; x < 9; x++) {
		for (y = 0; y < 9; y++) {
			printf ("%3d", board [x] [y]);
		}
		printf ("\n");
	}
	printf ("\n");

	return 0;
}
