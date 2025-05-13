/* Odin's horse. transports you to Asgard */
inherit "obj/monster";
int i;

void reset(int arg) {
   ::reset(arg);
   i=0;

   if(!arg) {
      set_name("sleipnir");
      set_alias("horse");
      set_short("Sleipnir, Odin's eight legged horse");
      set_long("Sleipnir is one of the biggest and most beautiful horses you have ever \n"
             + "set eye on. His eight legs tremble of impatience, for it likes to fly home. \n");
      set_level(10);
      set_race("devine horse");
      set_gender(1);
      set_al(300);
      }
   }

void init() {
   ::init();
   add_action("mount","mount");
   }

int mount(string str) {
object ob;
   if(!(!str || str=="horse" || str=="sleipnir")) return 0;
   write("You mount Sleipnir. \n");
   if(i<3) {
      write("Sleipnir doesn't like to be touched by mortals and throws you off. \n");
      i=i+1;
      return 1;
      }
   ("/players/uglymouth/vikings/monsters/odin")->dummy();
   ob = find_living("odin");
   if(ob->query_hero() && ob->query_hero()!=this_player()->query_short_name()) {
      write("After a while Sleipnir knows to control his energy and allows you on his back.\n"
         + "Then he takes of, fast as lightning. You need all your power to keep on his back.\n"
         + "After a while he dives into a cloud and comes out at the other end.\n"
         + "In your mind you hear Odin's rumbling voice:\n"
         + capitalize(ob->query_hero()) + " has my attention. Do not disturb me any longer.\n");
      move_object(this_object(),"/players/uglymouth/vikings/falltop");
      tell_room(environment(this_object()),"Sleipnir arrives with " + capitalize(ob->query_hero())+" on his back.\n");
      this_player()->move_player("on Sleipnir's back#players/uglymouth/vikings/falltop");
      tell_room(environment(this_player()),"Sleipnir flies away, fast as lightning.\n");
      destruct(this_object());
      return 1;
      }
   ob = present("the village medallion of symria",this_player());
   if(ob && ob->query_parts_done() > 0) {
      write("After a while Sleipnir knows to control his energy and allows you on his back.\n"
         + "Then he takes of, fast as lightning. You need all your power to keep on his back.\n"
         + "After a while he dives into a cloud and comes out at the other end.\n"
         + "In your mind you hear Odin's rumbling voice:\n"
         + "You have been here once already. Don't waste my time.\n");
      move_object(this_object(),"/players/uglymouth/vikings/falltop");
      tell_room(environment(this_object()),"Sleipnir arrives with " +this_player()->query_short_name()+ " on his back.\n");
      this_player()->move_player("on Sleipnir's back#players/uglymouth/vikings/falltop");
      tell_room(environment(this_player()),"Sleipnir flies away, fast as lightning.\n");
      destruct(this_object());
      return 1;
      }
   write("After a while Sleipnir knows to control his energy and allows you on his back. \n"
       + "Then he takes of, fast as lightning. You need all your power to keep on his back. \n"
       + "In the end your concentration slips and so do you. \n"
       + "You are f\n         a\n          l\n           l\n            i\n             n\n              g\n               !\n\n"
       + "Then, at the moment you expect to slam into the earth, \n"
       + "your fall gets broken into a puddle of some stuff. It smells like stew. \n");
   this_player()->move_player("on the back of Sleipnir#players/uglymouth/vikings/walhalla");
   destruct(this_object());
   return 1;
   }
