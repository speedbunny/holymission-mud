/* VIOLENS.C - Programmed by Kelly */
/* 090290: Latest update */
/* 020793: Ethereal Cashimor: Changed to room/room */
 
inherit "room/room";
 
object sign,obliterator,follow,last_talker,violens,sword;
string follow_name;
status found_him;
 
/* For the NEW, IMPROVED monster class: */
string chat_str, a_chat_str, function, type, match;
 
/* If you change this, change obli_hit_func.c too: */
#define WEAPON_CLASS 20 

reset(str) {
  if(!str) {
    dest_dir=({
      "/players/emerald/garden/gard_ent", "north",
      "room/yard","south",
//             "/players/jug/room/garden/gard_ent","north",
//               "players/alian/road1","north",
               "players/exos/rooms/house","east",
            });
    short_desc="Alley";
    long_desc="You are in an alley. The town is to the south and " +
	       "a small house rests to the east. To the north is " +
	       "a garden, you think it is a good place for newbies " +
	       "to go. The smell of honey floats in from the garden.\n";
    items=({"alley","It's very dirty here",
            "forest","It's still far away",
            "house","It's made of wood"});
    set_light(1);
    smell="This place hasn't got a good sewage system.";
  }
  if(!violens) make_violens();
  if(!sign) {
    sign=clone_object("players/padrone/obj/thing");
    sign->set_name("sign");
    sign->set_short("A metal sign on a wooden pole");
    sign->set_long("This is a small white metal sign on a pole. There is "
                 + "something written on it.\n");
    sign->set_read("It says: Prince Violens was here.\n");
    sign->set_can_get(0);
    move_object(sign, this_object());
  }
}
 
