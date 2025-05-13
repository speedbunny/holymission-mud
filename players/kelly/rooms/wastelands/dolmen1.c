inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  no_castle_flag=1;
  short_desc="The Wastelands";
  long_desc="You're in the Wastelands.\n"+
    "An enourmous dolmen is standing here.\n"+
    "It seems that you can climb it.\n";
  dest_dir=({
   "players/kelly/rooms/wastelands/waste8","west",
   "players/kelly/rooms/wastelands/waste9","east",
   "players/kelly/rooms/wastelands/waste6","north"
 });
 
 items=({
  "dolmen","This seems to be the grave of a former master of the "+
      "Wastelands.\nUnder the stoneplate you can see a small hole",
  "hole","It's dark and a cold and wet air is blowing out of it", 
 });
}
 
init() {
::init();
  add_action("climb","climb");
  add_action("enter","enter");
}
 
enter(str) {
  if(str!="hole") return;
  write("You step into the dark hole, which seems to be the entrace "+
    "to the tomb.\n");
  this_player()->move_player("into the hole#players/kelly/rooms/wastelands/"+
   "grave_entr");
  return 1;
}
 
climb(str) {
  if(str!="dolmen" && str!="up") return;
  write("It's hard to climb up because the stones' surface is that plai"+
    "n, but finally\nyou do it!\n");
  this_player()->move_player("up#players/kelly/rooms/wastelands/on_dolmen");
  return 1;
}
 
 
query_drop_castle() {
    return 1;
}
