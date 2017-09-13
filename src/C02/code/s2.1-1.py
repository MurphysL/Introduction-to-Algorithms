import matplotlib.pyplot as plt
import numpy as np


def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while key < arr[j] and j >= 0:
            arr[j + 1] = arr[j]
            update(arr)
            j -= 1
        arr[j + 1] = key
        update(arr)


def update(arr):
    try:
        ax.clear()
        ax.bar(left=range(1, len(arr) + 1), height=arr, fc='g')
        plt.draw()
        plt.pause(0.001)
    except Exception as err:
        print(err)


if __name__ == "__main__":
    array = np.random.randint(1, 100, 10).tolist()
    print(array)

    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1)
    plt.grid(True)  # 添加网格
    plt.ion()
    pic = ax.bar(left=range(0, len(array)), height=array, fc='g')

    insertion_sort(array)
    print(array)

    plt.ioff()
    plt.pause(10)
    plt.close()
