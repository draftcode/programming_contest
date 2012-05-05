(use srfi-1)
(display (/ (apply * (iota 20 21)) (apply * (iota 20 1))))
