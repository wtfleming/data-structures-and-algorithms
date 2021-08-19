(ns ninety-nine-lisp-problems.core-test
  (:require [clojure.test :refer :all]
            [ninety-nine-lisp-problems.core :refer :all]))

(deftest my-last-test
  (testing "Finds the last box in a list."
    (is (= (my-last '(:a :b :c :d)) :d))))

(deftest my-but-last-test
  (testing "Finds the last but one box in a list."
    (is (= (my-but-last '(:a :b :c :d)) '(:c :d)))))

(deftest element-at-test
  (testing "Finds the K'th element of a list."
    (is (= (element-at '(:a :b :c :d :e) 3) :c)))
  (testing "Returns nil if n is larger than the length of the list"
    (is (= (element-at '(:a) 3) nil))))

(deftest my-count-test
  (testing "Find the number of elements of a list."
    (is (= (my-count '(:a :b :c :d)) 4)))
  (testing "Find the number of elements of an empty list."
    (is (= (my-count '()) 0))))

(deftest my-reverse-test
  (testing "Reverses a list."
    (is (= '(:d :c :b :a) (my-reverse '(:a :b :c :d))))))

(deftest is-palindrome-test
  (testing "Returns true if list is a palindrome."
    (is (= true (is-palindrome '(:x :a :m :a :x))))
    (testing "Returns false if list is not a palindrome."
      (is (= false (is-palindrome '(:x :a :m :a)))))))

(deftest my-flatten-test
  (testing "Flattens a list."
    (is (= '(:a :b :c :d :e) (my-flatten '(:a (:b (:c :d) :e)))))))

(deftest my-flatten-2-test
  (testing "Flattens a list."
    (is (= '(:a :b :c :d :e) (my-flatten-2 '(:a (:b (:c :d) :e)))))))

(deftest compress-test
  (testing "Compresses a list."
    (is (= '(:a :b :c :a :d :e) (compress '(:a :a :a :a :b :c :c :a :a :d :e :e :e :e)))))
  (testing "Compresses an empty list."
    (is (= '() (compress '())))))

(deftest pack-test
  (testing "If a list contains repeated elements they should be placed in separate sublists."
    (is (= '((:a :a :a :a) (:b) (:c :c) (:a :a) (:d) (:e :e :e :e)) (pack '(:a :a :a :a :b :c :c :a :a :d :e :e :e :e))))))

(deftest encode-test
  (testing "Run-length encoding of a list."
    (is (= '((4 :a) (1 :b) (2 :c) (2 :a) (1 :d) (4 :e)) (encode '(:a :a :a :a :b :c :c :a :a :d :e :e :e :e))))))

(deftest encode-modified-test
  (testing "Only elements with duplicates are transferred as (N E) lists."
    (is (= '((4 :a) :b (2 :c) (2 :a) :d (4 :e)) (encode-modified '(:a :a :a :a :b :c :c :a :a :d :e :e :e :e))))))

(deftest dencode-modified-test
  (testing "Only elements with duplicates are transferred as (N E) lists."
    (is (= '(:a :a :a :a :b :c :c :a :a :d :e :e :e :e) (decode-modified '((4 :a) :b (2 :c) (2 :a) :d (4 :e)))))))

(deftest dupli-test
  (testing "Duplicate the elements of a list."
    (is (= '(:a :a :b :b :c :c :c :c :d :d) (dupli '(:a :b :c :c :d))))))

(deftest repli-test
  (testing "Replicate the elements of a list a given number of times."
    (is (= '(:a :a :a :b :b :b :c :c :c) (repli '(:a :b :c) 3)))))

(deftest my-drop-test
  (testing "Drop every N'th element from a list"
    (is (= '(:a :b :d :e :g :h :k) (my-drop '(:a :b :c :d :e :f :g :h :i :k) 3)))))

(deftest my-split-test
  (testing "Split a list into two parts"
    (is (= '((:a :b :c) (:d :e :f :g :h :i :k)) (my-split '(:a :b :c :d :e :f :g :h :i :k) 3)))))

(deftest slice-test
  (testing "Extract a slice from a list"
    (is (= '(:c :d :e :f :g) (slice '(:a :b :c :d :e :f :g :h :i :k) 3 7)))))

(deftest rotest-test
  (testing "Rotate a list N places to the left"
    (is (= '(:d :e :f :g :h :a :b :c) (rotate '(:a :b :c :d :e :f :g :h) 3))))
  (testing "Rotate a list N places to the left with a negative N"
    (is (= '(:g :h :a :b :c :d :e :f) (rotate '(:a :b :c :d :e :f :g :h) -2)))))

(deftest remove-at-test
  (testing "Removes the K'th element from a list"
    (is (= '(:a :c :d) (remove-at '(:a :b :c :d) 2)))))

(deftest insert-at-test
  (testing "Insert an element at a given position into a list"
    (is (= '(:a :alfa :b :c :d) (insert-at :alfa '(:a :b :c :d) 2)))))

(deftest my-range-test
  (testing "Create a list containing all integers within a given range"
    (is (= '(4 5 6 7 8 9) (my-range 4 9)))))
