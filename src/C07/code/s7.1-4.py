import numpy as np


def quick_sort(start, end):
    if start < end:
        q = partition(start, end)
        quick_sort(start, q - 1)
        quick_sort(q + 1, end)


def partition(start, end):
    x = arr[end]
    i = start - 1

    for j in range(start, end+1):
        if arr[j] > x:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    i += 1
    arr[i], arr[end] = arr[end], arr[i]
    return i


if __name__ == "__main__":
    arr = np.random.randint(1, 100, 20).tolist()
    print(arr)
    quick_sort(0, len(arr) - 1)
    print(arr)
