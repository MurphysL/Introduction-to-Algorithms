import numpy as np


def des_insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while arr[j] < key and j >= 0:
            arr[j+1] = arr[j]
            j -= 1
        arr[j + 1] = key


array = np.random.randint(1, 100, 10).tolist()
des_insertion_sort(array)
print(array)