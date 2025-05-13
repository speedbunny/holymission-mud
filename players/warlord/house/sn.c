inherit "obj/monster";

string allowed;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("snoopchecker");
  set_short(0);
  set_long(0);
  set_level(50);
  set_hp(10000000);
  set_ac(10000000);
}

query_real_name() { return "warlordtest"; }

heart_beat() {
  object obje,obje2;
  string snoopname;
  int loop,permit;
  if(!environment(this_object())) return;
  if(file_name(environment(this_object()))!="players/warlord/house/master")
	move_object(this_object(),"players/warlord/house/master");
  allowed="players/warlord/house/master"->query_allowed();
  for(loop=0;allowed[loop];loop++) {
    obje=present(allowed[loop],environment(this_object()));
    if(obje) {
      obje2=query_snoop(obje);
      if(obje2 && !allow(obje2->query_real_name())) {
	  move_object(obje2,"room/void");
	  destruct(obje2);
      }
    }
  }
  ::heart_beat();
}

allow(str) {
  int loop,flag;
  loop=0; flag=0;
  while(loop<10 && !flag) {
    if(str==allowed[loop]) flag=1;
    loop++;
  }
  return flag;
}
