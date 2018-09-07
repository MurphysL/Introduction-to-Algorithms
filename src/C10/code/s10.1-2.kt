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

    init {
        values[0] = 0
        values[capacity + 1] = capacity + 1
    }

    fun emptyLeft() : Boolean = values[0] == 0

    fun emptyRight() : Boolean = values[capacity + 1] == capacity + 1

    fun full() : Boolean = values[0] + 1 == values[capacity + 1]

    fun push(pos : Position, value : Int){
        if(full()){
            throw IndexOutOfBoundsException("overflow")
        }else{
            if(pos == Position.LEFT)
                values[++ values[0]] = value
            else
                values[-- values[capacity + 1]] = value
        }
    }

    fun pop(pos : Position) : Int{
        return if(pos == Position.LEFT){
            if(emptyLeft())
                throw IndexOutOfBoundsException("underflow")
            else
                values[values[0] --]
        }else{
            if(emptyRight())
                throw IndexOutOfBoundsException("underflow")
            else
                values[values[capacity + 1] ++]
        }
    }
}

fun main(args: Array<String>) {
    val stack = Stack(5)
    stack.push(Position.LEFT, 1)
    stack.push(Position.RIGHT, 2)
    stack.push(Position.RIGHT, 3)
    println(stack.pop(Position.RIGHT))

    stack.push(Position.LEFT, 4)
    stack.push(Position.LEFT, 5)
    stack.push(Position.LEFT, 6)
    print(stack.full())
    stack.pop(Position.LEFT)
    stack.pop(Position.LEFT)
    stack.pop(Position.LEFT)
    stack.pop(Position.LEFT)
}

