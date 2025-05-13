inherit "/obj/std_shadow";



varargs int start_shadow(object who,int time)
{
    set_effect_msg("blinded");
    move_object(clone_object("/players/akira/psi/obj/blindness"), who);
    return ::start_shadow(who,time,"blinded",0);
}

attack(o, h){
   object att;
 	att=me->query_attack();
	if(random(99)<24){
	     return apply(call,me,"attack",o,h);
	     }
	else{
	     tell_object(me, "You swing blindly and miss horribly!\n");
	     tell_room(environment(me), capitalize(me->query_name())+
	      " swings blindly at "+att->query_name()+" and misses "+
	      "horribly!\n");
	     return 1;
	     }
	}

end_shadow(object ob)
{
   object *ob1;
   int i, j;
     tell_object(me, "You regain your vision!\n");
     tell_room(environment(this_player()), capitalize(me->query_name())+" "+
	"regains "+me->query_possessive()+" vision.\n");
     ob1=all_inventory(me);
     j=sizeof(ob1);
     for(i=0; i<j; i++){
	if(ob1[i]->id("blindness")){
	    destruct(ob1[i]);
	    }
	}
     ::end_shadow(ob);
}

