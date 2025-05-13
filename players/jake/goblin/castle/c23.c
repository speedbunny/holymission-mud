inherit "room/room";
object cat;
reset (arg) {
if (!cat) {
cat=clone_object("obj/monster");
transfer(cat,this_object());
cat->set_name("cat");
cat->set_short("black cat");
cat->set_alt_name("cat");
cat->set_level(2);
cat->set_hp(50);
cat->set_long("A stray black cat.\n");
cat->set_al(400);
cat->set_aggressive(0);
cat->set_race("cat");
}
if (arg) return;
set_light(2);
short_desc = "c23  E/W hallway  black cat";
long_desc = "The hallway goes east and west.\n" 
          + "A black carpet extends to both ends of the hall.\n"
   + "A small window in the south wall.\n";
items = ({
 "floor","A floor made of ruby-red stone",
 "ceiling","It is made of pearl-white stone",
 "wall","Grey stones make up the walls, there is a small window in the south wall",
 "carpet","A beautiful black carpet",
 "window","You can see the goblin village from here",
});
dest_dir = ({
"players/jake/goblin/castle/c22","west",
"players/jake/goblin/castle/c24","east",
});
}
