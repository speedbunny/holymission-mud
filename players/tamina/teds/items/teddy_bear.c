inherit "obj/treasure";

query_auto_load() {
  return "players/ted/items/teddy_bear:";
}

short() {
  return "A soft, silky Teddy with lace trim";
}

long() {
 write("This looks exactly like a lace body suit!\n");
}

drop() { return 1;}

id(str) { return str == "teddy"; }

query_name() { return "teddy"; }
