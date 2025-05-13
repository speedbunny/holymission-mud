/* Galadriel: There were 52 Sleipnirs here. horse is now a global object, */
/* the clone checks if its there, and after a minute the call_outs stop ;)*/
/* The location of the holy oak */
inherit "room/room";
int slept;
object horse;

void reset(int arg) {
   if(arg) return;

   set_light(1);
   property = "no_teleport";
   short_desc="At the holy oak";
   long_desc="You stand at an open place in the jungle. A thin mist hangs "
           + "in the air and there is absolute silence. In the centre of this "
           + "place stands a large oak. It strongly radiates some mystical "
           + "power. This is obviously a holy place. \n";
   items=({"mist","Some thin white mist",
           "oak","It must be ages old, almost from the beginning of time", });
   smell="Although in the middle of the jungle the air is quite fresh here. \n";
   }

void init() {
   ::init();
   /* Galadriel: no more call_outs after the first horse appears  ;) */
   if(!horse)
     call_out("pick_up",60);

   add_action("sleep","sleep");
   }

int sleep() {
   write("You close your eyes and try to sleep. \n"
       + "When you wake up you find yourself still at the foot the holy oak. \n");
   return 1;
   }

void pick_up() {
   /* Odin has only one Sleipnir? */
   if(horse) return;
   write("A sudden gust of wind makes you shiver. When turn around you see \n"
       + "a big eight legged horse. \n");
   horse=clone_object("/players/uglymouth/vikings/monsters/sleipnir");
   transfer(horse,this_object());
   return 0;
   }

void set_slept() {
   slept=0;
   return 0;
   }
