/**
 * Busca Binaria de Forma iterativa.
 * O(lg n)
 */

func buscaBinaria(itens:[Int], key:Int) -> Int?{
    var left = 0
    var middle = 0;
    var right = itens.count
    
    repeat{
        
        middle = (left + right)
        middle /= 2
        
        if itens[middle] == key{
            return middle
        }else if itens[middle] > key{
            right = middle - 1
        }else{
            left = middle + 1
        }
    }while (left <= right)
    
    return nil
    
}


let itens = [1,12,33,34,55,68,71,82,90]
buscaBinaria(itens: itens, key: 33)
buscaBinaria(itens: itens, key: 0)

