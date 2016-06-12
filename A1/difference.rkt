#lang racket

(provide difference)

;; (defference lst1 lst2): return a list of any that in lst1 
;; or lst2 but not both, it comes from lst1 to lst2
;; difference: (listof Any) (listof Any) -> (listof Any) 
(define (difference lst1 lst2)
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
         [else (find-common (rest lst1) lst2)]))
     ;; re-lst: the list of item both in list1 and list2
     (define re-lst (find-common lst1 lst2))]
      (append (foldr (lambda (x y)
                            (cons x (filter (lambda (z)
                                              (not (equal? x z))) y)))
                     empty
                     (filter (lambda (x)
                               (not (member x re-lst))) lst1))
              (foldr (lambda (x y)
                          (cons x (filter (lambda (z)
                                            (not (equal? x z))) y)))
                   empty
                   (filter (lambda (x)
                             (not (member x re-lst))) lst2)))))
