/* temporary altar until the real one gets ungzipped 4-5-96 */
inherit "obj/container";

void reset(int arg) {
object arm;

      if(!present("heart")) {
         arm=clone_object("/players/sarge/objects/heart");
         transfer(arm,this_object());
         }
   ::reset(arg);

   if(!arg) {
      set_name("altar");
      set_alias("altar");
      set_short("A small altar");
      set_long("A small altar laying in the center of the room.\n" +
	       "It appears to have two doors in the front of it.\n" +
	       "Perhaps, you can open it?\n");
      set_max_weight(5);
      set_closed(1);
      set_can_close(1);
      set_can_get(0);
      }
   }
