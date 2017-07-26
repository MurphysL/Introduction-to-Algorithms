package C10.code

/**
 * 10.2-2
 *
 * Created by MurphySL on 2017/7/26.
 */
class SNode(val value : Int){
    var next : SNode? = null
}

val head : SNode = SNode(0)

private fun pushNode(value : Int){
    val node = SNode(value)
    node.next = head.next
    head.next = node
}

private fun popNode() : Int =
    head.next?.let {
        val value = it.value
        head.next = it.next
        value
    }?: throw IndexOutOfBoundsException("underflow")


fun main(args: Array<String>) {
    pushNode(1)
    pushNode(2)
    pushNode(3)
    pushNode(4)
    println(popNode())
    println(popNode())
    println(popNode())
    println(popNode())
}