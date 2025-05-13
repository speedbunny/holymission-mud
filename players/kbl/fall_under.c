/* KBL's Library Key can be gotten here */

object elem,mon,key;

reset(arg)
{
  if(arg)
   return;
  if(!elem)
  {
    elem = clone_object("players/kbl/objs/water_elem");
    transfer(elem,this_object());
    key = clone_object("players/kbl/objs/leaf");
    transfer(key,elem);
    mon = clone_object("obj/money");
    mon->set_money(5000);
    transfer(mon,elem);
  }
}

short()
{
  return "Water World";
}

long()
{
  write(short()+".\n");
  write("This is a very plain looking area, looks as if everything is\n");
  write("washed clean. You feel alot of power here tho.\n");
  write("   Obvious exits are out, dive and down.\n");
}

init()
{
  set_light(0);
  add_action("out","out");
  add_action("out","dive");
  add_action("out","down");
  add_action("look_it","look");
  add_action("look_it","scan");
}

out()
{
  write("You dive back into the water to...\n");
  this_player()->move_player("out of lair#players/kbl/falls_cav1");
  return 1;
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at area" || str == "area")
  {
    long();
    return 1;
  }
}

