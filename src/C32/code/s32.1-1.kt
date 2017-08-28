package C32.code

fun main(args: Array<String>) {
    val s1 = "0001"
    val s2 = "0000100101001"

    naiveStringMather(s1, s2)
}

private fun naiveStringMather(s1 : String , s2 : String){

    var i = 0
    var j = 0
    for(index in 0..s2.length - s1.length){
        i = 0
        j = index
        println("${s1[i]} ${s2[j]} index : $index")

        while(s1[i] == s2[j]){
            println("while ${s1[i]} ${s2[j]}")
            i ++
            j ++
            if(i == s1.length){
                println("Pattern occurs with shift")
                return
            }
        }

    }
}