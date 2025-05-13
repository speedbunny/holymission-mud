#define SAY(x);         tell_room(environment(),x);
inherit "obj/monster";


string next_out;
object tam, jacket, next_dest;
int delay;

short(){ return "Hem, the pan-African freedom fighter"; }

long() {
    write(short() + ".\n");
}

id(str) { return ::id(str) || str=="hem"; }

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("hem");
  set_level(40);
  add_money(random(400)+250);
  tam = clone_object("players/rasta/obj/tam");
  move_object(tam,this_object());
}
