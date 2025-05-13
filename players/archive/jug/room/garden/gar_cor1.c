/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Garden corridor";
  long_desc = 
    "You are now west of the garden entrance, the golden hedge continues to\n"+
    "the south and north. Further west will lead you into the garden, you can\n"+
    "smell the flowers from here.\n";
    items = ({
    "hedge", "The hedge looks like it is made out of gold",
    });
  dest_dir = ({
    "players/jug/room/garden/gard_ent", "east",
    "players/jug/room/garden/gar_cor2", "west",
  });
}
