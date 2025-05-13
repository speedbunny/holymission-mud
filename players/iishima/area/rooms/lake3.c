
inherit "room/room";

status beenfound;
object sword;

void reset(int arg){

if (arg) return;
set_light(1);
short_desc="In A Body of Water";
long_desc=("\
\n\
  The water is extremely cold.  You feel like your body has slowed down.  You\n\
  have entered the den of a shark.  You pray that he does not attack you.  As\n\
  you look around you think you see a rather large pair of eyes watching\n\
  you.   You see a dark shadow in front of you. \n\
\n\
");
dest_dir=({"players/iishima/area/rooms/lake2.c","north"});

items=({"water","The water looks deep and cold",
        "fish","The fish are swimming happily through the seaweed",
        "seaweed","The seaweed is a dark green color",
        "eyes", "You think you see a pair of read eyes watching you from the shadows",
        "shadow","It is too dark to see. Maybe you could search it"});
beenfound = 0;

clone_list = ({ 1, 1, "shark", "players/iishima/area/monsters/shark", 0 });

::reset(arg);
}


init(arg)
{
 ::init();
 add_action("do_search","search");
}

do_search(arg)
{
 if (arg == "shadow" || arg == "shadows")
  {
   if (beenfound) { return write("You find nothing.\n"),1; }
   beenfound = 1;
   write("You search around and feel a lump in the sand.\n");
   write("You begin to dig in the sand.\n"); 
   write("You feel something sharp and grab for it.\n");
   write("It is an old, rusty sword.\n");
   sword = clone_object("/players/iishima/quest/qsword1.c");
   move_object(sword,this_player());
   say("Someone searches the shadows.\n");
   return 1;  
  }
}
