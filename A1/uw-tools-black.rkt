#lang racket

(require "uw-api.rkt")

(provide cur-temp course-desc total-parking-capacity)

;; (cur-temp): return the cur-temp from the result of 
;; waterloo-api
;; cur-temp: void -> Num
(define (cur-temp)
  (local
   [;; lst: the result from uw-api
    (define lst (uw-api "/weather/current"))
    ;; (find-w lst): find the current temperature from the 
    ;; result
    ;; find-w: (lisfof Any) -> Num
    (define (find-w lst)
      (cond 
        [(string=? "temperature_current_c" (first (first lst))) (second (first lst))]
        [else (find-w (rest lst))]))]
   (find-w lst)))

;; (course-desc subject number): return the description of 
;; the course by given subject and number 
;; course-desc: String Num -> String
(define (course-desc subject number)
  (local
   [;; lst: the result from uw-api
    (define lst (uw-api (string-append "/courses/" subject "/" (number->string number))))
    ;; (find-d lst): find the course description from the 
    ;; result 
    ;; find-d: listof Any -> String
    (define (find-d lst)
      (cond 
        [(string=? "description" (first (first lst))) (second (first lst))]
        [else (find-d (rest lst))]))]
   (find-d lst)))

;; (total-parking-capacity): calculate the total parking 
;; capacity of all the parking lot in uw
;; total-parking-capacity: void -> Int
(define (total-parking-capacity)
  (local
   [;; lst: the result from uw-api
    (define lst (uw-api "/parking/watpark"))
    ;; (find-c lst): find the capacity of a parking lot
    ;; find-c: listof Any -> Int
    (define (find-c lst)
      (cond 
        [(string=? "capacity" (first (first lst))) (second (first lst))]
        [else (find-c (rest lst))]))
    ;; (find-p lst): sum the capacity of each parking lot
    ;; find-p lst: listof Any -> Int
    (define (find-p lst)
      (cond
       [(empty? lst) 0]
       [else (+ (find-c (first lst)) (find-p (rest lst)))]))]
   (find-p lst)))
