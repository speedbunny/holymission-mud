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

int hit_player(int dam, int kind) {
  if (length < 1) dest_me();
  length--;
  if (TP != owner) {
    TP->hit_player(dam * 2, kind);
    TELL(owner, "Your fireshield sears " + NAME(TP) + "!\n");
    TELL(TP, "You are seared by " + NAME(owner) + "'s fireshield!\n");
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
