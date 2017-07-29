package C6.code

class Heap(val capacity : Int){
    val values = IntArray(capacity + 1)
    var size = 0
}

fun maxHeapifyWithRecursion(heap : Heap, pos : Int){
    var largest : Int = pos
    val left = pos*2
    val right = pos * 2 + 1

    if(left <= heap.size && heap.values[largest] < heap.values[left]){
        largest = left
    }

    if(right <= heap.size && heap.values[largest] < heap.values[right]){
        largest = right
    }

    if(largest != pos){
        val temp = heap.values[pos] xor heap.values[largest]
        heap.values[pos] = temp xor heap.values[pos]
        heap.values[largest] = temp xor heap.values[largest]
        maxHeapifyWithRecursion(heap,largest)
    }

}

fun buildMaxHeapWithRecursion(heap : Heap){
    for(i in heap.size/2 downTo 1){
        maxHeapifyWithRecursion(heap, i)
    }
}

fun maxHeapify(heap : Heap,  origin : Int){

    var pos = origin
    while(true){
        var largest = pos
        val left = pos * 2
        val right = pos * 2 + 1

        if(left <= heap.size && heap.values[largest] < heap.values[left]){
            largest = left
        }

        if(right <= heap.size && heap.values[largest] < heap.values[right]){
            largest = right
        }

        if(pos != largest){
            val temp = heap.values[largest] xor heap.values[pos]
            heap.values[largest] = temp xor heap.values[largest]
            heap.values[pos]= temp xor heap.values[pos]
            pos = largest
        }else{
            break
        }
    }
}

fun buildMaxHeap(heap : Heap){
    for(i in heap.size / 2 downTo 1){
        maxHeapify(heap, i)
    }
}

fun minHeapifyWithRecursion(heap : Heap, pos : Int){
    var minimum = pos
    val left = pos * 2
    val right = pos * 2 + 1

    if(left <= heap.size && heap.values[minimum] > heap.values[left]){
        minimum = left
    }

    if(right <= heap.size && heap.values[minimum] > heap.values[right]){
        minimum = right
    }

    if(minimum != pos){
        val temp = heap.values[pos] xor heap.values[minimum]
        heap.values[pos] = temp xor heap.values[pos]
        heap.values[minimum] = temp xor heap.values[minimum]
        minHeapifyWithRecursion(heap, minimum)
    }

}

fun buildMinHeapWithRecursion(heap : Heap){
    for(i in heap.size / 2 downTo  1){
        minHeapifyWithRecursion(heap, i)
    }
}

fun printHeap(heap : Heap){
    println()
    for(i in 1..heap.size){
        print("${heap.values[i]}  ")
    }
    println()
}

fun main(args: Array<String>) {
    val heap : Heap = Heap(9)
    heap.values[1] = 5
    heap.size += 1
    heap.values[2] = 3
    heap.size += 1
    heap.values[3] = 17
    heap.size += 1
    heap.values[4] = 10
    heap.size += 1
    heap.values[5] = 84
    heap.size += 1
    heap.values[6] = 19
    heap.size += 1
    heap.values[7] = 6
    heap.size += 1
    heap.values[8] = 22
    heap.size += 1
    heap.values[9] = 9
    heap.size += 1

    printHeap(heap)

    buildMaxHeapWithRecursion(heap)

    printHeap(heap)

    buildMinHeapWithRecursion(heap)

    printHeap(heap)

    buildMaxHeap(heap)

    printHeap(heap)

}