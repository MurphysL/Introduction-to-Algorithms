package C10.code

/**
 * 10.2-7
 *
 * Created by MurphySL on 2017/7/26.
 */
class Node3(var value : Int){
    var next : Node3? = null

    operator fun plusAssign(value : Int) = insert(value)

    private fun insert(value : Int){
        val node = Node3(value)
        node.next = head3.next
        head3.next = node
    }

    fun toList() : ArrayList<Int>{
        val list  = ArrayList<Int>()
        this.let {
            var node = next

            while (node != null){
                list.add(node.value)
                node = node.next
            }
            return list
        }
    }
}

val head3 : Node3 = Node3(0)

fun reverse(){
    var node = head3.next
    var next : Node3?
    head3.next = null

    while(node != null){
        next = node.next
        node.next = head3.next
        head3.next = node
        node = next
    }
}


fun main(args: Array<String>) {
    head3 += 1
    head3 += 2
    head3 += 3
    head3 += 4
    head3 += 5
    head3.toList().forEach(::println)

    reverse()
    head3.toList().forEach(::println)
}

