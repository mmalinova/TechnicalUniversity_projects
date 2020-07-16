#pragma once
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//This was not part of the assignment but is included here anyway
//This function sorts an array using Bubble Sort
//Pre: size must be less than or equal to declared size of array
//     The > and = operators must be overloaded for type T
//Post: The array is sorted
template<typename T>
void bubbleSort(T array[], const int size)
{
	for (int i = 0; i < size - 1; i++)
	for (int j = 0; j < size - 1 - i; j++)
	if (array[j] > array[j + 1])
		swap(array[j], array[j + 1]);
}

#endif