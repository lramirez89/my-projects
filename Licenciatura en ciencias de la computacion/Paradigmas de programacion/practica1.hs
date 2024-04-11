import Distribution.Simple.Utils (xargs)

--Ejercicio 1
max2:: Ord a => (a,a)->a
max2 (x,y) | x>=y = x
           | otherwise = y

--no está currificada, version currificada
max2c:: Ord a=> a->a->a
max2c x y | x>=y = x
           | otherwise = y

normaVectorial (x,y) = sqrt (x^2 + y^2)

normaVectorial2 x y = sqrt (x^2 + y^2)

substract = flip (-)

--version no currificada
substractc (a, b) = (flip (-)) a b

predecesor = substract 1 --recibe un solo parametro, es igual a la versio no currificada?

evaluarEnCero = \f-> f 0 --está currificada, recibe un solo parámetro

dosVeces = \g -> g . g -- está currificada, el primer parámetro es una funcion

dosVecesunc (g,e)= dosVeces g e


flipAll = map flip    --recibe in solo parámetro

flipRaro = flip flip  --está currificada

------------------------------------------------------------------------------------------------------------------------

--Ejercicio 2
curry' f x y = f (x,y)

uncurry' f (x,y) = f x y

------------------------------------------------------------------------------------------------------------------------
--Ejercicio 3
sum':: [Int]->Int
sum' = foldr (+) 0

elem' e = foldr (\x recu-> e==x || recu) False

--filter f [] = []
--filter f (x:xs)= if f x then x:filter f xs else filter f xs

filter' f = foldr (\x recu-> if (f x) then x:recu else recu ) []

--map f [] = []
--map f (x:xs) = (f x): map f xs 

map' f xs = foldr (\x recu -> f x : recu) [] xs 

--concat' xs [] = xs
--concat' (x:xs) ys = x: concat' xs ys

--concatinv ys [] = ys                         --misma funcion pero recibo los parametros al reves
--concatinv ys (x:xs) = x: concat' xs ys 

concatinv' ys = foldr (:) ys

concat':: [a]->[a]->[a]
concat' = flip concatinv' 














