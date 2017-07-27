package C10.code

import java.util.Stack

/**
 * 10.4-3
 *
 * Created by MurphySL on 2017/7/27.
 */
class BinTreeNode(val value : Int){
    var left : BinTreeNode? = null
    var right : BinTreeNode? = null
}

fun preorderTraversal(root : BinTreeNode) : List<Int>{
    val list = ArrayList<Int>()
    val stack = Stack<BinTreeNode>()

    var node : BinTreeNode? = root
    stack.add(node)
    while(!stack.empty()){
        node = stack.pop()
        node?.let {
            list.add(it.value)
            stack.add(it.right)
            stack.add(it.left)
        }
    }
    return list
}

fun main(args: Array<String>) {
    val root = BinTreeNode(18)
    root.left = BinTreeNode(12)
    root.right = BinTreeNode(10)
    root.left!!.left = BinTreeNode(7)
    root.left!!.right = BinTreeNode(4)

    preorderTraversal(root).forEach(::println)
}