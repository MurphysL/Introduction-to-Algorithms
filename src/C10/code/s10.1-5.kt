package C10.code

/**
 * 10.1-5
 *
 * Created by MurphySL on 2017/7/25.
 */
class Deque(capacity : Int = 10){
    val inner_capacity = capacity + 2
    val values = IntArray(inner_capacity)
    var front : Int = 0
    var rear : Int = 0

    fun empty() : Boolean = front == rear

    fun full() : Boolean = (rear + 1) % inner_capacity == front

    fun addFirst(value : Int){
        if(full()){
            throw IndexOutOfBoundsException("overflow")
        }else{
            if(empty()){
                rear = (rear + 1) % inner_capacity
            }
            values[front] = value
            if(front == 0)
                front = inner_capacity - 1
            else
                front --
        }
    }

    fun addLast(value : Int){
        if(full()){
            throw IndexOutOfBoundsException("overflow")
        }else{
            if(empty()){
                if(front == 0)
                    front = inner_capacity - 1
                else
                    front --
            }
            values[rear] = value
            rear = (rear + 1) % inner_capacity
        }
    }

    fun removeFirst() : Int{
        if(empty()){
            throw IndexOutOfBoundsException("underflow")
        }else{
            front = (front + 1) % inner_capacity
            return values[front]
        }
    }

    fun removeLast() : Int{
        if(empty()){
            throw IndexOutOfBoundsException("underflow")
        }else{
            if(rear == inner_capacity - 1){
                rear = 0
            }else{
                rear --
            }
            return values[rear]
        }
    }
}

fun main(args: Array<String>) {
    val deque = Deque(5)
    deque.addFirst(1)
    //println(deque.removeLast())

    deque.addLast(2)
    deque.addFirst(3)
    deque.addLast(4)
    deque.addFirst(5)
    println(deque.removeLast())
    println(deque.removeFirst())
    //deque.addLast(6)
}