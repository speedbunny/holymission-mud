inherit "room/room";
#define PATH "players/baalthasar/area/keep"

reset(arg) {
if (arg) return;
set_light(1);
short_desc = "West of castle gates";
long_desc =
"        You are outside the castle wall which stands to \n"
+"the north.  Thick grass grows here between the mountains and \n"
+"the great wall.  To the east you can see the magnificent \n"
+"gates.  The wall seems to blend more and more smoothly into \n"
+"the surrounding rocks, a path is still open west. \n\n";
dest_dir = 
({
PATH + "/gates", "east",
PATH + "/gview4", "west"
});
items = ({ "grass", "It's strong, bright green mountain grass",
"wall", "It's the tall southern wall of the castle.  Guards pace \n"+
"back and forth on the battlements above, occasionally \n"+
"staring down at you",
"guards", "Very tough looking men with noble ambiances, they \n"+
"enjoy their job",
"gates", "The gates lie to the east",
"rocks", "The hills become great mountains here, and the castle \n"+
"seems to fade into the rocks" 
});
}
