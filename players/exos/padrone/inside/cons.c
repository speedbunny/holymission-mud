/* Padrone's consultation room. Latest change: Feb 9, 1991.
 *   The spell "Change Alignment Description" is not available
 *   on GENESIS. Lars didn't like it. How sad.
 * Ethereal Cashimor, 190393: Updated. Now uses room/room, and the
 *   MAGNETIC WEAPON SUMMONING checks if the weapon is made of metal.
 * Uglymouth, 970725: Recoded to current coding standards. Modulated spells.
 *   Left in the original comments for fun :-).
 */
#include "../config.h"

inherit "room/room";

/* 920320 Herp: only one hat allowed in the game */
object hat;

object apprentice, invisible_companion;
object client, teleportee, latest_teleportee, bird;
status busy_teleporting;

/* --- Prototyping --- */
void make_apprentice();
void make_invisible_companion();
static int take_money( int sum );

void reset( int arg ) {
  ::reset( arg );
  make_apprentice();
  make_invisible_companion();
  if( arg ) return;

  set_light( 1 );
  short_desc = "Consultation room";
  long_desc = "You are in Padrone's consultation room. It is in this room "
    + "that the mighty Wizard meets his clients. The waiting room is "
    + "west, and a small door leads east into a wardrobe or something.\n";
  dest_dir = ({
    "players/padrone/inside/waitingroom", "west",
    "players/padrone/inside/eddies_room", "east",
  });
  items = ({
    "room", "It is wealthily furnished",
    "wardrobe", "Someone could well live there",
  });
  smell = "You smell plain magical air.";
}
    
/* --- Object making functions --- */
void make_apprentice() {    
  object item;
  string *function, *type, *match;

  if( apprentice && living( apprentice ) ) return;
    
  function = allocate(3);
  type = allocate(3);
  match = allocate(3);

  function[0] = "handle_say";
  type[0] = "says";
  match[0] = "";
  type[1] = "tells you:";
  match[1] = " ";
  function[2] = "handle_arrival";
  type[2] = "arrives";
  match[2] = "";
  
  /* NEW, IMPROVED monster class! */
  apprentice = clone_object("obj/monster");
  apprentice->set_name( "apprentice" );
  apprentice->set_short( "The Wizard's apprentice");
  apprentice->set_long( "This is the Wizard's apprentice. "
    + "Although still a young man, he has already mastered many of the "
    + "secrets of magic. He is wearing a strange hat and looks somewhat "
    + "dangerous. Since the Wizard is not in today, the apprentice is "
    + "handling the consultations. Talk to him and state your problem!\n" );
  apprentice->set_level( 29 );
  apprentice->set_male();
  apprentice->set_hp( 800 );
  apprentice->set_al( 100 );
  apprentice->set_whimpy( -1 );
  apprentice->set_aggressive( 0 );
  apprentice->add_money( 10 + 10 * random(5) );
  apprentice->set_chance( 40 );
  apprentice->set_spell_mess1( "The apprentice casts a fireball." );
  apprentice->set_spell_mess2( "The apprentice casts a fireball at you." );
  apprentice->set_spell_dam( random( 100 ) );
  apprentice->set_dead_ob( this_object() );
  /* The NEW, IMPROVED monster calls: */
  apprentice->load_chat( 2, ({
    "The apprentice says: How can I help you?\n",
    "The apprentice studies the appointment book.\n"
  }) );
  apprentice->set_match( this_object(), function, type, match );

  transfer( call_other( "players/padrone/outside/front_yard", 
    "make_ticket" ), apprentice );

  item = clone_object( "obj/weapon" );
  item->set_name( "long knife" );
  item->set_alt_name( "knife" );
  item->set_short( "A long knife" );
  item->set_long( "Years of cutting magic herbs corroded its blade.\n" );
  item->set_class( 8 );
  item->set_value( 20 );
  item->set_weight( 1 );
  transfer( item, apprentice );
  apprentice->init_command( "wield knife" );
	
  item = clone_object( "obj/thing" );
  item->set_name( "crystal key" );
  item->set_alias( "key" );
  item->set_alt_name( "towerdoorkey" );
  item->set_short( "A crystal key" );
  item->set_long( "A crystal key. You wonder where it fits...\n" );
  item->set_weight( 1 );
  item->set_value( 10 );
  transfer( item, apprentice );

  item = clone_object( "players/padrone/obj/gravstone" );
  item->set_weight(-2);
  transfer( item, apprentice );
  
  apprentice->move_player( "X", this_object() );
}

