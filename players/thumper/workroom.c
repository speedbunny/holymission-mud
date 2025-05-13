inherit "room/room";

void reset(int arg) {
  ::reset(arg);
  set_light(1);
  short_desc="Torr a Mhuilt";
  long_desc=
    "You find yourself standing on the banks of a small loch, the heather "+
    "beneath your feet is just in blossom with its small purple and blue "+
    "flowers, and the a tall munroe towers above you, standing at the foot "+
    "of this hill, is a granite crofters cottage, it looks quite welcoming.\n"+
    "  A large forest of conifers line the far banks of the loch, as a small "+
    "burn winds its way down the hillside.\n";
  dest_dir=({
    "players/paris/waste/room/gw-a-1","waste",
    "room/church", "church",
    "players/paris/places/arkaig/enter", "cottage",
    "room/post", "post",
  });
  items=({ 
    "hill","The hill is quite breathtaking in its beauty",
    "munroe","The hill is quite breathtaking in its beauty",
    "heather","The soft blue flowers look very pretty",
    "loch", "The deep blue of Loch Arkaig looks cold",
    "burn", "White water rushes down towards the loch",
    "cottage", "A small granite building, looks inviting though",
  });
  smell = "You smell the soft scent of Scottish heather";
  property = ({
    "no_teleport","no_sneak","no_steal",
  });
}
