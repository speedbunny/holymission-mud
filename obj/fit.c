#ifndef __fit__
#define __fit__

string do_fit
/*     ------								*/
	(string *list,		/* the to choose one from 		*/
	 string item)		/* the string to search for 		*/
{
    int i;
				/* its a full command 			*/
    if(member_array(item, list)!=-1) { return item; };

				/* search for a fitting in the list	*/
    for (i=sizeof(list)-1 ; i>=0 ; i--)
    { 	if(!strstr(list[i],item)) return list[i]; }

    				/* we found nothing, lets return the 	*/
				/* given item 				*/
    return item;
}

#endif
