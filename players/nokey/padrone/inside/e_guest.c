/* 170694: Nokey: strict typed */

#pragma strict_types

inherit "room/room";

object query_occupied();

object guest, notebook;
string guestname;

void extra_reset(int arg) {
    if (!notebook || !present(notebook)) {
	notebook = clone_object("players/padrone/obj/thing");
	notebook->set_name("notebook");
	notebook->set_alias("book");
	notebook->set_short("A small black notebook");
	notebook->set_long("This is a small notebook with a black cover,\n" +
			   "and inside it some notes have been written down in pencil.\n");
	notebook->set_can_get(1);
	notebook->set_weight(1);
	notebook->set_value(10);
	notebook->set_read_file("/players/padrone/inside/diary.txt");
	move_object(notebook, this_object());
    }
} /* extra_reset */

void init() {
  ::init();
    if (query_occupied()) {
	write("Sorry, that room is occupied by " + guestname + ".\n");
	write("You'll have to wait outside.\n");
	tell_object(guest, this_player()->query_name() +
		   " tried to magically enter the guestroom, but failed (haha!).\n");
	this_player()->move_player("back out again#players/padrone/inside/e_uhall");
    }
    else {
	guest = this_player();
       guestname = (string)guest->query_name();
	write("Welcome to the East Guestroom!\n");
    }
}

string extra_long() {
    if (notebook && present(notebook)) {
        return "One of the earlier guests seems to have forgotten a small\n" +
	      "notebook here. It has fallen down on the floor, and noone\n" +
             "has noticed it - until you came.\n";
    }
    else return "";
}

varargs void long(string str)
  {
  if(!str) write(extra_long());
  ::long(str);
  }

void exit() {
  guest = 0;
}

void reset(int arg)
  {
  ::reset(arg);
  extra_reset(arg);
  if(arg) return;
  set_light(1);
  dest_dir = ({"players/padrone/inside/e_uhall","south",
  });
  short_desc = "East Guestroom";
  long_desc =
	 "This is the East Guestroom of the Castle, a spacious and\n" +
	 "luxuriously furnished room on the second floor.\n" +
	 "In this room you are guaranteed privacy, because\n" +
        "while you are inside this room, noone else can enter!\n";
  }

object query_occupied() {

    if (!guest)
	return 0;
    else if (!present(guest)) {
	write("Strange -- this guestroom used to be occupied\n" +
	      "by " + guestname + ", but there is noone here now...\n");
	guest = 0;
	return 0;
    }
    else
	return guest;
} /* query_occupied */
