#include "func.c"
object owner;
int length;

void dest_me();

void set_owner(object ob) { owner = ob; }
void set_length(int x) { length = x; }

void start() {
  shadow(owner, 1);
}

int hit_player(int x, int y) {
  if (length < 1) dest_me();
  if (!random(2)) {
    length--;
    TELL(owner, "You try to avoid an attack and get burned by your armour!\n");
    tell_room(ENV(owner), NAME(owner) + " gets burned by " + POSS(owner) +
      " armour!\n");
    return (owner->hit_player(x + random(50), y));
  }
  return (owner->hit_player(x, y));
}

mixed attack() {
  if (length < 1) dest_me();
  if (!random(2)) {
    length--;
    TELL(owner, "You are afraid to shift in your burning armour and miss\n" +
      "an attack.\n");
    say(NAME(owner) + " is too afraid of getting burnt by " + POSS(owner) + 
      " armour to attack!\n");
    return;
  }
  return (owner->attack());
}

void dest_me() {
  unshadow();
  destruct(TO);
}
