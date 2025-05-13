
/* amulet_shad.c */

// the standard shadow 

inherit "/obj/std_shadow";

// for the special look
string look_info()
{
    return " ( wrapped into a glowing aura ) ";
}

varargs mixed hit_player(int dam,int kind,mixed elem) 
{
    // 7 special attacks, 0 physical attacks, 6 poison, 5 magic or breath

    if (random(100) <= 30 && kind==0 || kind==7) 
    {
	// the this_player is ever the caller of the function TP == attacker 
	tell_object(me,this_player()->query_name()+"'s attack passes "+
	  "harmlessly through your ethreal form !\n");
	say(this_player()->query_name()+"' attack passes harmlessly "+
	  "through "+me->query_name()+"'s ethreal form !\n",me,this_player());
	// we call the hit_player in living.c with value 0 
	return me->hit_player(0, kind, elem);
    }
    // else we call the hit_player with the true :*) value 
    return me->hit_player(dam, kind, elem);
}

int amulet_shad()
{
    return 1;
}

object amulet_object()
{
    return this_object();
}

void end_shadow(object ob)
{
    tell_object(me,"You revert to your normal form.\n");
    ::end_shadow(ob);
}
