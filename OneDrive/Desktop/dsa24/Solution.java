import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        int s = 0;
        findCombinations(0, res, candidates, target, s, temp);
        return res;
    }

    private void findCombinations(int i, List<List<Integer>> res, int[] candidates, int target, int s, List<Integer> temp) {
        if (i == candidates.length) {
            if (s == target) {
                res.add(new ArrayList<>(temp));
            }
            return;
        }
        if (s > target) {
            return;
        }

        // Include current candidate
        temp.add(candidates[i]);
        s += candidates[i];
        findCombinations(i, res, candidates, target, s, temp);

        // Exclude current candidate
        temp.remove(temp.size() - 1);
        s -= candidates[i];
        findCombinations(i + 1, res, candidates, target, s, temp);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] candidates = {2, 3, 5};
        int target = 8;

        // Get the result
        List<List<Integer>> result = solution.combinationSum(candidates, target);

        // Print the result
        System.out.println("Combinations summing to " + target + ":");
        for (List<Integer> combination : result) {
            System.out.println(combination);
        }
    }
}
