inherit "/players/goldsun/gen/std/std_bow"; 

#define TP this_player()

	  void reset(int i)
	  {
           ::reset(i);
 	   set_name("goldsun's bow");
	   set_alias("bow");
	   set_short("Short bow");
	   set_long(
"This is a short bow made out of teak wood.  It smells faintly of the "+
"sea.  The string is made from the intestines of some animal and feels "+
"slightly sticky.  The bow has been sighted using standard nocking blocks.\n");
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
