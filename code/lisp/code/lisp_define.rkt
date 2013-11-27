;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname lisp_define) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ())))
(define (area x y)(- (* x y) (+ x y)))
(define (my_abs x)
  (cond ((> x 0) x)
        ((= x 0) 0)
        ((< x 0)(- x))))

(define (cal x y)(* y 
                    (cond ((> y x) (cal x (- y 1)))
                          (else 1)
                           )))

(define (is_right s x)(