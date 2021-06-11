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

(deftest encode-test
  (testing "If a list contains repeated elements they should be placed in separate sublists."
    (is (= '((:a :a :a :a) (:b) (:c :c) (:a :a) (:d) (:e :e :e :e)) (encode '(:a :a :a :a :b :c :c :a :a :d :e :e :e :e))))))

