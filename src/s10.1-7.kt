/**
 * 10.1-7
 *
 * Created by MurphySL on 2017/7/25.
 */
class Queue(val capacity : Int = 5){
    val inner_capacity = capacity + 1
    val values = IntArray(inner_capacity)
    var rear = 0
    var front = 0

    operator fun plusAssign(value : Int) = enqueue(value)

    fun empty() : Boolean = rear == front
    fun full() : Boolean = (rear + 1) % inner_capacity == front
    fun enqueue(value : Int) {
        if(full()){
            throw IndexOutOfBoundsException("overflow")
        }else{
            values[rear] = value
            rear = (rear + 1)%inner_capacity
        }
    }
    fun dequeue() : Int{
        if(empty()){
            throw IndexOutOfBoundsException("underflow")
        }else{
            val value = values[front]
            front = (front + 1) % inner_capacity
            return value
        }
    }
}

val queue1 = Queue()
val queue2 = Queue()

fun push(value : Int){
    if(queue1.full() || queue2.full()){
        throw IndexOutOfBoundsException("overflow")
    }else{
        if(queue2.empty())
            queue1 += value
        else
            queue2 += value
    }
}

fun pop() : Int{
    if(queue1.empty() && queue2.empty()){
        throw IndexOutOfBoundsException("underflow")
    }else{
        if(queue2.empty()){
            while((queue1.front + 1) % queue1.inner_capacity != queue1.rear){
                queue2 += queue1.dequeue()
            }
            return queue1.dequeue()
        }else{
            while((queue2.front + 1) % queue2.inner_capacity != queue2.rear){
                queue1 += queue2.dequeue()
            }
            return queue2.dequeue()
        }
    }
}

fun main(args: Array<String>) {
    push(1)
    push(2)
    push(3)
    push(4)
    println(pop())
    println(pop())
    println(pop())
    println(pop())
}

