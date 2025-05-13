inherit "room/room";

#include "/players/tamina/defs.h"

object frost_king;
int got_sword, got_spear, ink_move, candle_move, fking_moved;
string chat_str, function, type, match;

void reset(int arg) 
{
  got_sword = 0; got_spear = 0;
  ink_move = 0;  candle_move = 0;
  ::reset(arg);
  if (!arg) 
  {
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
      TFROST + "entrance", "south"
    });

    items = ({
  "desk",
"This is a large mahogany desk. The light reflects from the\n"+
"surface, bringing out deep hightlights. Sitting on the desk are:\n"+
"   An hourglass, some pieces of parchement,\n"+
"   An inkwell,  and an open book",
  "hourglass", 
"This is an hourglass, a primitive timing device",
  "parchement",
"These are blank pieces of paper",
  "inkwell",
"This is an ornate gold plated inkwell. It is open and\n"+
"appears to have been recently used.\n"+
"It looks like you could move it",
  "book",
"The book appears to be written in a different language.\n"+
"You can't seem to read it",
  "candle",
"These is a finely made candle stick. There are no candles\n"+
"in the candle holders\n"+
"It looks like you could move it",
  "candle sticks",
"These are finely made candle sticks. There are no candles\n"+
"in the candle holders\n"+
"It looks like you could move it",
  "candles",
"These are finely made candle sticks. There are no candles\n"+
"in the candle holders\n"+
"It looks like you might be able to move it",
  "rugs", 
"These are richly embroidered and quite soft",
  "tapestries", 
"These are richly embroidered and quite soft",
  "bookshelf",
"These are made of wood and contain books of no interest"
    });
  }
  if (!present("frost giant king") && !fking_moved) 
  {
    frost_king = clone_object(TMONS + "frost_king");
    move_object(frost_king, this_object());
  }
}

void long(string str) 
{
  ::long(str);
  if (str == "fireplace") 
  {
    write("A huge brick fireplace. Two candle sticks sit on the mantle.\n");
  if (!candle_move) 
    write("A fire roars in the fireplace, adding warmth.\n");
  if (!got_sword) 
    write("There is a sword hanging over the fireplace.\n");
  if (!got_spear) 
    write("There is a spear hanging over the fireplace.\n");
  if (candle_move) 
    write("A secret door is open, leading north.\n");
  }
  if ((str == "sword") && !got_sword)
    write("It is a large ornate sword, beautifuly made.\n");
  if ((str == "spear") && !got_spear)
    write("A short war spear, actualy quite beautiful in a warlike way.\n");
}

int id(string str) 
{
  if(::id(str)) return 1;
  return (str=="fireplace" || str=="spear" || str == "sword");
}

void init() 
{
  ::init();
  AA("do_get", "get");
  AA("do_get", "take");
  AA("do_move", "pull");
  AA("do_move", "move");
  AA("do_move", "turn");
  AA("do_move", "push");
  AA("do_north", "north");
}

void fking_moved(int i) 
{ 
  fking_moved = i; 
}

int do_get(string str) 
{
  object sword, spear;
  if (present("king")) 
  {
    write("The Frost Giant King blocks your way.\n");
    return 1;
  }
  if (str == "sword" && !got_sword) 
  {
    if (!TP->add_weight(4)) 
    {
      write("You can't carry anymore.\n");
      return 1;
    }
    write("You take the sword from over the fireplace.\n");
    got_sword = 1;
    sword = clone_object("players/tamina/teds/weapons/fine_sword");
    move_object(sword, TP);
    say(TPN+" takes sword from over the fireplace\n");
    return 1;
  } 
  if (str == "spear" && !got_spear) 
  {
    if (!TP->add_weight(4)) 
    {
      write("You can't carry anymore.\n");
      return 1;
    }
    write("You take the spear from over the fireplace.\n");
    got_spear = 1;
    spear = clone_object("players/tamina/teds/weapons/war_spear");
    move_object(spear, TP);
    say(TPN+" takes spear from over the fireplace\n");
    return 1;
  } 
}

int do_move(string str) 
{
  if (present("king")) 
  {
    write("The Frost Giant King blocks your way.\n");
    return 1;
  }
  if (str == "candle" || str == "candle sticks"
    || str == "candles" || str == "candle stick") 
  {
    if (candle_move) 
    {
      write("Nothing happens.\n");
      return 1;
    }
    write("As you move the candle stick, a secret door hidden inside\n"+
          "the fireplace opens.  A passage leading north is revealed.\n"+
          "As the door opens, a cold breeze blows through, extinguishing\n"+
          "the fire.\n");
    say(TPN+" does something near the fireplace and opens a secret door \n"+
        "leading north.  A cold breeze blows  through and extinguishes \n"+
        "the fire.\n");

    candle_move = 1;
    return 1;
  }
  if ((str == "inkwell") && !got_sword && !got_spear) 
  {
    write("You move the inkwell. You hear a faint grinding noise.\n");
    say(TPN+" fiddles with the inkwell.\n"+
        "You hear a faint grinding noise.\n");

    ink_move = 1;
    return 1;
  }
  if (str == "inkwell") 
  {
    write("You try to move the inkwell.....but nothing happens.\n");
    return 1;
  }
  if (id(str)) 
  {
    write("You can't move the "+str+". You try, but nothing happens.\n");
    say(TPN+" fiddles with the "+str+".\n");
    return 1;
  }
  write("What?\n");
  return 1;
}

int query_ink_move() 
{ 
  return ink_move; 
}

int do_north() 
{
  if (present("king")) 
  {
    write("What?\n");
    return 1;
  }
  if (candle_move)
    MPL("north into the fireplace#players/tamina/teds/frost/false");
  else
    write("What?\n");
  return 1;
}
