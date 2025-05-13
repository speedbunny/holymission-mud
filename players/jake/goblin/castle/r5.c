#define TP this_player()
#define TPN TP->query_name()
inherit "room/room";
reset (arg) {
if (arg) return;
set_light(2); 
short_desc = "waiting room";
long_desc = "A small room with benches along the walls.\n"
          + "It appears to be some sort of a waiting area.\n";
items = ({
 "floor","It is made of ruby red stones",
 "walls","The grey stone walls are barren",
 "benches","Old wooden benches.\nLooks like a nice place to take a seat!",  
 });
dest_dir = ({
 "players/jake/goblin/castle/r3","north",
});
}
init() {
 ::init() ;
     add_action("sit","sit");
}
sit(str) {
   switch(str) {
case "on bench":
  write ("You sit on the wooden bench.\n");
  write ("OUCH!  You got splinters in your you-know-what!.\n");
  say (TPN + " sits on the wooden bench.\n");
return 1;
   default:
   write ("Do what?\n");
return 1;
}
}
