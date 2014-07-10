;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname basic) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f ())))
(define PI 3.14159267)
;; define the method, fmt: (define (<name> <arguments>...) (<body>))
(define (area_of_circle r) (* r r PI))
(define (square x) (* x x))
(define (sum-of-squares x y) (+ (square x) (square y)))

;; cond 
(define (my-abs x) 
  (cond ((> x 0) x)
        ((= x 0) 0)
        ((< x 0) (- x))))
(define (my-abs2 x)
  (cond ((< x 0) (- x))
        (else x)))

;; like if...?<do_1>:<do_2>
(define (my-abs3 x)
  (if (< x 0) (- x) x))

(define (test-score s) 
  (cond 
    ((> s 90) "perfect")
    ((> s 80) "good")
    ((> s 70) "fine")
    ((> s 60) "normal")
    (else "bad"))
  )