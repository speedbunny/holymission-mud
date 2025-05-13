inherit "room/room";
reset (arg){
int i;

	set_light(0);
	dest_dir = ({"players/airborne/temple/levela/room1", "west",
		"players/airborne/temple/levela/stairs3", "north", });
	short_desc = "A dirty room";
long_desc =
"This room is filthy! Dust and dirt are everywhere.\n"+
"There is a small slot on the wall.\n";
	items = ({"dust", "So much dust it makes you want to sneeze",
		"dirt", "So much dirt your mother would have a fit",
		"slot", "A small slot that looks like it used to hold something",
		"hole", "A small hole that looks like it used to hold something", });

i =0;
if(!present("ghoul", this_object())){
object gho;
	while (i < 4){
		i += 1;
	gho = clone_object("players/airborne/monsters/ghoul");
		move_object(gho, this_object());
		}
	}
}
init() {
::init();
add_action("place_it","place");
add_action("place_it","put");
}
place_it(str) {
object ob;
if ((str=="statuette in slot") || (str=="the statuette in slot")) {
  if (present("statuette",this_player())) {
  write("You place the statue in the slot.\n");
  ob=present("statuette",this_player());
  transfer(ob,"/room/void");
dest_dir=({
  "players/airborne/temple/fountain", "east",
  "players/airborne/temple/levela/room1","west",
  "players/airborne/temple/levela/stairs3","north",
});
  ::init();
  return 1;
  }
  else { 
  write("You don't have that on you.\n");
  return 1 ;
  }
}
else {
 write("Place what?\n");
 return 1;
 }
 }
