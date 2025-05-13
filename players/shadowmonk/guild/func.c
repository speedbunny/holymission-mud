#define INFO "/players/shadowmonk/guild/info.c"

#define GLD "/players/shadowmonk/guild/"
#define OBJ GLD + "obj/"
#define DOC GLD + "docs/"

#define TP this_player()
#define TPSP TP->query_spell_points()
#define TPA TP->query_attack()
#define LVL(x) x->query_level()
#define LLVL(x) x->query_legend_level()
#define NAME(x) x->query_name()
#define PRO(x) x->query_pronoun()
#define POSS(x) x->query_possessive()
#define OBJE(x) x->query_objective()
#define CO clone_object
#define MO move_object
#define TO this_object()
#define PRES present
#define TELL tell_object
#define CAP capitalize
#define ENV environment

#define REDSP(x) TP->restore_spell_points(-x)

status TIME(string type, object *soul, string file) {
  if(soul->check_allow_spell(type, file)) return (1);
  return (0);
}

status MIND(int cost) {
  if(TPSP >= cost) return (1);
  write("Your mind is to weak to cast that.\n");
  return (0);
}

status LEVEL(int level) {
  int lvl;
  
  lvl = LLVL(TP) ? LVL(TP) + LLVL(TP) : LVL(TP);
  if (lvl >= level) return (1);
  write("You are not experienced enough to cast that.\n");
  return (0);
}

status GHOST() {
  if (!TP->query_ghost()) return (1);
  write("You can't seem to cast that in your current state.\n");
  return (0);
}

status CHECK(int cost, int level) {
  if (!GHOST()) return (1);
  if (!LEVEL(level)) return (1);
  if (!MIND(cost)) return (1);
  return (0);
}

status MON_STILL_HERE(object blah) {
  if (PRES(blah, ENV(TP))) return (1);
  printf("Hmm, %s is no longer here...\n", blah->query_name());
  return (0);
}

status NF_ROOM(object blah) {
  if (!blah->query_property("no_fight")) return (0);
  write("You can't fight here!\n");
  return (1);
}
