mixed *del_array(mixed *array,int index) {
   int len;
   if(stringp(array)) len=strlen((string)array);
   else if(pointerp(array)) len=sizeof(array);
   else return array;
   if(index<0 || index>=len) return array;
   return array[0..index-1]+array[index+1..len-1];
}

