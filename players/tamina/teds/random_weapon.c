#include "std.h"

/* ------------------------------------------------------------------------- 
             Created by Ted                                                
   This will create a random weapon and put it on the monster 
   from which this is called from......simply put this line in;

 call_other("/players/tamina/teds/random_weapon","make_item", monster_obj, level);

   where monster_ob is the monster currently being created and the
   level is the level of the monster. For example: 

  guard = clone_object("obj/monster");    
  guard->set_name("Treasury Guard"); 
  guard->set_level(14);
  ...
  etc 
  ...
  call_other("/players/tamina/teds/random_weapon","make_item", guard, 14);
  
  -=- Revised by Elemental Tamina  13-09-94  

 ------------------------------------------------------------------------- */

make_item(ob, level) 
{
  int length, test, value, weight, class;
  string name, alias, long, short;
  object item;

  test = random(100);
  if (level >= 5)
    test = random(100) + level;
  if (level >= 10)
    test = random(100) + (level * 2);
  if (test >= 50) 
  {
    length = random(3) + 1;
    if (level >= 5)
      length = random(3) + 4;
    if (level >= 10)
      length = random(5) + 6;
    if (level >= 15)
      length = random(5) + 10;
    if (length == 1) 
    {
      name = "wooden club";
      alias = "club";
      short = "A Hefty Wooden Club";
      long = "This is reasonably large club, carved from very solid wood.\n"+
             "You imagine that it can do a fair amount of damage.\n";
      class = 6;
      weight = 1;
      value = 12;
    } 
    if (length == 2) 
    {
      name = "dagger";
      alias = "dagger";
      short = "A Small Dagger";
      long = "A small, sharp dagger.\n"+
             "It glints as the light is reflected from its blade.\n";
      class = 7;
      weight = 1;
      value = 15;
    }  
    if (length == 3) 
    {
      name = "hand axe";
      alias = "axe";
      short = "A Hand Axe";
      long = "A short handled axe.\n";
      class = 9;
      weight = 1;
      value = 25;
    }
    if (length == 4) 
    {
      name = "curved falchion";
      alias = "falchion";
      short = "A Curved Falchion";
      long = "This is a wickedly curved Falchion-Sword.  Its blade is weighted\n"+
             "at the end, so as to hit more harder...\n";
      class = 10;
      weight = 2;
      value = 110;
    } 
    if (length == 5) 
    {
      name = "war hammer";
      alias = "hammer";
      short = "A War Hammer";
      long = "This is a heavy club-like weapon, with a sharp spike at the end.\n"+
	     "It will not please its victim if you use it...\n";
      class = 11;
      weight = 2;
      value = 260;
    } 
    if (length == 6) 
    {
      name = "hooked blade";
      alias = "blade";
      short = "A Hooked Blade";
      long = "This hooked blade looks quite deadly.\n";
      class = 12;
      weight = 2;
      value = 550;
    } 
    if (length == 7) 
    {
      name = "Battleaxe";
      alias = "battleaxe";
      short = "A Battleaxe";
      long = "This heavy, well-sharpened axe can do a serious amount of damage.\n";
      class = 14;
      weight = 3;
      value = 700;
    } 
    if (length == 8) 
    {
      name = "Broadsword";
      alias = "broadsword";
      short = "A Broadsword";
      long = "This is the weapon of choice for Knights and Fighters.\n";
      class = 14;
      weight = 3;
      value = 850;
    } 
    if (length == 9) 
    {
      name = "War Mattock";
      alias = "mattock";
      short = "A War Mattock";
      long = "This is a very large hacking weapon, that will do an ugly amount\n"+
             "of damage to its victim...\n";
      class = 15;
      weight = 3;
      value = 1000;
    } 
    if (length == 10) 
    {
      name = "sword of fire";
      alias = "sword";
      short = "A Sword of Fire";
      long = "Fire glimmers along the edge of the blade of this sword.\n";
      class = 16;
      weight = 4;
      value = 1500;
    } 
    if (length == 11) 
	    {
      name = "sword of frost";
      alias = "sword";
      short = "A Sword of Frost";
      long = "Frost glints along the edge of the blade of this sword.\n";
      class = 16;
      weight = 4;
      value = 1500;
    } 
    if (length == 12)  
    {
      name = "lance";
      alias = "lance";
      short = "A Pointed Lance";
      long = "This was used to spear opponents on the battle-field, and it\n"+ 
	     "did its job reasonably well...\n";
      class = 17;
      weight = 4;
      value = 2000;
    } 
    if (length == 13) 
    {
      name = "two handed sword";
      alias = "sword";
      short = "A Two-Handed Sword";
      long = "This is a large two-handed sword, it's weight and sharpness\nmake it a very deadly weapon.\n";
      class = 17;
      weight = 4;
      value = 2500;
    } 
    if (length == 14) 
    {
      name = "War Flail";
      alias = "flail";
      short = "A War Flail";
      long = "This is an enormous weapon, with two spiked balls attached\n"+
	     "by chains to the end of a metal rod.  It will do a fearsome\n"+
	     "amount of damage.\n";
      class = 18;
      weight = 4;
      value = 3000;
    }
    item = clone_object("obj/weapon");
    item->set_name(name);
    item->set_alias(alias);
    item->set_short(short);
    item->set_long(long);
    item->set_class(class);
    item->set_weight(weight);
    item->set_value(value);

    move_object(item, ob);
    call_other(ob, "init_command", "wield "+alias);
    return 1;
  }
}
