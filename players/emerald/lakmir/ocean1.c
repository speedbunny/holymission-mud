#define TO this_object()
#define TPN this_player()->query_name()
inherit "room/room";

int a;

reset(arg) {
  a=0;
  if (arg) return;

  set_light(1);

  short_desc="In the shallow bay";
  long_desc="You are standing in the warm water of the shallow bay.  The " +
            "waves lap gently against your legs.  From time to time, " +
            "something smooth bumps into you, and you realise that this " +
            "might be a good area in which to search for fish.\n";

  smell="The air smells salty here";

  dest_dir=({"/players/emerald/lakmir/ocean2","north",
             "/players/emerald/lakmir/ocean5","east",
             "/players/emerald/lakmir/shore1", "west",
           });

  items=({"bay","A calm bay with where fish like to live",
          "water","It is nice and warm",
          "fish", "Maybe you should search for one",
          "waves","Small waves caused by the pull of gravity from the moon",
          "legs","They connect your feet with the rest of your body",
        });

  ::reset();

}

void init() {
  ::init();
  add_action("_search", "search");
}

int _search(string str) {
object seahorse, perch, salmon, shark, cod, herring, tuna;

  if(a>=5) {
    write("There are no fish left to be found.\n");
    return 1;
  }
  switch(str) {
    case "water":
    case "for fish":
    case "bay":
      switch(random(15)) {
      case 0:
        write("You find a seahorse.\n");
        say(TPN + " finds a fish.\n");
        move_object(clone_object("/players/emerald/lakmir/sh"),TO);
        a++;
        return 1;
      case 2:
        write("You find a perch.\n");
        say(TPN + " finds a fish.\n");
        a++;
        move_object(clone_object("/players/emerald/lakmir/perch"),TO);
        return 1;
      case 3:
        write("You find a red salmon.\n");
        say(TPN + " finds a fish.\n");
        a++;
        move_object(clone_object("/players/emerald/lakmir/salmon"),TO);
        return 1;
      case 4:
        write("You find a shark.\n");
        say(TPN + " finds a fish.\n");
        a++;
        move_object(clone_object("/players/emerald/lakmir/shark"),TO);
        return 1;
      case 5:
        write("You find a cod.\n");
        say(TPN + " finds a fish.\n");
        a++;
        move_object(clone_object("/players/emerald/lakmir/cod"),TO);
        return 1;
      case 6:
        write("You find a herring.\n");
        say(TPN + " finds a fish.\n");
        a++;
        move_object(clone_object("/players/emerald/lakmir/herring"),TO);
        return 1;
      case 7:
        write("You find a tuna.\n");
        say(TPN + " finds a fish.\n");
        a++;
        move_object(clone_object("/players/emerald/lakmir/tuna"),TO);
        return 1;
      default:
        write("You search and find nothing.\n");
        say(TPN+" searches, but finds nothing.\n");
        return 1;
      }
    default :
      notify_fail("Search what?\n");
      return 0;
  }
}
