inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  object ob;

  if(ob = present("entrance"))
    destruct(ob);
  if(arg) return;

  set_light(1);
  short_desc = "The dead end of the obscure alley";
  long_desc =
    "You've arrived at a dead end. It's almost pitch dark here. "+
    "The mice have made place for rats. North you go back to safer places. "+
    "South of you rises the stockade that surrounds the village.\n";

  dest_dir = ({
    HM_VILLAGE + "alley2", "north",
  });

  items = ({
    "end","This is the end of the alley. Pray that it's not your end too",
    "dead end","The alley ends dead. Pray that you don't do the same here",
    "mice","There are no more mice",
    "rats","They look as hatefully at you as you at them",
    "places","The one safe place to go back now seems Main Street",
    "main street","No more than a white spot, seen from here",
    "stockade","A strong and high wall of pointed wooden poles",
    "poles","Rough poles, selected only for their strength"
  });

  ::reset(arg);
}

void init() {
  ::init();
  add_action("climb_pole", "climb");
  add_action("_search", "search");
  add_action("enter_tunnel", "enter");
}

/* try to climb over the stockade */
int climb_pole(string str) {
  switch(str) {
    case "pole" :
    case "poles" :
    case "stockade" :
      writelw("You can't climb the stockade without hurting yourself "+
              "badly. That's what it is made for.\n");
      return 1;
    default :
      notify_fail("Climb what?\n");
      return 0;
  }
}

/* search to find a tunnel out of the village */
status _search(string str) {
  object ob;

  if(str!="dead end" && str!="alley") {
    notify_fail("Search what?\n");
    return 0;
  }

  if(present("entrance"))
    return 0;
  if(random(5))
    return 0;

  write("You found the entrance to a tunnel.\n");
  ob = clone_object("obj/thing");
  ob->set_name("the entrance to a tunnel");
  ob->set_alias("entrance");
  ob->set_short("The entrance to a tunnel");
  ob->set_long("A dark hole into the earth. It might lead anywhere...\n");
  ob->set_can_get(0);
  transfer(ob, TO);
  return 1;
}

/* leave the village through the tunnel */
int enter_tunnel(string str) {
  object ob;

  switch(str) {
    case "tunnel" :
    case "entrance" :
      if(!ob = present("entrance")) {
        write("There is no "+ str +" here you can enter.\n");
        return 1;
      }
      TP->MOVEP("into the tunnel#"+ HM_VILLAGE +"hideout");
      return 1;
    default :
      notify_fail("Enter what?\n");
      return 0;
  }
}

