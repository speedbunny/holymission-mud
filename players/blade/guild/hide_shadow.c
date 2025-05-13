
/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=  Hide_shadow =+ =+=+=+=+=+=+=+=+=+=+=+=+=+=*/

string sid;			                               /* special id */

int  start_shadow(object what,int time,string type,string id)
{
    if (objectp(what) && intp(time) && strlen(type) && strlen(id))
    {
	sid=id+"__hidden__";
	if(call_other(what,type))
	{
	    tell_object(what,"There is already a spell of that kind active.\n");
	    return 0; 
	}
	else
	{
	    shadow(what,1);
	    return 1;
	}
    }
    return 0;
}

void end_shadow()
{
    destruct(this_object());
}

int hide_shadow()
{
    return 1;
}

object hide_object()
{
    return this_object();
}

id(string str) 
{
    return str==sid;
}

query_name() {
  return "Someone";
}

short()
{
    return 0;
}

