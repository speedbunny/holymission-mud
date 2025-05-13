object wep_ob;
int time;
int bonus;

query_prevent_shadow() { return 1; }

set_bonus(n) { bonus = n; }
set_weapon(obj) { wep_ob = obj; }
set_done(t) { time = t; }

start(arg) {
  shadow(wep_ob,1);
  call_out("finish",time);
}

long() {
  wep_ob->long();
  write("This weapon has poison on it!\n");
}

weapon_class() {
  return wep_ob->query_class()+bonus;
}

finish() {
 if(wep_ob->query_wielded())
   tell_object(environment(wep_ob),"The poison on your weapon dries up!\n");
 destruct(this_object());
}
