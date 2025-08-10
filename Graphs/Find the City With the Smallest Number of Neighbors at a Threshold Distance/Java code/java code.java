import java.util.*;

class java_code {
    public static int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] dist=new int[n][n];
       // Arrays.fill(dist,Integer.MAX_VALUE);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dist[i][j]=Integer.MAX_VALUE;
            }
        }
        int m=edges.length;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        for(int i=0;i<n;i++) dist[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(dist[i][k]==Integer.MAX_VALUE || dist[k][j]==Integer.MAX_VALUE){
                        continue;
                    }
                    dist[i][j]=Math.min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int cityCnt=n+1;
        int cityNo=-1;
        for(int i=0;i<n;i++) {
            int cnt=0;
            for(int j=0;j<n;j++) {
                if(dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cityCnt >= cnt){
                cityCnt = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
    public static void main(String[] args) {
        int n=4;
        int[][] egdes={{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
        int distanceThreshold = 4;
        System.out.println(findTheCity(n, egdes, distanceThreshold));
    }
}
