(use srfi-13)

(define (reverse-number n)
  (string->number (string-reverse (number->string n))))

#?=(let loopx ((x 100) (m 0))
  (if (> x 999) m
      (loopx (+ x 1)
             (max m
                  (let loopy ((y 100) (m 0))
                    (if (> y 999) m
                        (loopy (+ y 1)
                               (let1 n (* x y)
                                     (if (= n (reverse-number n))
                                         (max m n)
                                         m)))))))))
