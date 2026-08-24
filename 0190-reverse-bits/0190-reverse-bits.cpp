class Solution {
public:
    int reverseBits(int n) {
        // Cast to unsigned to ensure logical right shifts (padding with 0 instead of sign bit)
        uint32_t unsigned_n = static_cast<uint32_t>(n);
        uint32_t result = 0;
        
        for (int i = 0; i < 32; ++i) {
            // Shift result left to clear space for the incoming bit
            result <<= 1;
            
            // Extract the rightmost bit of unsigned_n and place it into result
            result |= (unsigned_n & 1);
            
            // Logically shift unsigned_n right by 1
            unsigned_n >>= 1;
        }
        
        // Cast the fully reversed bit pattern back to a signed 32-bit integer
        return static_cast<int>(result);
  
    }
};