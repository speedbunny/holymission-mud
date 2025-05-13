inherit "room/room";

void reset(int arg) {
  if(arg)
    return;
  set_light(1);
  short_desc="Centre of the chapel";
  long_desc="You are at the centre of the chapel of the Black Monks. To the north, a\n"
	+ "hallway leads off to the altar, while off to the south are the prayer rooms.\n";
  dest_dir=({ "players/moonchild/chapel/n1", "north",
	"players/moonchild/chapel/e1", "east",
	"players/moonchild/chapel/s1", "south" });
  items=({ "chapel", "A large, distinguished, underground building",
	"hallway", "It's dimly lit with torches along the walls",
	"altar", "You can't really see it from here" });
  replace_program("room/room");
}
