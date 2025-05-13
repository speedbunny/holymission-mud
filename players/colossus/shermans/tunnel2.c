#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (!present("ghul")) {
	move_object(clone_object("/players/sherman/ghul"),this_object());
    }
    if (arg) return;
    set_light(0);
    short_desc="A dark tunnel";
    long_desc=
    "The room is just big enough for you to walk without feeling\n"+
    "claustrophobic. Judging from the surroundings it looks like\n"+
    "this is a tunnel leading into some unknown area where some\n"+
    "slimy, smelly monster roams. The walls are slick with slime\n"+
    "and there is a really foul stench of rotting garbage. Roughly\n"+
    "to the right and above you there is a trapdoor where a few\n"+
    "wispy rays of sunlight stream through.\n";
    items=({
      "tunnel", "The tunnel is slimy and smelly and leading into\n"+
      "places people rather leave unexplored",
      "light", "The light comes from the trapdoor on the ceiling of\n"+
      "this tunnel",
      "sunlight", "The sunlight is a warm and comforting sight in\n"+
      "the midst of this gross surroundings",
      "rays", "The rays of sunlight stream through the trapdoor",
      "trapdoor", "The trapdoor looks like it leads back out to the\n"+
      "world of light as you know it",
    });
    dest_dir=({
      "/players/sherman/tunnel1","west",
      "/players/sherman/grave1","east"
    });
    smell = "The stench of slime and garbage is close to overpowering.";
}

