#define	TP	this_player()
#define TPN	TP->query_name()

inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Arena";
     long_desc= "You are in the western part of the Arena.\n"+
		"Many bones and mortal remains lay strewn about, but\n"+
		"one fully intact skeleton catches your attention.\n";
     items=({ "bones","The bones have been bleached by the sun",
	      "remains","These are body parts which have been lost by "+
		"fighters in previous duels",
	      "skeleton","You see the bones of Ouzo, "+
		"a wizard who hath failed The Herp" });
     dest_dir=({ "room/arena/ar02","north",
		 "room/arena/ar04","south",
		 "room/arena/ar01","west",
		 "room/arena/ar07","east" });
  }
}
