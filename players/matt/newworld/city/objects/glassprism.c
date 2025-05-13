inherit "/obj/thing";

#include "/players/matt/defs.h"

#define ACID_DAM 50

int value;
string msg, type, extra_string, inscr;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  type = "empty";
  extra_string = "It is empty.\n";
  value = 1000;
  inscr = "fill";
  msg = "Nothing happens.\n";
  set_name("glass prism");
  set_alias("prism");
  set_weight(1);
}

id(arg) {
  return arg == "prism" || arg == "glass prism" ||
    arg == type + "glass" || arg == type + " prism";
}

short() {
  return CAP(type) + " prism (glass)";
}

long() {
  write("Shaped like a small glass pyramid, this prism refracts the\n");
  write("light into rainbows in all directions.\n");
  write(extra_string);
  write("There is an inscription on the side.\n");
}

init() {
  ::init();
  add_action("read", "read");
  add_action("fill", "fill");
  add_action("smash", "smash");
}

read(arg) {
  object spec;
  if(id(arg) || arg == "inscription") {
    spec = present("spectacles", TP);
    if(spec && spec->query_worn()) {
      write("The inscription simply reads '" + inscr + "'.\n");
      return 1;
    }
    write("You cannot understand the writing.\n");
    return 1;
  }
}

fill(arg) {
  string contents;
  if(id(arg)) {
    write("Fill prism with what?\n");
    return 1;
  }
  contents = ENV(TP)->query_fill_with();
  if(contents && arg == "empty prism with " + contents ||
     arg == "prism with " + contents) {
    if(type == "empty") {
      ENV(TP)->fill_it(TO);
      return 1;
    }
    if(!present("emptyglass", TP)) {
      write("The prism is already full.\n");
      return 1;
    }
  }
}

smash(arg) {
  object att;
  if(id(arg)) {
    write("You smash the prism to shards.\n");
    say(TP->NAME + " smashes " + TP->POS + "  prism to shards.\n");
    TELLR(ENV(TP), msg);
    switch(type) {
      case "brown":
	att = TP->query_attack();
	if(att && present(att, ENV(TP))) {
	  att->HIT(ACID_DAM);
	  TELL(att, "You are burned with the prism's acid!\n");
	  TELL(TP, att->NAME + " is burned with the prism's acid!\n");
	  say(att->NAME + " is burned with the prism's acid!\n", att);
	  destruct(TO);
	}
	return 1;
	break;
      default:
	if(ENV(TP)->query_smash())
	  ENV(TP)->smash_it();
	destruct(TO);
	return 1;
    }
  }
}

set_value(arg) {
  value = arg;
  return 1;
}
set_type(arg) {
  type = arg;
  return 1;
}
set_extra(arg) {
  extra_string = arg;
  return 1;
}
set_inscr(arg) {
  inscr = arg;
  return 1;
}
set_msg(arg) {
  msg = arg;
  return 1;
}

query_value() { return value; }
