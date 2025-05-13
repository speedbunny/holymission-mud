inherit "room/room";

#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Mage Tower Dentatore";
  long_desc =
      "You are in the dentatore of the Mage Tower.  There is a chair in "+
      "the center of the room that has a tilted back to it.  Next to the "+
      "chair, there is a wooden table with vairous tools laying on it to "+
      "be used in dental procedures.  In the southeast corner, there is a "+
      "pitcher of water inside a rather large bowl.\n";
  dest_dir=({
      TOWER+"room/hall3", "north",
  });
  items=({
      "chair", "A chair for the victim...patient to sit in",
      "back", "The tilted back of the dentatore chair",
      "table", "A table with dental tools on it",
      "tools", "Metal binders, scrapers, forceps, rasps, saws, spatumina, "+
               "elevators, cauteries, probes, scalpels, tooth trephines, and siles",
      "pitcher", "A pitched of water",
      "bowl", "A bowl with a few teeth in it",
      "water", "Water to help clean out victims...patients' mouths",
      "scarpers", "Horrid looking tools used for dental care",
      "forceps", "Horrid looking tools used for dental care",
      "rasps", "Horrid looking tools used for dental care",
      "spatumina", "Horrid looking tools used for dental care",
      "elevators", "Horrid looking tools used for dental care",
      "cauteries", "Horrid looking tools used for dental care",
      "probes", "Horrid looking tools used for dental care",
      "binders", "A horrid looking used for pulling teeth",
      "scapels", "Horrid looking tools used for dental care",
      "trephines", "Horrid looking tools used for dental care",
      "siles", "Horrid looking tools used for dental care",
      "teeth", "Teeth taken from various victims of the dentist",
  });
  ::reset();
  replace_program("room/room");
}
