func numMagicSquaresInside(grid [][]int) int {
    result:=0
    for i:=0;i<len(grid)-2;i++ {
        for j:=0;j<len(grid[i])-2;j++ {
            if isMagic(grid,i,j){
                result++
            }
        }
    }
    return result
}

func isMagic(grid [][]int, row int, col int) bool {
    array:= [] bool{false,false,false,false,false,false,false,false,false}
    for i:=row;i<row+3;i++ {
        for j:=col;j<col+3;j++ {
            if grid[i][j]>=1 && grid[i][j]<=9 {
                if array[grid[i][j]-1] {
                    return false
                }else{
                    array[grid[i][j]-1] = true
                }
            }else{
                return false
            }
        }
    }
    
    for i:=row;i<row+3;i++ {
        sum:=0
        for j:=col;j<col+3;j++ {
            sum+=grid[i][j]
        }
        if sum!=15 {
            return false
        }
    }
    
    for i:=col;i<col+3;i++ {
        sum:=0
        for j:=row;j<row+3;j++ {
            sum+=grid[j][i]
        }
        if sum!=15 {
            return false
        }
    }
    
    if grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2]!=15 {
        return false
    }
    
    if grid[row+2][col]+grid[row+1][col+1]+grid[row][col+2]!=15 {
        return false
    }
    
    return true
}
