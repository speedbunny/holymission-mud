/* amidst the tents. the chief is in the biggest one. */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="A muddy piece of ground";
   long_desc="You stand among the tents of the vikings. A big, red and white striped \n"
           + "tent stands in the centre. Both left and right of it stands a smaller, dirty \n"
           + "white tent. The ground has turned into mud because of the many people \n"
           + "walking in and out of the tents. \n";
   dest_dir=({
      "/players/uglymouth/vikings/camp1","north",
      });
   items=({
      "tents","Two dirty white tents stand next to a red and white striped tent",
      "big tent","It looks important",
      "red and white striped tent","It looks important",
      "smaller tent","The left or the right tent?",
      "left tent","Obviously used many times. A snoring sound comes from it",
      "right tent","Obviously used many times. A fishy smell emerges from it",
      "dirty white tent","The left or the right tent?",
      "ground","Ordinary muddy ground, as you have walked on many times before",
      "mud","Dirty, slippery mud",
      });

   transfer(clone_object("/players/uglymouth/vikings/monsters/vkeepar"),this_object());

   }

void init() {
   ::init();
   add_action("enter","enter");
   }

int enter(string str) {
object vik;
   if(str!="tent" && str!="big tent" && str!="left tent" &&
      str!="right tent") return 0;
   if(("/players/uglymouth/vikings/ship")->query_location()==1) {
      write("There are no tents here. \n");
      return 1;
      }
   if(str=="tent") {
      write("There's a big tent, one tent left and one right of it. \n"
          + "Which one do you want to enter? \n");
      return 1;
      }
   if(str=="left tent") {
      this_player()->move_player("into the left tent#players/uglymouth/vikings/tent2");
      return 1;
      }
   if(str=="right tent") {
      this_player()->move_player("into the right tent#players/uglymouth/vikings/tent3");
      return 1;
      }
   if(str=="big tent") {
      if(!present("viking keepar")) {
         this_player()->move_player("into the big tent#players/uglymouth/vikings/tent1");
         return 1;
         }
      vik=present("viking keepar");
      if(vik->drunk()>60) {
         write("Viking Keepar is too drunk to notice you slipping past him. \n");
         this_player()->move_player("into the big tent#players/uglymouth/vikings/tent1");
         return 1;
         }
      if(this_player()->query_invis()>0) {
         write("Somehow Viking Keepar notices you trying to sneak in. \n"
             + "Viking Keepar tells you: Ha ha, You thought I fell for that trick, huh? \n"
             + "Viking Keepar kicks you hard and sends you flying... \n");
         say("Viking Keepar grabs someone and kicks him away. \n",this_player());
         this_player()->move_player("through the air#players/uglymouth/vikings/camp1");
         return 1;
         }
      write("Viking Keepar won't let you in. \n");
      return 1;
      }
   }

void vikings_leave() {
object vik,*inv;
int i;
   long_desc="You're standing on a muddy piece of ground. Three spots of bleak \n"
           + "grass indicate that some time ago tents were put up here. Nothing's left. \n";
   items=({
      "ground","It looks like many people used to walk on it",
      "spots","Three square spots of very light green grass",
      "grass","It's so light because the tent on it took away all the light it needed",
      });
   vik=present("viking");
   while(vik) {
      inv=all_inventory(vik);
      for(i=0;i<sizeof(inv);i++) {
         destruct(inv[i]);
         }
      destruct(vik);
      vik=present("viking");
      }
   tell_room(this_object(),"The vikings take down their tents and bring all therir belongings to their ship. \n");
   }

void vikings_arrive() {
object vik;
   long_desc="You stand among the tents of the vikings. A big, red and white striped \n"
           + "tent stands in the centre. Both left and right of it stands a smaller, dirty \n"
           + "white tent. The ground has turned into mud because of the many people \n"
           + "walking in and out of the tents. \n";
   items=({
      "tents","Two dirty white tents stand next to a red and white striped tent",
      "big tent","It looks important",
      "red and white striped tent","It looks important",
      "smaller tent","The left or the right tent?",
      "left tent","Obviously used many times. A snoring sound comes from it",
      "right tent","Obviously used many times. A fishy smell emerges from it",
      "dirty white tent","The left or the right tent?",
      "ground","Ordinary muddy ground, as you have walked on many times before",
      "mud","Dirty, slippery mud",
      });
   vik=clone_object("/players/uglymouth/vikings/monsters/vkeepar");
   transfer(vik,this_object());
   tell_room(this_object(),"The vikings arrive, having set the nearby village on fire, and start \n"
      + "building up some tents here. \n");
   }
