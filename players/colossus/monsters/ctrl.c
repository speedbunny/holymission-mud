/*
 * A control daemon for "changing" a monster into other monsters
 *
 * Justice@HMC
 *
 * Made specifically for Longshot@HMC
 *
 * May 10, 1993
 *
 */
 
#define OWNER    "longshot"
#define DIR      "/players/"
#define SUBDIR   "monster"
#define MASTER   "shang"
#define CHANGER  "corpse_changer"
#define MONSTERS ({ "sonia", "goro", "shang", "cage", "kano", "liukang", "subzero", "scorpion", "raiden" })
#define CHANCE   5
 
object master;
string old_name;
 
id(str) { return str == "monster_daemon"; }
 
init() {
   call_out("load_master", 2);
   set_heart_beat(1);
}
 
heart_beat() {
   if (nobody_here()) {
      set_heart_beat(0);
      return;
   }
   if (!random(CHANCE))
      change_monster();
}
 
load_master() {
   object it;
   if (!environment(this_object()))
      return;
   if (master)
      return;
   if ((it = clone_object(DIR + OWNER + "/" + (SUBDIR != "" ? SUBDIR + "/" : "") + MASTER))) {
      master = it;
      move_object(clone_object(DIR + OWNER + "/" + CHANGER), it);
      move_object(it, environment(this_object()));
   }
}
change_monster() {
   int which, x;
   object it, who;
   if (master && master->query_attack()) {
      do {
         which = random(sizeof(MONSTERS));
      }
      while(old_name == MONSTERS[which]);
      while(catch(it = clone_object(DIR + OWNER + "/" + (SUBDIR != "" ? SUBDIR + "/" : "") + MONSTERS[which])) && x++ < sizeof(MONSTERS));
      it->set_level(master->query_level());
      it->set_align(master->query_alignment());
      it->set_ep(master->query_exp());
      it->set_hp(master->query_hp());
      tell_room(environment(master), master->query_name() + " suddenly changes to " + it->query_name() + "!\n");
      while(first_inventory(it))
         destruct(first_inventory(it));
      while(first_inventory(master))
         move_object(first_inventory(master), it);
      move_object(it, environment(master));
      who = master->query_attack();
      it->attack_object(who);
      destruct(master);
      if (who)
         who->attacked_by(it);
      master = it;
      old_name = MONSTERS[which];
   }
   else
      if (!master)
         destruct(this_object());
}
nobody_here() {
   return !sizeof(filter_array(deep_inventory(environment(this_object())), "is_interactive", this_object()));
}
is_interactive(what) {
   return interactive(what);
}
 
