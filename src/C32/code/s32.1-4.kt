package C32.code

val separator = "X"

fun match(text : String, pat : String){
    val pats = pat.split(separator)

    //pats.forEach(::println)

    var origin = text
    var pos = 0
    while(pos < pats.size && origin.length >= pats[pos].length){
        //println("origin $origin")
        val result = naiveStringMather(pats[pos], origin)
        if(result == -1){
            break
        }else{
            if(pos == pats.size - 1){
                println("Pattern occurs with shift")
                return
            }
            origin = text.substring(result + 1)
            pos ++
        }
    }

}

private fun naiveStringMather(s1 : String , s2 : String) : Int{
    var i = 0
    var j = 0
    for(index in 0..s2.length - s1.length){
        i = 0
        j = index
        //println("${s1[i]} ${s2[j]} index : $index")

        while(s1[i] == s2[j]){
            //println("while ${s1[i]} ${s2[j]}")
            i ++
            j ++
            if(i == s1.length){
                //println("Pattern occurs with shift XXX")
                return index + 1
            }
        }

    }
    return -1
}

fun main(args: Array<String>) {
    val text = "cabccbacbacab"

    val pat = "abXbaXc"

    match(text, pat)
}