inherit "/obj/std_shadow";

varargs int start_shadow(object ob,int time) {
    tell_object(ob,"The dagger's blade springs open.\n");
    say(this_player()->query_name()+"'s dagger's blade springs open.\n");
    return ::start_shadow(ob,time,"parry",0);
}

void end_shadow(object ob) {
    int remain;

    if(ob)
	tell_object(me,"The daggers blade closes.\n");
    say(this_player()->query_name()+"'s dagger's blade closes.\n");
    remain = shadow_time("parry");
    ::end_shadow(ob);
}

int parry_shad() { return 1; }
object parry_object() { return this_object(); }

varargs int hit_player(int dam,int kind,mixed *elem) 
{
    int rand,chance;

    if(kind==7 || kind == 5) 
	return apply(call,me,"hit_player",dam,kind,elem);
    rand = random(100) + 1;
    chance = 42 + (25 * me->query_dex())/40;
    if(rand < chance) {
	tell_object(this_player(),me->query_name()+" parries the blow!\n",this_player());
	tell_object(me,"You manage to parry the incoming blow!\n");
	say(me->query_name()+" parries the blow!\n",me,this_player());
	return apply(call,me,"hit_player",0,kind,elem);
    }
    if(rand < chance+15) {
	tell_object(this_player(),apply(call,me,"query_name")+
	  " manages to deflect the blow somewhat.\n");
	tell_object(me,"You manage to deflect the blow somewhat.\n");
	say(me->query_name()+" manages to partially deflect the blow!\n",me,this_player());
	return apply(call,me,"hit_player",dam/2,kind,elem);
    }
    return apply(call,me,"hit_player",dam,kind,elem);
}
