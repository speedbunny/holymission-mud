#define TO this_object()
#define TPN this_player()->query_name()
inherit "room/room";
int a;
void reset(int arg) {
a=0;

  if (arg) return;

  set_light(0);
  short_desc="In the dark forest of the druid Lakmir.";
  long_desc="The dark oak and beech trees of the forest surround you with "+
            "their dark presence.  Though you cannot see anything, the "+
            "forest and its inhabitants seem to be watching you.  The "+
            "ground is littered with leaves and deadfall.\n";

  dest_dir=({"/players/emerald/lakmir/forest0","east",
             "/players/emerald/lakmir/fork","south",
             "/players/emerald/lakmir/forest3","west",
           });
  items=({"oak","Tall, ancient oaks with lichens growing on their bark",
          "beech","Its smooth skin is a satiny grey",
          "trees","They grow thickly together",
          "forest","It has a sinister feel to it",
          "ground","It is hidden beneath dead leaves",
          "leaves","Last year's living oak and beech leaves",
          "deadfall","Moldy branches, acorns, and beechnuts",
        });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("_search","search");
}

_search(str) {
  object branch, acorn, beechnut, wolf, fox;

  if(a>=3) {
    write("There is nothing more to be found.\n");
    return 1;
  }

  switch(str) {
    case "leaves":
    case "deadfall":
    case "forest":
    case "ground":
      a++;
      switch(random(6)) {
      case 0..1:
        write("You find an acorn.\n");
        say(TPN + " finds an acorns.\n");
        move_object(clone_object("/players/emerald/lakmir/acorn"),TO);
        return 1;
      case 2:
        write("You find a branch.\n");
        say(TPN + " finds a branch.\n");
        move_object(clone_object("/players/emerald/lakmir/branch"),TO);
        return 1;
      case 3:
        write("You find a beechnut.\n");
        say(TPN + " finds a beechnuts.\n");
        move_object(clone_object("/players/emerald/lakmir/beechnut"),TO);
        return 1;
      case 4:
        write("You find a wolf.\n");
        say(TPN + " finds a wolf.\n");
        move_object(clone_object("/players/emerald/lakmir/wolf"),TO);
        return 1;
      case 5:
        write("You find a fox.\n");
        say(TPN + " finds a fox.\n");
        move_object(clone_object("/players/emerald/lakmir/fox"),TO);
        return 1;
      }
      default :
        notify_fail("Search what?\n");
        return 0;
  }
}
