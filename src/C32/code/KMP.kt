package C32.code

class KMP(pat : String, R : Int = 3){

    private val M : Int = pat.length
    private val dfa  = Array(R){IntArray(M)}

    init {
        var X = 0
        dfa[pat[0] - 'A'][0] = 1
        for(i in 1 until M){
            for(j in 0 until R){
                dfa[j][i] = dfa[j][X]
            }
            dfa[pat[i] - 'A'][i] = i + 1
            X = dfa[pat[i] - 'A'][X]
        }

    }

    fun search(text : String) : Int{
        var j = 0
        for(i in 0 until text.length){
            j = dfa[text[i] - 'A'][j]
            if(j == M) return i - M + 1
        }
        return -1
    }
}

fun main(args: Array<String>) {
    val kmp = KMP("ABABAC")
    println(kmp.search("AACAAAABABACACC"))
}