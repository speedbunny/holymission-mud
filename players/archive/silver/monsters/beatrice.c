inherit "obj/monster";

object client;
string function, type, match, function2, type2, match2;

id(str) { return str == "stall" || str == "flower stall" || str=="flowerstall" || str=="beatrice" || str=="beatrice the stallholder"; }

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_level(7);
  set_ep(100);
  set_ac(1000000);
  set_hp(1000000);
  set_name("beatrice the stallholder");
  set_alias("beatrice");
  set_short("Beatrice the stallholder.\nBeatrice's flower stall");
  function = allocate(4);
  type = allocate(4);
  match = allocate(4);
  function[0] = "handle_say";
  type[0] = "says";
  match[0] = "";
  type[1] = "tells you:";
  match[1] = " ";
  function[2] = "handle_arrival";
  type[2] = "arrives";
  match[2] = "";
  function[3] = "handle_gives";
  type[3] = "gives";
  match[3] = "";
  set_match(this_object(), function, type, match);
}

long(str) {
  if(!id(str)) return;
  if(str=="beatrice" || str=="beatrice the stallholder")
    return write("Beatrice is an elderly woman with a benevolent smile.\n");
  return write("A flower stall a sign on it saying: Beatrice's Instant Delivery\n"
	+ "Flower Service. Send flowers to the one you love - IN SECONDS!\n" +
	"Just say 'send flowers to <name>' and we will do our best....\n");
}

handle_say(str) {
  string who, phrase, a, b, a_name, out, send, recip;
  int oa, na, add;
  object obj, flowers;

  if ((sscanf(str, "%s says: %s\n", who, phrase) != 2)
    && (sscanf(str, "%s says \"%s\"\n", who, phrase) != 2)
    && (sscanf(str, "%s tells you: %s\n", who, phrase) != 2)) {
    say("Beatrice looks at a basket of flowers.\n");
    return;
  }
  if (who == "Beatrice")
    return;
  phrase = lower_case(phrase);
  client = present(lower_case(who), environment(this_object()));
  if (!client) {
    say("Beatrice scratches her head.\n");
    return;
  }
  if (sscanf(phrase, "send flowers to %s", a_name) == 1) {
    obj = find_living(a_name);
    if (!obj) {
      say("Beatrice says: I'm sorry, I know of nobody called " + a_name + "!\n")
;
      return 0;
    }
    if (obj == this_object()) {
      say("Beatrice says: Less of that!\n");
      return 0;
    }
    if (client->query_money() < -1) {
      say("Beatrice says: I want 50 coins to do that.\n");
      return 0;
    }
    tell_object(client, "You needn't pay to send some flowers.\n");
    say("Beatrice mutters something to a man in the back of the stall.\n");
    say("Beatrice says: Thank you very much!\n");
    move_object(this_object(), environment(obj));
    say("A messenger appears suddenly.\n");
    flowers=clone_object("players/moonchild/misc/flowers");
    recip = client->query_real_name();
    send = obj->query_real_name();
    flowers->set_name1(capitalize(send));
    flowers->set_name2(capitalize(recip));
    move_object(flowers,obj);
    tell_object(obj, "The messenger delivers some flowers to you.\n");
    say("The messenger disappears again.\n");
    move_object(this_object(),"room/jetty");
    say("Beatrice says: Your flowers have now been delivered.\n");
  }
  else if (phrase == "send flowers to") {
    say("Beatrice says: To who do you want them delivered?\n");
  }
  else if ((sscanf(phrase, "%smoney%s", a, b) == 2)
  || (sscanf(phrase, "%scost%s", a, b) == 2)
  || (sscanf(phrase, "%sprice%s", a, b) == 2)) {
    say("Beatrice says: For free I do instant flower deliveries....\n");
  }
  else if(!random(5)) say("Beatrice looks at you.\n");
}

handle_arrival(str) {
  string who, rest, n;
  if (sscanf(str, "%s arrives%s", who, rest) != 2) {
    say("Beatrice shakes her head.\n");
    return;
  }
  if (who == "Beatrice") return;
  client = present(lower_case(who), environment(this_object()));
  if (!client) {
    say("Beatrice arranges some flowers.\n");
    return;
  }
  if(!random(4)) {
    n = client->query_name();
    say("Beatrice says: Hello, " + n + ". Do you want to send some\n");
    say("Beatrice says: flowers to a special friend. We do instant deliveries\n");
    say("Beatrice says: for just 50 coins. Just say 'send flowers to <name>'.\n");
  }
} 

handle_gives(str) {
  string who, what;
  int nr_coins;
  if (sscanf(str, "%s gives %s to Beatrice.\n", who, what) == 2) {
    say("Beatrice says: Thank you very much!\n");
  }
  else if (sscanf(str, "%s gives you %d coins.\n", who, nr_coins) == 2) {
    if (nr_coins == 50) say("Beatrice says: Thank you! But who do you want to send flowers to?\n");
    else say("Beatrice says: Thank you very much!\n");
    }
  else say("Beatrice arranges some flowers.\n");
}

attack() {
  if(attacker_ob) { attacker_ob->stop_fight(); attacker_ob->stop_hunter(1); }
  stop_fight();
  stop_hunter(1);
}
