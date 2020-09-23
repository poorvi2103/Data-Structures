struct tree* INS(struct tree* ptr)
{
	while(ptr&&ptr->left)
	{
		ptr=ptr->left;
	}
	return ptr;
}
struct tree* INP(struct tree* ptr)
{
	while(ptr&&ptr->right)
	{
		ptr=ptr->right;    //will delete from where height is more so that height remains  balanced coz if height is balanced then searching will be fast
	}
	return ptr;
	
}
struct tree* del(node * ptr,int ele)
{
	struct tree* ptr1;
	if(ptr!=NULL)
	{
		if(!ptr->left&&!ptr->right) ;                  //leaf node
		{
			if(ptr==root&& ptr->data==ele)                       //if root only
			{
				root=NULL;
				return NULL;
			}
			free(ptr);
			return NULL;
		}
		else                            //reaching/searching element
		{
			if(ele>ptr->data)
				ptr->right=del(ptr->right,ele);
			else if(ele<ptr->data)
				ptr->left=del(ptr->left,ele);
			else
			{
				if(height(ptr->left)<height(ptr->right))
				{
					ptr1=INS(ptr->right);
					ptr->data=ptr1->data;
					ptr->right=del(ptr->right,ptr1->data);
					
				}
				else
				{
					ptr1=INS(ptr->right);
					ptr->data=ptr1->data;
					ptr->left=del(ptr->left,ptr1->data);
				}
			}
		}
		return ptr;
	}
	return NULL;
}
int height(struct tree * ptr)
{
	int x,y;
	x=height(ptr->left)
	y=height(ptr->right);
	if(x>y)
		return x+1;
	else
		return y+1;
}
