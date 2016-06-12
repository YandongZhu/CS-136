#lang racket

(provide range-missing)

;; (range-missing lon l-bound h-bound): produce a list of number that not exist the lon but within the low bound and high bound
;; range-missing: (listof Num) Int Int -> (listof Int)
(define (range-missing lon l-bound h-bound)
  (local
    [;; (member? x lst): check x is in the given list or not
     ;; member?: any (listof any) -> Bool
     (define (member? x lst)
       (not (false? (member x lst))))]
    (cond
      [(= h-bound l-bound)
         (cond
           [(member? l-bound lon) empty]
           [else (cons l-bound empty)])]
      [(member? l-bound lon)
       (range-missing lon (add1 l-bound) h-bound)]
      [else  (cons l-bound
                   (range-missing lon (add1 l-bound) h-bound))])))
