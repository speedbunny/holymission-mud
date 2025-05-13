inherit "obj/monster";

#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"

int light_strength;
object att, master;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Wisp");
  set_alt_name("wisp");
  set_alias("will-o-the-wisp");
  set_race("wisp");
  set_level(1);
  set_no_fight(1);
}

init() {
  if(!master) destroy_me(1);
  add_action("ban", "ban");
}

hit_player() {
  if(TP && living(TP) && (TP != TO) && (ENV(TP) == ENV(TO))) {
    write("The Wisp explodes in a bright flash of light!\n" +
	  "You feel biting pain as shards embed themselves " +
	  "in your flesh.\n");
    if(TP != master)
      TELL(master, TP->NAME + " has destroyed your Wisp!\n");
    TELLRS(ENV(TO), TO->SHORT + " explodes, impaling " + TP->SNAME +
	   " with jagged shards!\n", TP, master, TO);
    TP->HIT(WISP_DAM);
    destroy_me(1);
    return 1;
  }
}

heart_beat() { set_heart_beat(0); }

ban(arg) {
  if(TP != master) return;
  if(id(arg)) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(WISP_BAN_SP);
    write("You banish your Will-O-The-Wisp.\n");
    say(TP->SNAME + " gestures towards " + TP->POS +
	" Wisp, banishing it to its own Plane.\n");
    TELLRS(ENV(TP), "The area becomes dimmer.\n", TO);
    destroy_me(1);
    return 1;
  }
}

make_me(obj) {
  master = obj;
  light_strength = WISP_LS;
  set_short(master->SNAME + "'s Will-O-The-Wisp");
  set_long("A living globe of Light hovering above the ground.\n" +
	   "It belongs to " + master->SNAME + ".\n");
  set_light(light_strength);
  write("You chant the words of Summoning.\n");
  write("A Will-O-The-Wisp materializes before you, " +
	"illuminating the area.\n");
  say(master->NAME + " traces burning symbols in the air and " +
      "calls out:\n");
  say("'Te arcesso ut illumines noctem!'\n", master);
  say("A living globe of Light materializes, hovering above " +
      "the ground.\n");
  say("The area becomes brighter.\n");
  return 1;
}

move_me(silent) {
  if(ENV(TO) != ENV(master)) {
    if(!silent)
      TELLRS(ENV(TO), SHORT + " follows " + master->OBJ + ". " +
	  "The area becomes dimmer.\n", TO);
    MOVE(TO, ENV(master));
    if(!silent) {
      TELL(master, "Your Wisp floats in. The area becomes brighter.\n");
      TELLRS(ENV(TO), SHORT + " floats in. The area becomes brighter.\n",
	     master, TO);
    }
  }
  return 1;
}

destroy_me(silent) {
  if(!silent) {
    if(master) TELL(master, "Your Wisp vanishes. " +
		    "The area becomes dimmer.\n");
    TELLRS(ENV(TO), SHORT + " blinks out of existence.\n", master, TO);
    TELLRS(ENV(TO), "The area becomes dimmer.\n", master, TO);
  }
  destruct(TO);
  return 1;
}

query_ls() { return light_strength; }
query_show_short() { return 1; }
query_creature() { return "wisp"; }
