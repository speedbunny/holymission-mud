int scalps;

restore(str) {
  if(restore_object("players/moonchild/gquest/" + str)) return scalps;
  scalps=-1;
  add(str);
  return -1;
}

save(str) { save_object("players/moonchild/gquest/" + str); return; }

add(str) {
  if(!restore_object("players/moonchild/gquest/" + str)) scalps=0;
  scalps++;
  save_object("players/moonchild/gquest/" + str);
  return scalps;
}
