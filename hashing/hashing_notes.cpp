HASHING:
	fastest searching technique
	
h(x)=x%10   -------> modulus hash function

two major problems to remove collision problem:
	1.Open hashing :
		chaining       /\(lamba)=number of elements/size of array    
		
In hashing,/\ should be always(recommended) <=0,5 [coz due to this ,there will be less collisionsj] i.e,/\<=0.5   i.e size of array=2*no.of elements
		
	2.closed hashing:
		->linear probing        h'(x)=(h(x)+f(i))%10
		                	    f(i)=o,1,2,3.....
		                		h(x)=x%10
		->quadratic probing
								h'(x)=(h(x)+f(i))%10
		                	    f(i)=i*i
		                		h(x)=x%10
		->double hashing
								h'(x)=(h(x)+i*h1(x))%10
								where,
								h(x)=x%10
								i=o,1,2,3,4...
								h1(x)=R-(x%R)         R=prime number just less than sizeof array
								
								
								
Some Other Functions:
	mid square hash function
	folding hashh function
