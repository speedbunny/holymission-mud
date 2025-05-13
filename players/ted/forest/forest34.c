inherit "room/room";

object chimera;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"Large burn marks mar the trees and grass here. One\n"+
"area has been used as a dirt bath. The smell reminds\n"+
"of burnt sewage.\n";
    dest_dir = ({
"players/ted/forest/forest24", "north",
"players/ted/forest/forest33", "west"
    });
  }
  if(!present("chimera")) {
    chimera = clone_object("players/ted/monsters/chimera");
    move_object(chimera, this_object());
    call_other("players/ted/random_treasure","make_item",chimera,17);
    call_other("players/ted/random_magic","make_item",chimera,17);
  }
}
