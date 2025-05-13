inherit "room/room";

#include "/players/tamina/defs.h"

object bag1, bag2, bag3, adamite, gem, jewel, money;
int count, test, gotten, longest;

void reset(int arg) 
{
  string name, short, alias;
  count = 0;  gotten = 0;
  ::reset(arg);
  if (!arg) 
  {
    set_light(0);
    short_desc = "The Treasure Room!";
    long_desc =
"This is the real treasure room of the Frost Giants!\n"+
"It is carved from the solid rock of the montain and\n"+
"looks more like a vault than a room. There is a large\n"+
"pedestal in the center of the room\n.";

    dest_dir = ({
      TFROST + "false", "south"
    });
  }
  if (!present("leather sack")) 
  {
    bag1 = clone_object("/players/tamina/teds/items/leather_sack");
    call_other("/players/tamina/teds/random_treasure","make_item",bag1,19);
    call_other("/players/tamina/teds/random_treasure","make_item",bag1,19);
    call_other("/players/tamina/teds/random_treasure","make_item",bag1,19);
    move_object(bag1, this_object());

    bag2 = clone_object("/players/tamina/teds/items/leather_sack");
    call_other("/players/tamina/teds/random_treasure","make_item",bag2,19);
    call_other("/players/tamina/teds/random_treasure","make_item",bag2,19);
    call_other("/players/tamina/teds/random_treasure","make_item",bag2,19);
    move_object(bag2, this_object());

    bag3 = clone_object("/players/tamina/teds/items/leather_sack");
    money = clone_object("obj/money");
    money->set_money(5000+random(5000));
    move_object(money, bag3);
    move_object(bag3, this_object());
  }
}

void init() 
{
  ::init();
  AA("do_get", "get");
  AA("do_get", "take");
  AA("press", "push");
  AA("press", "press");
}

void long(string str) 
{
  ::long(str);
  if (str == "pedestal") 
  {
    write("This is a three foot high pedestal. It is carved from\n");
    write("the very stone of the cave floor. There are six buttons\n");
    write("set in random order about the edge of the pedestal.\n");
    if (gotten)
      write("The pedestal is empty.\n");
    if (!gotten) 
      write("There is a large chunk of metal on the pedestal.\n");
  }
}

int id(string str) 
{
  if(::id(str)) return 1;
  return str == "pedestal";
}

int do_get(string str) 
{
  if (str == "metal" || str == "adamite" || str == "lump"
   || str == "metal from pedestal" || str == "metal lump") 
  {
    if (gotten) 
    {
      write("Somone has already gotten it.\n");
      return 1;
    }
    if (set_light(0) <= 0) 
    {
      write("It is totaly dark!\n");
      write("However, you manage to find the pedestal and You feel\n");
      write("around on the top of the pedestal and find a lump of metal!\n");
      if (!TP->add_weight(6)) 
      {
	write("But you can't carry anymore.\n");
	return 1;
      }
      adamite = clone_object("/players/tamina/teds/items/adamite");
      move_object(adamite, TP);
      gotten = 1;
      return 1;
    }
    write("As you reach for the "+CAP(str)+", some type of force field\n");
    write("stops your hand just inches away from it.\n");
    say(TPN+" trys to get the "+CAP(str)+" but can't seem to touch it.\n");
    return 1;
  }
}

int press(string str) 
{
  object ob, scroll, room, next, temp;
  string name;

  if (str=="button" || str=="button 1" || str=="button 2" || 
      str=="button 3" || str=="button 4" || str=="button 5" || 
      str=="button 6" || str=="1" || str=="2" || str=="3" ||  
      str=="4" || str=="5" || str=="6") 
  {
    name = TPN;
    test = random(6) + 1;
    write("You press "+str+".\n");
    say(name+" pushes "+str+".\n");
  switch(test)
  {
    case 1: 
      ob = first_inventory(TP);
      while(ob) 
      {
        next = next_inventory(TP);
        if (!call_other(ob, "id", "ND")) 
        {
	  call_other(ob, "drop");
	  if (ob) 
            destruct(ob);
          write("You feel a sudden loss.\n");
          return 1;
        }
        ob = next;
      }
      return 1;

    case 2:
    case 5: 
      write("A scroll suddenly appears in midair and falls to the ground!\n");
      say("A scroll suddenly appears in mid air and falls to the ground!\n");

      scroll = CLO("/players/tamina/teds/items/adamite_hint_scroll");
      move_object(scroll, environment(TP));
      return 1;

    case 3:
      write("Bolts of electricity hit everyone in room!\n");
      next = first_inventory(TO);
      while(next) 
      {
        temp = next_inventory(next);
        if (living(next)) 
        {  
	  TOBJ(next, "You are hit by a bolt of electricity!\n");
	  next->hit_player(30);
        }
        next = temp;
      } 
      return 1;

    case 4: 
      next = first_inventory(TO);
      while(next) 
      {
        temp = next_inventory(next);
        if (living(next)) 
        {
	  TOBJ(next, "You are ejected from the room!\n");
	  next->move_player("suddenly#room/clearing");
        }
        next = temp;
      }
      return 1;

    case 6: 
      write("You are shocked by a bolt of electricity!\n");
      say(name+" is zapped by a bolt of electricity!\n");
      HIT(30);
      return 1;

    }
  }
}
