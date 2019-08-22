#pragma once
#include <vector>

class Sort
{
public:
	using BaseType = int;

	// 冒泡排序
	bool BubbleSort(std::vector<BaseType>& dataSet)
	{
		for (size_t i = 0; i < dataSet.size(); i++) {
			for (size_t j = 0; j < dataSet.size() - i - 1; j++) {
				if (dataSet[j] > dataSet[j + 1])
					std::swap(dataSet[j], dataSet[j + 1]);
			}
		}

		return true;
	}

	// 选择排序
	bool ChooseSort(std::vector<BaseType>& dataSet)
	{
		BaseType bigest = -10000;
		size_t bigestIndx = 0;
		size_t sortIndx = dataSet.size() - 1;

		for (size_t i = 0; i < dataSet.size(); i++) {
			bigest = dataSet[0];
			for (size_t j = 0; j <= sortIndx; j++) {
				if (dataSet[j] > bigest) {
					bigest = dataSet[j];
					bigestIndx = j;
				}
			}
			std::swap(dataSet[bigestIndx], dataSet[sortIndx]);
			sortIndx--;
		}

		return true;
	}

	// 插入排序
	bool InsertSort(std::vector<BaseType>& dataSet)
	{
		if (dataSet.size() == 1)
			return true;

		for (size_t i = 1; i < dataSet.size(); i++) {
			for (size_t j = i; j > 0; j--) {
				if (dataSet[j] < dataSet[j - 1])
					std::swap(dataSet[j], dataSet[j - 1]);
				else
					break;
			}
		}

		return true;
	}

	// 快速排序
	bool QuickSort(std::vector<BaseType>& dataSet, size_t low, size_t high)
	{
		if (low >= high) 
			return true;

		size_t temp = GetIndex(dataSet, low, high);
		QuickSort(dataSet, low, temp);
		QuickSort(dataSet, temp + 1, high);

		return true;
	}

	// 归并排序
	bool MergingSort(std::vector<BaseType>& dataSet, size_t low, size_t high)
	{
		if (low >= high) {
			return true;
		}

		if (low + 1 == high) {
			if (dataSet[low] > dataSet[high])
				std::swap(dataSet[low], dataSet[high]);
			return true;
		}

		size_t mid = (high + low) / 2;
		MergingSort(dataSet, low, mid);
		MergingSort(dataSet, mid + 1, high);
		Merge(dataSet, low, mid, high);

		return true;
	}

private:
	size_t GetIndex(std::vector<BaseType>& dataSet, size_t low, size_t high) 
	{
		BaseType temp = dataSet[low];
		while (low < high) {

			while (low < high && dataSet[high] >= temp) {
				high--;
			}
			dataSet[low] = dataSet[high];

			while (low < high && dataSet[low] < temp) {
				low++;
			}
			dataSet[high] = dataSet[low];
		}

		dataSet[low] = temp;
		return low;
	}

	bool Merge(std::vector<BaseType>& dataSet, size_t low, size_t mid, size_t high)
	{
		size_t i = low;
		size_t j = mid+1;
		std::vector<BaseType> mergeArray(high - low + 1);
		for (size_t i = low; i <= high; i++) {
			mergeArray[i - low] = dataSet[i];
		}

		size_t mergeArrayIdx = low;
		while (i <= mid && j <= high) {
			if (mergeArray[i - low] < mergeArray[j - low]) {
				dataSet[mergeArrayIdx++] = mergeArray[i - low];
				i++;
			}
			else{
				dataSet[mergeArrayIdx++] = mergeArray[j - low];
				j++;
			}
		}

		for (; i <= mid; i++)
			dataSet[mergeArrayIdx++] = mergeArray[i - low];

		for (; j <= high; j++)
			dataSet[mergeArrayIdx++] = mergeArray[j - low];

		return true;
	}
};
