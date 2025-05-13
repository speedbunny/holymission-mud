#include "/players/redsexy/defs.h"

inherit "room/room";

void reset(int arg) {

  if(arg) return;
  set_light(1);
  short_desc="A strange little building in the town of Mos Eisley.";
  long_desc="You have entered the House of Linkage, a rugged little workshop for an "+
            "apprentice wizard, who spends his days trying to be as good as his masters. "+
            "Spell books and potions are laid out in neat racks and rows, but all this "+
            "poor fellah has learned to do is make portals!  You are sure if "+
            "you searched here hard enough you would find one he has left lying around.\n\n";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/2","northwest",
          /*   "/players/redsexy/jedi/areas/moseisley/5","northeast", This is at present unneccessary.  It will be my next area.*/
             "/players/redsexy/jedi/areas/moseisley/22","south",
           });
  
  items=({"workshop","This stone workshop doesn't look very solidly constructed",
          "books","The books are all written in an ancient language you cannot understand",
          "potions","Potions of many colours adorn the shelves",
          "press","A truly magnificent piece of machinery",
          "hut","Built of wood, this hut is actually very cool to sit in",
          "windows","There are no windows",
          "holes","Holes in the wall let the vague breeze drift in and cool the area",
          "newspaper","All the newspapers seem to have gone, maybe you should come again tomorrow?",
         });

  clone_list=({
    1,1,"apprentice","obj/monster", ({
      "set_name","apprentice",
      "set_long","A young apprentice trying to learn his spells.\n",
      "set_race","human",
      "set_level",30,
      "set_gender",1,
      "add_money",200,
      "set_wc",40,
      "set_ac",20,
    }),

 });

  ::reset();

}

init() {
  ::init();
  add_action("search", "search");
} 

search(arg) {
  if(!arg || arg == "floor") {
    write("You search the floor and find a portal.\n");
    say(TPQN + " finds an opening in the ceiling!\n");
    add_action("enter", "enter");
    add_action("up", "up");
    add_action("my_look", "look");
    return 1;
  }
}

enter(arg) {
  if(arg == "portal" || arg == "opening") {
    write("You enter the portal.\n");
    this_player()->move_player("through the portal.#players/redsexy/dimensions/connect/chamber");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}


my_look(arg) {
  if(arg == "at portal") {
    write("A cleverly hidden portal on the floor of the hut.\n");
    return 1;
  }
}
