/* Shadow from The Cloak of Blade */
/* Coded on Holy Mission by Blade */
/* Version 10.8.94                */

object master;

void start_shad(object obj) {
  master = obj;
  shadow(master, 1);
}

hit_player(int dam, int kind) {
tell_object(master,"Monster inflicts "+dam+" damage with attack "+kind+"\n");
return master->hit_player(dam,kind);
}

object query_damage_shadow(){
  return this_object();
}
