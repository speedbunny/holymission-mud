object owner;
int length;

void dest_me();

status bark_shadow() { return (1); }

void set_owner(object ob) { owner = ob; }

void start(int level) {
  length = 100 + 2 * (owner->query_legend_level() ? 
    owner->query_legend_level() + owner->query_level() :
    owner->query_level()); 
  shadow(owner,1);
}

int hit_player(int dam, int kind) {
  if (length < 1) dest_me();
  length--;
/*
  if (owner->query_immortal())
    tell_object(owner, "Original damage: " + dam + "\n");
*/
  dam = dam * 2 / 3;
/*
  if (owner->query_immortal())
    tell_object(owner, "Modified damage (before ac check): " + dam + "\n");
*/
  tell_object(owner, "Your barkskin absorbs some damage!\n");
  return (owner->hit_player(dam, kind));
}

void dest_me() {
  if(owner)
    tell_object(owner,"\nYour barkskin wears off!\n\n");
  unshadow();
  destruct(this_object());
}

void stop_bark_shad() {
  unshadow();
  destruct(this_object());
}
