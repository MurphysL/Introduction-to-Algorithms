package C10.code

/**
 * 10.1-6
 *
 * Created by MurphySL on 2017/7/25.
 */
class Stack1(val capacity :Int = 10){
    val values = IntArray(capacity + 1) // values[0] 设为哨兵
    var top : Int = 0

    operator fun plus(value : Int) = push(value)
}

fun Stack1.empty() : Boolean = top == 0

fun Stack1.full() : Boolean = top == capacity

fun Stack1.pop() : Int =
        if(empty())
            throw IndexOutOfBoundsException("underflow")
        else {
            top --
            values[top + 1]
        }

fun Stack1.push(value : Int) =
        if(full())
            throw IndexOutOfBoundsException("overflow")
        else
            values[++ top] = value

fun Stack1.size() : Int = top

val stack1 : Stack1 = Stack1(4)
val stack2 : Stack1 = Stack1(4)

fun enqueue(value : Int){
    stack1.push(value)
}

fun dequeue() : Int{
    if(stack2.empty()){
        if(!stack1.empty()){
            for(i in 1..stack1.size()){
                stack2.push(stack1.pop())
            }
            return stack2.pop()
        }else{
            throw IndexOutOfBoundsException("underflow")
        }
    }else{
        return stack2.pop()
    }
}

fun main(args: Array<String>) {

    enqueue(1)
    enqueue(2)
    enqueue(3)
    enqueue(4)

    println(dequeue())
    println(dequeue())
    println(dequeue())
    println(dequeue())

}

