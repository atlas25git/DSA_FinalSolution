//opptimization to do Range Updates in seg trees in O(logN)
//Postpone the updates to descendants of a node untill they themseleves aren't require to be accessed

//when assigned lazy value l, to children of a node in question,whose value is changed, program will be reminded to 
//update the value of these children nodes once they are fetched.

