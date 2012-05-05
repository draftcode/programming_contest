(define (make-list n)
  (cond ((= n 1000) '())
        ((or (= 0 (modulo n 3))
             (= 0 (modulo n 5))) (cons n (make-list (+ n 1))))
        (else (make-list (+ n 1)))))

#?=(fold + 0 (make-list 1))
