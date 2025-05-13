inherit "/players/akira/fun/shot.c";
#define TP this_player()
#define NAME query_name()
/* SPECIAL THANKS TO TINMAN */
object who;
int bullseye;

reset(arg)
{
    ::reset(arg);
    set_name("staff-sling");
    set_alt_name("sling");
    set_alias("4thstaff");
    /* put "4thstaff" in set_alias(), prevent mistake from other
     staffs on the mud, like mage staff - Nylakoorub 06-30-96  */
    set_hit_func(this_object());
    set_short("The Staff-Sling of the 4th Dimension");
    set_long("This is the legendary Staff-Sling of the 4th Dimension. It\n"+
      "is said to be as old as time itself. The shaft of the staff\n"+
      "is covered with magic runes. This weapon is only ment for a\n"+
      "true master of time and space.\n");
    set_weight(7);
    set_class(18);
    set_value(5000);
    set_two_handed();
    set_max_shots(300);
    set_shots(300);
    set_max_salvo(2);
    set_wc_per_shot(this_player()->query_level()+1);
    set_sound(" SMACK! A rock hits its' target ");
    set_value_per_shot(7);
}
query_auto_load(){
    return "/players/akira/vag/staff:";
}
drop(){
    destruct(this_object());
    write("Your staff returns to its own dimension until needed again.\n");
    return 1;
}
init(){
    ::init();
    add_action("bop","bop");
}
int bop (string str){
    if(!str) return 0;
    who= present (str, environment(this_player()));
    if (who){
	write("Your staff jumps from your hands and bops "+
	  capitalize(str)+
	  " on the head.\n");
	tell_object(who,
	  capitalize(this_player()->query_real_name())+
	  "'s staff jumps from their hands "+
	  "and bops you on the head.\n");
	bullseye=1;
	return 1;
    }
    else
	write("Who do you want to bop?\n");
    return 1;
}

weapon_hit(ob){



    if(this_player()->query_guild() !=10)
    {
	write(
	  "The staff pulses in your hands, and your body ages at an\n"+
	  "accelerated rate.  Your bones become brittle, and your\n"+
	  "teeth fall out, along with your hair.\n");
	this_player()->hit_player(8 + random(100),3);
	return 0;
    }
    return 1;
}
