inherit "room/room";
object bird;
int i; 
reset (arg) {
if (!bird) {
for (i=0;i<3;i++) {
bird=clone_object("obj/monster"); 
transfer(bird,this_object());
bird->set_name("sparrow");
bird->set_short("sparrow");
bird->set_level(4);
bird->set_hp(50);
bird->set_al(1000);
bird->set_aggressive(0);
bird->set_long("A small sparrow.\nIt is really pretty to look at.\n");
}
if (arg) return;
set_light(3);
short_desc = "c8...hall N/S...3 birds";
long_desc = 
    "The hall continues to the north and south.\n"
 +  "The blue carpet seems to be somewhat soiled.\n"
 +  "A small window in the east wall.\n";
items = ({"floor","It is made of ruby-red stone",
"ceiling","It is made of pearl-white stone",
"carpet","A beautiful blue carpet.\nIt looks as if something excreted some waste on it",
"wall","Grey stone walls",
"window","All you can see is trees.\nA small birdsnest in the windowsill",
"nest","A small bird nest",
});
dest_dir = ({
"players/jake/goblin/castle/c7","south",
"players/jake/goblin/castle/c9","north",
});
}
}
