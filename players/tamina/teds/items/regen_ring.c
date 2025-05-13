inherit "obj/armour";

int heal_left;

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
    set_name("ring");
    set_alias("ruby ring");
    set_type("ring");
    set_short("A Ruby Ring");
    set_size(0);
    set_ac(0);
    heal_left = 500 + random(250);
  }
}

void init() 
{
  ::init();
  add_action("read", "read");
}

int query_value() 
{ 
  return 1000 + heal_left*2; 
}

long()
{
  write("This is a small gold ring set with a single red ruby.\n");
  write("There are small runes inscribed on the inside of the band.\n");
  if (heal_left >= 0)
    write("The ruby is glowing brightly.\n");
  else 
    write("The ruby is dull and lifeless.\n");
}

int wear(string str) 
{
  if (!id(str)) 
    return 0;

  ::wear(str);
  if (worn)
    set_heart_beat(1);
  return 1;
}

drop(silently) 
{
  ::drop(silently);
  set_heart_beat(0);
  return 0;
}

int remove(string str) 
{
  if (!id(str)) 
    return 0;

  ::remove(str);
  set_heart_beat(0);
  return 1;
}

int query_info() 
{
  write("This is a ring of regeneration. If you wear it and you are\n");
  write("wounded, it will heal you faster than normal.\n");
  return 1;
}

int read(string str) 
{
  if (!id(str) && str !="runes") 
  {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The runes seem to say:\n");
  write("   When he whom for the ring is worn is wounded now, not dead\n");
  write("   more wounds will heal than if it be not worn at all.\n");
  return 1;
} 

int heart_beat() 
{
  int max_hp, hp, amount;
  if (!worn) 
  {
    set_heart_beat(0);
    return 1;
  }
  if (heal_left <= 0) 
  {
    if (worn_by)
      tell_object(worn_by, "Your ruby ring grows cold and lifeless.\n");
    set_heart_beat(0);
    return 1;
  }
  hp = worn_by->query_hp();
  max_hp = worn_by->query_max_hp();
  if (hp < max_hp) 
  {
    amount = random(3) + 2;
    worn_by->reduce_hit_points(-amount);
    heal_left -= amount;
  }
  return 1;
}
