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


drop(){
 write("Bow breaks.\n");
 destruct(this_object());
 return 1;
}
