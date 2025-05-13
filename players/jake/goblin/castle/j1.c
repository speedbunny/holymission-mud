#define TP this_player()
#define TPN TP->query_name()
inherit "room/room";
reset (arg) {
if (arg) return;
set_light(2);
short_desc = "Guard sleeping quarters";
long_desc = 
    "You have entered what appears to be some sort of sleeping quarters.\n"
 +  "The walls are barren except for 3 small cots along them.\n"
 +  "This is where the castle guards sleep.\n" 
 +  "A small wardrobe stands against the south wall.\n";
items = ({
 "floor","You see a red stone floor.\nIt appears kinda dirty",
 "statue","A small replica of a dragon.\nIt is made of pretty green ivory",
 "wardrobe","You see a small wooden wardrobe.\nIt holds the guards personal belongings.\nA small statue sits on the wardrobe",
});
dest_dir = ({
 "players/jake/goblin/castle/h1","east",
});
}
init(){
   ::init();
       add_action("sit","lay");
}
sit(str) {
  switch(str) {
case "on cot":
  write ("You sit down on the cot.\n");
  write ("It is real comfortable.  Make you kinda sleepy.\n");
  say (TPN + " sits on the cot.\n");
return 1;
   default:
    write ("Do what?\n");
  return 1;
}
}
