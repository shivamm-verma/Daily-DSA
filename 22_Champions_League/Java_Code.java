import java.lang.*;
import java.util.*;

class Java_Code
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while(t-->0){
            HashMap<String, int[]> teams = new HashMap<>();
            for(int i = 0;i<12;i++){
                String line = sc.nextLine();
                String arr[] = line.split(" ");
                teams.put(arr[0], teams.getOrDefault(
                    arr[0],new int[2]
                ));
                teams.put(arr[4], teams.getOrDefault(
                    arr[4],new int[2] 
                ));
                
                if(Integer.parseInt(arr[1]) > Integer.parseInt(arr[3])){
                    teams.get(arr[0])[0] += 3;
                } else if(Integer.parseInt(arr[1]) < Integer.parseInt(arr[3])){
                    teams.get(arr[4])[0] += 3;
                } else {
                    teams.get(arr[0])[0] += 1;
                    teams.get(arr[4])[0] += 1;
                }
                
                teams.get(arr[0])[1] += Integer.parseInt(arr[1]) - Integer.parseInt(arr[3]);
                teams.get(arr[4])[1] += Integer.parseInt(arr[3]) - Integer.parseInt(arr[1]);
            }
            String f = "",s = "";
            for(Map.Entry<String, int[]> e : teams.entrySet()){
                String name = e.getKey();
                int[] score = e.getValue();
                if(f == ""){
                    f = name;
                } else if (s == ""){
                    if((teams.get(f)[0] < score[0]) || (teams.get(f)[0] == score[0] && teams.get(f)[1] < score[1])){
                        s = f;
                        f = name;
                    } else {
                        s = name;
                    }
                } else {
                    if((teams.get(f)[0] < score[0]) || (teams.get(f)[0] == score[0] && teams.get(f)[1] < score[1])){
                        s = f;
                        f = name;
                    } else if ((teams.get(s)[0] < score[0]) || (teams.get(s)[0] == score[0] && teams.get(s)[1] < score[1])) {
                        s = name;
                    }
                }
            }
            System.out.println(f + " " + s);
        }
	}
}
