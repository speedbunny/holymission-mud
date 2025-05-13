id(str) { return str == "onyx" || str == "onyx of checkout"; }
short() { return "Onyx of Checkout";}
long() {
    write("The onyx pulses softly. It can inform you about\n"+
    "the strength of your enemy. Just issue \"checkout <someone>\".\n"+
    "Or just \"checkout\" while fighting.\n"+
    "If you checkout a monster the onyx will show info about:\n"+
	"Hitpoints, weapon class, and armour class of your (potential) enemy.\n"+
	"As the onyx cannot measure these values absolutely as it lacks any\n"+
	"reference, it will compare them to your own values and show sentences\n"+
	"according to the result of the comparison. They'll soon become clear.\n"+
	"NOTE: any magic capabilities can not be measured!!!.\n\n" );
}

query_value() { return 500; }
init() { 
	add_action("checkout", "checkout"); 
}
put() { return 1; }
get() { return 1; }

checkout(arg) 
{
  object attacker, me;
  int health,weapon,armour;
  string EN;
  me = this_player();
  if (arg) {
      attacker = present(lower_case(arg), environment(me));
      if (!attacker) { 	
	  	write("No " + arg + " is present here.\n");
	  	return 1;
	  }
      else if (!living(attacker)) {
	 	 write(arg + " is not a living object!\n");
	  	return 1;
	  }
  }
  else attacker = me->query_attack();
  if (!attacker) {
      write("What do you want to checkout?.\n");
      return 1;
  }
  write("Your onyx pulses faster and faster and suddenly small messages\n"+
		"appear on it's surface...it compares your enemy to you!\n\n" );
  if (me->query_hp()) health= attacker->query_hp()*100/me->query_hp();
  else if (attacker->query_hp()) health = 1000; else health = 100;
  if (me->query_ac()) armour= attacker->query_ac()*100/me->query_ac();
  else if (attacker->query_ac()) armour = 1000; else armour = 100;
  if (me->query_wc()) weapon= attacker->query_wc()*100/me->query_wc(); 
  else if (attacker->query_wc()) weapon = 1000; else weapon = 100;
  EN = attacker->query_name();

/* for debugging:
write(health+"\n");
write(weapon+"\n");
write(armour+"\n");
*/

	write( "You're hp is: "+me->query_hp()+".\n"); 
	if (health>=125) {
  		write( "You are ");
		if (health>=500) write( "as good as dead compared to "+EN+".\n" );
		else if (health>=400) write( "extremely weak compared to "+EN+".\n" );
		else if (health>=300) write( "very weak compared to "+EN+".\n" );
		else if (health>=200) write( "weak compared to "+EN+".\n" );
		else write("a bit weaker than "+EN+ " is.\n");
	}
	else if (health<=80) {
  		write( attacker->query_name() + " is ");
		if (health<=20) write( "as good as dead compared to you.\n" );
		else if (health<=40) write( "very weak compared to you.\n" );
		else if (health<=60) write( "weak compared to you.\n" );
		else write("a bit weaker than you are.\n");
	}
	else {
  		write( attacker->query_name() + " is ");
		write( "about as healthy as you are.\n" );
	}

	if (weapon>=125) {
  		write( "You're weapon is ");
		if (weapon>=500) write( "plain shit compared to "+EN+"'s.\n" );
		else if (weapon>=400) write( "extremely weak compared to "+EN+"'s.\n" );
		else if (weapon>=300) write( "very weak compared to "+EN+"'s.\n" );
		else if (weapon>=200) write( "weak compared to "+EN+"'s.\n" );
		else write("a bit weaker than "+EN+ "'s is.\n");
	}
	else if (weapon<=80) {
  		write( attacker->query_name() + "'s weapon is ");
		if (weapon<=20) write( "plain shit compared to yours.\n" );
		else if (weapon<=40) write( "very weak compared to yours.\n" );
		else if (weapon<=60) write( "weak compared to yours.\n" );
		else write("a bit weaker than yours.\n");
	}
	else {
  		write( attacker->query_name() + "'s weapon is ");
		write( "about as good as yours is.\n" );
	}

	if (armour>=125) {
  		write( "You're armour is ");
		if (armour>=500) write( "plain shit compared to "+EN+"'s.\n" );
		else if (armour>=400) write( "extremely weak compared to "+EN+"'s.\n" );
		else if (armour>=300) write( "very weak compared to "+EN+"'s.\n" );
		else if (armour>=200) write( "weak compared to "+EN+"'s.\n" );
		else write("a bit weaker than "+EN+ "'s is.\n");
	}
	else if (armour<=80) {
  		write( attacker->query_name() + "'s armour is ");
		if (armour<=20) write( "plain shit compared to yours.\n" );
		else if (armour<=40) write( "very weak compared to yours.\n" );
		else if (armour<=60) write( "weak compared to yours.\n" );
		else write("a bit weaker than yours.\n");
	}
	else {
  		write( attacker->query_name() + "'s armour is ");
		write( "about as good as yours is.\n" );
	}

  return 1;
}

