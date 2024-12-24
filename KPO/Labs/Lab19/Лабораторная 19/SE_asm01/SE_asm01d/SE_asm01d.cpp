extern "C" 
{
	int __stdcall getmin(int* arr, int length) {
		int min = *arr;
		for (int i = 1; i < length; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		return min;
	}

	int __stdcall getmax(int* arr, int length) {
		int max = *arr;
		for (int i = 1; i < length; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		return max;
	}
}