inherit "room/room";
#define PATH "players/baalthasar/area/keep"
reset(arg) {
if (arg) return;

set_light(1);
short_desc = "Gates to the Castle Strongheart";
long_desc =
"     Before you loom the mighty gates to the white Castle \n"
+"Strongheart, the home of the great Avatar of Gwendolyn, and \n"
+"the worthy Silver Dragon order, the paladins.  The gates are \n"
+"welcomingly open, and decorated with many battle scenes from \n"
+"the triumphant past of the holy order.  Guards stand above on \n"
+"the parapets and the sounds of castle life spill from the \n"
+"mouth of this huge white fortress.  A large banner flaps in \n"
+"wind above. \n"

+"     The mountain road runs back south through the hills. \n"
+"to the east and west the castle wall seems to run into the \n"
+"mountainside. \n\n";
dest_dir =
({
PATH + "/enter", "enter",
PATH + "/gview2", "west",
PATH + "/gview1", "east",
PATH + "/mroad1", "south"
});
items = ({"gates", "The large gates are excellently carved from ivory, and are standing open",
"guards", "The guards glance over you and appear to play little attention",
"banner", "On the banner you see a white rose and broadsword crossing over a large \n"+
"silver dragon, the symbol of the powerful Lady Gwendolyn",
});
}
init() {
::init() ;
add_action("listen", "listen");}
listen () {
write("You hear faint voices to the north, in the castle. \n");
return 1;
}
