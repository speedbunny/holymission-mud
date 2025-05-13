/* -------------------------------------------------------------------------
             Created by Ted 
   This will create some random armor and put it on the monster
   from which this is called from......simply put this line in: 

  call_other("/players/tamina/teds/random_armor","make_item", monster_obj, level);

   where monster_ob is the monster currently being created and the
   level is the level of the monster. For example: 

  guard = clone_object("obj/monster");
  guard->set_name("Treasury Guard"); 
  guard->set_level(14); 
    ...
    etc
    ...
  "/players/tamina/teds/random_armor"->make_item(guard, 14);

    -=- Revised by Elemental Tamina 13-09-94

  ------------------------------------------------------------------------- */


make_item(ob, level) 
{
  int length, test, size;
  object item, junk;

  length = random(5) + 1;
  if (length == 1) 
    size = 2;
  if (length == 2) 
    size = 3;
  if (length == 3) 
    size = 4;
  if ((length == 4) && (random(3) == 2))
    size = 0;
  else 
    size = 3;
  if (length == 5) 
    size = 3;

  test = random(100);
  if (level >= 5)
    test = random(100) + level;
  if (level >= 10)
    test = random(100) + (level * 2);
  if (test >= 50) 
  {
    length = random(4);
    if (level >= 10)
      length = random(7);
    if (level >= 15)
      length = random(9) + 3;
    if (level >= 20)
      length = random(10) + 4;

    if (!item) 
    {
      item = allocate(15);
      item[0] =  "/players/tamina/teds/armors/leather_vest";
      item[1] =  "/players/tamina/teds/armors/leather_armor";
      item[2] =  "/players/tamina/teds/armors/small_shield";
      item[3] =  "/players/tamina/teds/armors/chain_shirt";
      item[4] =  "/players/tamina/teds/armors/leather_gloves";
      item[5] =  "/players/tamina/teds/armors/medium_shield";
      item[6] =  "/players/tamina/teds/armors/leather_boots";
      item[7] =  "/players/tamina/teds/armors/steel_cap";
      item[8] =  "/players/tamina/teds/armors/chainmail";
      item[9] =  "/players/tamina/teds/armors/wool_cloak";
      item[10] = "/players/tamina/teds/armors/amulet_of_prot";
      item[11] = "/players/tamina/teds/armors/ring_of_protection";
      item[12] = "/players/tamina/teds/armors/platemail";
      item[13] = "/players/tamina/teds/armors/cloak_of_protection";
      item[14] = "/players/tamina/teds/armors/shield_of_light";
    }
    junk = clone_object(item[length]);
    if (length != 2 || length != 5 || length != 10 || length != 11)
      junk->set_size(size);

    move_object(junk, ob);
    call_other(ob, "init_command", "wear "+junk->query_type());
    return 1;
  }
}
