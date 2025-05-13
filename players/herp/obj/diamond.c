/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/* Black Diamond / Grim Reaper. Inspired by Realms-mud */

#define	OBJ	"players/herp/obj"

inherit "obj/thing";
string kill_str;

reset(arg) {

  if (!arg) {
    set_name("diamond");
    set_alias("black diamond");
    set_short("a black diamond");
    set_long("A black diamond with an inscription on it.\n");
    set_read("It reads: 'death' and 'call reaper' ...\n");
    set_weight(1);
    set_can_get(1);
    set_value(10000);
  }
}

init() {
  add_action("set_death","death");
  add_action("do_call","call");
  add_action("read","read");
}

read(str) { if (str=="inscription") return ::read("diamond"); }

set_death(str) {
  if (str) {
     kill_str=str;
     write("The reaper understands.\n");
     return 1;
  }
}

do_call(str) {
object ob,pl,e;

  if (str=="reaper") {
     write("The diamond disappears.\n");
     ob=clone_object(OBJ+"/reaper");
     if (kill_str) {
	ob->set_death(kill_str);
	if ((pl=find_living(kill_str)) && (e=environment(pl))) {
	   ob->move_player("X",e);
	   ob->attack_object(pl);
	}
     }
     else ob->move_player("X",environment(this_player()));
     destruct(this_object());
     return 1;
  }
}
