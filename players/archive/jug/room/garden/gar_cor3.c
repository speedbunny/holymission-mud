/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Garden corridor";
  long_desc = 
    "You have arrived at the western end of the path. There is a fountain\n"+
    "standing to the west, fishes jump up everyonce in a while. To the south\n"+
    "is the opening through the hedge. You can see that this is the way into the\n"+
    "garden. As you look at the garden to the south you realise that it looks\n"+
    "as wonderful as it has been described to you.\n";
    items = ({
    "hedge","The hedge fence seems to attract diffrent types of bugs here",
    "fountain","As you look into the fountain a gold fish looks up at you\n"+
	       "and squirts you in the eye with water! Ouch",
    "fishes","There is a bunch of little gold fishes swiming around in the\n"+
	   "fountain but one seems to almost be mischiefiviously grining at you",
    });
  dest_dir = ({
    "/players/jug/room/garden/garden1", "south",
    "/players/jug/room/garden/gar_cor2", "east",
  });
}
