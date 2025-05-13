/* the vikings' boat that takes you to the ship */
inherit "obj/thing";
int loc;

void reset(int arg) {
   ::reset(arg);

   /* loc==0 at campbeach, loc==1 at shipsea */
   if(loc==1) {
      transfer(this_object(),"/players/uglymouth/vikings/campbeach");
      }
   if(!present("viking rowar")) {
      transfer(clone_object("/players/uglymouth/vikings/monsters/vrowar"),this_object());
      }

   if(!arg) {

      set_light(1);
      set_name("rowing boat");
      set_alias("boat");
      set_short("A rowing boat");
      set_long("The rowing boat of the vikings. It's made of rough wood \n"
             + "and contains two benches and a pair of oars. The view \n"
             + "out over the sea is beautiful. \n"
             + "   There is one obvious exit: out \n");
      set_can_get(0);

      transfer(this_object(),"/players/uglymouth/vikings/campbeach");
      loc=0;
      }
   }

void init() {
   ::init();
   add_action("row","row");
   add_action("out","out");
   add_action("enter","enter");
   add_action("look_at_it","look");
   }

int row() {
   if(!present(this_player(),this_object())) return 0;
   if(present("viking rowar")) {
      if(!(present("voucher of " + this_player()->query_real_name(),this_player()))) {
         write("Viking Rowar says: You don't have permission from the chief to use this boat. \n"
             + "So I will not let you use it. \n");
         return 1;
         }
      }
   if(loc==0) {
      tell_room(this_object(),"You row to the viking ship.\n");
      tell_room(environment(this_object()),"The rowing boat leaves for the ship. \n");
      transfer(this_object(),"/players/uglymouth/vikings/shipsea");
      tell_room(environment(this_object()),"A rowing boat arrives. \n");
      loc=1;
      return 1;
      }
   tell_room(this_object(),"You row to the beach. \n");
   tell_room(environment(this_object()),"The rowing boat leaves for the shore. \n");
   transfer(this_object(),"/players/uglymouth/vikings/campbeach");
   tell_room(environment(this_object()),"A rowing boat arrives. \n");
   loc=0;
   return 1;
   }

int out() {
   if(loc==0) {
      this_player()->move_player("out#players/uglymouth/vikings/campbeach");
      return 1;
      }
   if(("/players/uglymouth/vikings/ship")->query_location()==0) {
      write("You climb the rope ladder up to the ship. \n");
      this_player()->move_player("out#players/uglymouth/vikings/shipdeck2.c");
      return 1;
      }
   }

int enter(string str) {
   if(!id(str)) return 0;
   this_player()->move_player("into the rowing boat#players/uglymouth/vikings/rowboat");
   return 1;
   }

status query_location() {
   return loc;
   }

void move_back() {
   tell_room(environment(this_object()),"The rowing boat leaves for the shore. \n");
   say("Viking Peddlor takes the oars and rows back to the shore. \n");
   move_object(this_object(),"/players/uglymouth/vikings/campbeach");
   loc=0;
   return 0;
   }

int look_at_it(string str) {
object env;
string thing,msg;
   if(!str) return 0;
   if(sscanf(str,"at %s",thing)!=1) return 0;
   if(thing=="view") {
      env=environment(this_object());
      env->long();
      if(present("longship",env)) {
         write("The longship of the vikings lies here at anchor. \n");
         }
      return 1;
      }
   if(thing=="wood") msg="Rough but strong oak wood";
   if(thing=="sun") msg="A warm sun shines on you. \n";
   if(thing=="sea") msg="The wide blue sea, reflecting a golden sun. \n";
   if(thing=="benches") msg="Just some planks to sit on. \n";
   if(thing=="oars" || thing=="pair of oars") msg="To row with. How else would you move this boat? \n";
   if(msg!=0) {
      write(msg);
      return 1;
      }
   return 0;
   }

void vikings_leave() {
object *inv;
int i;
   tell_room(this_object(),"The vikings arrive and take this boat to row to their ship. \n"
      + "They dump you rudely ashore. \n");
   inv=all_inventory(this_object());
   for(i=0;i<sizeof(inv);i++) {
      if(inv[i]->query_player()) {
         inv[i]->move_player("out#players/uglymouth/vikings/campbeach");
         }
      }
   if(loc==0) {
      row();
      }
   destruct(this_object());
   return 0;
   }