/* The invisible companion hack */
void make_invisible_companion() {
  string *function, *type, *match;

  if( invisible_companion && living( invisible_companion ) ) return;
    
  function = allocate(3);
  type = allocate(3);
  match = allocate(3);

  function[0] = "take_weapon";
  type[0] = "hit";
  match[0] = "";
  type[1] = "missed";
  match[1] = "";
  type[2] = "smashed";
  match[2] = "";

  /* NEW, IMPROVED monster class! */   
  invisible_companion = clone_object( "obj/monster" );
//  invisible_companion->set_name( 0 );
  invisible_companion->set_alt_name("invisible companion of the apprentice");
  invisible_companion->set_alias( "invisible companion" );
  invisible_companion->set_short( 0 );
  invisible_companion->set_long("He is invisible and lurks in a corner.\n");
  invisible_companion->set_level( 1 );
  invisible_companion->set_no_fight( 1 );
  invisible_companion->set_male();
  invisible_companion->set_ac( 1 );
  invisible_companion->set_hp( 1 );
  invisible_companion->set_aggressive( 0 );
  invisible_companion->set_no_ears( 1 );
  /* The NEW, IMPROVED monster calls: */
  invisible_companion->set_match( this_object(), function, type, match );
  
  transfer( clone_object( "players/padrone/obj/immunity" ), 
    invisible_companion );
  move_object( invisible_companion, this_object() );
}

/* 920320 Herp: only one hat allowed in the game.
static void make_hat() {
  if( hat ) return;
  hat = clone_object( "players/padrone/obj/wizardshat" );
  transfer( hat, apprentice );
  apprentice->init_command( "wear hat" );
}
*/

static object make_bird() {
  object b;
  string *function, *type, *match;

  function = allocate(3);
  type = allocate(3);
  match = allocate(3);

  function[0] = "bird_handle_say";
  type[0] = "says";
  match[0] = "";
  type[1] = "tells you:";
  match[1] = " ";
  function[2] = "bird_handle_leaves";
  type[2] = "leaves";
  match[2] = "";

  b = clone_object("obj/monster");     /* NEW, IMPROVED monster class! */
  b->set_name( "bird" );
  b->set_level( 1 );
  b->set_hp( 10 );
  b->set_al( 100 );
  b->set_ac( 10 );
  b->set_short( "A small bird that shimmers strangely" );
  b->set_long( "This small bird doesn't seem quite natural.\n"
    + "There must be magic involved here...\n" );
  b->set_aggressive( 0 );

  /* The NEW, IMPROVED monster calls: */
  b->load_chat( 25, ({
    "The small bird flutters happily.\n",
    "The small bird sings cheerfully.\n",
    "The small bird seems to be waiting for something.\n",
    "The small bird seems to be waiting for someone to say something.\n",
    "The small bird looks at you questioningly.\n",
  }) );
  b->set_match( this_object(), function, type, match );

  /* This is done only to start the heart beat in the bird: */
  move_object( bird, environment( apprentice ) );
  move_object( apprentice, environment( apprentice ) );
  return b;
}
/* --- End object making functions --- */

/* --- Apprentice's spell functions --- */
static void spell_know_alignment() {        
  if( !take_money( 100 ) ) return;
  tell_room( this_object(), 
    "The apprentice casts the spell KNOW ALIGNMENT.\n" );
  tell_object( client,
    sprintf( "The apprentice tells you: Your alignment is %d.\n",
      client->query_alignment() ) );
}
    
