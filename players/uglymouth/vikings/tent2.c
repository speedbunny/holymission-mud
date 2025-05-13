/* a tent with a sleeping viking... or do you wake him up? */
inherit "room/room";

void reset(int arg) {
object vik,arm;

   if(!(vik=present("viking snorar")) || !living(vik)) {
      vik=clone_object("/players/uglymouth/vikings/monsters/vsnorar");
      transfer(vik,this_object());
      }
   if(!(arm=present("viking axe"))) {
      arm=clone_object("/players/uglymouth/vikings/items/vikaxe");
      transfer(arm,this_object());
      }
   if(!(arm=present("viking helm"))) {
      arm=clone_object("/players/uglymouth/vikings/items/vikhelm");
      transfer(arm,this_object());
      }
   if(!(arm=present("clan tunic"))) {
      arm=clone_object("/players/uglymouth/vikings/items/viktunic");
      transfer(arm,this_object());
      }

   if(arg) return 0;

   set_light(0);
   short_desc="The tent where the vikings sleep";
   long_desc="You are in the tent the vikings use for sleeping. It's filled with "
           + "dirty strawbeds and blankets. It's quite messy. \n";
   dest_dir=({"/players/uglymouth/vikings/camp3","out", });
   items=({"strawbags","A large cloth filled with straw. It smells awful after a long sea voyage",
           "blankets","Roughly woven woolen blankets, smelling of sheep and sweat",
           "tent","A sturdy canvas tent that can hold eight beds", });
   smell="It smells of sheep, sleep and sweat. \n";
   }

void init() {
   ::init();
   add_action("get_it","get");
   add_action("get_it","take");
   }

int get_it(string str) {
object vik;
   if(str!="axe" && str!="viking axe" && str!="helm" && str!="viking helm" && str!="tunic" && str!="clan tunic") return 0;
   vik=present("viking Snorar");
   if(vik) {
      vik->wake_up();
      return 0;
      }
   return 0;
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
   if(!(vik=present("viking snorar")) || !living(vik))
   transfer(clone_object("/players/uglymouth/vikings/monsters/vsnorar"),this_object());
   return 0;
   }
