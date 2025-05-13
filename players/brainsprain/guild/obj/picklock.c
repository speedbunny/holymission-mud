/* 920407 mud@mud.edvz.uni-linz.ac.at Herbert Rosmanith */

int is_broken;			/* is it broken ? */

id(str) { return str=="picklock"; }

short() { 
  if (is_broken) return "broken picklock";
//  else return "picklock";
  else return "a picklock";
}

long() { 
  if (is_broken) write("A broken picklock.\n");
  else write("A picklock. Thieves can use it.\n");
}

get() { return 1; }

query_value() {
  if (is_broken) return 5;
  return 100;
}

set_broken() { is_broken=1; }
query_broken() { return is_broken; }
