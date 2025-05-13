inherit "obj/monster";

#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"

status linked;
int gnum;
string short_desc, obdir;
object att, master, control, leader;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "Seeker";
  set_name("Seeker");
  set_alias("seeker");
  set_level(1);
  set_no_fight(1);
  gnum = GM->query_number(GUILD);
  obdir = GM->query_dir(gnum) + "/objects/";
}

init() {
  ::init();
  if(!master || master->query_ghost()) destroy_me(1);
}

hit_player() {
  if(TP && living(TP) && (TP != TO) && (ENV(TP) == ENV(TO))) {
    write("The Seeker explodes in a bright flash of light!\n" +
	  "You feel biting pain as shards embed themselves " +
	  "in your flesh.\n");
    if(master && (TP != master))
      TELL(master, TP->NAME + " has destroyed your Seeker!\n");
    TELLS(TO->SHORT + " explodes, impaling " + TP->SNAME +
	  " with jagged shards!\n", TP, master);
    TP->HIT(SEEK_DAM);
    destroy_me(1);
    return 1;
  }
}

heart_beat() { set_heart_beat(0); }

catch_tell(arg) {
  string dummy, lname, exit_msg, exit_mmsg;
  if(sscanf(arg, SHORT + "%s", dummy) ||
     sscanf(arg, SHORT + "Seeker%s", dummy)) return;
  if(linked && ENV(TO) != ENV(master)) {
    TELL(master, "SEEKER: " + arg);
    return 1;
  }
}

make_me(obj) {
  master = obj;
  control = clone_object(obdir + "scontrol");
  MOVE(control, master);
  control->orient(TO);
  short_desc = master->SNAME + "'s Seeker";
  set_short(short_desc);
  set_long("A lean, low-built, four-legged beast whose keen eyes\n" +
	   "scan the area vigilantly. It belongs to " +
	   master->SNAME + ".\n");
  write("You chant the words of Summoning.\n");
  write("A Seeker materializes before you.\n");
  say(master->NAME + " traces burning symbols in the air and " +
      "calls out:\n");
  say("'Te arcesso ut sis meos oculos!'\n" +
      "A lean Seeker materializes sitting on its haunches, its " +
      "keen eyes\n" +
      "gazing into your very soul.\n");
  return 1;
}

move_me(silent) {
  if(leader && (ENV(TO) != ENV(leader))) {
    if(master->SP >= SEEK_GO_SP) {
      if(!silent) {
	if(leader != TP)
	  TELL(TP, "Your Seeker follows " + leader->NAME + ".\n");
	TELLRS(ENV(TO), "Seeker follows " + leader->NAME + ".\n", TO);
      }
      MOVE(TO, ENV(leader));
      if(!silent)
	TELLR(ENV(TO), "Seeker arrives.\n", TO);
      control->dump_long(ENV(TO));
    }
    else {
      TELL(master, "You cannot make your Seeker follow " + leader->NAME +
	   " any longer.\n");
      set_follow();
    }
  }
  return 1;
}

destroy_me(silent) {
  if(!silent) {
    if(master) TELL(master, "Your Seeker vanishes.\n");
    TELLRS(ENV(TO), SHORT + " vanishes.\n", master, TO);
  }
  destruct(control);
  destruct(TO);
  return 1;
}

set_link(arg) { linked = arg; }
set_follow(obj) { leader = obj; }

query_follow() { return leader; }
query_link() { return linked; }
query_creature() { return "seeker"; }
