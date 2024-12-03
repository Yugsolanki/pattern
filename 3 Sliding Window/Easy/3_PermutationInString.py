def checkInclusion(s1, s2):
    s1map = {}
    for i in s1:
        if i in s1map:
            s1map[i] += 1
        else:
            s1map[i] = 1
    
    m = len(s1)
    n = len(s2)

    if m>n:
        return False
    
    for i in range(n-m+1):
        s2map = {}
        for j in range(m):
            s2map[s2[i+j]] = s2map.get(s2[i+j], 0) + 1
        
        if s1map == s2map:
            return True
    return False


s1 = "ab"
s2 = "eidbaooo"
print(checkInclusion(s1, s2)) # True