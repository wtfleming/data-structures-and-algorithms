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
  (->> coll
       (partition-by identity)
       (map first)))

(defn pack
  "Pack consecutive duplicates of list elements into sublists."
  [coll]
  (partition-by identity coll))

(defn encode
  "Run-length encoding of a list"
  [coll]
  (->> coll
       pack
       (map #(list (count %) (first %)))))

(defn encode-modified
  "Modify the result of encode in such a way that if an element has no duplicates it is simply copied into the result list. Only elements with duplicates are transferred as (N E) lists."
  [coll]
  (->> coll
       pack
       (map #(if (= (count %) 1)
               (first %)
               (list (count %) (first %))))))

(defn decode-modified
  "Given a run-length code list generated as specified in encode-modified. Construct its uncompressed version."
  [coll]
  (->> coll
       (map #(if (seq? %)
               (repeat (first %) (second %))
               (list %)))
       (reduce concat)))

(defn dupli
  "Duplicate the elements of a list."
  [coll]
  (mapcat #(list % %) coll))

(defn repli
  "Replicate the elements of a list a given number of times."
  [coll x]
  (mapcat #(repeat x %) coll))

(defn my-drop
  "Drop every N'th element from a list"
  [coll x]
  (loop [coll coll
         pos 1
         acc []]
    (if (empty? coll)
      acc
      (if (= pos x)
        (recur (rest coll) 1 acc)
        (recur (rest coll) (inc pos) (conj acc (first coll)))))))

(defn my-split
  "Split a list into two parts; the length of the first part is given."
  [coll x]
  (loop [coll coll
         pos 0
         acc []]
    (if (= pos x)
      (list acc coll)
      (recur (rest coll) (inc pos) (conj acc (first coll))))))

(defn slice
  "Extract a slice from a list. Given two indices, I and K, the slice is the list containing the elements between the I'th and K'th element of the original list (both limits included). Start counting the elements with 1."
  [coll i k]
  (loop [coll coll
         pos 1
         acc []]
    (cond
      (> pos k) acc
      (>= pos i) (recur (rest coll) (inc pos) (conj acc (first coll)))
      :else (recur (rest coll) (inc pos) acc))))

(defn rotate
  "Rotate a list N places to the left"
  [coll x]
  (cond
    (= 0 x) coll
    (> x 0) (let [[a b] (my-split coll x)]
              (concat b a))
    :else (rotate coll (+ (count coll) x))))
