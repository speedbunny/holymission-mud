/* lightstone.c */
 
status glowing;
 
get() { return 1; }
 
query_value() { return 100; }
 
drop() { return 0; }
 
id(str) { return str == "worm" || str == "glowworm"; }
 
short() {
  if (glowing)
    return "A trained glowworm (glowing)";
  else
    return "A trained glowworm";
}
 
long() {
  write("This is a glowworm trained by the Faun-druid.\n");
  write("He will start glowing if you tell him to.\n");
  write("Simply do 'glow worm' and it'll glow.\n");
}
 
init() {
  add_action("light","glow");
}
 
light(str) {
  if (!str) return 0;
  if (str != "worm") return 0;
  if (glowing) {
    write("The glowworm is already glowing, he looks puzzled.\n");
    return 1;
  }
  if (this_player()->query_spell_points() < 5) {
    write("You don't have enough spellpoints, the glowworm "+
     "doesn't hear you!\n");
    return 1;
  }
  write("The glowworm begins to glow.\n");
  set_light(1);
  glowing = 1;
  this_player()->restore_spell_points(-5);
  call_out("extinguish",300);
  return 1;
}
extinguish() {
  say("The glowworm stops glowing.\n");
  set_light(-1);
  glowing = 0;
  return 1;
}
 
