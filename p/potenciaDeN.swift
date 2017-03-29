/**
 * Potencia x^n O(lgn)
 * T(n) = C + T(n/2)
 */

func pot(x:Int, n:Int) -> Int{
    if n == 0{
        return 1
    }
    if n == 1{
        return x
    }
    
    if n % 2 == 0{ //Par
        let temp = pot(x: x, n: n/2)
        return temp * temp
    }else{ //Impar
        let temp = pot(x: x, n: (n-1)/2)
        return x * (temp * temp)
    }
}

pot(x: 2, n: 1)
pot(x: 2, n: 2)
pot(x: 2, n: 3)
pot(x: 2, n: 4)
pot(x: 2, n: 5)
pot(x: 2, n: 6)

