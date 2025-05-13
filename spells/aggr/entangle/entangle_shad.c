/*
 * shadow for the entangle
 * (c) sourcer
 */
inherit "/obj/std_shadow";

int power;

start_shadow( who, time )
{
   power=this_player()->query_level()+this_player()->query_legend_level();
   return( ::start_shadow( who, 0, "entangle", 0 ) );
}

end_shadow( o )
{
   tell_object(me,"You get free of the roots!\n");
   say(me->query_name()+" breaks free of the roots.\n");
   me->unlock_input();
   ::end_shadow( o );
}

void chk_all_shadows()
{
	if(random(75)< me->query_str() ) 
    {
        me->chk_all_shadows();
        end_shadow();
    }
    else
    {
        ::chk_all_shadows();
        write("You try to get free of the wines but FAIL !!\n");
        say(me->query_name()+" tries to get free of the wines but fails\n");
    }
}

varargs int attack(object ob, int hand)
{
	write("You are stuck in the wines and can't move!\n");
	say(this_player()->query_name()+ " tries to move but fails miserably.\n");
    if(me != this_player())
       write(me->query_name()+" is bound by the roots!\n");
	return 1;
}
	
