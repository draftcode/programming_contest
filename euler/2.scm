(define (fib pp p)
  (let ((r (+ pp p)))
    (if (> r 4000000) 0
        (if (even? r)
            (+ r (fib p r))
            (fib p r)))))

#?=(fib 0 1)
