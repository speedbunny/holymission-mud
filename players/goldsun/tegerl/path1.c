/* Tegerl's first room, coded 4.3.1995 */
/* rooms/out/path1 */

inherit "/room/room";

void reset(int arg)
{
::reset(arg);

if (arg) return;
short_desc="A dim path through forest";

long_desc=
    "You entered a dim large forest.\n" +
    "A narrow path meanders through it. As you look into\n" +
    "the depth of the forest you decide to follow the path\n" +
    "and don't dare to leave it.\n" +
    "You can see that the path is use frequently as there\n" +
    "are footprints and trails of carriages.\n" +
    "Maybe you will meet some people living near.\n";

/* now make the light */
set_light(1);
/* exits */
dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/path2", "north",

    });

/* descriptions */
items=({
    "forest","The forest is very dark, you wonder what creatures could live in it. You decide to stay away.",
    "path","The ground is muddy and you can see that it has been used lately.",
    "footprints","Yes, footprints, and they are human.",
    "trails","As you look at tho trails you think that maybe a carriage used this path.",
});

/* no proberties */

/* smell */
smell = "The air is damp and you can smell rotten trees.";
  
  }
