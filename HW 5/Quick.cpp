void quick_sort(int* data, int size) {
	quick_sort_helper(data, 0, size - 1);
}

void quick_sort_helper(int* data, int start, int end) {
	if (start < end) {
		int middle = partition(data, start, end);
		quick_sort_helper(data, start, middle - 1);
		quick_sort_helper(data, middle + 1, end);
	}
}

int partition(int* data, int start, int end) {
	int pivot = data[start];
	int left_index = start + 1;
	for (int i = (start + 1); i <= end; i++) {
		if (data[i] < pivot) {
			int temp = data[left_index];
			data[left_index] = data[i];
			data[i] = temp;
			left_index++;
		}
	}
	data[start] = data[left_index - 1];
	data[left_index - 1] = pivot;
	return left_index - 1;
}

int main() {
	int a[8] = { 10,5,7,9,0,6,4,2 };
	quick_sort(a, 8);
	for (int i = 0; i < 8; i++) {
		cout << "The sorted array position " << i + 1 << ": " << a[i] << endl;
	}
}
