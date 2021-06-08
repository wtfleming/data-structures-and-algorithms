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

