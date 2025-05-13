inherit "room/room";

#include "/players/tamina/defs.h"

int testg, testp;
object cave_guard, weapon, shield, item;

void reset(int arg) 
{
  int i;
  ::reset(arg);
  if (!arg) 
  {
    set_light(1);
    short_desc = "A Guard Room";
    long_desc =
"This room is well lit and quite large. You almost forget that\n"+
"you are underground for a moment. A large fountain pours water\n"+
"into a small pool. A wooden table has some sort of game set up\n"+
"on it and couches lie scattered around the room. The white marble\n"+
"and sound of falling water are very soothing.\n";

    dest_dir = ({
      TFROST + "cave17", "southwest",
      TFROST + "cave16", "east"
    });

    items = ({
"pool","The water pours from a statue of a cherub into a small pool\n"+
       "of water. The pool is crystal clear and very beautiful",
"fountain","The water pours from a statue of a cherub into a small pool\n"+
           "of water. The pool is crystal clear and very beautiful"
    });
  }
  if (!present("frost giant guard")) 
  {
    i = 0;
    testg = 5;
    testp = 3;
    while(i < 3) 
    {
      i ++;
      cave_guard = clone_object("obj/monster");

      cave_guard->set_name("Frost Giant Guard");
      cave_guard->set_alias("guard");
      cave_guard->set_race("giant");
      cave_guard->set_gender(1);
      cave_guard->set_short("A Frost Giant Guard");
      cave_guard->set_long(
        "This is a large, clean-shaven frost giant.  He must be at least\n"+
	"10 feet tall, and weigh about 400 pounds.  He is glaring at you...\n");
      cave_guard->set_level(14);
      cave_guard->set_wc(25);
      cave_guard->set_ac(6);
      cave_guard->set_al(-450);
      cave_guard->set_size(4);

      weapon = clone_object("obj/weapon");

      weapon->set_name("Frost Giant Longsword");
      weapon->set_alias("longsword");
      weapon->set_short("A Frost Giant's Longsword");
      weapon->set_long(
        "It seems longer and sharper than your average longsword.\n");
      weapon->set_class(13);
      weapon->set_weight(4);
      weapon->set_value(500);

      shield = clone_object("obj/armour");

      shield->set_name("Frost Giant's Shield");
      shield->set_type("shield");
      shield->set_alias("frost giant shield");
      shield->set_short("A Frost Giant's Shield");
      shield->set_long("This is a huge white shield.  Crude but effective.\n");
      shield->set_ac(1);
      shield->set_weight(3);
      shield->set_value(100);
      shield->set_size(4);

      move_object(weapon, cave_guard);
      move_object(shield, cave_guard);
      move_object(cave_guard, this_object());

      command("wield longsword", cave_guard);
      command("wear shield", cave_guard);
    }
  }
}

void init() 
{
  ::init();
  add_action("do_move", "southwest");
  add_action("do_get", "take");
  add_action("do_get", "get");
}

void long(string str) 
{
  ::long(str);
  if (str == "couch" || str == "couches") 
  {
    write("These are marble couches covered with soft pillows and\n");
    write("rich fabrics. They look quite comfortable and very heavy.\n");
    write("The pillows look like they might be worth some money.\n");
    if (testp > 0) 
      write("There are "+testp+" pillows left.....\n");
  }
  if (str == "game" || str == "table") 
  {
    write("This game of checkers is almost over, as almost all the red\n");
    write("pieces are gone from the board. However there mightbe a few left\n");
    write("for you to get.");
    if (testg > 0) 
      write(" In fact, there are "+testg+" pieces left.\n");
  }
}

int id(string str) 
{
  if(::id(str)) return 1;
  return (str == "couches" || str == "couch" || str == "game" || 
          str == "pillow" || str == "pieces" || str == "piece" || 
          str == "fountain" || str == "pool" || str=="table"); 
}

int do_move() 
{
  if (present("frost giant guard")) 
  {
    write("Frost Giant Guard blocks your path.\n");
    write("Frost Giant Guard says: Leave now!\n");
    return 1;
  }
}

int do_get(string str) 
{
  if (str == "game" || str == "pieces" || str == "piece") 
  {
    if (testg > 0) 
    {
      testg = testg - 1;
      item = clone_object("obj/treasure");
      item->set_id("game piece");
      item->set_alias("piece");
      item->set_short("A Red Game Piece");
      item->set_long(
"This looks like a piece from a game of checkers.\n");
      item->set_weight(1);
      item->set_value(25);
      move_object(item, this_player());
      write("You find a red game piece.\n");
      return 1;
    } 
    else
      write("You can't seem to find anything more.\n");
  }
  if (str == "pillow") 
  {
    if (!this_player()->add_weight(1)) 
    {
      write("You can't carry anymore\n");
      return 1;
    }
    if (testp > 0) 
    {
      testp = testp-1;
      item = clone_object("obj/treasure");
      item->set_id("silk pillow");
      item->set_alias("pillow");
      item->set_short("A Soft Silk Pillow");
      item->set_long(
"This light blue silk pillow is very, very soft and silky.\n");
      item->set_weight(1);
      item->set_value(75);
      move_object(item, this_player());
      write("You get a silk pillow.\n");
      return 1;
    }  
    else 
      write("You can't seem to find anything more.\n");
    return 1;
  }
}
