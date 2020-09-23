                                                      SORTING
In sorting, if order of duplicates remains same after soting, then stable,and if order of duplicates change after sorting,then unsorted.    

//comparision based sortings:
    bubble
    insertion
	selection
	quick
	merge




                                                  
1.Bubble Sort: in one pass,greatest element comes at its original position.  time complexity=O(n^2)   ,maximum swap=(n-1)+(n-2)+......+1=n^2.
            stable sorting.
            have to make it adaptive.ie if passa sorted array,then complexity reduces.(if after one pass,if there is no swap,then it means sorted and can do this by introducing flag)
            

2.Insertion Sort:insert already in sorted order by comparing inserting element from backward side and shifting.
                      worst case complexity:O(n)
                      best case complexity:O(1)
k
                       (take one element from unsorted array and insert in sorted aray by comparing element from vacant -1 element) 
					   adaptive byitself
					   more useful in linked list(coz no shifting)  



3.SelectionSort:not adaptive and can't make it adaptive.(min element will come at its origuinal position   opp of bubble sort
				Also NOT Stable.
			worst	O(n*n)
			best   O(n)	
				
4.Quick Sort: take one element and all smaller elements at left side and greater at right.
              Best:O(nlogn)=average (partition at middle for best)
              worst:O(n^2) (when array  is sorted or reverse sorted)
              RandomizedQuickSort i.e. randomize pivot by using rand() function (which generates random numbers) to remove worst case
              not stable and not adaptive
              
              
              
5.Merge Sort:no average,best or worst case
			so time complexity in every scenario is O(nlog n).
			space complexity: max entry in  stack =height of binary tree=log n.
			                 for merge sort: n for array+n for extra array(for result) + log n for stack.
			                 
			                 
			                
//inplace sorting algorithm:if algo don't need extra space,then implace  sorting algoritm 
      merge sort is not inplace.	(stack cox recursion)
	  
	  
	  
	  
6.Cout Sort:count[0]=index based orting
                     comlexity=o(n+k)        => linear complexity and fastest but should be feasible 
                     whwere k = max element,n=no.of elements
                     
                     space complexity=n+k (n for output array amd k for count array)
                     
                     for negATIVE numbers,add largest negative  to all elements and then after sorting,again subtract.
7.Radix Sort: sort on basis of radix

8.Shell Sort:
	        we have to manage/select gap.
	        when gap=1 i.e.last paas, then similar to insertion sort.
	        Not stable
	        best case
	        
	        
	        



		  					                         