static void spell_heal( string a_name ) {    
  object obj;

  if( a_name == "myself" || a_name == "me" ) obj = client;
  else {
    obj = present( lower_case( a_name ), environment( apprentice ) );
    if( !obj || !living( obj ) ) {
      tell_object( client,
	sprintf( "The apprentice says: But there is no %s here!\n", 
	  a_name ) );
      return;
    }
  }
  if( obj == client && !take_money( 4000 ) ) return;
  else if( obj != client && !take_money( 2000 ) ) return;

  tell_room( this_object(), "The apprentice casts the spell HEAL.\n" );
  obj->heal_self( 1000 );
  tell_object( obj, "You are healed by the Wizard's Apprentice.\n" );
  /* Snicker, snicker... */
  apprentice->heal_self( 1000 );
  tell_object( client, "The apprentice heals himself at the same time.\n" );
}

static void spell_teleport( string a_name ) {
  object teleportee_env;

  teleportee = find_living( lower_case( a_name ) );
  if( !teleportee ) {
    tell_object( client, 
      sprintf( "The apprentice says: Sorry, I cannot find %s.\n",
        a_name ) );
    return;
  }
  teleportee_env = environment( teleportee );
  if( teleportee_env->query_property( "no_teleport" ) ) {
    tell_object( client,
      "The apprentice says: Sorry, I cannot reach your friend.\n" );
    return;
  }
  if( teleportee->query_npc() ) {
    tell_object( client,
      "The apprentice says: Sorry, but that is just a simple monster.\n"
      + " - I only teleport players.\n" );
    return;
  }
  if( present( teleportee, environment( apprentice ) ) ) {
    tell_room( this_object(), "The apprentice says: Don't be stupid.\n" );
    return;
  }
  if( !take_money( 1000 ) ) return;
  tell_object( client,
    "The apprentice says: Ok, this may take some time...\n" );
  tell_room( this_object(), "The apprentice casts the spell TELEPORT.\n" );
  busy_teleporting = 1;

  /*  We create a small bird that teleports to the presumptive teleportee
   *  and asks him if he wants to be teleported.
   *  Otherwise, someone might use this spell for evil purposes...
   */
  bird = make_bird();
  move_object( bird, teleportee_env );
  tell_room( teleportee_env,
    sprintf( "Suddenly a small bird comes flying from no obvious "
      + "direction. It seems to whisper something to %s.\n",
      teleportee->query_name() ) );
  tell_object( teleportee,
    sprintf( "The bird whispers to you: Greetings from %s!\n" 
      + " - Do you want to be teleported?\n", client->query_name() ) );
}
	
static void spell_change_alignment( int na ) {
  int oa, bug_fix, add;

  oa = client->query_alignment();

  /* Moonchild edit */
  bug_fix = 100 * ( (oa - na) < 0 ? (na - oa) : (oa - na) );
  if( bug_fix < 0 ) {
    tell_room( this_object(), "The apprentice falls down laughing.\n" );
    return;
  }
  if( !take_money( bug_fix ) ) return;
  /* End Moonchild edit */
	
  add = na - ( oa * 9 ) / 10;
  tell_room( this_object(), 
    "The apprentice casts the spell CHANGE ALIGNMENT.\n" ); 
  tell_object( client,
    sprintf( "The apprentive changes your alignment from %d to %d.\n",
      oa, na ) );
  client->add_alignment( add );
}

#ifndef GENESIS
static void spell_change_align_desc( string al_desc ) {        
  if( !take_money( 20 ) ) return;
  tell_room( this_object(),
    "The apprentice casts the spell CHANGE ALIGNMENT DESCRIPTION.\n" );
  apprentice->set_level( 100 );
  client->set_alignment( al_desc );
  apprentice->set_level( 29 );
}
#endif

static void spell_remove_frog() {
  if( !take_money( 500 ) ) return;
  tell_room( this_object(),
    "The apprentice casts the spell REMOVE FROG CURSE.\n" );
  client->frog_curse( 0 );
}
/* --- End apprentice's spell functions --- */

