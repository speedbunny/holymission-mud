int gived;


id(str) {
    return str == "crystal" || str == "crystal of perception";
}

short() {
    return "The crystal of perception";
}

long() {
    write("The stone is shimmering in a magic light. It can tell\n"+
    "you the strength of your enemy. Just say \"perception <someone>\".\n"+
    "Or just \"perception\" while fighting.\n"+
    "If you perception a monster the stone can shimmer in a:.\n\n"+
    "*black light  for a much too hard monster.\n"+
    "*red light for a too hard monster.\n"+
    "*blue light for a very hard monster.\n"+
    "*green light for a hard monster.\n"+
   "*white light if the monster has nearly your power.\n"+
   "*pink light if the monster is under your power.\n"+
    "*bright light if the monster is far under your power.\n\n"+
    "It also tells you if a monster has a better armour, weapon\n"+
    "or if the opponent is in a better condition.\n\n"+
    "But be careful with magical weapons as the Starburst or\n"+
    "special armours, which irritate your stone.\n\n");
}

query_value() { return 10; }

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
  int diff,diff2,diff3,diff4;
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

 diff = (attacker->query_level() - me->query_level())*100/me->query_level();
 diff2 = attacker->query_hp() - me->query_hp();
 diff3 = attacker->query_ac() - me->query_ac();
 diff4 = attacker->query_wc() - me->query_wc();
  if (diff >= 100) { 
  write("Your stone shimmers in a black light.\n");
 }
  else if (diff >= 50) {
  write("Your stone shimmers is a red light.\n");
 }
  else if (diff >= 25) {
  write("Your stone shimmers is a blue light.\n");
 }
  else if (diff >= 0) {
 write("Your stone shimmers in a green light.\n");
 }
 else if (diff >= -25) {
 write("Your stone shimmers in a white light.\n");
 }
  else if (diff >= -50) {
  write("Your stone shimmers in a pink light.\n");
  }
  else {
  write("Your stone shimmers in a bright light.\n");
  }
  if (diff2 == 0)
    {
      write(capitalize(pronoun) + " is in the same shape like you.\n");
    }
  else  if (diff2 > 0)
    {
      write(capitalize(pronoun) + " is in better shape than you.\n");
    }
  else
    {
      write(capitalize(pronoun) + " is in worse shape than you.\n");
    }
  

  if (diff3 == 0) {
	  write(possessive + " armour is as good as yours.\n");
    }
  else if (diff3 > 0) {
	  write(possessive + " armour is better.\n");
	}
  else {
	  write(possessive + " armour is worse.\n");
       return 1;
	}
  
  if (diff4 == 0)
    {
  write(possessive + " weapon seems to be as good as yours.\n");
	}
  else if (diff4 >= 0) 
    {
	  write(possessive + " weapon seems to be better.\n");
	}
  else
   {
         write(possessive+" weapon seems to be worse.\n");
  
 } 
return 1;
}

  
