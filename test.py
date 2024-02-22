def minNumMonedasPD(C, S):
    M = [float('inf')] * (C + 1)
    M[0] = 0
    
    for cantidad in range(1, C + 1):
        for i in S:
            if cantidad >= i:
                num = M[cantidad - i] + 1
                if num < M[cantidad]:
                    M[cantidad] = num

    return M[C]

# Example usage
C = 10
S = {2, 3, 4}
result = minNumMonedasPD(C, S)
print("Minimum number of coins:", result)
