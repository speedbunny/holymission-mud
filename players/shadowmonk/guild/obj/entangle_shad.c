#include "func.c"
object owner;
int duration;

void dest_shad();

status entangle_shad() { return (1); }

void set_owner(object ob) { owner = ob; }

void start(int level) {
  duration = level / 5;
  shadow(owner, 1);
}

int attack(object ob, int hand) {
  if (duration < 1) {
    TELL(owner,"You break free of the tangle vines!\n");
    say(NAME(owner) + " breaks free of the tangle vines!\n");
    dest_shad();
  }
  duration--;
  TELL(owner,"You are trapped in tangle vines!\n");
  say(NAME(owner) + " fights against the tangle vines!\n");
  return (1);
}

void dest_shad() {
  unshadow();
  destruct(TO);
}
