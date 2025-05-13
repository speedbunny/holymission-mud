inherit "room/room";
#define PATH "players/baalthasar/area/keep"

reset(arg) {
if (arg) return;
set_light(1);
short_desc = "End of the mountain road";
long_desc =
"       You have reached the end of this rocky mountain \n"
+"path.  You notice to the north a large white, shining wall \n"
+"set into the mountains.  You also notice a on the battlements  \n"
+"huge silver and white banner flapping excitedly in the \n"
+"cool mountain air.  It seems to stem from the wall in the \n"
+"distance before you. \n"
+"      To your left and right continue the large \n"
+"cliff faces.  To the south, the mountain road stretches on. \n\n";

dest_dir =
({
PATH + "/gates", "north",
PATH + "/mroad2", "south"
});
items = ({
"banner", "This far away, you can't make out the details on the banner",
"faces", "The stone wall continues here",
"face", "The stone wall continues here",
"wall", "Sunlight shines brilliantly off this ivory structure"
});
}
