inherit "/obj/std_shadow";

varargs int start_shadow(object who, int time)
{
    set_effect_msg("muted");
    move_object(clone_object("/players/trout/psi/obj/mute"), who);
    return ::start_shadow(who,time,"muted",0);
}
end_shadow(object ob)
{
   object *ob1;
   int i, j;
     tell_object(me, "You regain your speech!\n");
     tell_room(environment(this_player()), capitalize(me->query_name())+" "+
	"regains "+me->query_possessive()+" speech.\n");
     ob1=all_inventory(me);
     j=sizeof(ob1);
     for(i=0; i<j; i++){
	if(ob1[i]->id("mute")){
	    destruct(ob1[i]);
	    }
	}
     ::end_shadow(ob);
}

