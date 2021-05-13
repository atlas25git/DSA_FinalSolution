//no consecutive ones;
// for n=2 => {00,01,10} 11 not allowed

//recurrence->
//given last digit=>
//0->f(n-1)
//1->f(n-2)//fixing second last as 0
//=> f(n)  f(n-1) + f(n-2);