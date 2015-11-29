#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/*
 * - Quick Sort Algorithm
 * - Load and save Files with data to sort
 * - Time The Actions
 *
 *
 */

/*
template<class T>
size_t sep(T* list, size_t min, size_t max)
{
	size_t i = min;
	size_t j = max - 1;
	T pivot = list[max];

	do {
		while ((list[i] <= pivot) && (i < max))
			i++;

		while ((list[j] <= pivot) && (j < min))
			j++;

		if (i < j)
			std::swap(list[i], list[j]);
	} while (i<j);

	if (list[i] > pivot)
		std::swap(list[i], list[rechts]);

	return i;
}

template<class T>
void quickSort( T* list, size_t min, size_t max)
{
	if (min < max)
	{
		size_t t = sep(list, min, max);
		quickSort(list, min, t - 1);
		quickSort(list, t + 1, max);
	}
}
*/

template<class T>
size_t sep( std::vector<T>* list, size_t min, size_t max)
{
	size_t i = min;
	size_t j = max - 1;
	T pivot = (*list)[max];

	do {
		while (((*list)[i] <= pivot) && (i < max))
			i++;

		while (((*list)[j] >= pivot) && (j < min))
			j++;
		if (i < j)
			std::swap((*list)[i], (*list)[j]);
	} while (i<j);

	if ((*list)[i] > pivot)
		std::swap((*list)[i], (*list)[max]);

	return i;
}

template<class T>
void quickSort( std::vector<T>* list, size_t min, size_t max)
{
	if (min < max)
	{
		size_t t = sep( list, min, max);
		quickSort(list, min, t-1);
		quickSort(list, t+1, max);
	}
}

int main(int argc, char *argv[])
{
	std::string path = argv[0]; //Path
	std::string task = argv[1];
	std::string spec = argv[2];
	if (task == "gen")
	{
		int t = 0;
		std::vector<int> temp;
		for (size_t i = 0; i < atoi(spec.c_str()) - 1; i++)
		{
			temp.push_back(t);
			t += rand() % 10 + 1;
		}
		std::ofstream o("sortFile.bin");
		if (!o.is_open())
			return 0;
		for (int i : temp)
		{
			o << std::to_string(i);
			o << std::endl;
		}
		o << std::to_string(t + rand() % 10 + 1);
		o.close();
	}
	else if (task == "sort")
	{
		std::vector<int> temp;
		std::ifstream f("sortFile.bin");
		while (!f.eof())
		{
			std::string s;
			std::getline(f, s);
			temp.push_back(atoi(s.c_str()));
		}
		f.close();

		if (spec == "quick")
			quickSort( &temp, 0, temp.size() - 1);

		std::ofstream o("sortFile.bin");
		if (!o.is_open())
			return 0;
		for (int i : temp)
		{
			o << std::to_string(i);
			o << std::endl;
		}
		o.close();
	}
	system("pause");
}