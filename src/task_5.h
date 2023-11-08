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





