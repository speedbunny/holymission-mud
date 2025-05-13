inherit "room/room";
#define PATH "players/baalthasar/area/keep"

reset(arg) {
if (arg) return;
set_light(1);
short_desc = "Mountain wall";
long_desc =
"       Here the path stops and the mountains begin.  The wall \n"
+"of the castle that had been north, has subtly faded into the \n"
+"rocks here. \n\n";
dest_dir =
({
PATH + "/gview1", "west"
});
items = ({"mountains", "The grass covered rocks continue north out of sight",
"rocks", "Beautifully, the wall fades into the natural rocks here",
"wall", "Beautifully, the wall fades into the natural rocks here",
"path", "The path has dissolved into stone"
});
}
