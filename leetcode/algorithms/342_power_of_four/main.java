class PowerOfFour {
    public boolean isPowerOfFour(int n) {
        if (Math.log10(n) / Math.log(4) % 1 == 0) {
            return true;
        }
        return false;
    }


    // Best Solution
    public boolean bestSolution(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
        // 0x55555555 is to get rid of those power of 2 but not power of 4
        // so that the single 1 bit always appears at the odd position
    }
}