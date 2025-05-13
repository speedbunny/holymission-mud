inherit "room/room";

void reset(int arg) {
  if(arg)
    return;
  set_light(1);
  short_desc="Entrance to the chapel";
  long_desc="You are at the entrance to the chapel of the Black Monks. The hallway is\n"
	+ "decorated with shields and paintings. The chapel itself is to the west, while\n"
	+ "to the north there is a restaurant and to the south there is a shop.\n";
  dest_dir=({ "players/moonchild/chapel/rest", "north",
	"players/moonchild/cave/c21", "east",
	"players/moonchild/chapel/shop", "south",
	"players/moonchild/chapel/e2", "west" });
  items=({ "chapel", "A large, distinguished, underground building",
	"hallway", "It's dimly lit with torches along the walls",
	"torches", "There are torches all along the walls",
	"walls", "There are torches all along the walls",
	"shields", "There are shields fastened to the walls",
	"paintings", "There are paintings fastened to the walls",
	"restaurant", "It looks quite friendly",
	"shop", "Just an ordinary shop, but necessary as the Black Monks\n"
	+ "are not permitted by their order to leave their chapel" });
  property=({ "has_fire" });
  replace_program("room/room");
}
