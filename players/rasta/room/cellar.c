
inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
dest_dir=({"/players/rasta/room/sub_cave","west",
   "/players/rasta/room/passage","northwest"});

short_desc="Subterranean Cave";
long_desc=
"This subterranean cave fedits with the fume of blood and the stench of \n"
+ "decay.\n";
    no_castle_flag = 1;
  }
}
