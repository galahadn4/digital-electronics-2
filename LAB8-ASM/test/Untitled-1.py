def lfsr(seed, taps):
    import time
    sr, xor = seed, 0
    while 1:
        for t in taps:
            xor += int(sr[t-1])
        if xor%2 == 0.0:
            xor = 0
        else:
            xor = 1
        print(xor)
        print('')
        time.sleep(0.75)
        sr, xor = str(xor) + sr[:-1], 0
        print(sr)
        print('')
        time.sleep(0.75)

lfsr('1000',[0,1])

