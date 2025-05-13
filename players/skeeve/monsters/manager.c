inherit "/obj/monster";

#include "/players/skeeve/area.h"
#include "/players/skeeve/code.h"

string function, type, match;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("manager");
    set_short("The manager");
    set_long("He is a small and slim elf. He isn't a fighter, "
            +"but he is a very good manager.\n");
    set_race("elf");
    set_size(2);
    set_al(400);
    set_level(14);
    set_hp(600);
    set_sp(600);
    set_wc(12);
    set_ac(0);
    set_aggressive(0);
    add_money(5 + random (11));
    set_no_steal();
    set_whimpy(50);
  }
  if (!function) {
    setup_arrays();
    set_match(this_object(), function, type, match);
  }
  
  ARMOUR("black trousers","black_trousers",this_object());
  ARMOUR("black shoes","black_shoes",this_object());
  ARMOUR("black shirt","black_shirt",this_object());
  ARMOUR("black cloak","black_cloak",this_object());
}

setup_arrays() {
    function = allocate(2);
    type = allocate(2);
    match = allocate(2);
    function[0] = "handle_say";     type[0] = "says";    match[0] = "";
    function[1] = "handle_arrives"; type[1] = "arrives";    match[1] = "";
}

handle_say(arg) {
  string *words, x;
  int i;
  if ( !arg ) return;    
  if (!sscanf( arg, "%s says: %s\n", x, arg ))
    sscanf ( arg, "%s asks: %s\n", x, arg );
  if (x == "The manager") return;
  words = explode( arg, " " ); 
  if ( !words || !sizeof( words ) ) return 1;
  i = 0;
  while ( i < sizeof( words ) ) {
    if ( words[i] == "job" || words[i] == "jobs" || words[i] == "jobs" ) {
      notify("The manager says: Yes. I have a nice job for you. Our cook is lost at\n"
            +"the search for the ingrediants of Druid Lakmir's dinner. We heard\n"
            +"that a very strong monster had killed him. \n"
            +"Go and make the dinner for the druid instead of the cook.\n");
      return;
    } else if ( words[i] == "ingrediants" ) {
      notify("The manager says: All you need to know about the ingrediants is writen\n"
            +"down in the cook's cooking-book.\n");
      return;
    } else if ( words[i] == "dinner" ) {
      notify("The manager says: Druid Lakmir loves to eat a fine fishsoup.\n");
      return;
    } else if ( words[i] == "fishsoup" ) {
      notify( "The manager says: At first you must search the ingrediants.\n");
      return;
    } else if ( words[i] == "Lakmir" || words[i] == "lakmir" ) {
      notify( "The manager says: He is lying in his bed!\n");
      return;
    } else if ( words[i] == "cook" ) {
      notify( "The manager says: He had a book with a recipe for a fine fishsoup!\n");
      return;
    } else if ( words[i] == "recipe") {
      notify( "The manager says: You must search the cook's cooking-book.\n");
      return;
    } else if ( words[i] == "cooking-book" ||words[i] == "book") {
      notify( "The manager says: Maybe it's in the kitchen.\n");
      return;
    } else if ( words[i] == "water") {
      notify( "The manager says: There is a brooklet in the southwest.\n");
      return;
    } else if ( words[i] == "ruby") {
      notify( "The manager says: Maybe the snake has it.\n");
      return;
    } else if ( words[i] == "rug") {
      notify( "The manager says: You must burn it with a torch.\n");
      return;
    } else if ( words[i] == "snake") {
      notify( "The manager says: The snake lives in a cave in the west.\n");
      return;
    } else i++;
  }
}

handle_arrives (str) {
  notify("The manager says: Hi! Can I help you?\n");
}

hit_player(dam,kind) {
  object bodyguard;
  int x;
  
  x = ::hit_player(dam,kind);

  if (bodyguard = CASTLE->query_monster(7)) {
    tell_room(environment(this_object()),"Help!....Heeelp!\n");
    if (environment(bodyguard) != environment(this_object())) {
      tell_room(environment(this_object()),"The bodyguard arrives.\n");
      move_object(bodyguard,environment(this_object()));
    }
    bodyguard->attack_object(attacker_ob);
  }
  return (x);
}

notify(x) {
    write(x); say(x);
}
