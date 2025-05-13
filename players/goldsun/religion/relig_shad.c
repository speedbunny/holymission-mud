       /*   shadow for mist in QUERCUS religion   */

inherit "/players/whisky/obj/std_shadow";

#define SA(x) say(x,me)
#define WR(x) tell_object(me,x)
#define SAY(x) tell_room(environment(mist),x)

object mist;

query_linkdeath(){ return 1; }

query_ghost(){ 
  return 1; }

set_mist(){
 mist=clone_object("players/goldsun/religion/mist");
 move_object(environment(me),mist);
}

hit_player(dam,kind,elem)
{
  return me->hit_player(0,kind,elem);
}


void mend_shadow()
{

 if (mist) destruct(mist);
 destruct(this_object());
}

int relig_shad() 
{ 
    return 1; 
}

object query_relig_shad()
{
   return this_object(); 
}


move_player(mixed dir_dest,mixed optional_dest_ob,mixed raw,string income_msg) 
{
    string dir,who,short_str;
    mixed tmp, dest;
    int is_light,i;

    if (!optional_dest_ob) 
    {
	if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) 
	{
	    return;
	}
    } 
    else 
    {
	dir = dir_dest;
	dest = optional_dest_ob;
    }
    is_light = set_light(0);
    if(is_light < 0)
	is_light = 0;
    if(is_light) 
    {
       SAY("CHECK THIS, mail Goldsun !\n");
    }

    move_object(mist, dest);

    tmp=dest;

    if(stringp(tmp)) 
	tmp=find_object(tmp);
    if(environment(mist)!=tmp) 
	return;

    is_light = set_light(0);

    if(is_light < 0)
	is_light = 0;

    if(is_light) 
    {
       SAY("You fee undefined force.\n");
    }
    if (!interactive())
	return;
    mist->show_this(me);
  return 1;
}

