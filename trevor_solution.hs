module Main where

main = do
  putStrLn "Hello, World!"
  print nums
  putStrLn $ show (minMaxSum nums)
  print (missingNumber nums)

nums = [3, 7, 1, 2, 8, 4, 5]


minMaxSum lst = minMaxSum' (lst !! 0) (lst !! 0) 0 lst where
    minMaxSum' a b c [] = [a, b, c]
    minMaxSum' a b c (x : xs) = minMaxSum' (if x < a then x else a) (if x > b then x else b) (x + c) xs

missingNumber :: [Int] -> Int
missingNumber lst = do
    let r = minMaxSum lst
    let a = r !! 0
    let b = r !! 1
    let c = r !! 2
    return (2 * a + (b - a)) * (b - a + 1) / 2 - c
    
