function k = primf(f, N)
    
    for i=1:N
        k(i) = sum(f(1:i))
    end