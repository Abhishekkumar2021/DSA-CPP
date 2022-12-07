let list = new Array(101)
for(let i=0; i<list.length; i++) list[i] = true;
list[0] = list[1] = false
for(let i=2; i<list.length; i++){
    if(list[i]){
        for(let j=2*i; j<list.length; j+=i)
        list[j] = false
    }
}
for(let i=2; i<list.length; i++){
    if(list[i]){
        console.log(`${i} is a prime number.`)
    }
}
