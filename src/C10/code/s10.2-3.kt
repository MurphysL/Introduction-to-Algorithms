package C10.code

/**
 * 10.2-3
 *
 * Created by MurphySL on 2017/7/26.
 */
class QNode(val value: Int){
    var next : QNode? = null
}

val qhead : QNode = QNode(0)
var qrear : QNode = qhead

fun ENQUEUE(value : Int){
    val node : QNode = QNode(value)
    qrear.next = node
    qrear = node
}

fun DEQUEUE() : Int =
    qhead.next?.let {
        val value = it.value
        qhead.next = it.next
        value
    }?:throw IndexOutOfBoundsException("underflow")


fun main(args: Array<String>) {
    ENQUEUE(1)
    ENQUEUE(2)
    ENQUEUE(3)
    ENQUEUE(4)
    println(DEQUEUE())
    println(DEQUEUE())
    println(DEQUEUE())
    println(DEQUEUE())
}