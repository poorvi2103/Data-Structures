void insert()                                            complexity =height of tree =O(n)
{
	int t;
	t=A[i];
	while(i>>0&&A[(i-1)/2])                            //parent in complete binary tree=(i-1)/2
	{
		arr[i]=arr[(i-1)/2];
		i=(i-1)/2;
	}
	arr[i]=t;
}
void delete(int arr[],int n)                            complexity =height of tree =O(n)
{
	int temp;
	temp=arr[0];
	arr[0]=arr[n];
	arr[n]=temp;
	i=0,j=2i+1;
	while(j<n)
	{
		if(arr[j+1]>arr[j]&& j<n-1)
		{
			j=j+1;
		}
		if(arr[i]<arr[j])
		{
			
		}
	}
}
int main()
{
	for(i=1;i<n;i++)
		insert(arr,i);
	for(i=n-1;)
}                                                             heap create=nlogn
                                                               delete every element=nlign
                                                                complexity of heap sort=2nlognj
