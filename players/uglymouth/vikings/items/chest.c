/* a viking's cabin trunk */
inherit "obj/container";

void reset(int arg) {
object arm;

      if(!present("clan tunic")) {
         arm=clone_object("/players/uglymouth/vikings/items/viktunic");
         transfer(arm,this_object());
         }
      if(!present("viking helm")) {
         arm=clone_object("/players/uglymouth/vikings/items/vikhelm");
         transfer(arm,this_object());
         }
      if(!present("viking axe")) {
         arm=clone_object("/players/uglymouth/vikings/items/vikaxe");
         transfer(arm,this_object());
         }
   ::reset(arg);

   if(!arg) {
      set_name("chest");
      set_alias("wooden chest");
      set_short("A wooden chest");
      set_long("A big wooden chest \n");
      set_max_weight(5);
      set_closed(1);
      set_can_close(1);
      set_can_get(0);
      }
   }
