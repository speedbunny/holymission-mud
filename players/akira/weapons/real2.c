inherit "/obj/weapon";
#define TP this_player()
#define NAME query_name()
object who;
object shad;
int bullseye;

reset(arg)
{
    ::reset(arg);
	set_light(1);
    set_name("reality");
    set_alt_name("real");
    set_alias("ball");
    set_hit_func(this_object());
    set_short("Reality");
    set_long("It is hard to describe what it is your looking at. It as\n"+
             "mass, and then it doesn't. Just as it has no one shape, it\n"+
             "seems to be in a state of temperal flux. Some times it is\n"+
             "surounding your hands and others it is in your hands. It is\n"+
             "for lack of better words, reality. One thing is for sure, you\n"+
             "can feel its power flowing in you!\n");
    set_weight(1);
    set_class(20);
    set_value(5000);
    set_two_handed();
}
	query_auto_load(){
	     return "/players/akira/weapons/real:";
	}
drop(){
    destruct(this_object());
    write("Your pocket of reality folds in on itself and is gone, until\n"+
          "it is needed again.\n");
    return 1;
}
init(){
    ::init();
    add_action("bop","bop");
    add_action("wield", "wield");
}
int bop (string str){
    if(!str) return 0;
    who= present (str, environment(this_player()));
    if (who){
        write("A small bit of reality jumps from your and and bops "+
	  capitalize(str)+
	  " on the head.\n");
	tell_object(who,
	  capitalize(this_player()->query_real_name())+
          "'s weapon jumps from his heands "+
	  "and bops you on the head.\n");
	bullseye=1;
	return 1;
    }
    else
	write("Who do you want to bop?\n");
    return 1;
}
int wield (string arg){
 if(id(arg) && (! query_wielded())); {
  if(this_player()->query_hands_free());{
write("As you wield Reality a Temperal Shield Surrounds your Body!\n");
say(this_player()->query_name()+" is surrounded by a Temperal Shield!\n");
shad= clone_object("/players/akira/vag/armour/shadow");
shad-> start_shadow(this_player(), 0);
}
   return ::wield(arg);
}
}



weapon_hit(ob)
{
    int guild;

    guild = this_player()->query_guild();
    if (random(20) <=5)
    {
	printf("You summon a dimensional rift, and the temporal tidal\n"+
	  "forces rip and shred your opponent.\n");
	say(" "+TP->NAME+" opens a dimensional rift, whose violent temporal\n"+
	  "eddies tear the opponent apart.\n",TP);
	if (guild == 10)
	    return(40+(this_player()->query_level()));
	else
	    return(30+(this_player()->query_level()));
    }
    if ( guild !=10)
    {
	write(
          "The reality pulses in your hands, and your body ages at an\n"+
	  "accelerated rate.  Your bones become brittle, and your\n"+
	  "teeth fall out, along with your hair.\n");
        this_player()->hit_player(100 + random(200),3); /*GRIN*/
	return 0;
    }
    return 1;
}
