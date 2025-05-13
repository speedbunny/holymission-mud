/* An earthen jug, containing wasps */
inherit "obj/thing";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("earthen jug");
      set_alias("jug");
      set_short("An earthen jug");
      set_long("It feels like there's something in it, but you'd have to break \n"
             + "the jug to get to it. \n");
      set_value(10);
      }
   }

void init() {
   ::init();
   add_action("destroy","break");
   }

int destroy(string str) {
object obj;
   if(str!="jug" && str!="earthen jug") return 0;
   write("You break the jug with a loud CRACK. \n"
       + "Oh oh, you also released a swarm of angry wasps! \n");
   obj=clone_object("/players/uglymouth/vikings/monsters/wasps");
   move_object(obj,environment(this_player()));
   obj=clone_object("/players/uglymouth/vikings/items/flygem");
   transfer(obj,environment(this_object()));
   destruct(this_object());
   return 1;
   }
