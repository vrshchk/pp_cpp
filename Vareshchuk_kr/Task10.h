template <typename T>
void task10_sort(T** strs, int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if (*strs[j + 1] < *strs[j]) {
				T* k = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = k;
			}
		}
	}
}
