inherit "room/room";
#include "/players/gareth/define.h"

object board, lvlbook;
 
reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="Resting room";
    long_desc="This is the fighters most favorite room. You may stay "+
      "here as long as you want and cure your wounds after bashing "+
      "your favorite monster. To the west is the Entrance to the "+
      "inner rooms. Type 'mantle' and/or 'sword' to get your own "+
      "Fighter's mantle and sword. This room is only for fighters!!!\n";

    dest_dir = ({
               "/players/gareth/guild/rooms/room", "north",
               "/players/gareth/guild/rooms/hall", "west",
	       "/players/gareth/guild/rooms/magicshop", "up",
                });
    property=({"no_fight","no_steal"});
    smell="It stinks like sweat!! whew!";

     lvlbook = TR(CO("/players/gareth/guild/obj/book.c"), TO);
     board = TR(CO("/boards/guilds/fighter_guild"), TO);
    }
}

init() {
  ::init();
// If you ever try to lock me out of this guild again I will
//      personally come up there to NY and beat you senseless. -Mangla
// hehehe
   if(TP->query_real_guild()!= 3 && !TP->query_immortal()) {
    say("It is a non fighter! Throw him out!\n");
    printf("You are kicked out of the fighter guild - you jerk!\n");
    TP->MP("you land on your ass#/room/church");
    return;
    }
  add_action("mantle","mantle");
  add_action("sword","sword");
}

sword() {
  object sword;
  if (present("bastardsword",TP)) {
     write("But you already have one!\n");
     return 1;
  }
  if(TP->query_real_guild() != 3) {
    write("PISS OFF SCUM This is not your guild!\n");
    return 1;
  }
  sword = CO("/players/gareth/guild/obj/bas_sword.c");
  sword->set_weight(0);
  if(TR(sword,TP)) {
    write("You are carrying too much!\n");
    destruct(sword);
    return 1;
  }
  write("You are given a fighter sword.\n");
  return 1;
}

mantle() {
  object ob2;
  if (present("fighter_mantle",TP)) {
     write("You already have one.\n");
     return 1;
  }
  if(TP->query_real_guild() != 3) {
    write("ARE YOU A DUMB-ASS  ????\n");
    return 1;
  } 
  ob2 = CO("/players/gareth/guild/obj/mantle.c");
  if(TR(ob2,TP)) {
    write("You are carrying too much!\n");
    destruct(ob2);
    return 1;
  }
  write("You get your own Fighter's mantle.\n");
  return 1;
}

