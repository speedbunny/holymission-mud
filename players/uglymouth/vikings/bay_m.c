/* 120893 Galadriel: room did not load, 3 bugs fixed */
/* Midpoint of the bay */
inherit "room/room";
int gold;

void reset(int arg) {
   
   gold=0;
   if(arg) return;

   set_light(1);
   short_desc="This is the middle of the bay";
   long_desc="You're walking in the middle of the bay. \n"
           + "A small stream flows at your feet from the waterfall west \n"
           + "into the sea. You see a big jungle to the south, although \n"
           + "to the southeast an enormous cloud of smoke hangs above it. \n";
   dest_dir=({"/players/uglymouth/vikings/bay_n","north",
              "/players/uglymouth/vikings/bay_s","south",
              "/players/uglymouth/vikings/bay_mw","west", });
   items=({"stream","It's just too wide to take in one step",
           "waterfall","A violent waterfall rushing down from a cliff",
           "jungle","A dense, tropical jungle",
           "cloud","You can see the air shimmering with intense heat",
           "smoke","The dark smoke of burning bad materials. Yuch!", });
   }

void init() {
   ::init();
   add_action("south","south");
   add_action("jump","jump");
   add_action("search","search");
   }

int south() {
   write("The stream is to wide to step across. You'll have to jump. \n");
   return 1;
   }

/* 120893 Galadriel: added 'string' in next line */
int jump(string str) {
object lost_item;
int i;
   if(!str || str=="stream") {
      if(this_player()->query_dex()>15) {
         write("You jump over the stream without problems. \n");
         this_player()->move_player("south, jumping over the stream#players/uglymouth/vikings/bay_s");
         return 1;
         }

      write("You fall facedown into the stream. \n"
          + "You rub the mud out of your eyes and leave the stream at the southern side. \n");
      say(this_player()->query_name()+" jumps up and falls facedown into the stream. \n",this_player());
      i=random(100) + 50;
      if(i > this_player()->query_money()) i = this_player()->query_money();
      this_player()->add_money(-i);
      gold=gold + i;
      write("You've got the feeling you've lost something... \n");
      this_player()->move_player("south, climbing out of the stream#players/uglymouth/vikings/bay_s");
      return 1;
      }
   return 0;
   }

/* 120893 Galadriel: added 'string' in next line */
int search(string str) {
object mon;
   /* 120893 Galadriel: added '0' in next line */
   if(str!="stream" && str!="water") return 0;
   if(gold==0) {
      write("You search the stream, but you find nothing. \n");
      return 1;
      }
   if(random(10) < 6 ) {
      write("You search the stream, but you find nothing. \n");
      return 1;
      }
   write("You found some money! \n");
   mon=clone_object("/obj/money");
   mon->set_money(gold);
   transfer(mon,this_object());
   gold=0;
   return 1;
   }
