/* the house of the village eldest */
inherit "room/room";
int fdoor,odoor;

void reset(int arg) {
object pers;
int i;

   for(i=0;i<3;i++) {
      if(pers=present("elder")) destruct(pers);
      }
   fdoor=0;
   odoor=0;
   if(arg) return;

   set_light(1);
   short_desc="You're in the house of the village eldest";
   long_desc="You're in the house of the village eldest. \n"
           + "It's a small miracle that it survived the fire so well. Although \n"
           + "a lot of smoke hangs around most items seem to be undamaged. Against \n"
           + "the north wall stands a comfortable couch and two chairs. Above the \n"
           + "desk on the south wall hangs the painting of an old woman. A rougly \n"
           + "woven carpet covers the wooden floor. \n";
   dest_dir=({"/players/uglymouth/vikings/villroad3","west", });
   items=({"wall","A wooden wall",
           "couch","A green wooden couch with comfortable thick cushions",
           "chairs","Green wooden chairs with thick cushions match with the couch",
           "desk","A simple oak desk. Some papers linger on it",
           "papers","There's something written on it",
           "painting","It pictures an old wise woman repairing a sail",
           "floor","A rough wooden floor covered with a thin layer of ashes",
           "carpet","It's roughly woven of thick threads of brown wool", });
   smell="The smell of smoke is somewhat less intense here. \n";
   }

void init() {
   ::init();
   add_action("read","read");
   add_action("look","look");
   add_action("search","search");
   add_action("open","open");
   add_action("west","west");
   }

int read(string str) {
   if(str!="papers") return 0;
   write("They mainly contain figures about the village's economy.\n");
   return 1;
   }

int west() {
   if(("/players/uglymouth/vikings/geiser")->on_fire()==2) {
      this_player()->move_player("west#players/uglymouth/vikings/fireroad3");
      return 1;
      }
   this_player()->move_player("west#players/uglymouth/vikings/villroad3");
   return 1;
   }

int look(string str) {
   if(str!="at carpet" && str!="at floor" && str!="at trapdoor") return 0;
   if(fdoor==1) {
      if(str=="at carpet" || str=="at floor") {
         write("The woolen carpet has been pulled back and reveals a trapdoor. \n");
         return 1;
         }
      if(str=="at trapdoor") {
         if(odoor==1) {
            write("There is an open trapdoor in the middle of the floor. \n");
            return 1;
            }
         write("The wooden trapdoor is closed. \n");
         return 1;
         }
      }
   return 0;
   }

int search(string str) {
   if(str!="carpet" && str!="floor") return 0;
   if(fdoor==1) {
      write("Someone already found the trapdoor. What is it you seek? \n");
      return 1;
      }
   write("You pull away the carpet and reveal a trapdoor in the floor. \n");
   say(this_player()->query_name()+" discovers a trapdoor under the carpet.",this_player());
   fdoor=1;
   return 1;
   }

int open(string str) {
   if(str!="trapdoor") return 0;
   if(fdoor==0) {
      write("You don't see a trapdoor. \n");
      return 1;
      }
   if(odoor==1) {
      write("The trapdoor is already open. \n");
      return 1;
      }
   write("You open the trapdoor. \n");
   say(this_player()->query_name()+"open a trapdoor in the middle of the floor.",this_player());
   tell_room(this_object(),"From their hidingplace appear three people. They look scared, but \n"
      + "seem relieved that they don't see vikings. \n");
   transfer(clone_object("/players/uglymouth/vikings/monsters/eldest"),this_object());
   transfer(clone_object("/players/uglymouth/vikings/monsters/villager"),this_object());
   transfer(clone_object("/players/uglymouth/vikings/monsters/villager"),this_object());
   odoor=1;
   call_out("scare",3);
   return 1;
   }

void scare() {
object *all,man;
int i,j;
   if(!this_player()->query_quests("viking")) return;
   tell_room(this_object(),"The eldest screams: AAAHH!! One of these people once helped the vikings! \n"
           + "The eldest and the villagers flee into their hiding place. \n");
   for(i=0;i<3;i++) {
      man=present("elder");
      all=all_inventory(man);
      for(j=0;j<sizeof(all);j++) {
         destruct(all[j]);
         }
      destruct(man);
      }
   fdoor = 0;
   odoor = 0;
   return;
   }
