/* 210794: Nokey: strict_types */
#pragma strict_types

inherit "room/room";

object query_occupied();

object guest;
string guestname;

void init() {
  ::init();
    if (query_occupied()) {
	write("Sorry, the bathroom is occupied by " + guestname + ".\n");
	write("You'll have to wait outside.\n");
       tell_object(guest, (string)this_player()->query_name() +
		   " tried to magically enter the bathroom, but failed (haha!).\n");
        this_player()->move_player("back out again#players/padrone/inside/w_uhall");
    }
    else {
	guest = this_player();
       guestname = (string)guest->query_name();
	/* 	write("Welcome to the bathroom!\n"); */
    }
}

void exit() {
    guest = 0;
}

void reset(int arg)
  {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  dest_dir = ({"players/padrone/inside/w_uhall", "north",
  });
  short_desc = "Bathroom";
  long_desc =
	 "This is the bathroom.\n" +
	 "In this room you are guaranteed privacy, because\n" +
        "while you are inside this room, noone else can enter!\n";
  }

object query_occupied() {

    if (!guest)
	return 0;
    else if (!present(guest, this_object())) {
	write("Strange -- the bathroom used to be occupied\n" +
	      "by " + guestname + ", but there is noone here now...\n");
	guest = 0;
	return 0;
    }
    else
 	return guest;
} /* query_occupied */
