inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Code of Wizardly Conduct";
  long_desc = "Code of Wizardly Conduct.\n\n"
    + "As a wizard have many special powers, and you will receive more\n"
    + "powers as you advance. It may be clear that such powers can easily\n"
    + "be used differently than they were originally intended to be. In\n"
    + "using your powers (your commands, as well as any wiztools you may\n"
    + "have later), some simple rules of thumb will keep life simple:\n"
    + "\t* Even as a wizard you must adhere to the player rules.\n\n"
    + "\t* Don't use you powers to help or harm a player, neither directly,\n"
    + "\t  nor indirectly.\n"
    + "\t* Don't use your powers on fellow wizards without their approval.\n"
    + "\nMore detailed rules on conduct can be found in the books in the\n"
    + "player's and wizard's sheriff office. You can 'conjure player book'\n"
    + "or 'conjure wizard book' here. Please read them both carefully.\n";
  dest_dir = ({
    "/players/uglymouth/appr/appr3", "next",
    "/players/uglymouth/appr/appr1", "previous",
    "/players/airborne/new/station", "leave",
  });
}

void init() {
  ::init();
  add_action("conjure", "conjure");
}

int conjure(string str) {
  string which;
  object book;
  if(sscanf(str, "%s book", which) != 1) {
    notify_fail("Conjure what?\n");
    return 0;
  }
  switch(which) {
    case "player":
      if(present("player rulebook")) {
        write("The player rule book is already here.\n");
        return 1;
      }
      if(book = present("wiz rulebook")) {
        write("The wizard rule book vanishes into the fabric of space.\n");
        destruct(book);
      }
      move_object(clone_object("/players/acdc/office/player_rulebook"),
        this_object());
      write("You conjure the player rule book from the fabric of space.\n");
      return 1;
    break;
    case "wizard":
      if(present("wiz rulebook")) {
        write("The wizard rule book is already here.\n");
        return 1;
      }
      if(book = present("player rulebook")) {
        write("The player rule book vanishes into the fabric of space.\n");
        destruct(book);
      }
      move_object(clone_object("/players/acdc/office/wiz_rulebook"),
        this_object());
      write("You conjure the wizard rule book from the fabric of space.\n");
      return 1;
    break;
    default:
      write("A dark voice from the fabric of space moans: You may only\n"
        + "conjure the player book or the wizard book.\n");
      return 1;
    break;
  }
}

