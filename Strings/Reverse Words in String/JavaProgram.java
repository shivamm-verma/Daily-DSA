class Solution {
    public String reverseWords(String s) {
        int i;
        String s1="", word="";
        s=" "+s.trim();
        for(i=s.length()-1; i>=0; i--)
        {
            if(s.charAt(i)==' ')
            {
                if(word!="")
                {
                    s1=s1+" "+word;
                    word="";
                }
            }else
            {
                word=s.charAt(i)+word;
            }
        }
        return s1.trim();
    }
}