/* --- Interactive string handling functions --- */
/* Purchasing spells from apprentice */
void handle_say( string str ) {
  string who, phrase, a, b, a_name;
  int na; 

  if( sscanf( str, "%s says: %s\n", who, phrase ) != 2 && 
      sscanf( str, "%s tells you: %s", who, phrase ) != 2 ) { 
    tell_room( this_object(), "The apprentice looks brain damaged.\n" );
    return;
  }
  if( who == "The apprentice" || who == "Apprentice") return;

  if( !bird || !teleportee ) busy_teleporting = 0;
  if( busy_teleporting ) {
    tell_room( this_object(),
      "The apprentice is concentrating on a spell and doesn't listen.\n" );
    return;
  }
  client = present( lower_case( who ), environment( apprentice ) );
  if( !client ) {
    tell_room( this_object(), "The apprentice looks confused.\n" );
    return;
  }

  if( sscanf( phrase, "%shelp%s", a, b ) == 2 ||
      sscanf( phrase, "%sHelp%s", a, b ) == 2 ) {
    tell_room( this_object(), 
      sprintf( "The apprentice says: Well, %s, I do have some powers.\n"
        + " - But magic assistance is of course not free.\n", who ) );
    return;
  }
  if( sscanf( phrase, "%scost%s", a, b ) == 2 ||
      sscanf( phrase, "%sprice%s", a, b ) == 2 ||
      sscanf( phrase, "%sprice%s", a, b ) == 2 ||
      sscanf( phrase, "%slist%s", a, b ) == 2 ||
      sscanf( phrase, "%stell%s", a, b ) == 2 ||
      sscanf( phrase, "%sTell%s", a, b ) == 2 ||
      sscanf( phrase, "%sservice%s", a, b ) == 2 ||
      sscanf( phrase, "%swhat%s", a, b ) == 2 ||
      sscanf( phrase, "%sWhat%s", a, b ) == 2 ) {
    tell_room( this_object(),
      sprintf( "%s\n%-=35s   %-=30s\n%s\n",
	"The apprentice says: The prices are fixed:",
	"   Know alignment\n   Heal yourself\n   Heal someone else\n   Teleport a "
	  + "player here\n   Change alignment\n   Change alignment description\n   "
	  + "Remove forg curse\n",
	" 100 gold coins\n4000 gold coins\n2000 gold coins\n1000 gold "
	  + "coins\n 100 gold coins per point\n  20 gold coins (temporary)\n"
	  + " 500 gold coins\n",
	" - Just tell me what you want, the apprentice smiles." ) );
    return;
  }
  if( phrase == "know alignment" || phrase == "Know alignment" ) {
    spell_know_alignment();
    return;
  }
  if( phrase == "heal" || phrase == "Heal" ) {
    tell_object( client,
      "The apprentice says: Heal who? Say 'heal ...', and I'll do it.\n" );
    return;
  }
  if( sscanf( phrase, "heal %s", a_name ) == 1 ||
      sscanf( phrase, "Heal %s", a_name ) == 1 ) {
    spell_heal( a_name );
    return;
  }
  if( phrase == "teleport" || phrase == "Teleport" ) {
    tell_object( client,
      "The apprentice says: Yes, but who? Say 'teleport ...', "
      + "and I'll do it.\n" );
    return;
  }
  if( sscanf( phrase, "teleport %s", a_name ) == 1 ||
      sscanf( phrase, "teleport %s", a_name ) == 1 ) {
    spell_teleport( a_name );
    return;
  }
  if( sscanf( phrase, "change alignment to %d", na ) == 1 ||
      sscanf( phrase, "Change alignment to %d", na) == 1 ) {
    spell_change_alignment( na );
    return;
  }
  if( phrase == "change alignment" ||
      phrase == "Change alignment" ||
      sscanf( phrase, "Change alignment %d", a ) == 1 ||
      sscanf( phrase, "change alignment %d", a ) == 1 ) {
    tell_object( client,
      "The apprentice says: What? Say 'change alignment to ...', "
      + "and I'll do it.\n" );
    return;
  }
  if( sscanf( phrase, "change alignment to %s", a ) == 1 ||
      sscanf( phrase, "Change alignment to %s", a ) == 1 ) {
    tell_room( this_object(),
      "The apprentice says: The alignment has to be a numeric value.\n" );
    return;
  }

#ifndef GENESIS
  if( sscanf( phrase, "change alignment description to %s", a ) == 1 ||
      sscanf( phrase, "Change alignment description to %s", a ) == 1 ) {
    spell_change_align_desc( a );
    return;
  }
  if( phrase == "change alignment description" ||
      phrase == "Change alignment description" ||
      sscanf( phrase, "change alignment description %s", a ) == 1 ||
      sscanf( phrase, "Change alignment description %s", a ) == 1 ) {
    tell_object( client,
      "The apprentice says: What? Say 'change alignment description "
      + "to ...',\n - and I'll do it.\n" );
    return;
  }
#endif
  if( phrase == "remove frog curse" ||
      phrase == "Remove frog curse" ) {
    spell_remove_frog();
    return;
  }
  if( sscanf( phrase, "%sfrog%s", a, b ) == 2 ||
      sscanf( phrase, "%scurse%s", a, b) == 2 ) {
    tell_object( client, "The apprentice says: I can remove a frog curse.\n"
      + " - Just say 'remove frog curse', and I'll do it.\n" );
    return;
  }
  if( sscanf( phrase, "%stitle%s", a, b ) == 2 ||
      sscanf( phrase, "%sdescription%s", a, b ) == 2 ) {

#ifdef GENESIS
    tell_object( client,
      "The apprentice says: Sorry, I don't know how to change either\n"
      + " - your title or your alignment description.\n" );
#else
    tell_object( client,
      "The apprentice says: I can change your alignment\n"
      + " - description for you (but not your title).\n"
      + " - Just say 'change alignment description to ...',\n"
      + " - and I'll do it.\n" );
#endif
    return;
  }
  if( sscanf(phrase, "%salignment%s", a, b ) == 2 ) {

#ifdef GENESIS
    tell_object( client,
      "The apprentice says: I have the power to change your alignment.\n"
      + " - Just say 'change alignment to ...',\n"
      + " - and I'll do it.\n" );
#else
    tell_object( client,
      "The apprentice says: I know two spells to handle alignments,\n"
      + " - KNOW ALIGNMENT and CHANGE ALIGNMENT.\n"
      + " - Just say 'know alignment',\n"
      + " - or 'change alignment to ...',\n"
      + " - and I'll do it.\n");
#endif
    return;
  }
  tell_room( this_object(), "The apprentice looks puzzled.\n" );
} /* end handle_say */

