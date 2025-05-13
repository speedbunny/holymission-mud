inherit "/obj/std_shadow";

varargs int start_shadow(object who,int time)
{
	set_effect_msg("mind wipe");
        return ::start_shadow(who,time,"wipe_shad",0);
}

wield(){
	write("You can't seem to remember how to use your weapons"+
	"!\n");
	return 0;
	}


end_shadow(object ob){
	tell_object(me, "You regain your memory!\n");
	::end_shadow(ob);
	}
