import numpy as np
import matplotlib.pyplot as plt


def selection_sort(arr):
    for i in range(0, len(arr) - 1):
        min = i
        for j in range(i + 1, len(arr)):
            if arr[min] > arr[j]:
                min = j
        arr[i], arr[min] = arr[min], arr[i]
        update(arr)


def update(arr):
    try:
        ax.clear()
        ax.bar(left=range(1, len(arr) + 1), height=arr, fc='g')
        plt.draw()
        plt.pause(0.001)
    except Exception as err:
        print(err)


if __name__ == '__main__':
    array = np.random.randint(1, 100, 50).tolist()
    print(array)

    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1)
    plt.grid(True)  # 添加网格
    plt.ion()
    pic = ax.bar(left=range(0, len(array)), height=array, fc='g')

    selection_sort(array)
    print(array)