make_violens() {
    object special_sword, talker, thing;
 
    follow = 0;
    follow_name = 0;
    last_talker = 0;
    found_him = 0;
    violens = 0;
 
  violens = clone_object("obj/monster"); /* NEW, IMPROVED monster class! */
  violens->set_name("violens");
  violens->set_alias("prince violens");
  violens->set_level(19);
  violens->set_hp(500);
  violens->set_al(1000);
 violens->set_race("human");
  violens->set_male();
  violens->set_size(3);
  violens->set_short("Prince Violens Jr.,the holy paladin");
  violens->set_long("Prince Violens Jr. is a holy paladin.\n" +
  "He is dressed in white, has a friendly look on his face.\n" +
  "Prince Violens is on an important mission -- a matter of life\n" +
  "and death! Well, mostly death, really...\n");
  violens->set_aggressive(0);
  violens->set_spell_mess1("Prince Violens punches his opponent with his spiked gloves.");
  violens->set_spell_mess2("Prince Violens punches you hard with his spiked gloves.");
  violens->set_chance(20);
  violens->set_spell_dam(20);
  violens->set_dead_ob(this_object());
  move_object(violens, this_object());
 
    /* The NEW, IMPROVED monster calls: */
    if (!chat_str)
      setup_arrays();
    violens->load_chat(10, chat_str);
    violens->load_a_chat(20, a_chat_str);
    violens->set_match(this_object(), function, type, match);
 
    thing = clone_object("obj/armour");
    thing->set_type("amulet");
    thing->set_size(0);
    thing->set_name("white amulet");
    thing->set_alias("big white silver amulet");
    thing->set_short("A big white silver amulet");
    thing->set_long("This is Prince Violens's teleport device, a big white amulet\n" +
    "made of silver, engraved with some nice-looking runes. You cannot use\n" +
    "it to teleport, since it was made specifically for Prince Violens.\n");
    thing->set_weight(4);
    thing->set_value(20);
    move_object(thing, violens);
    violens->init_command("wear amulet");
 
    thing = clone_object("obj/armour");
    thing->set_name("plate");
    thing->set_alias("full plate");
    thing->set_type("armour");
    thing->set_size(3);
    thing->set_ac(4);
    thing->set_value(750);
    thing->set_weight(5);
    thing->set_short("A white full plate");
    thing->set_long("This is Prince Violens armour. It's made of white"+
      " metal and seems to provide good\nprotection.\n");
    move_object(thing, violens);
    violens->add_weight(5);
    violens->init_command("wear armour");
 
    thing = clone_object("obj/armour");
    thing->set_name("white shield");
    thing->set_alias("big white shield");
    thing->set_type("shield");
    thing->set_size(3);
    thing->set_ac(1);
    thing->set_arm_light(1);
    thing->set_value(2000);
    thing->set_weight(5);
    thing->set_short("A big white shield with a coat of arms on it");
    thing->set_long("The shield is big, white and shining brightly.\n" +
     "There is a picture painted on it, a picture of the prince's\n" +
     "family. Prince Violens with his father, also Prince Violens.\n");
    move_object(thing, violens);
    violens->add_weight(5);
    violens->init_command("wear shield");
 
    thing = clone_object("obj/armour");
    thing->set_name("platinum helmet");
    thing->set_ac(1);
    thing->set_size(3);
    thing->set_weight(2);
    thing->set_value(75);
    thing->set_alias("helmet");
    thing->set_type("helmet");
    thing->set_short("A platinum helmet");
    thing->set_long("A platinum helmet.\n");
    move_object(thing, violens);
    violens->add_weight(2);
    violens->init_command("wear helmet");
 
    thing = clone_object("obj/armour");
    thing->set_name("silver gloves");
    thing->set_ac(1);
    thing->set_size(3);
    thing->set_weight(1);
    thing->set_value(75);
    thing->set_alias("gloves");
    thing->set_type("glove");
    thing->set_short("A pair of silver gloves");
    move_object(thing, violens);
    violens->add_weight(1);
    violens->init_command("wear gloves");
 
    sword = clone_object("obj/weapon");
    sword->set_name("white longsword");
    sword->set_alt_name("longsword");
    sword->set_alias("sword");
    sword->set_class(16);
    sword->set_value(200);
    sword->set_weight(3);
    sword->set_short("A white longsword");
    sword->set_long("This is the white longsword of Prince Violens, the holy paladin.\n" +
    "It is not a really good weapon , but Prince Violens\n" +
    "obviously thinks it is quite sufficient for some fights with\n" +
    "some stupid guys who attack him.\n" +
    "For his real mission, though, he has another weapon...\n");
    sword->set_hit_func(this_object());
    move_object(sword, violens);
    violens->add_weight(3);
    violens->init_command("wield sword");
 
    special_sword = clone_object("obj/weapon");
    special_sword->set_name("holy avenger");
    special_sword->set_alt_name("avenger");
    special_sword->set_alias("sword");
    special_sword->set_class(WEAPON_CLASS);
    special_sword->set_value(9500);
    special_sword->set_weight(4);
    special_sword->set_short("Prince Violens' Holy Avenger");
    special_sword->set_long(
     "This is a really holy weapon. It flashes in the sunlight.\n"+
     "But you can feel that this weapon is made for only one very"+
     " special purpose.\n" +
     "There a some engravings on the white shining blade of this \n" +
     "holy avenger. A holy person gave sword this power, but \n" +
     "you may not find it that good.\n");
    move_object(special_sword, "players/kelly/obj/viol_hit_func");
    special_sword->set_hit_func(environment(special_sword));
    special_sword->set_wield_func(this_object());
    move_object(special_sword, violens);
 
    /* Adjusted for his extra strength and agility, to match Obliti: */
    violens->set_ac(9);
    violens->set_wc(30);
} /* make_violens */
 
/* Used by the longsword! The holy Avenger uses viol_hit_func.c! */
weapon_hit(victim) {
 
  if (previous_object() == violens && violens->query_attack() == victim
    && victim->query_npc() && victim->query_name() != "Obliterator"
    && environment(violens) != this_object()) {
 
 /*  Violens is using his longsword to fight an NPC,
  *  that is not olbiti, in a place other than the crossing! */
 
    say("Prince Violens says: I may not waste a second till I've found him.\n");
    say("Prince Violens disappears in a puff of smoke.\n");
    move_object(violens, this_object());
    say("Prince Violens arrives in a puff of smoke.\n");
  }
  return 0;
} /* weapon_hit */
 
