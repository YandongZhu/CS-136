#lang racket

(provide intersect)
;; (intersect lst1 lst2): produce a list of any that both exist in lst1 and lst2, the result list will follow the order  in lst1
;; intersect: (listof Any) (listof Any) -> (listof Any)
(define (intersect lst1 lst2)
  (local
    [;; (member? x lst): check x is in the given list or not
     ;; member?: any (listof any) -> Bool
     (define (member? x lst) 
       (not (false? (member x lst))))
     ;; (find-common lst1 lst2): create the list of item both
     ;; exist in lst1 and lst2
     ;; find-common: (listof Any) (listof Any) -> (listof Any)
     (define (find-common lst1 lst2)
       (cond
         [(empty? lst1) empty]
         [(member? (first lst1) lst2)
          (cons (first lst1)
                (find-common (rest lst1) lst2))]
         [else (find-common (rest lst1) lst2)]))]
    (find-common (foldr (lambda (x y)
                          (cons x (filter (lambda (z)
                                            (not (equal? x z))) y))) empty lst1) lst2)))
