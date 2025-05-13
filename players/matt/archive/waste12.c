inherit "players/matt/rooms/desert/waste";

#include "/players/matt/definitions"

reset(arg) {
  if(arg) return;
  ::reset(arg);
  long_desc +=
    "    You see a hole in the ground here, surrounded not by sand\n" +
    "but by glass; flames occasionally burst up from it.\n";

  dest_dir = ({
    "players/matt/rooms/desert/waste18", "west",
    "players/matt/rooms/desert/waste5", "east",
    "players/matt/rooms/desert/waste13", "north",
    "players/matt/rooms/desert/waste11", "south",
    "players/matt/rooms/desert/shadow12", "northwest",
    "players/matt/rooms/desert/shadow19", "northeast",
    "players/matt/rooms/desert/waste17", "southwest",
    "players/matt/rooms/desert/waste4", "southeast",
              });

  items += ({
    "hole", "A deep hole, about one meter wide",
    "glass", "The heat from the flames has melted the sand around the hole",
    "flames", "Hot flames, seemingly from the core of the earth itself",
            });
           }

fill_it(obj) {
  write("You fill the empty prism with flames.\n");
  say(TP->NAME + " fills " + TP->POS + " prism with flames.\n");
  obj->set_type("fire");
  obj->set_extra("Flames dance hypnotically within it.\n");
  return 1;
             }

query_diamond_fill() { return "flames"; }
