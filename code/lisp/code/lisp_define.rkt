;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname lisp_define) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ())))
(define (area x y)(- (* x y) (+ x y)))
(define (my_abs x)
  (cond ((> x 0) x)
        ((= x 0) 0)
        ((< x 0)(- x))))

;; run self 
(define (cal x y)(* y 
                    (cond ((> y x) (cal x (- y 1)))
                          (else 1)
                           )))

;;check is right
(define (is_right s x)(< (my_abs(- x (* s s))) 0.01))

;; like programming: if ? what : another
(define (my_abss x)(if (< x 0) (- x) x))

;; and
(define (check x)(and (> x 5) (< x 10)))
;; or
(define (check2 x)(or (> x 100) (< x 10)))

;; not