/* Players arriving at apprentice */
void handle_arrival( string str ) {
  string who, rest, n;

  if( sscanf( str, "%s arrives%s", who, rest ) != 2 ) {
    tell_room( this_object(), "The apprentice looks brain damaged.\n" );
    return;
  }
  if( who == "The apprentice" || who == "Apprentice") return;
  if( !bird || !teleportee) busy_teleporting = 0;
  if( busy_teleporting ) {
    tell_room( this_object(),
      "The apprentice is concentrating on a spell.\n");
    return;
  }
  client = present( lower_case( who ), environment( apprentice ) );
  if( !client ) {
    tell_room( this_object(), "The apprentice looks confused.\n" );
    return;
  }
  if( client == latest_teleportee ) {
    latest_teleportee = 0;
    return;
  }
  /* A player/monster without a ticket has arrived! -- ATTACK! */
  if( !present( "castle ticket", client ) ) {
    tell_room( this_object(), sprintf( "The apprentice immediately notices "
      + "that %s hasn't got a ticket.\n", who ) );
    apprentice->attacked_by( client );
    return;
  }

  n = client->query_name();
  tell_object( client,
    sprintf( "The apprentice says: Welcome, %s.\n", n ) );
  if( present( "padrone", environment( apprentice ) ) )
    tell_object( client,
      " - The Wizard is standing right here, but he is inventing new magic "
      + "and cannot be interrupted. But maybe I can help you?\n" );
  else
    tell_object( client,
      " - The Wizard is not here today, he's out looking for "
      + "a castle he lost. But maybe I can help you?\n" );
} /* end handle_arrival */

