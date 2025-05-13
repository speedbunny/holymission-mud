
inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
dest_dir=({"/players/rasta/room/sub_cav1","west",
   "/players/rasta/room/passage1","northwest"});

short_desc="Subterranean Cave";
long_desc=
"This subterranean cave fedits with the fume of blood and the stench of \n"
+ "decay.\n";
    no_castle_flag = 1;
  }
}
