

;; 1.3 计算3个参数中较大2个参数值的和
(define (sum-of-three x y z) (+ x y z))
(define (min-of-two x y) (if (> x y) y x))
(define (sum-of-two-large x y z) (- (sum-of-three x y z) (min-of-two x (min-of-two y z))))

;; 牛顿法求平方根
(define (abss x) (if (< x 0) (- x) x))
(define (n-sqrt-imp i r s) (if (< (abss (- r (* i i))) s) i 
                               (n-sqrt-imp (/ (+ i (/ r i)) 2) r s)))
(define (n-sqrt r) (n-sqrt-imp 1 r 0.00001))



;;1.6 会出现死循环，判断条件应该总是为true，why？ n-sqrt2 会出现死循环，http://blog.csdn.net/keyboardota/article/details/9835239
(define (new-if cond1 do1 do2) (
                                cond (cond1 do1)
                                     (else do2)))
(define (n-sqrt-imp2 i r s) (new-if (< (abss (- r (* i i))) s) i 
                               (n-sqrt-imp2 (/ (+ i (/ r i)) 2) r s)))
(define (n-sqrt2 r) (n-sqrt-imp2 1 r 0.00001))

;; 1.7 优化牛顿法求平方根，计算2次guess差值对比guess的比例来终止条件 
(define (n-sqrt-opt-imp guess-old guess-new difference x) 
  (if (< (/ (abss (- guess-new guess-old)) guess-new) difference) guess-new (n-sqrt-opt-imp guess-new (/ (+ guess-new (/ x guess-new)) 2) difference x)))

(define (n-sqrt-opt x) (n-sqrt-opt-imp 0 1 0.0001 x))

;; 1.9 跳过

;; 1.10 ackermann 
(define (A x y) 
  (cond ((= y 0) 0)
        ((= x 0) (* 2 y))
        ((= y 1) 2)
        (else (A (- x 1) (A x (- y 1))))))

;;1.2.2 fibonacci
(define (fib x) 
  (cond ((= x 0) 0)
        ((= x 1) 1)
        (else (+ (fib (- x 1)) (fib (- x 2))))))

(define (fib-opt-imp a b count)
  (if (= count 0) b (fib-opt-imp (+ a b) a (- count 1))))


(define (fib-opt x) (fib-opt-imp 1 0 x)) 

;; 1.11 f(n) = f(n-1)+2f(n-2)+3f(n-3)

(define (fun-imp f3 f2 f1 count)
	(if (< count 3) f3  (fun-imp (+ f3 (* 2 f2) (* 3 f1)) f3 f2 (- count 1)))) 
(define (fun n)
  (if (< n 3) n (fun-imp 2 1 0 n)))
