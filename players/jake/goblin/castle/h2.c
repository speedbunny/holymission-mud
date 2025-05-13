#define TP this_player()
#define TPN TP->query_name()
inherit "room/room";
reset(arg) {
if (arg) return;
set_light(2);
short_desc = "h2 Mid-hallway  secret downstairs";
long_desc =
           "This is a hallway that goes north and south.\n"
        +  "A small white carpet covers the center of the floor.\n"
        +  "There are doorways to the east and west of you.\n"
        +  "There is an iron grate in the floor.\n";
items = ({
      "floor","It is made of ruby-red stone",
      "ceiling","It is made of pearl-white stone",
      "wall","Grey stone walls with small doorways in them",
      "doorway","Rather large wood framed doorways",
      "carpet","A small and pretty white carpet",
      "grate","An iron grate.\nMaybe you could 'open' the 'grate' and 'enter' it?",
});
dest_dir = ({ 
   "players/jake/goblin/castle/h1","south",
   "players/jake/goblin/castle/h3","north",
});
}
init() {
::init();
add_action("open","open");
add_action("enter","enter");
}
open(str) {
 switch(str) {
case "grate":
 write ("You open the grate.\n");
 say (TPN + " opens the grate.\n");
return 1;
}
}
enter() {
move_object(TP,"players/jake/goblin/under/u1");
write("You enter the grate, ending up under the castle!\n");
say (TPN + " leaves through a hole in the floor.\n");
return 1;
}
