inherit "room/room";

void reset(int arg)
  {clone_list=({1,1,"sword","players/sarge/objects/change_sword",0});
  set_light(1);
  short_desc="The denizens treasury",
  long_desc=
  "You have found The Denizen's treasury, where he stores valuables "+
  "left behind by his victims.  Like the temple, the walls are "+
  "formed of mist, yet are solid.  Oddly enough, there is very little "+
  "here;  apparently The Denizen had much higher standards as to what "+
  "was valuable.\n";
  items=({
   "mist", "It is the same eerie mist you have been traveling through",
   "walls","Though formed from the mist in the air, they seem solid",
   "wall","Though formed from the mist in the air, it seems solid",
   "temple","You can't see it from here",
   "valuables","There really isn't much worth noting",
   "valuable","There really isn't much worth noting",
   "treasure","There really isn't much worth noting",
   "denizen","He is not here",
   "floor","The floor appears to be nothing more than mist",
   "ceiling","If there is a ceiling in here it is hidden in the mist"});
  dest_dir=({"room/church","leave",
   "players/warlord/quest1/room8","south"});
  ::reset(arg);
  replace_program("room/room");}

