/* the ship's stern */
inherit "room/room";

void reset(int arg) {
object vik;

   if(!(vik=present("viking ruddar")) || !living(vik))
   transfer(clone_object("/players/uglymouth/vikings/monsters/vruddar"),this_object());

   if(arg) return 0;

   set_light(1);
   short_desc="The stern of the longship";
   long_desc="This is the stern of the longship. At the end a big red dragon tail is "
           + "carved. There is a bench and an oar for rowers at each side of the ship. "
           + "Round shields are fixed on the sides of the ship. This is the place of the helmsman "
           + "when the ship is sailing. \n";
   dest_dir=({
      "/players/uglymouth/vikings/shipdeck3","front",
      });
   items=({"stern","The back of the longship",
           "longship","The vikings' longship",
           "tail","A dragon tail carved from wood and painted red. It looks impressive",
           "bench","A wooden bench for a rower to sit on",
           "oar","A wooden oar to row with if there is no wind or adverse wind",
           "shields","Big decorated shields which also offer protection for the rowers", });
   }

void init() {
   ::init();
   add_action("tell_it","tell");
   }

int tell_it(string str) {
string msg;
object vik;
   if(sscanf(str,"viking ruddar %s",msg)==1) {
      vik=present("viking ruddar");
      if(!vik) {
         write("That person is not present. \n");
         return 1;
         }
      tell_object(this_player(),"You tell Viking Ruddar: " + msg + ". \n");
      tell_object(vik,this_player()->query_real_name() + " tells you: " + msg + "\n");
      return 1;
      }
   if(sscanf(str,"viking %s",msg)==1) {
      vik=present("viking ruddar");
      if(!vik) {
         write("That person is not present. \n");
         return 1;
         }
      write("You tell Viking Ruddar: " + msg + "\n");
      tell_object(vik,this_player()->query_real_name() + " tells you: " + msg + "\n");
      return 1;
      }
   return 0;
   }

void vikings_leave() {
object ob;
   ob = first_inventory(this_object());
   while(ob) {
      if(ob->query_player() && !present("the village medallion of symria",ob)) {
         tell_object(ob,"The Vikings have orders to leave and put you ashore.\n");
         ob->move_player("for the shore#players/uglymouth/vikings/campbeach");
         }
      ob = next_inventory(this_object());
      }
   }
