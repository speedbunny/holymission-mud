static line_format(str,arg,w1,w2,indent,explo,delim,lastchar)
{

    string arr;
    int    i,j;

    arr=explode(str,explo);

    if (sizeof(arr) < 2) return arr[0]+lastchar;

    str="";

    for (i=0; i<sizeof(arr)-1; i++)
    {
	str += arr[i]+delim;
	if (strlen(str + arr[i+1])>(arg - w1))
	{
	   str += "\n";
	   if (!indent) indent="";
	   w1 = -strlen(str);
	   str += extract(indent+"                     ",0,w2);
	}
    }
    return str + arr[i]+lastchar;
}
