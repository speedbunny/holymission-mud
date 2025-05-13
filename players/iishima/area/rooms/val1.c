inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(2);
short_desc="In the woods";
long_desc=("\
\n\
  Your not so safe feeling tells you that you have now entered the woods. \n\
  There is an evil aura swarming about this place.  There are many inhuman\n\
  sounds comming from deeper in the woods.  The fog is so thick that you can\n\
  barely see the trail ahead of you.  You can make out the shape of a small\n\
  sign located off of the path. \n\
\n\
");
dest_dir=({"players/iishima/area/rooms/val2","north",
           "players/iishima/area/rooms/wood1","south"});

items=({"sign","A small, molded sign"});

::reset(arg);
}

init(){
::init();
add_action("read","read");
add_action("get","get");
}

read(str)
{
 if (!str)
 {
  write("Read What???\n");
  return 1;
 }
if (str=="sign")
 {
  write("You have now entered Zalpur Valley!  This place is\n");
  write("Not for the weak of heart!\n");
  return 1;
 }
}

get(str)
{
 if (!str)
 {
  write("Get what?\n");
  return 1;
 }
 if (str=="sign")
 {
 write("You think: That would not be a good idea.\n");
  return 1;
 }
}
