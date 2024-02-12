module Main where

main = do
  print $ missingNumber nums1
  print $ missingNumber nums2
  print $ missingNumber nums3
  print $ missingNumber nums4
  
nums1 = [3, 7, 1, 2, 8, 4, 5]
nums2 = [11, 2, 10, 4, 5, 6, 7, 8, 1, 9]
nums3 = [4, 3, 1, 5]
nums4 = [23, 24, 22, 26, 28, 21, 20, 27, 19, 32, 31, 30, 29]

missingNumber lst = missingNumber' (lst !! 0) (lst !! 0) 0 lst where
    missingNumber' a b c [] = (floor ((2 * a + (b - a)) * (b - a + 1) / 2 - c))
    missingNumber' a b c (x : xs) = missingNumber' (if x < a then x else a) (if x > b then x else b) (x + c) xs
