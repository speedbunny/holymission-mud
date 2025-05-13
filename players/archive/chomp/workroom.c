#define NAME "Ninja Assassin Chomp"
#define CNAME  NAME
inherit "room/room";

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
	/* do the following block only the first time !! */
	if(!arg) {
		set_light(1);
		short_desc=CNAME + "'s private workroom",
		long_desc=
  "This is the workroom of "+CNAME+".\n" +
  "It is full with the most extravagant things you can find in the nihonese\n"+
  "realms, a lot of pictures of monsters and special weapons. Looking at\n"+
  "the pictures you can see, that this immortal, the mighty Chomp, has\n"+
  "slain all of them and sobered the dangerous areas of Holy Mission.\n"+
  "You cannot avoid but to admire this legendary ninja !!\n";

		dest_dir=({
			"room/church", "church",
			"players/patience/ezo/coast/c1", "junk",
			"players/patience/ezo/forest/cave1", "kat",
			"players/chomp/kdland/room/entry", "kdl",
			"room/post", "post",
				 });
		items=({
   "pictures","Pictures of Shao Kahn, Haunter, and Gorgurack smilling at you",
			  });
		property = ({
   "no_sneak","no_steal","no_camouflage",
				   });
		smell = "Smells like something cooking.  Maybe the meat of mosters killed by Chomp";
	}
}

init()
{
  ::init();
}
