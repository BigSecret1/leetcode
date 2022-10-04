class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        n = len(data)
        i = 0
        
        while i < n:
            valid_encoding = False
            if self.one_byte_encoding(data[i]):
                i += 1
                valid_encoding = True
            
            for byte_len in range(2, 4 + 1):
                if self.byte_encoding(byte_len, data, i):
                    i += byte_len
                    valid_encoding = True
                    break
            
            if not valid_encoding:
                return False
        return True
    
    def one_byte_encoding(self, number: int):
		# check if 8th bit is set
        if number & 1 << 7 == 0:
            return True
        return False

    def byte_encoding(self, byte_len, data, i):
        # out of bound check
        if i + byte_len > len(data):
            return False

        # first byte should be byte_len 1's followed by 0
        first_byte = data[i]
        for j in range(byte_len):
            if first_byte & 1<<(7-j) == 0:
                return False

        # check n+1 bit to be 0
        if first_byte & 1 << 7 - byte_len != 0:
            return False

		# the rest n-1 bytes should be 10xxxxxx
        for j in range(i+1, i + 1 + (byte_len - 1)):
            # check 10xxxxxx
            if data[j] & 1<<7 == 0:
                return False
            if data[j] & 1<< 6 != 0:
                return False
        return True
