 function foo(fun, list, result) {
     if (list.length == 0) {
         return result
     }
     [first, ...list] = list
     value = fun(first) + fun(first)
     if (value < 0) {
         return foo(fun, list, [value, ...result])
     }
     return [value, ...foo(fun, list, result)]

 }

 foo(val => val, [-1, 1, -2, 2, -3, 3], [])



 function foo(list) {
     if (list.length == 0) {
         return list
     }
     [first, ...rest] = list
     const left = rest.filter((e => e < first));
     const right = rest.filter((e => e > first));

     console.log([...left, first, ...right]);
     return foo([...left, first, ...right]);

 }

 foo([3, 5, 2, 4, 5, 1, 3])