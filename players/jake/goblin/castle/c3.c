#define TP this_player()
#define TPN TP->query_name()
inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "c3";
long_desc = "The hall continues to the east, and to the west.\n"
+ "You see a beautiful tapestry hanging from the north wall.\n"
+ "Grunting noises can be heard from behind it.\n"
+ "A small window is in the south wall.\n";
items = ({
"floor","The floor is made of ruby red stone",
"ceiling","It is made of white stone",
"carpet","A beautiful black carpet extending the length of the hall",
"wall","It is made of grey stone...it has a large tapestry hanging on it",
"tapestry","A picture of a large red dragon.\nStrange noises can be heard from behind it",
"window","More trees surrounding the castle is all that can be seen",
});
dest_dir = ({
"players/jake/goblin/castle/c2","west",
"players/jake/goblin/castle/c4","east",
});
}
init () {
 ::init();
      add_action("my_move","move");
      add_action("enter","enter");
}
my_move(str) {
     switch(str){
     case "tapestry":
         write("You move the tapestry to the side.\n");
         write("You see a small doorway in the wall.\n");
         say (TPN + " moves the tapestry aside.\n");
  return 1;
  }
}
enter(){
   move_object(TP,"players/jake/goblin/castle/r1");
         write("You squeeze through the small doorway.\n");
         say (TPN + " leaves through a small doorway.\n");
  return 1;
}