wield() {
  if (call_other(this_player(), "query_alignment") < 250) {
    write("You're to evil to wield this weapon.\n");
    return 0;
  }
  else {
    write("This sword might not be as good as you believe it is.\n");
    return 1;
  }
} /* wield */
 
 
check_obliterator(str) {
  if (found_him && !obliterator) {
    say("Prince Violens says: Done! My mission is over!\n");
    say("Prince Violens disappears in a puff of smoke.\n");
    move_object(violens, "players/kelly/store");
    destruct(violens);
    return 1;
  }
  if (!found_him) {
    obliterator = present("obliterator", environment(violens));
    if (obliterator) {
      found_him = 1;
      /* Stop talking: */
      violens->load_chat(0, chat_str);
      violens->load_a_chat(0, a_chat_str);
      say("Prince Violens says: Allright! Finally I found you.\n"+
          "Prepare to die, you bastard.\n");
      violens->init_command("wield avenger");
      violens->set_wc(35);     /* He might still fight a player */
      violens->attacked_by(obliterator);
      return 1;
    }
  }
    return 0;
} /* check_obliti */
 
handle_say(str) {
    object talker;
    string who, phrase, a, b, dir, where;
    int oa, na, add;
 
    if (check_obliterator())
      return;
    else if (obliterator && present(obliterator, environment(violens)))
      return;
 
    if ((sscanf(str, "%s says: %s\n", who, phrase) != 2)
 && (sscanf(str, "%s says \"%s\"\n", who, phrase) != 2)   
 && (sscanf(str, "%s tells you: %s\n", who, phrase) != 2)) {
 say("Prince Violens looks puzzled.\n");
 return;
    }
    if ((who == "Prince Violens") || (who == "Violens"))
      return;
    phrase = lower_case(str); /* Use the whole sentence, including "X says: " */
    talker = find_living(lower_case(who));
    if (!talker) {
      say("Prince Violens looks confused.\n");
      return;
    }
    where = 0;
    if (sscanf(phrase, "%snorth%s", a, b) == 2) {
      where = "north";
    }
    else if (sscanf(phrase, "%ssouth%s", a, b) == 2) {
     where = "south";
    }
    else if (sscanf(phrase, "%seast%s", a, b) == 2) {
     where = "east";
    }
    else if (sscanf(phrase, "%swest%s", a, b) == 2) {
     where = "west";
    }
    else if (sscanf(phrase, "%ssoutheast%s", a, b) == 2) {
     where = "southeast";
    }
    else if (sscanf(phrase, "%ssouthwest%s", a, b) == 2) {
     where = "southwest";
    }
    else if (sscanf(phrase, "%snortheast%s", a, b) == 2) {
     where = "northeast";
    }
    else if (sscanf(phrase, "%snorthwest%s", a, b) == 2) {
     where = "northwest";
    }
    if (where) {
     say("Prince Violens says: " + capitalize(where) +
     ", you say! Well thanks a lot " + who +".\n");
     last_talker = talker;
     violens->init_command(where);
     return;
    }
    if (sscanf(phrase, "%sfollow%s", a, b) == 2) {
 say("Prince Violens says: Well then, " + who +
     ", take me to Sir Obliterator!\n");
 last_talker = 0;
 follow = talker;
 follow_name = capitalize(who);
 return;
    }
    if (sscanf(phrase, "%sobliterator%s", a, b) == 2) {
 say("Prince Violens frowns and says: You've seen him, show me\n");
 return;
    }
    say("Prince Violens says: Please don't bother me with that, I'm "+
     " looking for Sir Obliterator.\n");
    return;
} /* handle_say */
 
handle_arrival(str)
{
    string who, rest, n;
 
    if (check_obliterator())
      return;
    else if (obliterator && present(obliterator, environment(violens)))
      return;
 
    if (sscanf(str, "%s arrives%s", who, rest) != 2) {
      say("Prince Violens looks puzzled.\n");
      return;
    }
    if (   who != "Prince Violens" && who != "Violens"
        && who != "Obliterator")
     say("Prince Violens says: Sorry, " + who +
      ", but have you seen Sir Obliterator?\n");
} /* handle_arrival */
 
