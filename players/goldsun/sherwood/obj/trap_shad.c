/* trap_shadow */

inherit "/players/whisky/obj/std_shadow";


mixed move_player(mixed dir_dest,mixed optional_desc_ob, 
		mixed raw,string income_msg)
{
  tell_object(me,"You are trapped, you cannot move !\n");
  say(me->query_name()+" tries to run away, but FAILS.\n",me);
  return 1;
}
   

int trap_shad() 
{ 
    return 1; 
}

object trap_obj()
{ 
    return this_object();
}

