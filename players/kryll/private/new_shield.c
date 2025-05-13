#include "/players/meecham/guild/func.c"
 
object owner;
int length;
 
void dest_me();
 
status fireshield() { return (1); }
 
int set_owner() {
  owner = find_player("kryll");
  if(owner) return 1;
  else return 0;
}
 
void start() {
  length = (LLVL(owner) ? LVL(owner) + LLVL(owner) : LVL(owner)) * 10;
  shadow(owner, 1);
}
 
varargs mixed hit_player(int dam,int kind,mixed elem) {
  object tp;
 
  if (length < 1) dest_me();
  length--;
  tp = TP;
  if(tp && tp != owner) {
    TELL(owner, "This player = " + to_string(tp) + "\n");
    if(owner)
    TELL(owner, "Your fireshield sears " + NAME(tp) + "!\n");
    TELL(tp, "You are seared by " + NAME(owner) + "'s fireshield!\n");
    tp->hit_player(dam * 2, kind);
  }
  return (owner->hit_player(dam, kind));
}
 
void dest_me() {
  TELL(owner, "Your flames sizzle as your fireshield wears off.\n");
  unshadow();
  destruct(this_object());
}
 
void stop_fshield_shad() {
  unshadow();
  destruct(this_object());
}
