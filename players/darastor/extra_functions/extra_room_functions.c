mixed *add_array(mixed *arr1, mixed *arr2)
{
  	mixed *temp;
  	int i;
  	temp=allocate(sizeof(arr1)+sizeof(arr2));
  	for(i=0;i<sizeof(arr1);i++)
    	temp[i]=arr1[i];
  	for(i=sizeof(arr1);i<sizeof(temp);i++)
    	temp[i]=arr2[(i-sizeof(arr1))];
  	return temp;
}

/* remove_array removes the first occurrence of each element of
   arr2 from arr1 */
mixed *remove_array(mixed *arr1, mixed *arr2)
{
  	mixed *temp;
  	int i;
	int index;
 	temp=arr1;
  	for(i=0;i<sizeof(arr2);i++)
		index=member_array(arr2[i],arr1);
    	temp=del_array(temp,index);
  	return temp;
}

mixed *remove_dest_dir(string dir, mixed *dest_dir_arr)
{
    mixed *temp;
    int index;
    index=member_array(dir,dest_dir_arr);
    if(index>0)
    {
		/* delete the direction and the destination from the array */
		temp=dest_dir_arr;
		temp=del_array(temp,index);
		temp=del_array(temp,(index-1));
    }
	return temp;
}
