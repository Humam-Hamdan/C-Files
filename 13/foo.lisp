(defun foo (n)
  (if (< n 2)
      n
      (+ (foo (- n 1)) (foo (- n 2))
      )
  )
)

