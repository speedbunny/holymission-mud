#define TP this_player()

inherit "obj/weapon";

reset(arg){
 ::reset(arg);

 if (arg) return;
 set_name("short bow");
 set_alias("bow");
 set_class(1);
 set_short("A short bow");
 set_long("An oak short bow.\n");
 set_weight(1);
 set_value(900);
 set_hit_func(this_object());
}

weapon_hit(attacker){
object quiver; 
 if (present("quiver_of_arrows",TP))
  { 
	write("You cast an arrow agains your enemy.\n");
	say(TP->query_name()+" casts an arrow agains his enemy.\n");
	quiver=present("quiver_of_arrows",TP);
	quiver->dec_arrows(1);
	 /*   add hit for KNIGHTS */
        return 10;
  }
   return 0;

 }
 
