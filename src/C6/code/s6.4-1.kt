package C6.code

class Heap1(val capacity : Int){
    val values = IntArray(capacity + 1)
    var size = 0
}

//origin size must > 2
fun heapSort (origin : IntArray) : IntArray{
    val heap : Heap1 = Heap1(origin.size)
    var position = 1
    origin.forEach {
        heap.values[position] = it
        heap.size ++
        position ++
    }

    for(i in heap.size downTo 2){
        buildMaxHeap(heap)

        heap.values[0] = heap.values[heap.size]
        heap.values[heap.size] = heap.values[1]
        heap.values[1] = heap.values[0]

        heap.size --
    }

    val result = IntArray(heap.values.size - 1)
    (1..heap.values.size - 1).forEach { result[it -1] = heap.values[it] }
    return result
}

fun buildMaxHeap(heap : Heap1){
    for(i in heap.size/2 downTo 1){
        maxHeapify(heap, i)
    }
}

fun maxHeapify(heap : Heap1, pos : Int){
    var largest = pos
    val left = pos * 2
    val right = pos * 2 + 1

    if(left <= heap.size && heap.values[left] > heap.values[largest]){
        largest = left
    }

    if(right <= heap.size && heap.values[right] > heap.values[largest]){
        largest = right
    }

    if(largest != pos){
        val tmp = heap.values[largest] xor heap.values[pos]
        heap.values[largest] = tmp xor heap.values[largest]
        heap.values[pos] = tmp xor heap.values[pos]
        maxHeapify(heap, largest)
    }
}

fun main(args: Array<String>) {
    val values = intArrayOf(5, 13, 2, 25, 7, 17, 20, 8, 4)
    heapSort(values).forEach{
        print("$it ")
    }
}