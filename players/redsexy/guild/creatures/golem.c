inherit "obj/monster";

#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"

int golemnum;
object att, master, gshad;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Golem");
  set_alias("golem");
  set_level(1);
  set_wc(0);
  set_ep(0);
  set_dead_ob(TO);
}

init() {
  ::init();
  if(!master) destroy_me(1);  
  add_action("destroy", "destroy");
}

heart_beat() { set_heart_beat(0); }
attack() { return 1; }

destroy(arg) {
  if(TP != master) return;
  if(id(arg)) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(GOLEM_DES_SP);
    write("You speak a word of command and destroy your Golem.\n");
    say(TP->NAME + " gestures towards " + TP->POS + " " +
	CAP(golemarray[golemnum][0]) + " Golem and commands:\n");
    say("'Ad pulvem reverte.'\n");
    say("The Golem disintegrates into its component Elements before " +
	"your eyes.\n");
    destroy_me(1);
    return 1;
  }
}

make_me(obj, num) {
  master = obj;
  golemnum = num;
  set_name(CAP(golemarray[num][0]) + " Golem");
  set_alt_name(golemarray[num][0] + " golem");
  set_short(master->SNAME + "'s " + CAP(golemarray[num][0]) + " Golem");
  set_long("A massive, magically animated Golem made of solid " +
	   golemarray[num][0] + ".\n" +
	   "It belongs to " + master->SNAME + ".\n");
  set_hp(golemarray[num][3]);
  set_ac(golemarray[num][4]);
  TELL(master, "You gather and shape the Elements, speaking words " +
       "of power\n");
  TELL(master, "as your Golem comes to life.\n");
  say(master->SNAME + " slowly moves " + master->POS + " hands over " +
      "the ground, gathering up\n", master);
  say("the Elements and giving them form. " + CAP(master->PRO) +
      " chants the words\n", master);
  say("'Tibi dono formam vitamque ut me defendes' as " + master->POS +
      " creation\n", master);
  say("begins to move with its own life.\n", master);
  say("A " + CAP(golemarray[num][0]) + " Golem now stands silently " +
      "before you.\n", master);
  gshad = clone_object(GM->query_dir(GM->query_number(GUILD)) + "/" +
		       "objects/golem_shad");
  gshad->start_shadow(master, TO);
  return 1;
}

move_me(silent) {
  if(ENV(TO) != ENV(master)) {
    if(!silent)
      TELLRS(ENV(TO), SHORT + " trudges after " + master->OBJ + ".\n", TO);
    MOVE(TO, ENV(master));
    if(!silent) {
      TELL(master, "Your Golem trudges in.\n");
      TELLRS(ENV(TO), SHORT + " trudges in.\n", master, TO);
    }
  }
  return 1;
}

destroy_me(silent) {
  if(!silent) {
    if(master) TELL(master, "Your Golem crumbles to dust.\n");
    TELLRS(ENV(TO), SHORT + " crumbles to dust.\n", master, TO);
  }
  if(gshad) destruct(gshad);
  destruct(TO);
  return 1;
}

monster_died() {
  TELL(master, "Your Golem has been destroyed!\n");
  TELLRS(ENV(TO), TO->SHORT + " disintegrates.\n", master, TO);
  destroy_me(1);
  return 1;
}

grmems_in_room() {
  if(master) return ({ master });
  return ({ TO });
}

query_golem_type() { return golemarray[golemnum][0]; }
query_show_short() { return 1; }
query_creature() { return "golem"; }
