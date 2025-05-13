#define TP this_player()
#define TPN TP->query_name()
inherit "room/room";
int i;
object guard;
reset (arg) {
for (i=0;i<3;i++) {
guard=move_object(clone_object("players/jake/goblin/castle/monsters/goblin"),this_object());
if (arg) return;
set_light(2);
short_desc = "guard quarters 2";
long_desc = "You have entered the second room of the castle guard quarters.\n"
          + "Four small cots formed in bunk-beds are against the western wall.\\n"
          + "A small blue carpet lies in the center of the floor.\n";
items = ({
 "floor","You see a red stone floor.\nIt looks very dirty",
 "carpet","You are looking at a very old blue carpet.\nIt is very worn and tattered",
 "bunk-bed","You see a wood-framed bunk-bed.\nIt looks real comfortable",
 });
dest_dir = ({
 "players/jake/goblin/castle/j1","east",
});
}
}
init(){
  ::init();
     add_action("sit","lay");
}
sit(str) {
  switch(str) {
    case "on bed":
  write ("You sit upon the bunk-bed.\nIt feels very comfortable.\nYou feel very tired.\n");
  say (TPN + " takes a seat on the bunk-bed.\n");
return 1;
  default:
  write ("Do what?\n");
return 1;
}
} 
