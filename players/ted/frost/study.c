inherit "room/room";

object frost_king;
int got_sword, got_spear, ink_move, candle_move, fking_moved;
string chat_str, function, type, match;

long(str) {
  ::long(str);
  if(str=="fireplace") {
  write("A huge brick fireplace. Two candle sticks sit on the mantle.\n");
  if(!candle_move) write("A fire roars in the fireplace, adding warmth.\n");
  if(!got_sword) write("There is a sword hanging over the fireplace.\n");
  if(!got_spear) write("There is a spear hanging over the fireplace.\n");
  if(candle_move) write("A secret door is open, leading north.\n");
 }
 if((str == "sword") && !got_sword)
   write("It is a large ornate sword, beautifuly made.\n");
 if((str == "spear") && !got_spear)
   write("A short war spear, actualy quite beautiful in a warlike way.\n");
}


id(str) {
  if(::id(str)) return 1;
return (str=="fireplace" || str=="spear" || str == "sword");
}

init() {
  ::init();
 add_action("do_get"); add_verb("get");
 add_action("do_get"); add_verb("take");
 add_action("do_move"); add_verb("pull");
 add_action("do_move"); add_verb("move");
 add_action("do_move"); add_verb("turn");
 add_action("do_move"); add_verb("push");
 add_action("do_north"); add_verb("north");
}

fking_moved(i) { fking_moved = i; }

reset(arg) {
 got_sword = 0;
 got_spear = 0;
 ink_move = 0;
 candle_move = 0;
  ::reset(arg);
  if(!arg) {
    fking_moved = 0;
    set_light(0);
    short_desc = "Rich Study";
    long_desc =
"This is a richly decorated study. A large fireplace takes up\n"+
"the entire north wall. Tapestries cover the walls and rich\n"+
"colorfull rugs cover the floors. Several wooden bookshelves\n"+
"take up the remaining wall space. A large mahogany desk sits\n"+
"squarely in the center of the room.\n";
    dest_dir = ({
"players/ted/frost/entrance", "south"
    });
    items = ({
"desk","This is a large mahogany desk. The light reflects from the\n"+
       "surface, bringing out deep hightlights. Sitting on the desk are:\n"+
       " An hourglass, some pieces of parchment,\n"+
       " an inkwell and an open book",
"hourglass", "This is an hourglass, a primitive timing device",
"parchement","These are blank pieces of paper",
"inkwell","This is an ornate gold plated inkwell. It is open and\n"+
          "appears to have been recently used.\n"+
          "It looks like you could move it",
"book","The book appears to be written in a different language.\n"+
       "You can't seem to read it",
"candle","These are finely made candle sticks. There are no candles\n"+
	"in the candle holders\n"+
        "It looks like you could move it",
"candle sticks","These are finely made candle sticks. There are no candles\n"+
	"in the candle holders\n"+
        "It looks like you could move it",
"candles","These are finely made candle sticks. There are no candles\n"+
	"in the candle holders\n"+
        "It looks like you could move it",
"rugs", "These are richly embroidered and quite soft",
"tapestries", "These are richly embroidered and quite soft",
"bookshelf","these are made of wood and contain books of no interest"
    });
  }
  if(!present("frost giant king") && !fking_moved) {
    frost_king = clone_object("players/ted/monsters/frost_giant_king");
    move_object(frost_king, this_object());
  }
}

do_get(str) {
 object sword, spear;
 if(present("king")) {
  write("The Frost Giant King blocks your way.\n");
  return 1;
 }
 if(str == "sword" && !got_sword) {
  if(!this_player()->add_weight(4)) {
   write("You can't carry anymore.\n");
   return 1;
  }
  write("You take the sword from over the fireplace.\n");
  got_sword = 1;
  sword = clone_object("players/ted/weapons/fine_sword");
  move_object(sword, this_player());
  say(this_player()->query_name()+" takes sword from over the fireplace\n");
  return 1;
 }
 if(str == "spear" && !got_spear) {
  if(!this_player()->add_weight(4)) {
   write("You can't carry anymore.\n");
   return 1;
  }
  write("You take the spear from over the fireplace.\n");
  got_spear = 1;
  spear = clone_object("players/ted/weapons/war_spear");
  move_object(spear, this_player());
  say(this_player()->query_name()+" takes spear from over the fireplace\n");
  return 1;
 }
}

do_move(str) {
 if(present("king")) {
  write("The Frost Giant King blocks your way.\n");
  return 1;
 }
 if(str == "candle" || str == "candle sticks"
    || str == "candles" || str == "candle stick") {
  if(candle_move) {
    write("Nothing happens.\n");
    return 1;
  }
  write("As you move the candle stick, a secret door hidden inside\n");
  write("the fireplace opens. Revealed is a passage leading north.\n");
  write("As the door opens, a cold breeze blows through, extinguishing\n");
  write("the fire.\n");
  candle_move = 1;
  say(call_other(this_player(),"query_name")+" does something near the fireplace");
  say(" and opens\na secret door leading north.\nA cold breeze blows");
  say(" through and extinguishes the fire.\n");
  return 1;
 }
 if((str == "inkwell") && !got_sword && !got_spear) {
 write("You move the inkwell. You hear a faint grinding noise.\n");
 say(call_other(this_player(),"query_name")+" fiddles with the inkwell.\n");
 say("You hear a faint grinding noise.\n");
 ink_move = 1;
 return 1;
 }
 if(str == "inkwell") {
  write("You try to move the inkwell.....but nothing happens.\n");
  return 1;
 }
 if(id(str)) {
   write("You can't move the "+str+". You try, but nothing happens.\n");
   say(call_other(this_player(),"query_name")+" fiddles with the "+str+".\n");
   return 1;
 }
write("What?\n");
return 1;
}

query_ink_move() { return ink_move; }

do_north() {
 if(present("king")) {
   write("What?\n");
   return 1;
 }
 if(candle_move)
  call_other(this_player(),"move_player","north into the fireplace#players/ted/frost/false");
 else
  write("What?\n");
 return 1;
}
