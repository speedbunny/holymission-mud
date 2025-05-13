#define SAY(x);         tell_room(environment(),x);
inherit "obj/monster";


string next_out;
object tam, jacket, next_dest;
int delay;

short() { return "Deril, the ganja thief"; }

long() {
    write(short() + ".\n");
}

id(str) { return ::id(str) || str=="deril"; }

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("deril");
set_level(18);
  add_money(random(100)+25);
  tam = clone_object("players/rasta/obj/tam");
  move_object(tam,this_object());
}
