#include <iostream>
#include <vector>
#include <algorithm>

void BubbleSort(std::vector<int>& data) {
	int size = data.size();
	int temp = 0;
	for (int iter_size = size; iter_size > 1; iter_size--) {
		for (int index = 0; index < iter_size - 1; index++) {
			if (data[index] > data[index+1]) {
				temp = data[index + 1];
				data[index + 1] = data[index];
				data[index] = temp;
			}
		}
	}
}

void SelectionSort(std::vector<int>& data) {
	int size = data.size();
	for (int start = 0; start < size; start++) {
		int temp = data[start];
		int min_index = start;
		for (int index = start; index < size; index++) {
			if (data[index] < data[min_index]) {
				min_index = index;
			}
		}
		data[start] = data[min_index];
		data[min_index] = temp;
	}
}

void Exchange(std::vector<int>& data, int lhs, int rhs) {
	int temp = data[lhs];
	data[lhs] = data[rhs];
	data[rhs] = temp;
}

void InsertSort(std::vector<int>& data) {
	int size = data.size();
	for (int index = 0; index < size; index++) {
		for (int i = index; i > 0; i--) {
			if (data[i] < data[i -1]) {
				Exchange(data, i, i-1);
			} else {
				break;
			}
		}
	}
}


std::vector<int> merge(std::vector<int> lhs, std::vector<int> rhs) {
	std::vector<int> out;
	auto l_iter = lhs.begin();
	auto r_iter = rhs.begin();
	while(l_iter  != lhs.end() || r_iter != rhs.end()) {
		if (l_iter != lhs.end() && r_iter != rhs.end()) {
			if (*l_iter > *r_iter) {
				out.push_back(*r_iter);
				r_iter++;
			} else {
				out.push_back(*l_iter);
				l_iter++;
			}
		} else if (l_iter == lhs.end()) {
				out.push_back(*r_iter);
				r_iter++;
		} else if (r_iter == rhs.end()) {
				out.push_back(*l_iter);
				l_iter++;
		}
	}
	return out;
}

std::vector<int> MergeSort(std::vector<int>& data) {
	int size = data.size();
	if (size > 2) {
		std::vector<int> left(data.begin(), data.begin() + size/2);
		std::vector<int> right(data.begin() + size /2, data.end());
		auto sorted_lhs = MergeSort(left);
		auto sorted_rhs = MergeSort(right);
		// merge
		return merge(sorted_lhs, sorted_rhs);
	} else if (size == 2){
		if (data[0] > data[1]) {
			Exchange(data, 0, 1);
		}
	}
	return data;
}

int partition(std::vector<int>&data, int start, int end) {
	int pivot = start;
	int index = start + 1;
	for (int i = index; i <= end; i++) {
		if (data[i] < data[pivot]) {
			Exchange(data, i, index);
			index++;
		}
	}
	Exchange(data, pivot, index - 1);
	return index - 1;
}

std::vector<int> QuickSort(std::vector<int>& data, int start, int end) {
	int size = end - start + 1;
	if (start < end) {
		int pivot = partition(data, start, end);
		QuickSort(data, start, pivot - 1);
		QuickSort(data, pivot + 1, end);
	}
	return data;
}

void modifyHeap(std::vector<int>& data, int index, int len) {
	int larget_index = index;
	int larget_value = data[index];
	int left_index = index * 2 + 1;
	int right_index = (index + 1) * 2;
	if (left_index < len && larget_value < data[left_index]) {
		larget_value = data[left_index];
		larget_index = left_index;
	}

	if (right_index < len && larget_value < data[right_index]) {
		larget_value = data[right_index];
		larget_index = right_index;
	}

	if (larget_index != index) {
		data[larget_index] = data[index];
		data[index] = larget_value;
	}
}

std::vector<int> buildMaxHeap(std::vector<int>& data, int len) {
	int start_index = len / 2 - 1;
	for (int index = start_index; index >= 0; index--) {
		modifyHeap(data, index, len);
	}
	return data;
}

std::vector<int> HeapSort(std::vector<int>& data) {
	std::vector<int> out;
	for (int len = data.size(); len > 0; len--) {
		buildMaxHeap(data, len);
		std::for_each(data.begin(), data.end(), [&](int num) { std::cout << num << ", "; });
		std::cout << std::endl;
		if (data[0] > data[len - 1]) {
			int temp = data[len - 1];
			data[len - 1] = data[0];
			data[0] = temp;
		}
	}
	return data;
}

int main() {
	std::vector<int> data = {9, 10, 4, 5, 12, 15, 13, 7};
	// BubbleSort(data);
	// SelectionSort(data);
	// InsertSort(data);
	// std::for_each(data.begin(), data.end(), [&](int num) { std::cout << num << ", "; });
	// auto out = MergeSort(data);
	// auto out = QuickSort(data, 0, data.size() - 1);
	auto out = HeapSort(data);
	std::for_each(out.begin(), out.end(), [&](int num) { std::cout << num << ", "; });
	std::cout << std::endl;
}