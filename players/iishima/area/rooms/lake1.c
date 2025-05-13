inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(1);
short_desc="In A Body of Water";
long_desc=("\
\n\
  The water is extremely cold.  You feel like your body has slowed down. \n\
  Tiny fish and other sealife swim and crawl through the seaweed.  You feel\n\
  calm as you swim in the water. \n\
\n\
");

dest_dir=({"players/iishima/area/rooms/warm.c","up",
           "players/iishima/area/rooms/lake2.c","east"});

items=({"water","The water looks deep and cold",
        "sealife", "Little fish and other creatures swim about happily",
        "fish","The fish are swimming happily through the seaweed",
        "seaweed","The seaweed is a dark green color"});

::reset(arg);
replace_program("room/room");
}
