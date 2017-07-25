package C10.code
/**
 * 10.1-2
 *
 * Created by MurphySL on 2017/7/25.
 */

enum class Position{
    LEFT, RIGHT
}

class Stack(val capacity : Int = 10){
    val values = IntArray(capacity + 2)
    var left_top = 0
    var right_top = capacity + 1

    fun empty() : Boolean = left_top == 0 && right_top == capacity + 1

    fun full() : Boolean = left_top + 1 == right_top

    fun push(pos : Position, value : Int){
        if(full()){
            throw IndexOutOfBoundsException("overflow")
        }else{
            if(pos == Position.LEFT)
                values[++ left_top] = value
            else
                values[-- right_top] = value
        }
    }

    fun pop(pos : Position) : Int{
        if(empty()){
            throw IndexOutOfBoundsException("underflow")
        }else{
            if(pos == Position.LEFT){
                left_top --
                return values[left_top + 1]
            }else{
                right_top ++
                return values[right_top - 1]
            }
        }
    }
}

fun main(args: Array<String>) {
    val stack = Stack(5)
    //println(stack.C10.code.pop(C10.code.Position.LEFT))
    stack.push(Position.LEFT, 1)
    stack.push(Position.RIGHT, 2)
    stack.push(Position.RIGHT, 3)
    println(stack.pop(Position.RIGHT))

    stack.push(Position.LEFT, 4)
    stack.push(Position.LEFT, 5)
    stack.push(Position.LEFT, 6)
    stack.push(Position.RIGHT, 7)
}

