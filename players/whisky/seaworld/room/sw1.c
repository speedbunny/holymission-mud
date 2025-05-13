
#include "../seaworld.h"

void reset(int arg) 
{
    ::reset();

    if (sizeof(all_inventory()) < 2)
   {
        CO("shell"); CO("beer");
   }

    if (arg) return;
    set_light(1);
    short_desc = "In the sea";
    long_desc = BS(
    "You are standing in a pleasant and warm part of the sea. "+
    "If you wish you can climb up the rope which is hanging here. " +
    "A little river flows from the cavern into the sea "+
    "to the southwest. The sea leads further to the east. "+
    "Sometimes there are shells lying here.");
    move_object(clone_object("/players/whisky/island/monster/dagobert"),
                this_object());

    items = ({
      "rope","You see a big brown rope hanging down from a rock",
      "bottom","A stony sea bottom",
      "rock","A big black rock standing in the sea" });
    dest_dir = ({
//       "players/whisky/lake/room/river21","southwest",
      PATH+"sw3", "east", });
}

init() {
    ::init();
    add_action("climb","climb");
}

int climb(string str) 
{
    if(str!="rope" && str!="up the rope" && str!="up rope" && str!="up") {
	write("You should try climbing up the rope.\n");
	say(this_player()->query_name()+" tries to climb up the rope but fails.\n");
	return 1; }

    else {
	write("U F F F you are climbing up the long brown rope.\n\n\n");
	write("U F F F you are climbing up the long brown rope.\n\n\n");
	write("U F F F you are climbing up the long brown rope.\n\n\n");
	write("U F F F you are climbing up the long brown rope.\n\n\n");
	this_player()->move_player("up#players/whisky/seaworld/room/rock");
	return 1; }
}
