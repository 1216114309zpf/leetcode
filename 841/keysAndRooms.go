func canVisitAllRooms(rooms [][]int) bool {
    queue:=make(chan int,len(rooms))
    var appear [] bool
    for i:=0; i<len(rooms); i++ {
        appear = append(appear,false)
    }
    
    count:=1
    size:=0
    appear[0]=true
    for i:=0; i<len(rooms[0]); i++ {
        if !appear[rooms[0][i]]{
            queue<-rooms[0][i]
            appear[rooms[0][i]]=true
            size++
        }
    }
    
    for size!=0 {
        current:=<-queue
        size--
        count++
        for j:=0; j<len(rooms[current]); j++ {
            if !appear[rooms[current][j]] {
                size++
                queue<-rooms[current][j]
                appear[rooms[current][j]]=true
            }
        }
    }
    
    if count==len(rooms) {
        return true
    }
    
    return false
}
