//last discussed apporach to solve inv count using bit won't work for negative nos, and if th erange is very large
//array is compressed for a range using a diff array in relative ordering

//100|99|82|11|97
// 5 | 4| 2| 1|3

//we can use a set, insert them all and then give indices to top elements
//maintain a hashmap