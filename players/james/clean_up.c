/* new clean_up function Mud, by James of Holy Mission. Feel free to
   copy this to other muds, if appropriate */

clean_up(arg) {
  int i;
  object *all;

  if(arg > 1) return 0; 
  all=all_inventory(this_object());
  for(i=0; i<sizeof(all); i++) {
    if(living(all[i])) {
      if(!(all[i]->query_npc())) return 1;
      if(all[i]->query_max_hp() != all[i]->query_hp()) return 1;
    } else {
      if(!(all[i]->query_armour() || all[i]->query_weapon())) return 1;
    }
  }
/* If we get this far, the room contains only Armours, Weapons, and
   fully healed Monsters.  We assume its OK to destroy this room
   and all of its contents */

  all=deep_inventory(this_object());
  for(i=0; i<sizeof(all); i++) if(all[i]) destruct(all[i]);
  destruct(this_object());
}
