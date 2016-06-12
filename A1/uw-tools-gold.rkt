#lang racket

(require "uw-api.rkt")

(provide parking-availability course-sections course-capacity)

;; (parking-availability lot): produce the current available
;; number of spcific parking lot
;; parking-availability: String -> Num
(define (parking-availability lot)
  (local
   [;; lst: the result from uw-api
    (define lst (uw-api "/parking/watpark"))
    ;; name: (list String String)
    (define name (list "lot_name" lot))
    ;; (member? x lst): check x is in the given list or not
     ;; member?: any (listof any) -> Bool
    (define (member? x lst) 
      (not (false? (member x lst))))
    ;; (find-lot lst): find the parking lot by given string
    ;; find-lot： (list Str Str) -> listof Any
    (define (find-lot lst)
      (cond 
        [(member? name (first lst)) (first lst)]
        [else (find-lot (rest lst))]))
    ;; (find-c lst1): find the current available space in the 
    ;; given parking lot
    ;; find-c: listof Any -> Num
    (define (find-c lst1)
      (cond
        [(string=? "current_count" (first (first lst1)))
         (second (first lst1))]
       [else (find-c (rest lst1))]))]
   (find-c (find-lot lst))))

;; (course-sections term subject number): return all the 
;; section information by given term subject and number
;; course-sections: Num Str Num -> listof Str
(define (course-sections term subject number)
  (local
   [;; lst: the result from uw-api
    (define lst (uw-api (string-append "/terms/" (number->string term) "/" subject "/" (number->string number) "/schedule")))
    ;; (find-l lst): find the name of a section
    ;; find-l: listof Any -> Str
    (define (find-l lst)
      (cond 
        [(string=? "section" (first (first lst))) (second (first lst))]
        [else (find-l (rest lst))]))
    ;; (create-lst lst): find all the section names from a 
    ;; course
    ;; create-lst: listof Any -> listof Str
    (define (create-lst lst)
      (cond
        [(empty? lst) empty]
        [else (cons (find-l (first lst))
                    (create-lst (rest lst)))]))]
   (create-lst lst)))

;; (courese-capacity term subject number): return all the 
;; section enrollment status of a course
(define (course-capacity term subject number)
  (local
   [;; lst: the result from uw-api
    (define lst (uw-api (string-append "/terms/" (number->string term) "/" subject "/" (number->string number) "/schedule")))
    ;; (find-l lst): find the enrollment status of a 
    ;; section
    ;; find-l: listof Any -> listof Str
    (define (find-l lst)
      (cond
       [(empty? lst) empty]
       [(string=? "section" (first (first lst))) (cons (second (first lst)) (find-l (rest lst)))]
       [(string=? "enrollment_capacity" (first (first lst)))
        (cons (second (first lst)) (find-l (rest lst)))]
       [(string=? "enrollment_total" (first (first lst))) (cons (second (first lst)) (find-l (rest lst)))]
       [else (find-l (rest lst))]))
    ;; (create-lst lst): find the enrollment status of all
    ;; the sections
    ;;create-lst: listof Any -> (listof (listof Str))
    (define (create-lst lst)
      (cond
        [(empty? lst) empty]
        [else (cons (find-l (first lst))
                    (create-lst (rest lst)))]))]
   (create-lst lst)))
