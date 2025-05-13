inherit "room/room";

#include "/players/topaz/defs.h"

object busy;
reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Allport Library";
    long_desc="This is the back room of the Allport Library.\n" +
              "There are many books on the shelves.\n" +
              "There is a large tome on one of the shelves that\n" +
              "catches your attention.\n" +
              "There is a small room to the south.\n";

    dest_dir=({CONT + "statroom","south",
    });
    items=({"room","A well kept library",
            "books","They seem rather normal, except for the large one",
            "book","There are many books",
            "shelf","There are quite a few shelves",
            "shelves","They hold many books",
            "bookshelves","They hold many books",
            "book shelves","They hold many books",
            "library","A popular place in Allport.  Seems kinda strange",
            "large tome","Maybe you should pull it off the shelf",
            "tome","Maybe you should pull it off the shelf",
            "small room","It looks important",
            "book shelf","There are quite a few book shelves",
    });
    set_light(1);
return 1;
  }
}

init() {
  ::init();

    add_action("_pull","pull");

}

_pull(str) {
  if(!busy) {
    busy=1;
  if(str=="large tome off the shelf" || str=="large tome off shelf" || str=="tome off the shelf" || str=="tome off shelf" || str=="large tome" || str=="tome") {
    write("You pull the book and it releases some kind of mechanism.\n");
    say(TP->query_name() + " does something with one of the books\n" +
        "on the bookshelf.\n");
  busy=1;
    call_out("_move_to_stats1",2);
    return 1;
  }
  else {
    write("You can't pull that.  Sorry.\n");
    return 1;
  }
  }
  else {
    write("You pull the tome and nothing happens.\n");
  return 1;
  }
}

_move_to_stats1() {
  write("You hear some old machinery moving.\n");
  say("You hear some old machinery moving.\n");
  call_out("_move_to_stats2",2);
  return 1;
}

_move_to_stats2() {
object ob, k, i;
  write("Suddenly the bookshelf spins around, taking you, and everything\n" +
        "else in the room with it!\n");
  say("Suddenly the bookshelf spins around, taking everything in the room\n" +
      "with it!\n");
  ob=all_inventory(this_object());
  k=sizeof(ob);
  for(i=0;i<k;i++)
    move_object(ob[i],"/players/topaz/rooms/cont/town_hall2");
  busy=0;
  return 1;
}
