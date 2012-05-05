(use srfi-1)

(define (square x) (* x x))

(- (fold + 0 (map square (iota 101)))
   (square (fold + 0 (iota 101))))
