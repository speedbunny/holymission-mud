
string info, name, spell_type;
string short_desc, long_desc;
string alias, spell_dam;
string spell_mess1, spell_mess2;
string do_cmd, alt_name;
string value, weight, charges;
int used;

reset(arg) {
 if(arg) return 1;
 charges = 0;
 spell_dam = 0;
}

init() {
 if(environment() != this_player()) return 1;
 add_action("do_spell"); add_verb(do_cmd);
}

short() { return short_desc; }

long(str) {
  write(long_desc);
}

id(str) {
 return (str == name || str == alias || str == alt_name || str == "wand");
}

query_charges() { return charges; }
query_info() { 
  write("Charges: "+charges+"  Spell type: "+spell_type+"  Spell damage: 1-"+spell_dam+"\n command: "+do_cmd+"\n");
  return;
}
query_value() { return value; }
query_weight() { return weight; }
query_name() { return name; }
query_type() { return spell_type; }

set_name(n) { name = n; set_short(n); }
set_short(s) { short_desc = s; long_desc = s+"\n"; }
set_alias(a) { alias = a; }
set_alt_name(alt) { alt_name = alt; }
set_long(l) { long_desc = l; }
set_value(v) { value = v; }
set_weight(w) { weight = w; }
set_spell_mess1(m1) { spell_mess1 = m1; }
set_spell_mess2(m2) { spell_mess2 = m2; }
set_spell_dam(dam) { spell_dam =  dam; }
set_spell_type(t) { spell_type = t; }
set_charges(c) { charges = c; }
set_command(cmd) { do_cmd = cmd; }

do_spell(str) {
 object ob;
 if(used) return write("Your staff is not ready to attack again yet.\n");
 if(!str)
  ob = call_other(this_player(),"query_attack");
 else
  ob = present(lower_case(str), environment(this_player()));
 if(!ob || !living(ob)) {
	write("At whom?\n");
	return 1;
  }
 if(charges <= 0) {
	write(short_desc+" vibrates slightly, but nothing happens.\n");
	say(call_other(this_player(),"query_name"));
	say(" fiddles with "+short_desc+", but nothing happens.\n");
	return 1;
  }
  charges -= 1;
  if(call_other(ob,"query_npc"))
	call_other(ob,"attack_object",this_player());
  used=1;
  set_heart_beat(1);
  tell_object(ob, "You are hit by a "+spell_type+"!\n");
  say(call_other(this_player(),"query_name"));
  say(" activates "+short_desc+".\n");
  say(spell_mess1+"\n");
  write(spell_mess2+"\n");
  call_other(ob,"hit_player",spell_dam);
  return 1;
}

heart_beat() { used=0; set_heart_beat(0); }

get() { return 1; }
drop() { return 0; }
