inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "3-way junction";
  long_desc =
"You stand on a north-south path in the middle of dense forest. The path \
seems to get little use judging by the light growth of grass. The path \
branches to the west, a small dirt road. You hear distant cheers in that \
direction.\n";

  dest_dir = ({
"players/bobo/arena/road6","west",
"players/figleaf/smurf/path1","north",
"room/forest8","south",
             });

  items = ({
"forest","A dense growth of trees",
"path","A narrow, grassy path",
"road","A dirt road with wheel ruts in it",
"grass","A single-leafed, green plant of the genus Poa",
          });

  ::reset(arg);
  replace_program("room/room");
}
