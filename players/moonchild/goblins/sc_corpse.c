inherit "obj/corpse";

query_scalped() { return 1; }

short() {
  if(decay<2) return "The somewhat decayed remains of " + capitalize(name);
  return "Scalped corpse of " + capitalize(name);
}

long() { write("This is the scalped dead body of " + capitalize(name) + ".\n"); }

id(str) { return str=="corpse" || str=="corpse of " + name || str=="remains" ||
	str=="scalped corpse" || str=="scalped corpse of " + name ||
	str=="scalped remains"; }
