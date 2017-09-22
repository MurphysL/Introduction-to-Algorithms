import numpy as np
import matplotlib.pyplot as plt


def segment_intersect():
    d1 = direction(2, 3, 0)
    d2 = direction(2, 3, 1)
    d3 = direction(0, 1, 2)
    d4 = direction(0, 1, 3)
    print("{0} {1} {2} {3}".format(d1, d2, d3, d4))
    if ((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0)):
        return True
    elif d1 == 0 and on_segment(2, 3, 0):
        return True
    elif d2 == 0 and on_segment(2, 3, 1):
        return True
    elif d3 == 0 and on_segment(0, 1, 2):
        return True
    elif d4 == 0 and on_segment(0, 1, 3):
        return True
    else:
        return False


def direction(i, j , k):
    return (x[k] - x[i])*(y[j] - y[i]) - (x[j] - x[i])*(y[k] - y[i])


def on_segment(i, j, k):
    if max(x[i], x[j]) > x[k] > min(x[i], x[j]) and max(y[i].y[j]) > y[k] > min(y[i], [j]):
        return True
    else:
        return False


def min(x, y):
    if x < y:
        return x
    else:
        return y


def max(x, y):
    if x > y:
        return x
    else:
        return y


if __name__ == '__main__':
    x = np.random.randint(0, 100, 4)
    y = np.random.randint(0, 100, 4)
    if segment_intersect():
        print("相交")
    else:
        print("不相交")
    for i in range(0, 4):
        print("{0} {1}".format(x[i], y[i]))
        plt.scatter(x[i], y[i], c='g')
    plt.plot([x[0], x[1]], [y[0], y[1]])
    plt.plot([x[2], x[3]], [y[2], y[3]])
    plt.show()
