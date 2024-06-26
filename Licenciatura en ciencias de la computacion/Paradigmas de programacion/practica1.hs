
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

mejorSegun::(a->a->Bool)->[a]->a 
--mejorSegun f (x:[]) = x
--mejorSegun f (x:xs)= if f x (mejorSegun f xs) then x else mejorSegun f xs 

mejorSegun f = foldr1 (\x recu -> if f x recu then x else recu)


--sumasParcialesrev:: Num a=> [a]->[a]
--sumasParcialesrev (x:[])= [x]
--sumasParcialesrev (x:xs)= [x+ sum xs ] ++ sumasParcialesrev xs

--sumasParciales xs  = reverse (sumasParcialesrev (reverse xs) )         -- NO ES RECURSION ESTRUCTURAL!! es primitiva


sumasParcialesRev ac [] = ac
sumasParcialesRev [] (x:xs) = sumasParcialesRev  [x] xs 
sumasParcialesRev ac (x:xs) = sumasParcialesRev ( (x+head ac): ac ) xs

--sumasParciales xs = reverse (sumasParcialesRev [] xs)
sumasParciales:: Num a=> [a]->[a]
sumasParciales xs = reverse (foldl (\ac x-> if length ac ==0 then [x] else x+(head ac):ac ) [] xs)

--Es más intuitivo hacerlo con rec iterativa? 

sumaAlt :: Num a => [a]-> a
sumaAlt = foldr (-) 0

sumaAltRev:: Num a => [a] -> a
sumaAltRev xs |length xs `mod` 2 ==1 = sumaAlt xs
              |otherwise             = -sumaAlt xs


----------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------
-- Ejercicio 5

elementosEnPosicionesPares :: [a]-> [a] 
elementosEnPosicionesPares [] = [] 
elementosEnPosicionesPares (x:xs) = if null xs 
                                    then [x] 
                                    else x : elementosEnPosicionesPares (tail xs)

        --no es estructural porque opera con xs? Es primitiva
        --elementosEnPosicionesPares :: [a] -> [a]
        --elementosEnPosicionesPares xs = foldr (\(i, x) acc -> if even i then x : acc else acc) [] (zip [0..] xs)

entrelazar :: [a]-> [a]-> [a] 
entrelazar [] = id 
entrelazar (x:xs) = \ys-> if null ys 
                          then x : entrelazar xs [] 
                          else x : head ys : entrelazar xs (tail ys)
            --no es estructural, es primitiva porque utiliza xs 

------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------
-- Ejercicio 6

recr :: (a-> [a]-> b-> b)-> b-> [a]-> b 
recr _ z [] = z 
recr f z (x : xs) = f x xs (recr f z xs)

sacarUna :: Eq a => a-> [a]-> [a]
--sacarUna e [] = []
--sacarUna e (x:xs) | e==x = xs
--                  | otherwise = x: sacarUna e xs

sacarUna e = recr (\x xs recu  -> if e==x then xs else x:recu) [] 

insertarOrdenado :: Ord a => a-> [a]-> [a]
--insertarOrdenado elem []  = [elem]
--insertarOrdenado elem (x:xs) | elem<=x = elem: (x:xs)
--                             | otherwise = x: insertarOrdenado elem xs

insertarOrdenado elem = recr (\x xs recu-> if elem<=x then elem:(x:xs) else x:recu) [elem]


---------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
-- Ejercicio 8

mapPares:: (a->b->c) -> [(a,b)] -> [c]
mapPares f xs = map (uncurry f) xs

--Toma "dos argumentos" y devuelve una lista de tuplas
--armarPares:: [a]->[b] ->[(a,b)]
--armarPares xs [] = []
--armarPares xs (y:ys) | null xs = []
--                     | otherwise = (head xs, y) : armarPares (tail xs) ys

--Toma una lista y devuelve una funcion que toma por parámetro una lista y devuelve una lista de tuplas
armarPares:: [a]->[b] ->[(a,b)]
--armarPares [] = const []
--armarPares (x:xs) = (\ys -> if null ys then [] else (x,head ys): armarPares xs (tail ys) )

armarPares = foldr (\x recu-> (\ys-> if null ys then [] else (x,head ys):recu (tail ys)))   (const [])
                    --aprovechando la currificacion se puede escribir como un lambda que tome tres paranetros x recu ys

--Transformo a f e una funcion que tome un solo artumento (dupla) y aplico a las duplas armadas mediante zip
mapDoble:: (a->b->c) -> [a] -> [b] -> [c]
mapDoble f xs ys = map (uncurry f) (zip xs ys)


------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------
-- Ejercicio 10

generate :: ([a]-> Bool)-> ([a]-> a)-> [a] 
generate stop next = generateFrom stop next [] 

generateFrom:: ([a]-> Bool)-> ([a]-> a)-> [a]-> [a] 
generateFrom stop next xs | stop xs = init xs 
                          | otherwise = generateFrom stop next (xs ++ [next xs])

--esete no salió
--generateFrom stop next xs =  takeWhile stop (concat (iterate (\xs -> [next xs])  [] ) ) 

generateBase::([a]-> Bool)-> a-> (a-> a)-> [a]
generateBase stop casoBase next = generate stop (\xs -> if null xs then casoBase else next (last xs) )

potencias2  n = generateBase (\xs -> length xs == n) 2 (\x -> x*2 ) 
pot2menores256= generateBase (\l->not(null l )&& (last l > 256))1(*2) 

factoriales n = generate (\xs -> length xs == n ) (\xs -> if null xs then 1 else last xs * length xs )

iterateN :: Int-> (a-> a)-> a-> [a]
iterateN n f x = generateBase (\xs -> length xs == n+1 ) x (\elem -> f elem) 

--implementacion de iterateN dada en la guia de ejercicios
--iterateN n f x = take n (iterate f x)


---------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------
-- Ejercicio 11
foldNat:: (Integer->Integer) -> Integer -> Integer -> Integer
foldNat f b 0 = b
foldNat f b n = f (foldNat f b (n-1))

--potencia a 1 = a
--potencia a n = potencia a (n-1) * a 

potencia a = foldNat (\recu-> recu*a) 1


-------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------
-- Ejercicio 13
data AB a = Nil | Bin (AB a) a (AB a)

--foldAB 