inherit "room/room";
 
void reset(int arg){
if (arg) return;
set_light(2);
short_desc="A warm valley";
long_desc=("\
\n\
  You look around and take a deep breath of air.  This place is extremely\n\
  peaceful.   Behind you is a dark looking cave and in front of you is a\n\
  large, deep body of water.  This looks like a good place to dive. \n\
\n\
");
 
dest_dir=({"players/iishima/area/rooms/cave3","north"});
 
items=({"mountains","The mountains are very tall",
 
        "cave","The cave looks very dark and damp",
         "place", "The water here looks deep.  Maybe you could dive into the water",
        "water","The water looks deep and cold"});

::reset(arg);
}

 
init(arg)
{
 ::init();
 add_action("dive","dive");
}
 
dive()
{
 write("You dive into the water!\n");
 say(capitalize(this_player()->query_name())+" dives into the water.\n");
 transfer(this_player(),"/players/iishima/area/rooms/lake1.c");
 command("look",this_player());
 return 1;
}