/*----------------------------------------------------------
  This is a real hack.
  The apprentice is a monster, and he should react
  on strings like "Padrone hit Apprentice."
  (note that hits is misspelled hit),
  but since a monster does not react on any strings
  while it is busy fighting, we'll have to put ANOTHER,
  invisible monster in the room, just to cast the spell!
  That is, take_weapon is called by INVISIBLE_COMPANION,
  not by APPRENTICE.
----------------------------------------------------------*/
void take_weapon( string str ) {
  object foe, foe_weapon, app_weapon;
  int app_wc, i;
  string who, rest, *whoexp;

/*
  if( sscanf( str, "%s hits Apprentice%s\n", who, rest ) != 2 &&
      sscanf( str, "%s hit Apprentice%s\n", who, rest ) != 2 &&
      sscanf( str, "%s missed Apprentice%s\n", who, rest ) != 2 &&
      sscanf( str, "%s smashed Apprentice%s\n", who, rest ) != 2 )
    return;
*/
  for( i = 0; i < 4; i++ ) {
    if( sscanf( str, "%s hits Apprentice%s", who, rest ) == 2 ) break;
    if( sscanf( str, "%s hit Apprentice%s", who, rest ) == 2 ) break;
    if( sscanf( str, "%s missed Apprentice%s", who, rest ) == 2 ) break;
    if( sscanf( str, "%s smashed Apprentice%s", who, rest ) == 2 ) break;
  }
  if( i == 4 ) return;

  whoexp = explode( who, " " );
  who = whoexp[ sizeof( whoexp ) - 1 ]; /* correcting for pretitle */
  foe = present( lower_case( who ), environment( apprentice ) );
  if( !foe ) return;
  if( !random( 2 ) ) return; /* Just 50% that he casts the spell.. */

  foe_weapon = foe->query_wielded();
  if( !foe_weapon ) return;
  
  tell_room( environment( apprentice ),
    "The apprentice casts the spell MAGNETIC WEAPON SUMMONING.\n" );
  if( foe_weapon->query_non_metal() ) {
    tell_object( foe,
      "The weapon is not made of metal, and remains in your hands.\n" );
    return;
  }
  if( foe_weapon->drop() ) {
    tell_object( foe, "Strange. That weapon seems to be stuck.\n" );
    return;
  }
  app_weapon = apprentice->query_wielded();
  app_wc = app_weapon ? app_weapon->weapon_class() : 0;
  say( sprintf( "%s's %s jumps to the apprentice!\n",
    capitalize( foe->query_name() ), foe_weapon->query_name() ), foe );
  tell_object( foe, sprintf( "Your %s jumps to the apprentice!\n",
    foe_weapon->query_name() ) );
  transfer( foe_weapon, apprentice );
  if( foe_weapon->weapon_class() > app_wc ) {
    apprentice->init_command( "unwield " + app_weapon->query_name() );
    apprentice->init_command( "wield " + foe_weapon->query_name() );
    /* wield failed (Doomsgiver, for example), re-wield old weapon */
    if( !apprentice->query_wielded() )
      apprentice->init_command( "wield " + app_weapon->query_name() );
  }
} /* end take_weapon */

void bird_handle_leaves( string str ) {
  string who, rest;
  object last_location;

  if( sscanf( str, "%s leaves %s.\n", who, rest ) != 2 ) {
    tell_room( environment( bird ), "The bird looks brain damaged.\n" );
    return;
  }
  if( !teleportee || who != teleportee->query_name() ) return;
  last_location = environment( bird );
  bird->init_command( rest );
  if( environment( bird ) == last_location ) {
    tell_room( environment( bird ), 
      "Bird looks around, sighs disappointedly and flies away.\n" );
    move_object( bird, "players/padrone/store" );
    destruct( bird );
  }
}

