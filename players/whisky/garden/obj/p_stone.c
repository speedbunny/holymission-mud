/*  LAST EDIT: Wed May  1 16:48:05 1991 by Michael Schmidt (michael)  */
int gived;
int charges; /* Matt: 7-28-93 */

#define TRUE 0
#define FALSE 1

id(str) {
    return str == "stone" || str == "perception stone";
}

short() {
    return "The stone of perception";
}

long() {
    write("The stone is shimmering in a blue light. It can tell\n");
    write("you the strength of your enemy. Just say \"perception <someone>\".\n");
    write("Or just \"perception\" while fighting.\n");
    write("There are " + charges + " charges left.\n");
}

query_weight() { return 1; }
query_value() { return 100; }

reset(arg) {
  if(arg) return;
  charges = 10;
}

init() {
    add_action("perception", "perception", 1);
}

put()
{
  return 1;
}

get()
{
  return 1;
}

perception(arg)
{
  object attacker, me;
  int diff, bad;
  string pronoun, possessive;
  
  me = this_player();

  if (arg)
    {
      attacker = present(lower_case(arg), environment(me));
      if (!attacker)
	{
	  write("There is no " + arg + " here.\n");
	  return 1;
	}
      else if (!living(attacker))
	{
	  write(arg + " is no living object!\n");
	  return 1;
	}
    }
  else
    attacker = me->query_attack();
  
  if (!attacker)
    {
      write("Nothing to check.\n");
      return 1;
    }

  pronoun = attacker->query_pronoun();
  if (!pronoun) pronoun = "it";
  possessive = attacker->query_possessive();
  if (!possessive) possessive = "its";
  
  write("The name is " + attacker->query_name() + ".\n");

  bad = FALSE;
  diff = attacker->query_hit_point();
  if (diff == 0) diff = attacker->query_hp();
  diff = diff - me->query_hit_point();
  if (diff == 0)
    {
      bad = TRUE;
      write(capitalize(pronoun) + " is in the same shape like you.\n");
    }
  else  if (diff > 0)
    {
      bad = TRUE;
      write(capitalize(pronoun) + " is in better shape than you.\n");
    }
  else
    {
      bad = FALSE;
      write(capitalize(pronoun) + " is in worse shape than you.\n");
    }
  

  diff = attacker->query_ac() - me->query_ac();
  if (diff == 0)
    {
      if (bad == FALSE)
	{
	  bad = TRUE;
	  write("But " + possessive + " armour is as good as yours.\n");
	}
      else
	write(capitalize(possessive) + " armour is as good as yours.\n");
    }
  else if (diff > 0)
    {
      if (bad == FALSE)
	{
	  bad = TRUE;
	  write("But " + possessive + " armour is better.\n");
	}
      else
	write(capitalize(possessive) + " armour is better.\n");
    }
  else
    {
      if (bad == TRUE)
	{
	  bad = FALSE;
	  write("But " + possessive + " armour is worse.\n");
	}
      else
	write(capitalize(possessive) + " armour is worse.\n");
    }
  
  diff = attacker->query_wc() - me->query_wc();
  if (diff == 0)
    {
      if (bad == FALSE)
	{
	  bad = TRUE;
	  write("But " + possessive + " weapon is as good as yours.\n");
	}
      else
	write(capitalize(possessive) + " weapon is as good as yours.\n");
    }
  else if (diff > 0)
    {
      if (bad == FALSE)
	{
	  bad = TRUE;
	  write("But " + possessive + " weapon is better.\n");
	}
      else
	write(capitalize(possessive) + " weapon is better.\n");
    }
  else
    {
      if (bad == FALSE)
	write(capitalize(possessive) + " weapon is worse.\n");
      else
	write("But " + possessive + " weapon is worse.\n");
    }	
  
  charges--;
  if(!charges) {
    write("You've used up the last charge. The stone disappears.\n");
    destruct(this_object());
  }
  return 1;
  
}

  
