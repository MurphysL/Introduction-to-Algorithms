package C10.code

/**
 * 10.2-4
 *
 * Created by MurphySL on 2017/7/26.
 */
class Node(var value : Int){
    var prev : Node = this
    var next : Node = this

    operator fun plusAssign(value : Int) = insert(value)

    private fun insert(value : Int){
        val node = Node(value)
        nil.next.prev = node
        node.next = nil.next
        nil.next = node
        node.prev = nil
    }

    fun toArray() : MutableList<Int>{
        val array : ArrayList<Int> = ArrayList()
        var node = nil.next
        while(node != nil){
            array += node.value
            node = node.next
        }
        return array
    }
}

val nil = Node(0)

fun search(value : Int) : Node{
    nil.value = value
    var node = nil.next
    while(node.value != value){
        node = node.next
    }
    return node
}

fun main(args: Array<String>) {
    nil += 1
    nil += 2
    nil += 3
    nil += 4

    nil.toArray().forEach(::println)
    if(search(5) != nil)
        println("GOT IT")
    else
        println("NOT FOUND")
}

