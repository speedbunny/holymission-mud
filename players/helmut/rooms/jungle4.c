inherit "room/room";

reset(arg) {
    ::reset(arg);
    if(arg) {
	return;
    }
    short_desc="Courtyard";
    long_desc="The jungle opens up into a broad courtyard here. Hunching\n"+
    "at the back of this courtyard is an old wooden building.\n"+
    "Upon closer examination, it reveals itself to be the famous\n"+
    "Raptor Pit. The sign proclaiming this is well chewed for\n"+
    "some strange reason, and you wonder about this place's\n"+
    "reputation, which is rough, to say the least. The courtyard\n"+
    "itself is unremarkable, except for a few drunks lying around\n"+
    "in the tall grass, and some big footprints scattered around.\n";
    set_light(1);
    items=({"drunks","Man, they reek of alcohol. There are giants, orcs,\n"+
      "humans, elves, and other....uh...THINGS you've\n"+
      "never seen before. You decide to leave them alone.\n",
      "footprints","Three toes to the front, one to the rear,\n"+
      "like some impossibly huge bird.\n",
      "building","The Raptor Pit"});
    dest_dir=({"players/helmut/rooms/bar","west",
      "players/helmut/rooms/jungle3","east"});
    replace_program("room/room");
}
