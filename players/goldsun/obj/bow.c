inherit "/players/goldsun/gen/std/std_bow"; 

#define TP this_player()

	  void reset(int i)
	  {
           ::reset(i);
 	   set_name("goldsun's bow");
	   set_alias("bow");
	   set_short("Short bow");
	   set_long("Short bow. It's made of teak.\n");
	   set_value(120);
	   set_class(2);  /* optional */
	   set_weight(2);
 	   set_bow(this_object());
           set_arrow_damage(35); /* magic hit */
          }

/*
weapon_hit(attacker){
object quiver; 
 if (present("quiver_of_arrows",TP))
  { 
	write("You shoot an arrow agains your enemy.\n");
	say(TP->query_name()+" shoots an arrow against "+TP->query_possessive()+
             "enemy.\n");
	quiver=present("quiver_of_arrows",TP);
	quiver->dec_arrows(1);
        return dama;
  }
 }
*/
