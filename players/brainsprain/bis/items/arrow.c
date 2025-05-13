inherit "obj/treasure";
#include "/players/brainsprain/bis/bisdef.h"
string direction;
short(){
return "Arrow pointing "+direction;
}
long(){
if(environment(this_player()) == this_player())
  {
write(
"Power radiates from this seemingly incongrous piece of metal.  The "+
"cold steel comes together, forming a razor sharp barb.  You get the "+
"feeling that once placed this arrow will prove to hold a steady course. "+
"Try 'set'ting a direction for the arrow.\n");
}
}
void reset(int arg){
set_id("arrow");
set_alias("arrow");
if(arg) return;
set_value(500);
set_weight(1);
direction = "nowhere";
}
void init(){
  ::init();
  add_action("do_set","set");
  }
do_set(string arg){
if (arg == "north" || arg == "n"){
write("Setting arrow to north\n");
direction = "north";
return 1;
}
if(arg == "south" || arg == "s"){
write("Setting arrow to south\n");
direction = "south";
return 1;
}
if (arg == "east" || arg == "e"){
write("Setting arrow to east\n");
direction = "east";
return 1;
}
if(arg == "west" || arg == "w"){
write("Setting arrow to west\n");
direction = "west";
return 1;
}
if (arg == "northwest" || "nw"){
write("Setting arrow to northwest\n");
direction = "northwest";
return 1;
}
if(arg == "southwest" || "sw"){
write("Setting arrow to southwest\n");
direction = "southwest";
return 1;
}
if (arg == "northeast" || "ne"){
write("Setting arrow to northeast\n");
direction = "northeast";
return 1;
}
if(arg == "southeast" || "se"){
write("Setting arrow to southeast\n");
direction = "southeast";
return 1;
}
else { direction = "nowhere"; }
}
