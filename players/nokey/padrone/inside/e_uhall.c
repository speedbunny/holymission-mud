/* 170694: Nokey: strict typed and optimized */
#pragma strict_types

inherit "room/room";

int move(string dir)
  {
  if(!dir) dir = query_verb();
  if (dir == "north") {
    object guest;

    guest = (object)"players/padrone/inside/e_guest"->query_occupied();
    if (guest) {
	write("Sorry, that room is occupied by " +
	      guest->query_name() + ".\n");
	write("You'll have to wait outside.\n");
	return 1;
      }
    else
       return ::move(dir);
    }

  if (dir == "east") {
    if ("players/padrone/inside/conf_room"->query_closed()) {
	write("Sorry, the conference room is currently occupied.\n");
	write("You'll have to wait outside.\n");
	return 1;
      }
    else
       return ::move(dir);
    }
  return ::move(dir);
  }


void reset(int arg)
  {
  ::reset(arg);
  if(arg) return;
  dest_dir = ({"players/padrone/inside/e_guest","north",
	   "players/padrone/inside/m_uhall", "west",
	   "players/padrone/inside/conf_room", "east",
  });
  set_light(1);
  short_desc = "Upper hall";
  long_desc =
	   "You are in the east end of the upper hall.\n" +
	   "The East Guestroom is to the north, and the hall extends to the west.\n" +
          "The Conference Room is to the east.\n";
  }
