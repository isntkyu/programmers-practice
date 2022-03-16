import java.util.*;

class Solution {
    ArrayList<Integer>[] graph;
    int[] infoCopy;
    int answer = 0;
    public void dfs (int node, int sheep, int wolf, ArrayList<Integer> nN) {
        if (infoCopy[node] == 0) sheep++;
        else wolf++;

        if (sheep == wolf) return;
        if (sheep > answer) answer = sheep;

        System.out.println("node = " + node  + " sheep = " + sheep + " wolf = " + wolf);

        ArrayList<Integer> nextNodes = new ArrayList<>();
        nextNodes.addAll(nN);
        nextNodes.remove(Integer.valueOf(node));
        for (int i = 0; i < graph[node].size(); i++) {
            nextNodes.add(graph[node].get(i));
        }
        for (int next: nextNodes) {
            dfs(next, sheep, wolf, nextNodes);
        }
    }

    public int solution(int[] info, int[][] edges) {  //
        infoCopy = info;
        graph = new ArrayList[info.length];

        for (int i = 0; i < info.length; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] edge: edges) {
            graph[edge[0]].add(edge[1]);
        }

        ArrayList<Integer> nextNodes = new ArrayList<>();
        nextNodes.add(0);
        dfs(0, 0, 0, nextNodes);

        return answer;
    }
}
