/* Shadow from The Cloak of Blade */
/* Coded on Holy Mission by Blade */
/* Version 10.8.94                */

object master;

void start_shad(object obj) {
  master = obj;
  shadow(master, 1);
}

hit_player(int dam, int kind) {
  return master->hit_player(0,kind);
}

object query_invincible_shadow(){
  return this_object();
}
