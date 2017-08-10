package C6.code

class PriorityQueue(val capacity : Int){
    val values = IntArray(capacity + 1)
    var size = 0

    operator fun plusAssign(value : Int) = insert(value)

    fun minimum() : Int = values[1]

    fun extractMin() : Int {
        if(size < 1)
            throw Exception("heap underflow")
        val min = values[1]
        values[1] = values[size]
        values[size] = min
        size --
        minHeapify(1)
        return min
    }

    private fun insert(value : Int){
        size ++
        values[size] = Int.MAX_VALUE
        decreaseKey(size, value)
    }

    private fun decreaseKey(pos : Int, value : Int){
        if(values[pos] < value)
            throw Exception("now key is bigger than current key")

        values[pos] = value
        var i = pos
        while(i > 1 && values[i] < values[i / 2]){
            val tmp = values[i] xor values[i / 2]
            values[i] = tmp xor values[i]
            values[i / 2] = tmp xor values[i / 2]

            i /= 2
        }
    }

    fun minHeapify(pos : Int){
        var min = pos
        val left = pos * 2
        val right = pos * 2 + 1

        if(left <= size && values[left] < values[min]){
            min = left
        }

        if(right <= size && values[right] < values[min]){
            min = right
        }

        if(min != pos){
            val tmp = values[min] xor values[pos]
            values[min] = tmp xor values[min]
            values[pos] = tmp xor values[pos]
            minHeapify(min)
        }
    }
}

fun main(args: Array<String>) {
    val p_queue = PriorityQueue(10)
    p_queue += 1
    p_queue += 2
    p_queue += 10
    p_queue += 5

    println(p_queue.minimum())
    println(p_queue.extractMin())
    println(p_queue.extractMin())
    println(p_queue.extractMin())
    println(p_queue.extractMin())
    //println(p_queue.extractMin())
}



