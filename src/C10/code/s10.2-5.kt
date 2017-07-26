package C10.code

/**
 * 10.2-5
 *
 * Created by MurphySL on 2017/7/26.
 */
class Node2(var value : Int){
    var next : Node2 = this

    operator fun plusAssign(value : Int) = insert(value)

    operator fun minusAssign(value : Int) = delete(value)

    fun toList() : ArrayList<Int>{
        val list  = ArrayList<Int>()
        this.let {
            var node = head2.next

            while (node != head2){
                list.add(node.value)
                node = node.next
            }
            return list
        }
    }

    private fun insert(value : Int){
        val node = Node2(value)
        node.next = head2.next
        head2.next = node
    }

    private fun delete(value : Int) {
        head2.value = value
        var prev = head2
        var node = head2.next
        while(node.value != value){
            node = node.next
            prev = prev.next
        }

        if(node != head2 ){
            prev.next = node.next
        }
    }
}

val head2 : Node2 = Node2(0) // 哨兵，作为哑对象，简化边界处理

fun main(args: Array<String>) {
    head2 += 1
    head2 += 2
    head2 += 3

    head2 -= 2

    head2.toList().forEach { println(it) }
}