void bird_handle_say( string str ) {
  string who, phrase, a, b;
  object ticket;

  if( sscanf( str, "%s says: %s\n", who, phrase ) != 2 && 
      /* Morgar's say with quotes! */
      sscanf( str, "%s says \"%s\"\n", who, phrase) != 2 && 
      sscanf( str, "%s tells you: %s\n", who, phrase ) != 2 ) {
    tell_room( environment( bird ), "The bird looks brain damaged.\n" );
    return;
  }
  phrase = lower_case( phrase );
  client = present( lower_case( who ), environment( bird ) );
  if( !client ) {
    tell_room( environment( bird ), "The bird looks confused.\n" );
    return;
  }
  if( client != teleportee ) {
    tell_room( environment( bird ), sprintf( "The small bird doesn't "
      + "seem interested in what %s has to say.\n", who ) );
    return;
  }
  if( sscanf( phrase, "%syes%s", a, b ) == 2 ||
      sscanf( phrase, "%steleport%s", a, b ) == 2 ||
      sscanf( phrase, "%sok%s", a, b ) == 2 ) {
    tell_room( environment( bird ), sprintf( "The small bird chirps "
      + "happily, flutters around %s, and flies away.\n", who ) );
    move_object( bird, "players/padrone/store" );
    destruct( bird );
    latest_teleportee = teleportee;
    tell_object( teleportee, "You are magically transferred somewhere.\n" );
    teleportee->move_player( "X", environment( apprentice ) );
    if( !present( "castle ticket", teleportee ) ) {
      tell_room( environment( apprentice ), "The apprentice says: As a "
	+ "bonus you get a free ticket to the Castle of Padrone!\n" );
      transfer( ticket = call_other("players/padrone/outside/front_yard", 
	"make_ticket"), teleportee );
      say( sprintf( "The apprentice gives ticket to %s.\n",
	teleportee->query_name() ), teleportee );
    }
    else {
      tell_room( environment( apprentice ),
	"The apprentice drops the ticket.\n" );
      move_object( ticket, this_object() );
    }
    teleportee = 0;
    busy_teleporting = 0;
    return;  
  }
  if( sscanf( phrase, "%snot%s", a, b ) == 2 ||
      sscanf( phrase, "%sno%s", a, b ) == 2 ||
      sscanf( phrase, "%sdo not%s", a, b ) == 2 ||
      sscanf( phrase, "%sdon't%s", a, b ) == 2 ) {
    tell_room( environment( bird ),
      "The small bird looks disappointed and flies away.\n" );
    move_object( bird, "players/padrone/store" );
    destruct( bird );
    tell_room( environment( apprentice ), sprintf( "The apprentice says: " 
      + "%s didn't want to be teleported.\n", teleportee->query_name() ) );
    teleportee = 0;
    busy_teleporting = 0;
    return;
  }
  tell_room( environment( bird ), "The small bird doesn't understand. "
    + "It is still waiting for something.\n" );
} /* bird_handle_say */
/* --- End interactive string handling functions --- */

/* --- Miscellaneous functions called from elsewhere in this object --- */
static int take_money( int sum ) {
  object the_money;

  if( client->query_money() < sum ) {
    tell_object( client, 
      sprintf( "That would cost %d gold pieces, which you don't have.\n",
	sum ) );
    return 0;
  }
  tell_object( client, 
    sprintf( "You pay %d gold coins for the magic assistance.\n", sum ) );
  client->add_money(-sum);

  /*  Put the money in the vault -- but not if the client is a wizard! */
  if( !client->query_wizard() ) {
    the_money = clone_object( "obj/money" );
    the_money->set_money( sum );
    call_other( "players/padrone/walker/cell", "put_in_vault", the_money );
  }
  if( !random( 10 ) ) {
    tell_object( client, 
      "The apprentice fumbles and -- BLAMMM!! The spell failed."
      + " You are now a frog.\n" );
    say( sprintf( "The apprentice fumbles and turns %s into a frog.\n",
      client->query_name() ), client );
    client->frog_curse(1);
    return 0;
  }
  return 1;
}

/* Called when apprentice dies */
int monster_died( object poor_apprentice ) {
  if( invisible_companion ) destruct( invisible_companion );
  teleportee = 0;
  latest_teleportee = 0;
  busy_teleporting = 0;
  if( bird ) {
    tell_room( environment( bird ),
      "Suddenly the small bird fades away and disappears.\n" );
    move_object( bird, "players/padrone/store" );
    destruct( bird );
  }   
  return 0;
}
/* --- End miscellaneous functions --- */

