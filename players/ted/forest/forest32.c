inherit "room/room";

object mage, glaive;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"A crude lean to has been erected here. It is made\n"+
"of pine branches and covered with oak leaves. A\n"+
"fire pit has been dug in front of it and a roasting\n"+
"rack lies next to it.\n";
    dest_dir = ({
"players/ted/forest/forest22", "north",
"players/ted/forest/forest31", "west"
    });
  }
  if(!present("ogre magi")) {
    mage = clone_object("players/ted/monsters/ogre_magi");
    move_object(mage, this_object());
    glaive = clone_object("players/ted/weapons/mythryl_glaive");
    move_object(glaive, mage);
    call_other(mage, "init_command", "wield glaive");
  }
}
