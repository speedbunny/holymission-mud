inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(2);
short_desc="In A Body of Water";
long_desc=("\
\n\
  The water is extremely cold.  You feel like your body has slowed down. \n\
  Tiny fish and other sealife swim and crawl through the seaweed.  You feel\n\
  calm as you swim in the water. \n\
\n\
");

dest_dir=({"players/iishima/area/rooms/lake1.c","west",
           "players/iishima/area/rooms/lake3.c","south"});

items=({"water","The water looks deep and cold",
        "fish","The fish are swimming happily through the seaweed",
        "seaweed","The seaweed is a dark green color"});

clone_list = ({ 1, 2, "trout", "/players/iishima/area/monsters/trout", 0 });
::reset(arg);
replace_program("room/room");
}

