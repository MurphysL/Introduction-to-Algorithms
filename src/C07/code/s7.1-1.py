import matplotlib.pyplot as plt


def quick_sort(start, end):
    if start < end:
        q = partition(start, end)
        quick_sort(start, q - 1)
        quick_sort(q + 1, end)


def partition(start, end):
    x = arr[end]
    i = start - 1

    for j in range(start, end+1):
        if arr[j] < x:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
            update(arr)
    i += 1
    arr[i], arr[end] = arr[end], arr[i]
    update(arr)
    return i


def update(arr):
    try:
        ax.clear()
        ax.bar(left=range(1, len(arr) + 1), height=arr, fc='g')
        plt.draw()
        plt.pause(0.001)
    except Exception as err:
        print(err)


if __name__ == "__main__":
    arr = [13, 19, 3, 5, 12, 8, 7, 4, 21, 2, 6, 11]
    print(arr)
    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1)
    plt.grid(True)  # 添加网格
    plt.ion()
    pic = ax.bar(left=range(0, len(arr)), height=arr, fc='g')
    quick_sort(0, len(arr) - 1)
    print(arr)
