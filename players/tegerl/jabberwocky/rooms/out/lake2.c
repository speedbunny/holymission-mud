/* Coded by Tegerl, 7.3.1995 */
/* rooms/out/lake2 */

inherit "room/room";
void reset(int arg)
{
::reset(arg);

if (arg) return;
set_light(1);
short_desc="A lake";

long_desc=
    "You are at the coast of a lake. The water is dark blue and you " +
    "feel safe here. The lake continues to the west. A path leeds " +
    "to a small hut in the southeast.\n";
    
dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/lake1", "northeast",
    "players/tegerl/jabberwocky/rooms/out/hut", "southeast",
    });

items=({
    "path","The ground is muddy and you can see that it has been used lately",
    "footprints","Yes, footprints, and they are human",
    "trails","As you look at the trails you think that maybe a carriage used this path",
    "lake","The water is dark blue and you can see fishes under the surface",
    "hut","This seems to be the hut of a fisherman",
});

smell = "You smell water. The air is fresh and clear.";
 
}

