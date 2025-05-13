inherit "room/room";

int testg, testp;
object cave_guard, weapon, shield, item;

long(str) {
  ::long(str);
  if(str == "couch" || str == "couches") {
    write("These are marble couches covered with soft pillows and\n");
    write("rich fabrics. They look quite comfortable and very heavy.\n");
    write("The pillows look like they might be worth some money.\n");
    if(testp > 0) write("There are "+testp+" pillows left.....\n");
  }
  if(str == "game" || str == "table") {
    write("This game of checkers is almost over, as almost all the red\n");
    write("pieces are gone from the board. However there mightbe a few left\n");
    write("for you to get.");
    if(testg > 0) write(" In fact, there are "+testg+" pieces left.\n");
  }
}

id(str) {
  if(::id(str)) return 1;
return (str=="couches" || str=="couch" || str=="game" || str=="pillow" || str=="pieces" || str=="piece" || str=="fountain" || str=="pool" || str=="table");
}


init() {
  ::init();
 add_action("do_move"); add_verb("southwest");
 add_action("do_get"); add_verb("take");
 add_action("do_get"); add_verb("get");
}

do_move() {
  if(present("frost giant guard")) {
    write("Frost Giant Guard blocks your path.\n");
    write("Frost Giant Guard says: Leave now!\n");
    return 1;
  }
}

reset(arg) {
  int i;
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "A Guard Room";
    long_desc =
"This room is well lit and quite large. You almost forget that\n"+
"you are underground for a moment. A large fountain pours water\n"+
"into a small pool. A wooden table has some sort of game set up\n"+
"on it and couches lie scattered around the room. The white marble\n"+
"and sound of falling water are very soothing.\n";
    dest_dir = ({
"players/ted/frost/cave17", "southwest",
"players/ted/frost/cave16", "east"
    });
    items = ({
"pool","The water pours from a statue of a cherub into a small pool\n"+
       "of water. The pool is crystal clear and very beautiful",
"fountain","The water pours from a statue of a cherub into a small pool\n"+
           "of water. The pool is crystal clear and very beautiful"
    });
  }
  if(!present("frost giant guard")) {
    i = 0;
    testg = 5;
    testp = 3;
    while(i < 3) {
      i ++;
      cave_guard = clone_object("players/ted/monsters/frost_giant_guard");
      move_object(cave_guard, this_object());
      weapon = clone_object("players/ted/weapons/frost_giant_longsword");
      move_object(weapon, cave_guard);
      shield = clone_object("players/ted/armors/frost_giant_shield");
      move_object(shield, cave_guard);
    }
  }
}

do_get(str) {
 if(str == "game" || str == "pieces" || str == "piece") {
 if(!this_player()->add_weight(1)) {
   write("You can't carry anymore\n");
   return 1;
 }
 if(testg > 0) {
   testg = testg-1;
   item = clone_object("obj/treasure");
   call_other(item, "set_id", "game piece");
   call_other(item, "set_alias", "piece");
   call_other(item, "set_short", "A Red Game Piece");
   call_other(item, "set_long",
"This looks like a piece from a game of checkers.\n");
   call_other(item, "set_weight", 1);
   call_other(item, "set_value", 25);
   move_object(item, this_player());
   write("You find a red game piece.\n");
   return 1;
 } else write("You can't seem to find anything more.\n");
}
if(str == "pillow") {
 if(!this_player()->add_weight(1)) {
   write("You can't carry anymore\n");
   return 1;
 }
 if(testp > 0) {
   testp = testp-1;
   item = clone_object("obj/treasure");
   call_other(item, "set_id", "silk pillow");
   call_other(item, "set_alias", "pillow");
   call_other(item, "set_short", "A Soft Silk Pillow");
   call_other(item, "set_long",
"This light blue silk pillow is very, very soft and silky.\n");
   call_other(item, "set_weight", 1 );
   call_other(item, "set_value", 75 );
   move_object(item, this_player());
   write("You get a silk pillow.\n");
   return 1;
  } else write("You can't seem to find anything more.\n");
 }
}
