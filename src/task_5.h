class FifthTask {
    public:    
        int numberOfTowers(int num){
            if(num == 1){
                return 1;
            } else {
                return 2 * numberOfTowers(num-1) + 1;
            }
        }
};





// void fifthTask(){
//     int numberOfTowers(int num);
//     int n = 8;
//     int minNumMoves = numberOfTowers(n);
    

//     int numberOfTowers(int num){
//          if (num == 1){ 
//             return 1; // T(1) = 1
//         } else {
//             return 2 * numberOfTowers(num-1) + 1;
//         }
//     }
    
//     std::cout << minNumMoves << "\n";
// }






