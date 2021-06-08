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

