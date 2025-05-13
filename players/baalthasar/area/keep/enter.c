inherit "room/room";
#define PATH "players/baalthasar/area/keep"
reset(arg) {
if (arg) return;
property = ({"no_teleport"});

set_light(1);
short_desc = "Inside the gates";
long_desc =
"     You have entered a large archway of stone built into the \n"
+"castle wall.  Two burly guards armed to the teeth with steel \n"
+"stand before you, one to either side.  They stare dutifully \n"
+"straight ahead and don't seem to pay attention to you.  To \n"
+"the north you notice a large courtyard filled with people. \n"
+"A large doorway opens on your left and right, from the sounds \n"
+"you guess they are guard houses.  \n\n";
dest_dir = 
({
PATH + "/gates", "leave",
PATH + "/ghouse1", "east",
PATH + "/ghouse2", "west",
PATH + "/cyard1", "north"
});
}
init() {
::init() ;
add_action("listen", "listen"); }
listen() {
write("Many voices come from the courtyard, and from the guard houses \n"
+"it sounds as though the guards are enjoying a good game to pass time. \n");
return 1;
}
