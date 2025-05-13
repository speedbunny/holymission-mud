/* the kitchen tent */
inherit "room/room";

void reset(int arg) {
object vik;

   if(!(vik=present("viking boozar")) || !living(vik))
   transfer(clone_object("/players/uglymouth/vikings/monsters/vboozar"),this_object());

   if(arg) return 0;

   set_light(1);
   short_desc="The storage tent of the vikings";
   long_desc="This is the tent where the vikings store their supplies. A large chest \n"
           + "in the middle of the tent makes easy movement impossible. The rest of the \n"
           + "space is filled with barrels and sacks. In the back is some space left for \n"
           + "the cook to sleep. \n";
   dest_dir=({
      "/players/uglymouth/vikings/camp3","out",
      });
   items=({"barrels","A label on them says 'salted fish'",
           "sacks","They contain some clothes, kitchen tools, that kind of useless junk",
           "space","It's filled by a dirty strawbag",
           "strawbag","A linnen bag filled with straw, to sleep on", });

   transfer(clone_object("/players/uglymouth/vikings/items/chest"),this_object());
   }

void vikings_leave() {
object *inv;
int i;
   tell_room(this_object(),"A viking arrives. \n"
      + "The viking says: We're breaking up. You'll have to leave this tent. \n"
      + "The viking shows you out. \n\n");
   inv=all_inventory(this_object());
   for(i=0;i<sizeof(inv);i++) {
      if(inv[i]->query_player()) {
         transfer(inv[i],"/players/uglymouth/vikings/camp3");
         environment(inv[i])->long();
         }
      }
   return 0;
   }

vikings_arrive() {
object vik;
   if(!(vik=present("viking leadar")) || !living(vik))
   transfer(clone_object("/players/uglymouth/vikings/monsters/vleadar"),this_object());
   return 0;
   }
