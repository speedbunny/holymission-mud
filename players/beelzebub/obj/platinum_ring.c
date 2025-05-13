string shortname;
int worn;

reset(arg) {
  if(arg) return;
  shortname="A Platinum Ring";
}

query_weight() { return 0; }
query_value() { return 0; }

short() { 
  if(worn) return shortname+" (worn)";
  else return shortname;
}

get() { 
  if(!call_other(this_player(),"query_npc",0)) {
    write("The ring slips onto one of your fingers by\n");
    write("some invisible force as you take it.\n");
    worn=1;
  }
  return 1;
}

long() { 
  write("This ring bears the symbol of Elyssia.\n");
}

init() {
  add_action("wear_ring"); add_verb("wear");
  add_action("quit"); add_verb("quit");
}

wear_ring(str) {
  if(id(str)) {
    if(worn) write("You are already wearing it.\n");
    else write("You must get it first.\n");
    return 1;
  }
}

id(str) { return str== "ring" || str=="platinum ring" || str=="trlock5"; }

  destring() {
    write("The platinum ring suddenly disappears in a puff of smoke.\n");
    destruct(this_object());
  }

drop(silent) {
  if(!worn) return 0;
  return 1;
}

quit() {
  if(!worn) return 1;
  write("The platinum ring suddenly disappears in a puff of smoke.\n");
  destruct(this_object());
  call_other(this_player(),"quit",0);
}
