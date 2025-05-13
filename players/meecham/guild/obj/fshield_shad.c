#include "func.c"

object owner;
int length;

void dest_me();

status fireshield() { return (1); }

void set_owner(object ob) { owner = ob; }

void start() {
  length = (LLVL(owner) ? LVL(owner) + LLVL(owner) : LVL(owner)) * 10;
  shadow(owner, 1);
}

varargs mixed hit_player(int dam,int kind,mixed elem) {
  if (length < 1) dest_me();
  length--;
  if (TP && TP != owner) {
    TP->hit_player(dam * 2, kind);
    if(owner && TP)
    TELL(owner, "Your fireshield sears " + NAME(TP) + "!\n");
    if(owner && TP)
    TELL(TP, "You are seared by " + NAME(owner) + "'s fireshield!\n");
  }
  if(owner && TP)
  return (owner->hit_player(dam, kind));
  return 0;
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
