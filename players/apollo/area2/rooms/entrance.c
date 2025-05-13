

inherit "room/room";


reset(arg) {
  if(arg) return;
  set_light(1);

  short_desc = "The entrance to a deep thick forest";

  long_desc =
	"As you leave the beaten path you find yourself in an area that \n" +
	"has no set direction. It seems as if no one before you has ever \n" +
	"traveled this same path. And if anyone has gone before you, they \n" +
	"never lived to tell about their travels. \n" +
	"	\n" + 
	"If you continue up you will find a very nice contribution made by \n" +
	"Jewel, the AMAZON woman. \n" +
	"	\n" +
	"	\n" +
	"This area has been brought to you by Apollo, enjoy! \n" +
	"	\n"+
	"	\n";

  dest_dir = ({
	"players/jewel/rooms/amazon", "up",
	"players/apollo/area2/rooms/shore24", "west",
	"players/apollo/area2/rooms/forest32", "northwest",
	"players/apollo/area2/rooms/forest16", "southwest",
        "players/emerald/forest/f3-8", "east",
           });

}

