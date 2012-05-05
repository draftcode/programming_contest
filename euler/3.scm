(define (largest-factor n)
  (let loop ((n n) (k 2) (m 1))
    (cond ((= n 1) m)
          ((= 0 (modulo n k))
           (loop (/ n k) 2 (max m k)))
          (else
            (loop n (+ k 1) m)))))

#?=(largest-factor 600851475143)
