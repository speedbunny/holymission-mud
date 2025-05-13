inherit "/obj/std_shadow";

varargs int start_shadow(object who,int time)
{
	set_effect_msg("despair");
        return ::start_shadow(who,time,"despair_shad",0);
}

attack(o, h){
   object *ob1;
   int i,j;
	write("You are to depressed to fight!\n");
	ob1=all_inventory(environment(this_player()));
	j= sizeof(ob1);
	for(i=0; i<j; i++){
	    if(ob1[i]->query_attack()){
		ob1[i]->stop_fight();
		ob1[i]->stop_fight();
		ob1[i]->stop_hunter(1);
		}
	    }

	return 1;
	}

end_shadow(object ob){
	tell_object(me, "You come out of your depression!\n");
	::end_shadow(ob);
	}
