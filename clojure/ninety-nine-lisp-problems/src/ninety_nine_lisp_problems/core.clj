(ns ninety-nine-lisp-problems.core)

(defn my-last
  "Finds the last box of a list"
  [coll]
  (let [[h & t] coll]
    (if t
      (recur t)
      h)))

(defn my-but-last
  "Find the last two boxes of a list"
  [coll]
  (->> coll
      reverse
      (take 2)
      reverse))

(defn element-at
  "Find the K'th element of a list.
  Note that unlike nth, the first element in the list is number 1."
  [coll n]
  (loop [[h & t] coll
         acc 1]
    (if (= acc n)
      h
      (recur t (inc acc)))))

(defn my-count
  "Find the number of elements of a list."
  [coll]
  (if (empty? coll)
    0
    (loop [coll coll
           acc 1]
      (if (next coll)
        (recur (rest coll) (inc acc))
        acc))))

(defn my-reverse
  "Reverse a list"
  [coll]
  (reduce conj '() coll))

(defn is-palindrome
  "Returns true if list is a palindrome, false otherwise"
  [coll]
  (= coll (reverse coll)))


;; Much more complicated compared to looking at (source flatten)
;; but this does work
(defn do-flatten
  "Transform a list, possibly holding lists as elements into a reversed `flat' list"
  [coll]
  (loop [coll coll
         acc '()]
    (if (empty? coll)
      acc
      (if (list? (first coll))
        (recur (rest coll) (concat (do-flatten (first coll)) acc))
        (recur (rest coll) (cons (first coll) acc))))))

(defn my-flatten
  "Transform a list, possibly holding lists as elements into a `flat' list"
  [coll]
  (reverse (do-flatten coll)))


(defn my-flatten-2
  "Transform a list, possibly holding lists as elements into a `flat' list"
  [coll]
  (if (list? coll)
    (mapcat my-flatten-2 coll)
    (list coll)))

(defn compress
  "If a list contains repeated elements they should be replaced with a single copy of the element. The order of the elements should not be changed."
  [coll]
  (if (empty? coll)
    coll
    (loop [coll coll
           current (first coll)
           acc [(first coll)]]
      (cond
        (empty? coll) acc
        (= (first coll) current) (recur (rest coll) current acc)
        :else (recur (rest coll) (first coll) (conj acc (first coll)))))))
