#include "std.h"

/* -------------------------------------------------------------------------
                        Created by Ted
     This will create some random treasure and put it on the monster
     from which this is called from......simply put this line in:

  call_other("/players/tamina/teds/random_treasure","make_item", monster_obj,level);

     where monster_ob is the monster currently being created and the
     level is the level of the monster. For example:

  guard = clone_object("obj/monster");
  guard->set_name("Treasury Guard");
  guard->set_level(14);
  ...
  etc
  ...
  call_other("/players/tamina/teds/random_treasure","make_item", guard, 14);

  -=-  Revised by Elemental Tamina  28-09-94  

 ------------------------------------------------------------------------- */

make_item(ob, level) 
{
  int length, one, two, three, test, value, weight;
  string first, second, third, alias, id, short;
  object item;
  string array1, array2, array3;

  test = random(100);
  if (level >= 5)
    test = random(100) + level;
  if (level >= 10)
    test = random(100) + (level*2);
  if (test >= 50) 
  {
    length = random(4) + 1;
    one = 0;
    two = 0;
    three = 0;
    if (length == 1)
      one = random(8) + 1;
    if (length == 2) 
    {
      two = random(6) + 1;
      three = random(6) + 1;
    } 
    if (length == 3) 
    {
      one = random(8) + 1;
      two = random(6) + 1;
      three = random(6) + 1;
    } 
    if (length == 4) 
    {
      one = random(8) + 1;
      three = random(6) + 1;
    }
    array1 = allocate(15);
    array2 = allocate(10);
    array3 = allocate(10);

    array1[0] = "marble";
    array1[1] = "pearl";
    array1[2] = "diamond";
    array1[3] = "sapphire";
    array1[4] = "ruby";
    array1[5] = "coral";
    array1[6] = "ivory";
    array1[7] = "topaz";
    array1[8] = "emerald";
    array1[9] = "jade";
    array1[10] = "amethyst";
    array1[11] = "jet";
    array1[12] = "opal";
    array1[13] = "ebony";
    array1[14] = "aquamarine";

    array2[0] = "amber ";
    array2[1] = "gold ";
    array2[2] = "platinum ";
    array2[3] = "silver ";
    array2[4] = "electrum ";
    array2[5] = "copper ";
    array2[6] = "bronze ";
    array2[7] = "adamantine ";
    array2[8] = "mithril ";
    array2[9] = "laen ";

    array3[0] = "orb";
    array3[1] = "bracelet";
    array3[2] = "necklace";
    array3[3] = "tiara";
    array3[4] = "bauble";
    array3[5] = "buckle";
    array3[6] = "carving";
    array3[7] = "rod";
    array3[8] = "sceptre";
    array3[9] = "earring";

    if ((one > 0) && (two > 0) && (three > 0)) 
    {
      short = "A "+array1[one]+" and "+array2[two]+array3[three];
      alias = array3[three];
    }
    if ((one > 0) && (two == 0) && (three > 0)) 
    {
      short = "A "+array1[one]+" "+array3[three];
      alias = array3[three];
    }
    if ((one == 0) && (two > 0) && (three > 0)) 
    {
      short = "A "+array2[two]+array3[three];
      alias = array3[three];
    }
    if ((one > 0) && (two == 0) && (three == 0))  
    {
      short = "A large "+array1[one];
      alias = array1[one];
    }
    value = random(200) + 100;
    if (level >= 10)
      value = random(500) + 200;
    if (level >= 15)
      value = random(750) + 500;
    if (level >= 19)
      value = random(1000) + 750;

    weight = 1;
    if (value >= 750)
      weight = 2;

    item = clone_object("obj/treasure");

    item->set_id(alias);
    item->set_alias(alias);
    item->set_short(short);
    item->set_long(short+".\nIt looks quite expensive.\n");
    item->set_weight(weight);
    item->set_value(value);
    transfer(item, ob);
    return 1;
  }
}
