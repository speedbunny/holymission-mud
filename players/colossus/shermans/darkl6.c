/* Edited by Colossus 022494 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc="The dark path";
    long_desc=
    "This path is just like others around this area, it is full of stones\n"+
    "and thorny bushes. There are some bones lying on the path, probably of\n"+
    "a humanoid creature, judging by the size. To the southwest you see a\n"+
    "castle with looming towers that resemble gigantic vampire fangs.\n";
    items=({
      "path","A small path with sharp stones, on each side there are some\n"+
      "rotten bones",
      "stones","Sharp black stones",
      "bones", "The bones belong to some poor unfortunate creature that died here",
      "tower", "The tower resembles a gigantic vampire fang",
      "castle", "A huge castle with fang-like towers",
    });
    dest_dir=({
      "/players/sherman/darkl5","north",
      "/players/sherman/darkl7","west"
    });
}
