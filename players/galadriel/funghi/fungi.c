inherit "obj/treasure";
reset (arg) {
  if (arg) return;
  set_id ("fungus");
  set_alias ("mushroom");
  set_short ("A redish fungus");
  set_long ("The cap shows a bright orange-red. ");
  set_weight (random (1));
  set_value (random (700));
}
