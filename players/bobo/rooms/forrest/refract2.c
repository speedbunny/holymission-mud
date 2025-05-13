inherit "room/room";
object foreman, tech;
reset (arg) {
::reset(arg);
if (arg) return;
tech = clone_object("/players/bobo/monsters/tech");
transfer(tech,this_object());
tech = clone_object("/players/bobo/monsters/tech");
transfer(tech,this_object());
tech = clone_object("/players/bobo/monsters/tech");
transfer(tech,this_object());
foreman = clone_object("/players/bobo/monsters/foreman");
transfer(foreman,this_object());
set_light(1);
short_desc="The second floor of the pumping station.";
long_desc="The second floor of the station is full of computer panels with\n"+
"lots of beeping lights.  Running through this floor is the beam of energy\n"+
"there is tinted glass seperating this half of the floor from the half with\n"+
"the beam in it.  There are technicians staring intently at the panels and\n"+
"a foreman kicking back in a chair with a cup of coffee relaxing.\n";
dest_dir=({
	"players/bobo/rooms/forrest/refract1.c","down",
});
}
