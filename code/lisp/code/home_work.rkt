;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname home_work) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ())))
;;1.3 Define a procedure that takes three numbers as arguments and returns the sum of the squares of the two larger numbers.
(define (sq x)(* x x))
(define (f2 x y)(if (< x y) x y))
(define (f3 x y z)(f2 (f2 x y) (f2 y z)))
(define (sum_3 x y z)(- (+ (sq x) (sq y) (sq z)) (sq(f3 x y z))))
 
;;1.4 implemenets:
;;   (define (a-plus-abs-b a b)
;;   ((if (> b 0) + -) a b))
 
(define (a_b a b)(if(> b 0) (+ a b) (- a b)))

;;newtown cal sqrt
(define (is_ok a b t)(< (abs(- (* a a) b)) t))
(define (n_sqrt a b t)(if (is_ok a b t) a (n_sqrt (/ (+ a (/ b a)) 2) b t)))