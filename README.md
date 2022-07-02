# sudoku-2005
Brute force Sudoku solver written in C in 2005

## Example usage

It takes a single argument: the content of the cells in Western writing order (top to bottom, left to right). Unknowns are zeroes. It will return all possible solutions (if any).

```
	$ make
	$ ./sudoku 043080250600000000000001094900004070000608000010200003820500000000000005034090710

		1  4  3  9  8  6  2  5  7
		6  7  9  4  2  5  3  8  1
		2  8  5  7  3  1  6  9  4
		9  6  2  3  5  4  1  7  8
		3  5  7  6  1  8  9  4  2
		4  1  8  2  7  9  5  6  3
		8  2  1  5  6  7  4  3  9
		7  9  6  1  4  3  8  2  5
		5  3  4  8  9  2  7  1  6
```