handle_leaving(str)
{
    string who, rest, n;
 
    if (check_obliterator())
      return;
 
    if (sscanf(str, "%s leaves %s.\n", who, rest) != 2) {
      say("Prince Violens looks puzzled.\n");
      return;
    }
    else if ((who == "Price Violens") || (who == "Violens"))
      return;
    else if (who == "Obliterator") {
      violens->init_command(rest);
      check_obliterator();
    }
    else if (obliterator && present(obliterator, environment(violens))) {
      return;
    }
    else if (who == follow_name) {
     violens->init_command(rest);
     if (!found_him) {
      if (check_obliterator() && present(follow, environment(violens))) {
 say("Prince Violens says: Here is your reward, " + follow_name + ".\n");
 say("Prince Violens gives 500 coins to " + follow_name + ".\n");
 follow->add_money(500);
 tell_object(follow, "You feel very good, having lead Prince Violens to the anti-paladin.\n");
 follow->add_alignment(200);
 follow = 0;
 follow_name = 0;
    }
 }
 else
     check_obliterator();
    }
    else if (random(4)) {
 object enemy;
 
 /* Not following anyone: 75% chance of following anybody */
 enemy = violens->query_attack();
 if (!enemy || enemy->query_name() != who)
     violens->init_command(rest);
 check_obliterator();
    }
} /* handle_leaving */
 
 
/* Called when Violens died */
monster_died(poor_violens)
{
    object murderer, corpse;
 
    murderer = violens->query_attack();
    if (murderer && murderer == violens) {
 say("Prince Violens says: Shit! I didn't believe that he's THAT tough!\n");
 say("In his dying breath Prince Violens calls his father for help.\n"+
     "His body begins to glow and he's teleported away.\n");
 say("Prince Violens disappears in a puff of smoke.\n");
 move_object(violens, "players/kelly/store");
 corpse = present("corpse of violens", environment(murderer));
 if (corpse)
     move_object(corpse, "players/kelly/store");
 return 0;
    }
    return 0;
} /* monster_died */
 
 
/* For the NEW, IMPROVED monster class: */
setup_arrays() {
 
    function = allocate(6);
    type = allocate(6);
    match = allocate(6);
 
    function[0] = "handle_say";
    type[0] = "says";
    match[0] = "";
    type[1] = "tells you:";
    match[1] = " ";
    function[2] = "handle_arrival";
    type[2] = "arrives";
    match[2] = "";
    function[3] = "handle_leaving";
    type[3] = "leaves";
    match[3] = "";
    function[4] = "check_violens";
    type[4] = "died";
    match[4] = "";
    type[5] = "killed";
    match[5] = "";
    chat_str = ({
 "Prince Violens says: Sorry, but have you seen a man called Obliterator?\n",
 "Prince Violens says: Can you show me the way to Sir Obliterator?\n",
 "Prince Violens says: You! Where is the anti-paladin?\n",
 "Prince Violens says: Where must I go to find Sir Obliterator?\n",
 "Prince Violens says: Hello you! ! Seen Obliterator lately?\n",
 "Prince Violens says: Have you seen an anti-paladin called Obliterator?\n",
 "Prince Violens says: I need to find Obliterator.\n",
 "Prince Violens says: Take me to Sir Obliterator!\n",
 "Prince Violens says: I've got to tell him something.\n",
 "Prince Violens says: I must revenge my father's death.\n",
 "Prince Violens says: I'm on a holy mission from God.\n",
 "Prince Violens looks questioningly.\n",
 "Prince Violens looks sad.\n",
 "Prince Violens says: 500 gold coins if you lead me to Sir Obliterator!\n",
 "Prince Violens says: Show me the anti-paladin ,you get 500 gold coins!\n"
    });
 
    a_chat_str = ({
 "Prince Violens grins evilly.\n",
 "Prince Violens says: Stop that! I have something to do!\n",
 "Prince Violens says: You will not stop me!\n",
 "Prince Violens says: Hm, a friend of Obliterator, are you?\n",
 "Prince Violens laughs bitterly.\n",
 "Prince Violens says: I don't want to, but I will kill you now!\n",
 "Prince Violens says: Who put you up to this? Obliterator?\n",
 "Prince Violens says: Begin to pray, you'll need it!\n",
 "Prince Violens says: Ok, i'll let you go this time, but leave now.\n"
    });
} /* setup_arrays */








