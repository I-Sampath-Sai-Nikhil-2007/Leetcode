class Solution {
    HashSet<Character> set;
    int k=0,i,j;
    public boolean isValidSudoku(char[][] brd) {
        for(i=0;i<9;i++){
            //row checking
            set = new HashSet<>();
            for(j=0;j<9;j++){
                if(brd[i][j]=='.'){
                    continue;
                }
                if (set.contains(brd[i][j])){
                    return false;
                }
                else{
                    set.add(brd[i][j]);
                }
            }
        }
        for(i=0;i<9;i++){
            //column checking
            set = new HashSet<>();
            for(j=0;j<9;j++){
                if(brd[j][i]=='.'){
                    continue;
                }
                if (set.contains(brd[j][i])){
                    return false;
                }
                else{
                    set.add(brd[j][i]);
                }
            }
        }
        for(i=0;i<9;i++){
            //box checking
            set = new HashSet<>();
            for(j=0;j<9;j++){
                if(brd[(i/3)*3+(j/3)][(i%3)*3+(j%3)] =='.'){
                    continue;
                }
                if(set.contains(brd[(i/3)*3+(j/3)][(i%3)*3+(j%3)])){
                    return false;
                }
                else{
                    set.add(brd[(i/3)*3+(j/3)][(i%3)*3+(j%3)]);
                }
            }
        }
        return true;
    }
}