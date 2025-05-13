/* an open plain on which you can catch rabbits for food */
inherit "room/room";

reset(arg)   {
   if(arg) return;

   set_light(1);
   short_desc="An open area in the dunes";
   long_desc="You arrive at a flat and open part of the dunes. \n"
           + "The grass is greener here, probably because of the river \n"
           + "you hear streaming further west. \n"
           + "you can make out the playground of rabbits, but the rabbits have fled. \n";
   dest_dir=({"/players/uglymouth/vikings/well","north",
              "/players/uglymouth/vikings/dunes","east",
              "/players/uglymouth/vikings/westdune","south",
              "/players/uglymouth/vikings/rivir_n","west", });
   items=({"grass","Fresh, green grass, with clovers growing in between",
           "clovers","Growing in small groups",
           "river","You can only hear it. To see it you must go west",
           "playground","The grass is eaten here. You can vaguely make out some rabbit footprints",
           "footprints","At first glance they seem to go nowhere. But you could try to track them", });
   }

init() {
   ::init();
   add_action("search","search");
   add_action("track","track");
   add_action("set","set");
   add_action("make","make");
   add_action("smell","smell");
   }

search(str) {
   if(str!="clovers") return;
   write("You find a four-leaf clover, a good luck charm. \n");
   tell_room(this_player(),query_name()+"finds a four-leaf clover");
   return 1;
   }

track(str) {
   if(str!="footprints" && str!="rabbits") {
      write("You want to track WHAT? \n");
      return 1; }
   write("You track the footprints back to the rabbit's hole. \n"
       + "If you know how to snare a rabbit you might catch some food. \n"
       + "If not, maybe some of the locals can advise you on it. \n");
   return 1;
   }

make(str) {
object rope,snare;
int i,j;
   if(str!="snare") return;
   rope=all_inventory(this_player());
   j=1;
   do {
   for(i=0;i<sizeof(rope);i++) {
      if(rope[i]->query_name()=="rope") {
         snare=clone_object("obj/treasure");
         snare->set_id("snare");
         snare->set_alias("trap");
         snare->set_short("A snare");
         snare->set_value(20);
         transfer(snare,this_player());
         j=0;
         destruct(rope[i]);
         write("You make a snare of your rope. \n");
         return; }
         }
      } while(j==1);

   if(j==1) {
      write("You need a rope to make a snare. \n");
      return 1; }
   write("You just made the perfect snare to catch a rabbit. \n");
   return 1;
   }
