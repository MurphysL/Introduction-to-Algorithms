package C06.code

//以最小堆为例
fun PriorityQueue.delete(pos : Int){
    if(values[pos] == values[size]){
        size --
    }else if(values[pos] < values[size]){
        val tmp = values[pos] xor values[size]
        values[pos] = tmp xor values[pos]
        values[size] = tmp xor values[size]

        minHeapify(pos)
        size --
    }else{
        var p = pos
        values[p] = values[size]
        while(p > 1 && values[p/2] > values[size]){
            values[p] = values[p/2]
            p /= 2
        }
        values[p] = values[size]
        size --
    }
}

fun main(args: Array<String>) {
    val p_queue = PriorityQueue(10)
    p_queue += 10
    p_queue += 5
    p_queue += 3
    p_queue += 12
    p_queue += 6

    println(p_queue.minimum())
    p_queue.delete(1)
    println(p_queue.minimum())
}