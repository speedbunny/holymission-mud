
inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
  dest_dir=({"players/rasta/room/archway","east",
    "players/rasta/room/sub_cave","down",
    "players/rasta/room/afflict","west"});

  short_desc="Alley";


  long_desc= 
  "The wind blows from the West and you smell a diabolic stench.\n";
    no_castle_flag = 1;
  }
}
