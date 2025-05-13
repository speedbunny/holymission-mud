inherit "room/room";

status dug;

void reset(int arg){


if (arg) return;

set_light(1);
short_desc="The Dragon Realms Pit";
long_desc=("\
\n\
  You have stumbled into a pit in the dragon realms.  This is the home of the\n\
  black dragon.  He was a loyal follower of the 'dragon lord'.  You see many\n\
  remains of both humans and dragons.  You notice a small hole in the wall. \n\
  You can hear loud noises coming from the other side. \n\
\n\
");
dug = 0;

dest_dir=({"players/iishima/area/rooms/realm4","up"});

clone_list=({1,1,"dragon","players/iishima/area/monsters/blackdragon", 0 });
::reset(arg);
}

init(arg)
{
 ::init();
 add_action("dig","dig");
 add_action("look","look");
 add_action("enter","enter");
}

look(arg)
{
 if (arg == "at hole")
  {
   if (!dug) {return write("A small hole that is too small to enter.\n"),1; }
   write("A medium sized hole barely big enough for you to enter.\n");
   return 1;
}
}


dig(arg)
{
 ::reset(arg);
if(!arg) { return write("Dig what?\n"),1; }
 if (arg == "hole") { return write("Dig hole with what?\n"),1; }
 if (arg == "hole with shovel") 
  {
   if (present("#QUESTSHOVEL",this_player()))
    { 
     dug = 1;
     write("You dig a hole big enough to enter.\n");
     return 1;
    }
  }
 write("Dig what?\n");
 return 1;
}

enter(arg)
{
 ::reset(arg);
if(!arg) { return write("Enter what?\n"),1; }
 if (arg == "hole")
  {
   if (!dug) { return write("The hole is too small.\n"),1; }
   transfer(this_player(),"/players/iishima/area/rooms/realm7.c");
   command("look",this_player());
   tell_room(environment(this_player()),capitalize(this_player()->query_name())+" arrives through a hole.\n");
   return 1;
  }
 return write("Enter what?\n"),1; 
}
