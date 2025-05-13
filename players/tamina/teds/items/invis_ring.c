inherit "obj/armour";

#include "/players/tamina/defs.h"

int al;
status invis, too_long, twists;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

  set_name("gold ring");
  set_type("ring");
  set_size(0);
  set_short("A Gold Ring");
  set_value(1000);
  set_weight(1);
  set_ac(0);
  too_long = 0;  invis = 0;  twists = 0;
}

long() 
{
  write("This is a solid gold ring. It seems warm to the touch.\n");
  if (!worn)
  {
    write("You can see some writing on the inside of the ring.\n");
  }
  return 1;
}

string query_info() 
{
  return "This ring seems to have some type of magic about it.\n"+
         "type <twist ring> to activate it.\n";
}

void init() 
{ 
  ::init();
  add_action("do_read", "read");
  add_action("do_twist", "twist");
}

drop(silently) 
{
  if (invis)
    TP->set_vis();
  ::drop(silently);
  return 0;
}

remove(str) 
{
  if (invis)
  {
    TP->set_vis();
    set_heart_beat(0);
  }
  if (::id(str)) 
  {
    ::remove(str);
    return 1;
  }
}

int do_read(string str) 
{
  if (str == "writing" || str == "ring") 
  {
    if (!worn) 
    {
      write("You can make out the words:\n    t.i.t .e\n");
      return 1;
    }
    write("Your finger is in the way.\n");
    return 1;
  }
  else
  {
    NFAIL("Read what?\n");
    return 0;
  }
}

int do_twist(string str) 
{
  al = TP->query_alignment();

  if (str == "ring")
  {
    if (!worn || !worn_by) 
    {
      write("You twist the ring in the palm of your hand.\nNothing happens.\n");
      return 1;
    }
    if (invis) 
    {
      worn_by->set_vis();
      write("You fade back into view.\n");
      say(TPN+" suddenly appears!\n");
      set_heart_beat(0);
      invis = 0;
      return 1;
    }
    if (twists > 11) 
    {
      write("The ring glows with a blinding radiance, then fades!\n");
      say(worn_by->NAME+" suddenly glows brightly, then fades!\n");
      set_heart_beat(0);
      destruct(TO);
      return 1;
    }
    if (!invis) 
    {
      write("Your body takes on a strange transparancy.....\n");
      say(worn_by->NAME+" twists a ring on "+worn_by->QPOS+" finger and disappears from view!\n");
      set_heart_beat(1);

      worn_by->set_invis();
      TP->set_alignment(al - 25);

      invis = 1;
      twists++;
      return 1;
    }
  }
  else
  {
    NFAIL("Twist What?\n");
    return 0;
  }
}

heart_beat() 
{
  if (worn_by && too_long == 12)
  {
    TOBJ(worn_by, "The ring of invisibility saps your mental energy!\n");
    worn_by->restore_spell_points(-1);
    too_long = 0;
  }
  if (worn_by->query_attack())
    worn_by->set_vis();
  too_long++;
}
